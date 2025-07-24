---
title: "Js"
author: "Russell Waterhouse"
description: "description here"
tags: ["", ""]
date: 2025-05-26T14:26:34-06:00
draft: false
---

# My Relationship with JavaScript

## Part 1: Why I'm writing this:

I am a professional developer. I get paid to sit down at my desk and put my
fingers on the keyboard and write code, among other things.

For the last 6 months, I've noticed that I can do that for much longer periods
in other programming languages I can in JavaScript. After 3 hours in
JavaScript, I feel the same amount of mental fatigue that I feel after 4 of
Ruby or 5 of Rust.

I want to try to figure out why that is here:

I think the reason is that everything that I have to do in JavaScript feels
like it is much more time and effort than it should be or could be in other
languages. That's not because writing code in JavaScript is hard, it's not.
Nor is it because writing code in JavaScript is time-consuming; I believe
JavaScript to be the language that I can write a proof-of-concept in fastest.
It's because as soon as I hit a problem in JavaScript, it takes far too long to
debug.

I think this is because of a couple of features of the language and the
ecosystem that intersect in painful ways.

### Problem 1. Exceptions instead of errors-as-values.

In order for me to maintain control flow at all times, every line of code that
I write that could throw an exception must be covered by a try-block that I
write. Otherwise, when that innocent line of JavaScript does throw an
exception, I have totally lost control. Either the framework that I'm using
will catch the error, or I've crashed my program.

Additionally, if I want to handle two different errors differently, I either
need to have conditional logic in my `catch` block, or I need to have two
different `try-catch` blocks for different function calls that could throw an
exception.

I'm not perfect, and even though I'm aware that I need to write try-catch
blocks, I can have code that throws exceptions that I do not catch and have to
track down. Normally, this happens because I've written a helper-function that
I assume is called in a try-catch block one level of abstraction higher, but I
forgot about a code-path that doesn't have a try-catch block.

Tracking down exceptions in the JavaScript ecosystem is often trivial.

### Problem 2. Async/Await and Promises.

Now, in defence of Async/Await, I think it is far far far superior to the
callback hell that plagued the JavaScript ecosystem not so long ago.

However, I still don't think it's the right abstraction for concurrent
programming. I understand that in IO-heavy applications, such as the web often is,
it can look like a good abstraction. The single core in this lambda can do other
things in the event loop while we're `await`-ing this database query to resolve.
And all without threads! Isn't that awesome!

And quite frankly, no I don't think it's awesome. Real example here, let's say
you're writing JS on the backend, and you have two functions like this:
```js
async function notifyPagerDutyOfCriticalError(errMsg) {
...
}

async function assertOrNotifyPagerDuty(assertion, errMsg) {
  if (!assertion) {
    await notifyPagerDutyOfCriticalError(errMsg);
  }
}
```

In languages without async/await, I could use that `assertOrNotifyPagerDuty`
function anywhere I like to assert invariants in my program.

Not so in JavaScript, in JavaScript I can only use that async function in
other async functions. If I want to use this nice assert function I made, oops
now that function and every one that calls it is async.

And in addition to that, I've found that async makes things like debugging a
little bit harder. Ever seen a stack trace like this:
```
Error: Something went wrong while processing the request
    at doDatabaseCall (/app/node_modules/database_caller/index.js:42:15)
    at async doDatabaseThing (/app/node_modules/database_thing_2/index.js:88:13)
    at next (/app/node_modules/express/lib/router/route.js:144:13)
    at Route.dispatch (/app/node_modules/express/lib/router/route.js:114:3)
    at Layer.handle [as handle_request] (/app/node_modules/express/lib/router/layer.js:95:5)
    at /app/node_modules/express/lib/router/index.js:284:15
    at Function.process_params (/app/node_modules/express/lib/router/index.js:346:12)
    at next (/app/node_modules/express/lib/router/index.js:280:10)
    at processTicksAndRejections (node:internal/process/task_queues:95:5)
```

Not a single line in that stack trace goes back to a line of code in my app.
Obviously, this is a made up example, but I often have stack traces that are
like this, and such stack traces are almost worthless when I'm trying to figure
out what's actually wrong in the code that I wrote. I know I've awaited some
function call to a dependency that I've passed bad data to, but that's all that
the stack trace tells me. If I'm lucky, I've only used the dependency in the
stack trace once or twice in my app. I'm not often that lucky.

### Problem 3. Errors appear at runtime, not build-time.

The amount of code that you would actually need to write to handle runtime
errors correctly in JavaScript is a little bit insane. Let's say that you had
a function in a js backend that parses an uploaded json file and inserts it into
the database. Your initial implementation while you're trying to get things
working might look like this: 

```js

export async function insertParsedValue(req, res) {
  const json = req.json();
  const db = await getDBConnection();
  const dbResponse = await db.insert({
    foo: json.foo,
    bar: json.bar,
  });
  return res.status(201).json({
      status: "ok",
      userMessage: "Record successfully created",
  });
}
```

And if that code worked, that would be great! There's nothing in there that I'm
going to complain about.
However, programming doesn't work like that. Users upload bad data, databases
go down, Venezuela's currency becomes so worthless that it gets rounded to zero
and your currency-handling code is now blowing up at 2 am because you're dividing
by zero.

So, handling these errors, your code might instead look like this:

```js

export async function insertParsedValue(req, res) {
  try {
    let json = undefined;
    try {
      json = req.json();
    } catch (e) {
      return res.status(400).json({
        status: "error",
        userMessage: "The JSON file you tried to upload is not valid JSON.",
      });
    }

    if (!("foo" in json) || !("bar" in json)) {
      return res.status(400).json({
        status: "error",
        userMessage: "The JSON file you tried to upload is not formatted correctly. Please ensure both a `foo` and a `bar` key are present"
      });
    }

    try {
      const db = await getDBConnection();
    } catch (e) {
      console.error(e);
      await notifyPagerDutyOfCriticalError("The database is down!");
      return res.status(500).json({
        status: "error",
        userMessage: "We have encountered an error and are investigating. We apologize for the inconvenience",
      });
    }
    const dbResponse = await db.insert({
      foo: json.foo,
      bar: json.bar,
    });
    if (dbResponse.ok) {
      return res.status(201).json({
          status: "ok",
          userMessage: "Record successfully created",
      });
    }

    return handleDBErroMessage(dbResponse, req, res);
  } catch (e) {
    console.error(e);
    await notifyPagerDutyOfCriticalError(`Something unexpected happend and should be investigated: ${prettPrintError(e)}`);
    return res.status(500).json({
      status: "error",
      userMessage: "We have encountered an error and are investigating. We apologize for the inconvenience",
    });
  }
}
```


Now those that are keen among you might know that there are clever ways to make this
not look so bad. And you're right.
### Problem 4. General lack of cohesion.

---
title: "What Makes Good Code?"
author: "Russell Waterhouse"
description: "What does good code look like to me?"
tags: ["codestyle"]
date: 2025-07-23T16:40:21-06:00
draft: false
---

# The type of code that I like to write

After writing code professionally for a few years, I thought it was time that
I formalize my current definition of good code. I'm sure that it will change
over time as I grow, but I think that everything here is a good starting point.

The following is my list, in order of importance.


### 1. Has no known bug.

Never ship code that you know has a bug in it, and never add more features to
your code while you have open bug reports from users.


### 2. Contains no unnecessary abstractions.

For two reasons, you shouldn't add an abstraction until you need to.
1. If it turns out you never need that abstraction, it's just technical debt.
2. If you don't need it yet, the odds you pick the right abstraction are zero.

As an example, if your function is only called once, for the love of all that
is good in this world don't take function pointers as parameters, just call the
function. There's no need to generalize what is specific and doesn't need to be
generalized.

Also, don't write getters and setters like this:

```java

public int getFoo() {
  return this.foo;
}

public void setFoo(int foo) {
  this.foo = foo;
}
```

This adds nothing and just adds function calls to memory access. Just make the
member public. Nothing is accomplished by this.


### 3. Uses only explicit control-flow.

I don't want to program in a code base where I can't look at a line of code
and know what's happened before it and what will happen after it.

### 4. Favours vertical code over horizontal code.

If you're indenting too much, it's a strong sign you should refactor.

### 5. Handles All Errors Elegantly.

This can be broken down into 2 categories.

#### Category 1: Errors that should never happen (unexpected errors).

These errors indicate a bug in your program or understanding of the problem.

- An error message with debug information is logged.
- An alert is sent to the on-call person.
- An error message is displayed to user explaining that they didn't do anything
  wrong, and that we are investigating.

Examples of errors that should never happen:
- Passing NULL to a function that cannot handle NULL.
- Unexpected type mismatches (dynamically typed languages only).
- Two different structs having the same unique ID.
- An API call returns data in an unexpected format.
- Program invariant is broken.

#### Category 2: Recoverable errors (expected errors).

These errors indicate something you anticipated could go wrong has gone wrong.

They should be handled as below:
- An error message with debug information is logged.
- Recovery is attempted.
  - If recovery is successful, this is logged and regular control flow resumes.
  - If recovery fails, handle like a category 1 error.

Examples of recoverable errors:
- HTTP request returns an unexpected response.
- File read/write fails because device is busy.
- The user uploaded data in an incorrect format.


### 6. All Return Values Are Checked and All Exceptions Are Caught.

A great way to cover "rule 5: Handle all errors Elegantly" is to simply always
check return values and wrap anything that might throw an exception in a try
block.

Examples of return values to check:
- IO Operations (Network responses, file write successful, etc.).
- Return values from functions that might fail.

What to do will vary based on what value is being checked and what error is
being caught.

Sometimes this return value code and error-handling code can easily be
implemented elegantly, and sometimes it just can't. Either way, I prefer it
being there. The alternative 2 am prod outages and angry customers.

### 7. All Parameters are Checked For Validity.

If your function cannot work with all the parameters passed in as null, check
for that. If it should never happen, handle that error case as outlined in rule
5 category 1.

If your HTTP endpoint expects a POST request with a specific JSON format,
you should first validate that's what you got, and return a 4XX error if you
didn't.

### 8. Meets a sane floor of performance.

There are few actions a user could do that should take longer than 33 ms to
complete (30 fps). We should be suspicious of anything that takes longer than
that, and it should be investigated. If there's no reason for it to take that
long, it should probably be optimized. If it's not worth optimizing enough to
be fast, we should ask why we built that feature in the first place and if it
should be removed. If there's a legitimate reason for it taking longer than 33
ms to complete, there should be a clear indication on the UI explaining how
long the action will take. Loading bars help here.

### 9. Has Business logic extracted into pure functions where available.

If you have some data structure that needs to have some procedure ran on it,
wrap that in a function and unit test it. It's easy to do quickly

### 10. Has a suite of end-to-end (e2e) tests that test core functionality.

There should be some command that I can run to verify that in the current
environment, the current code has at least one code path that correctly
executes the core functionality of the program.

This is purely to prevent regressions. It cannot catch all errors, but it can
prevent the most catastrophic ones from sneaking through.

I place no limits on how fast it should run, but it should run every time a new
version of the program is deployed.

Now I know that there are many reasons not to use end-to-end tests, but allow
me to argue against the most common objections:

1. They're flaky.

When the best tool we had for end-to-end tests on the web was selenium, these
tests were flaky. However, in the age of cypress and playwright, I've found
that more often than not a flaky test actually indicated I had a flaky program.

2. They're slow to run.

I don't disagree. They are slow. I just think that the time that a CI runner
takes to run some end-to-end tests is worth the safety net that they provide.
If they're running in a CI pipeline, the developer is only inconvenienced when
there's a problem. Otherwise, the devs are happily working away at whatever
they were already doing.

3. They make it hard to diagnose the problem when they fail.

The alternative is a vague bug report from a user, which is never easier to
diagnose than a test that I can run on my computer in a debugger with verbose
logging turned on. And that's only after you've deployed a program that cannot
execute its core functionality properly.

4. They're slow to write.

Hire a junior developer or use some AI. When you're just writing enough
end-to-end tests to verify that users can log in and do the most basic version
of everything your widget does, you only need a few tests.

5. They're expensive to maintain.

I've found these tests only expensive to maintain when the UI is changing
often. When that's the case, I've found these tests are more valuable because
re-writing them catches regressions that were in the new UI. Also, as an aside,
every UI change to your core functionality SHOULD be expensive to you, because
it's expensive for your users.

### 11. Has a suite of unit tests to test pure functions.

There will be lots of places in your program where you're just manipulating
data. Data comes in, gets manipulated, and goes back out again. Everywhere like
that, I like to follow this pattern:

```js
export async function main() {
  const input = await getInputWithIO();
  const output = pureFunctionCalculatingOutput(input);
  const result = await writeOutputWIthIO(output);
}
```

If you separate the IO (in getting the input and writing the output somewhere)
from the pure function that actually calculates the output, the
`pureFunctionCalculatingOutput` becomes trivial to unit test.

I've found that this allows me to handle expected IO errors (retry logic,
buffering, etc.) clearly, and unit test easily without mocking or any
such complicated thing.

Additionally, if the logic is wrong, there's an easy place to write a test to
isolate the problem and prevent regressions.


### 9. Has a CI/CD pipeline that runs all tests before deployment, but not on every push.

### 10. Never sets default values.

Here's an example of using default values.

```js
export function foo(param1, param2) {
  if (!param2) {
    param2 = "some defaut value";
  }

  ...
}
```

This pattern feels useful, if you're not expecting to need have param2 in all
cases when calling foo, using a default is handy right in the function. It
reduces duplication. The same thing can also be accomplished like this:

```js
export function foo(param1, param2 = "some default value") {

  ...
}
```


However, I've found too often this hides cases where param2 has been lost
somewhere higher in the call stack, turning an obvious bug into a silent
failure.

I can't encourage breaking Rule 1: No failing silently.


### 1. No failing silently.

Failing is fine, but log, show errors to the user, and alert the on-call staff
when you fail.

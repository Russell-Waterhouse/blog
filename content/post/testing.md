---
title: "Testing Explained In Depth"
author: "Russell Waterhouse"
description: "How Logging, Assertions, Performance, DevOps, TDD, Integration Testing, and End-To-End Testing Help Make Great Software"
tags: ["", ""]
date: 2026-09-08T12:36:57-06:00
draft: false
---


# Testing Explained In Depth

## How Logging, Assertions, Performance, DevOps, TDD, Integration Testing, and End-To-End Testing Help Make Great Software

Recently, I've been doing a lot of testing on several projects.

Given that I recently talked about testing in [my Landmines
post,](https://www.rwater.house/post/landmines/) I think it's a good time
to talk a little bit about my testing strategy and how I'm using a bunch
of really awesome techniques together to make testing easier and my software
more robust.

I've come to find that a lot of the dogma about testing comes from a nugget
of truth that has been blown out proportion.

I'm testing web apps right now, so much of what I'm going to talk about is
going to mention web apps. However, I expect what I say here to be broadly
applicable to many types of software.

## Definitions

Since some of these terms are only loosely defined in industry, I'll give my
definitions here.

- Assertion: something you check at runtime that should always be true.
  - For me, assertions failing in production page the on-call team and kills the current action. In development, they crash.
- TDD: classic red-green-refactor test-driven-development.
- Performance: Ensuring latency is low and throughput is high.
- Unit tests: Any test that does not pass an IO boundary.
- Integration Testing: Any test that passes an IO boundary. Network requests, disk writes, DB queries, etc.
- End-To-End Testing: Any test that interacts with your user interface the same way a user does. It clicks buttons, enters text, etc.

## The Big Breakthrough

I think most developers don't use integration or end-to-end tests nearly
enough, and both their software developer experience and their user's experience
suffers for it. I want to explain how a bunch of small decisions compound
to create something better for the developer and the user.

These tests are great for a bunch of different reasons:

1. Integration tests are great because errors with integration are usually very
   hard to debug.
2. Integration tests are great because they break immediately upon the API
   you're calling to changing underneath of you.
3. E2E tests are great because they provide a foolproof way to check that there
   exists a working code path for your user to take to complete an action.
4. E2E tests are great because they make expensive for you what's expensive to
   your users: changing the UI every week.
5. E2E tests are great because they are phenomenal at finding bugs and
   regressions.
6. E2E tests are great because they actually show you how your product works
   for real users.
7. Integration and E2E tests are great because it means you can write your
   functions without dependency injection and your tests without mocks.

## Why It's Not More Common

If you ask developers why they don't have many integration or end-to-end (E2E)
tests, they'll usually say something about one of the following:

- Integration/E2E tests don't provide the same level of granularity for when things go wrong.
- Integration/E2E tests are slow.
- Integration/E2E tests are flaky.
- You should have more unit tests than Integration/E2E tests


I want to tackle these together.


### MYTH: Integration/E2E tests don't provide the same level of granularity for when things go wrong.

Honestly, that's a true statement. If a unit test called "test_isValidEmail"
fails, your email validation function isn't working.

If an integration test called "test_sendEmailNow" fails, it could have been
the email validation, it could have been networking code, it could have been
email formatting code, it could have been a lot of things.

But that's true in production too. If your user doesn't get a transactional
email, any of those things could have failed.

The answer to "I don't know what went wrong" isn't more granular tests, it's
more granular logging, monitoring, and asserting.

In my code, I check the outcome of every IO action. Regardless of whether it's
what I expect, I log something about it.

I also use a lot of assertions. They allow me to catch real problems in
production that would have either failed silently without the assertion or have
been impossible to debug.

Between my assertions and my logging, when an integration or end-to-end test
fails, I usually know EXACTLY what went wrong and how and why.

If your logging doesn't provide you this level of confidence, take a week and
do it up right. You'll be shocked at how useful it is.


### Myth: Integration/E2E tests are slow.

Yes, and no.

Years ago, when the best thing that we had for running web E2E tests was
the selenium web driver, this was more true. In the days of cypress and
playwright, much less so.

Yes, integration and end-to-end tests are slower than well-written unit tests.

Well-written unit tests usually only manipulate memory, which is faster than
writing to or reading from disk or doing network requests.

But computers are ridiculously fast, and if your unit tests and integration
tests are taking more than a minute or two to run, so long to run that you
don't want to run them, one of two things is probably true:

1. Your code is MUCH slower than it should be in the hands of real users.
2. You are actually working on a hard problem that takes hours of compute.

Remember how I said that E2E tests are great because they show you how your
product works in the hands of real users? This is one of the places this
shines.

If your end-to-end tests are slow, this means that your product is slow.

It's really that simple.

Chances are high that your product is just slow. Take a sprint, do some
performance work. It's worth it. You've been saying for years that "premature
optimization is the root of all evil."  Now that it's no longer premature,
do the work. Also, stop using that phrase as an excuse!

Now let's say that you are actually working on a hard problem that takes
hours to compute, no matter what you do.

That's fine, just split your test suite into three:

1. Unit tests (these can run anywhere in a fraction of a second).
2. Fast integration/e2e tests (these require things like a database, and run in development or staging).
3. Slow integration/e2e tests (these only run in your CI pipeline).

Now your slow tests only run in CI. Your fast tests run on your machine,
and life is good.


### Myth: Integration/E2E tests are flaky.

Flat out no.

Again, years ago, when the best thing that we had for running web E2E tests was
the selenium web driver, this was more true. In the days of cypress and
playwright, much less so.

Remember how I said that E2E tests are great because they show you how your
product works in the hands of real users? This is one of the places this
shines.

(notice I can just copy-paste paragraphs from section to section? It's almost
like these themes are repeating).

If your end-to-end tests are flaky, this means that your product is flaky.

I use playwright. Literally every integration or E2E test failure I've had
in the last year has been because there was a bug in my code.

### Myth: You should have more unit tests than Integration/E2E tests

Maybe? I'm not sure.

Let me walk you through an example to illustrate my point.

The basic pattern here is you have a function that does something. Some of it
is very unit-testable. Some of it is very integration-testable.

Let's say you have a function to send a user a transactional email:

Note: this is pseudocode, so I'm not doing full regular expression matching,
I'm going to simplify things by using functions that don't exist, I'm not
handling errors responsibly, to simplify the point I'm actually making here.

```ts
export async function sendTransactionalEmailNow(sendToAddress: string, subject: string, body: string) {
    if (!isEmailAddressValid(emailAddress)) {
        throw new Error("Invalid email address");
    }

    return await sendEmailUsingEmailProvider(sendToAddress, subject, body);
}

export async function isEmailAddressValid(emailAddress: string): boolean {
    // get the regex from https://gist.github.com/baker-ling/3b4b014ee809aa9732f9873fe060c098
    return re.match(emailRegex);
}

export async function sendEmailUsingEmailProvider(sendToAddress, subject, body) {
    // All the code to send an email with your email provider.
    // Things like retry logic go in here.
}
```

If you wanted to do unit testing, `isEmailAddressValid` is a great place to
start.

If you wanted to do integration testing, `sendEmailUsingEmailProvider` would
be great.

But most of the code that I write uses a little bit of both. Some does IO, like
`sendEmailUsingEmailProvider`,
some just operates on bytes in memory, like `isEmailAddressValid`.

I usually do separate them both like this, that way it's easier to unit test
the unit test parts and integration test the integration test parts.

But it hasn't been conclusively obvious to me that I end up with more
unit-test-friendly code than integration-test-friendly code.

It also hasn't been conclusively obvious to me that there are more test cases
to test in the unit-test-friendly code than the integration-test-friendly
code.

If I don't have more code that should be unit tested, I don't really see why I
would have more unit tests than integration tests.

Maybe that's just inherent with high-level application development, maybe it
has something to do with my coding style.

Either way, I don't take this one as gospel, and I'm at least a little bit
suspicious.

Trying to follow this too much leads to code that looks like this:

```ts
export async function sendEmailUsingEmailProvider(sendEmailFn: ()=>void, sendToAddress: string, subject: string, body: string) {
    // All the code to send an email with your email provider.
    // Things like retry logic go in here.
}


//////////////////////////////////////
// later in tests files
//////////////////////////////////////

export const test_sendEmailUsingEmailProvider() {
    const sendEmailFn = Jest.mock();
    const sendToAddress = "example@example.com";
    const subject = "test subject";
    const body = "test body";

    expect(sendEmailUsingEmailProvider(sendEmailFn, sendToAddress, subject, body))
        .toBeTrue();
    expect(sendEmailFn).toHaveBeenCalledOnceWithArgs(sendToAddress, subject, body);
}
```

And in a coverage report, that looks good. Lots of code covered.

But you haven't actually tested your integration.
You have no idea, after running this test, whether your user will actually
receive your email. You only know that some other function got called once
with these args.

But now because you're using mocks and don't send a real email, this is a
unit test, not an integration test, and you can sleep well at night
knowing you have more unit tests than integration tests.

Of course, while you're sleeping, your emails are getting throttled in a way
your mock doesn't account for, and therefore you don't test, and your users
aren't getting their transactional emails.

This is the type of outcome we're doing testing to avoid.

None of this is to say unit tests are bad. Unit tests that rely on mocks are
usually bad, but not always.

Don't be afraid of unit testing, but don't use unit tests as a replacement
for integration tests. They're not a good replacement.


## So What Does All of This Get You?

When you combine all of this, the software that comes out feels very robust,
simple, maintainable, and easy to debug.

The parts that are pure functions I write with TDD, and have a great test suite
for at the end.

The parts that operate on the outside world, I'll get working in context,
figure out a nice API for, and write integration tests for.

When things go wrong, either in dev or in production, I have an easy way to add
tests to debug. I have logs. Sometimes I'll even catch a bunch of debug
information with an assertion.

Almost everything runs super fast, and the parts that don't run super fast
I run in CI, so they run on every release, but I'm never waiting for things
to complete.

Everything about it feels really nice, and has been well worth the of effort
that it takes to get it all set up.

## My Next Challenge

The only part of this that I haven't figured out yet is how to explicitly test
different error handling cases for integration tests.

Things like retry logic are a little bit hard to test in an integration test.

I don't think it's going to be impossible, it's just something I haven't had
the time to figure out yet. If you know a slick way of doing it that doesn't
rely too heavily on mocks, I'd love to hear about it!


---
title: "My_style"
author: "Russell Waterhouse"
description: "description here"
tags: ["", ""]
date: 2025-07-23T16:40:21-06:00
draft: true
---

# The type of code that I like to write
After writing code professionally for a few years, I thought it was time that
I formalize my current definition of good code. I'm sure that it will change
over time as I grow, but I think that everything here is a good starting point.

The following is my list, in order of importance.

## 1. Has no known bugs.

I don't ship code that I know has flaws.

## 2. Has an intuitive UI.

This rule is a bit fuzzy, but I can break down some of the qualities of an
intuitive UI.

- Every action the user can take has immediate (30fps or faster) feedback.
- The user should be able to tell what actions are available on the page
  they're on just by looking at it.
- The user should be able to tell how to navigate to the page that has the
  action they're looking for.
- The user should be able to undo any action they take, or be warned before taking
  the action that it is irreversible.


## 3. Handles errors correctly per error case.

This can be broken down into 3 categories.

### Category 1: Errors that should never happen.
- An error message with debug information is logged.
- An alert is sent to the on-call person.
- An error message is displayed to user explaining that they didn't do anything
  wrong, and that we are investigating.

Examples of errors that should never happen:
- Passing NULL to a function that cannot handle NULL.
- Unexpected type mismatches (dynamically typed languages only).
- Two different structs having the same unique ID.
- An API call returns data in an unexpected format.
- Program invariant is broken (varies program-to-program).

### Category 2: Recoverable errors.
- An error message with debug information is logged.
- Recovery is attempted.
  - if recovery is successful, this is logged and regular control flow resumes.
  - if recovery fails, handle like a category 1 error

Examples of recoverable errors:
- HTTP request returns an unexpected response.
- File read/write fails because device is busy.


All IO return values are checked, and errors handled correctly.

## 4. Has a responsive UI.

The user should know what's going on at all times. The UI should
never hang. When updates cannot happen at 30 fps or faster, loading animations
should be used. Updates happening at 30 fps or faster are preferable to loading
animations.

## 5. Has Business logic extracted into pure functions where available.

## 5. Has a suite of end-to-end (e2e) tests that test core functionality.

There should be some command that I can run to verify that in the
current environment, the current code has at least one code path that correctly
executes the core functionality of the program.

This is purely to prevent regressions. It cannot catch all errors, but it can
prevent the most catastrophic ones from sneaking through.

I place no limits on how fast it should run, but it should run every time a new
version of the program is deployed.

Now I know that there's many reasons not to use end-to-end tests, but allow me
to argue against the most common issues:
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
re-writing them catches regressions that were in the new UI.
Also, as an aside, every UI change to your core functionality SHOULD be
expensive to you, because it's expensive for your users.

## 6. Has a suite of unit tests to test pure functions


## 7. Has a CI/CD pipeline that runs these tests before deployment, but not on every push.

## 8. Secure
- Dependencies updated.
- No pre-auth actions allowed.

## 9. Has style decisions that I like:

- snake_case over camelCase or PascalCase - I just like it.

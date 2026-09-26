---
title: "Techniques for Good Code"
author: "Russell Waterhouse"
description: "Techniques I've used to make robust software"
tags: ["", ""]
date: 2026-09-14T11:07:05-06:00
draft: false
---

# Tactics, Techniques, and Procedures for Robust Software

I've tried writing a code style document a whole bunch of times.
Hopefully, this one will be the one that I finally get working.

What I'm tackling here:
- What makes low-fault software that's easy to maintain.

What I'm not tackling here:
- UX.
- Product Design.
- In-depth arguments about why I believe these are effective techniques.

This is going to be brief, but very good. 

## 1. Assertions.

Assertions let you know when something you thought was impossible is, in fact,
possible.

Unfortunately, this happens.

When you have assertions, you can program defensively in a way that I find
very pleasant.

And it does find bugs.

I'm working with web technology right now, so right now a failed assertion
returns a 500 internal service error and pages oncall and logs a bunch about
the failed assertion and what happened leading up to it.

Super useful, super awesome, I would never program without it.

## 2. Error-Free/Warning-Free build/compile/linting/static analysis.

I'm going to use warning/error interchangeably here.

The logic of this one is very simple. If you have zero warnings, and one pops
up, you'll read it and fix it. If you have 8293 warnings and a new one pops up,
you won't even notice.

Certainly, not every warning or lint rule will be something critical to whether
or not your code works. Fix it anyways (or explicitly ignore the single error.

Errors should stop your build for this reason.

A great number of simple mistakes get caught and never make it into running
software, let alone your shipped product, if you follow this. It's a very
aggressive policy that yields great results.

## 3. Heavy use of unit tests for pure functions (no IO).

pure functions that have no side effects should be unit tested.
I usually write them with TDD. 

## 4. Heavy use of integration tests for impure functions (network, disk, peripherals).
## 5. Heavy use of logging.

I remember how much my co-workers in my second co-op harped on me about not
having enough logging. It was a constant comment in my pull requests.

In fairness to past me, I wasn't in the on-call rotation, so I wasn't seeing the
problems in production they were seeing.

In my first few hours trying to debug some esoteric bug in production without
adequate logs, I immediately understand what being hounded in code review was
trying to teach me.

If you don't have enough granularity in your logs to confidently know exactly
what function something went wrong at, you aren't logging enough.

## 6. Excellent DevOps (deployment pipeline, infra as code, tests run on every release, dev environment, preview environment).

Being able to deploy quickly and painlessly
means fixing bugs and adding features has less friction.

Good dev environments make it a joy to program, where otherwise it would
be pain.

## 7. Never ignore a bug during development. Fix any bugs you encounter before adding new features.

This ensures you're building on a solid foundation and delivering a solid product.

If you find a bug in development, one of two things are true.

1. It's trivial to fix, and you should fix it quick to get it out to your users.
2. It's not trivial to fix, and the change would be large, in which case you shouldn't build more on what is likely to change.

## 8. Check the return value of all non-void functions.

This ensures either you're doing enough error handling or
you have enough assertions and logging. These three rules go together
beautifully and make some very robust code.

## 9. Use a statically-typed language

I have MANY opinions about programming languages. However, if there's just one
thing you should do, it's choose a language that's statically typed. This makes
it trivial to check return types of all non-void functions, pass the right
parameters to functions, and generally never oopsy types. Get one that's
null-aware if you can, like TypeScript or Kotlin. Even better than that is one
that doesn't have null, like Rust.

Types are a solved program in computer science, we shouldn't be throwing out
good useful tools.


## 10. War against complexity.

I almost didn't include this, because it's the only one on this list that I
struggle to provide a checkable metric for. It's really hard to point to any
feature and say "I've made an excel sheet that shows that this implementation
is exactly 9.81 times more complex than it should be.

Nonetheless, I've included it anyways. It's that important.

If you have a bug that should be a 5-line fix, you shouldn't accept a solution
that changes 100+ lines of code.

And conversely, if you have a feature to add that should take a hundred lines,
and you find you've written a thousand because of some decision made in the
past, you should stop and go back and make the right decision before adding
your feature.


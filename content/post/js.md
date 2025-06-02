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

### Problem 2. Async/Await.

### Problem 3. Errors appear at runtime, not build-time.

### Problem 4. General lack of cohesion.

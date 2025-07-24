---
title: "One Language Challenge"
author: "Russell Waterhouse"
description: "description here"
tags: ["", ""]
date: 2025-07-15T09:48:33-06:00
draft: true
---

# One Language Challenge

I'm announcing that I'm starting a one-language programming challenge. For the next 6 months,
I'm going to program all my personal projects in one language, except
any exploration work I'm doing that will help my day job.

# What I have done until now

Until now, I've generally used the right tool for the job. When doing web stuff,
I've used TypeScript. When scripting, I've used python or bash. When writing
android apps, I've used Kotlin and when writing enterprise applications I've
used Java. I've explored writing backends in Go, and I've written CSV parsers in
Rust. I've written iOS apps in Objective C and document generators in Haskell.

And quite frankly, I'm tired. Exploring languages has been fun, but now when I
open a project that I've worked on, I have no guarantee that I can be confident
in that language immediately. I'll write a function or two in python before I
realize that I'm in a ruby code base, or I'll have to look up how to use get
environment variables in TypeScript. My language exploration is starting to have
a productivity cost, and I won't stand for that.

Originally, I was going to do this in C, because C is so universal and is such
a sharp tool. I figured with a little help from the
[stb libs](https://github.com/nothings/stb), C might be a worthy answer to my
evergreen question "What high-performance language should I have in my
tool box". If nothing else, I think it would have done a good job until I could
say whether Rust or C++ would win.

However, right before I committed to it, I took one last look and found
a language that I think will be even more suitable.

## Zig, the better C?

Imagine a C where you have generics, better error handling, better strings,
better arrays, better enums, yet still have the ability to use raw pointers.

That's Zig. I'm still in the early days of learning it, but I've seen enough
right now to know that if I have to settle on one language to use for the
next six months, I want it to be Zig.


## So why not before now?

Quite frankly, I've completely dismissed Zig up until now because I wanted to
wait until it was at a stable version 1.0.

However, none of my hobby projects are so big that updating between Zig versions
is going to be hard.

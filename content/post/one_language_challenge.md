---
title: "One Language Challenge"
author: "Russell Waterhouse"
description: "Can I use one language for a whole year?"
tags: ["6-month-challenge"]
date: 2025-07-15T09:48:33-06:00
draft: true
---

# One Language Challenge

I'm announcing that I'm starting a one-language programming challenge. For the
next 12 months, I'm going to program all my personal projects in one language,
except any exploration work I'm doing that will help my day job.

# What I have done until now

Until now, I've generally used the right tool for the job. When doing web
stuff, I've used TypeScript. When scripting, I've used python or bash. When
writing android apps, I've used Kotlin and when writing enterprise applications
I've used Java. I've explored writing backends in Go, and I've written CSV
parsers in Rust. I've written iOS apps in Objective C and document generators
in Haskell.

And quite frankly, I'm tired. Exploring languages has been fun, but now when I
open a project that I've worked on, I have no guarantee that I can be confident
in that language immediately. I'll write a function or two in python before I
realize that I'm in a ruby code base, or I'll have to look up how to use get
environment variables in TypeScript. My language exploration is starting to
have a productivity cost, and I won't stand for that.

In the last year, I've written programs in C++, Zig, Rust, and Go (among
others), trying to figure out which of those four are going to go into my box
of tools to reach for. I've been trying to figure out what they're good at and
which of them are going to become dominant.

And while I think I know what they're good for (Go for web backends, Zig for
control, Rust for safety, and C++ for C-interop), I haven't any clue of which
of them is going to be dominant or dead in ten years.

I plan to write a blog post on what my opinions of all of them are and why
despite my best efforts, I still can't predict where the languages are going.

For now, just know that I feel familiar enough with these languages that if I
needed to start a big project with them, I could be productive in all of those
languages in a few days.

If tomorrow I was told to write a new web backend, I could do it in Rust or I
could do it in Go, and I'd be productive by Friday.

If tomorrow I was told to write a project that needs interop with C, I could
have some decent C++ banged out by the end of the week.

I still think Zig is too early to build long-maintained programs in, but when
it hits a stable release I plan to go deep into it.

I know these languages well enough to be a little future-proofed, and well
well enough to be able to form my own opinions when I read news about them.
And until one of them becomes dominant enough to invest heavily into, that's
good enough for me.

Now, I want to pick a language and stick to it. I want to choose a single
language to do my personal projects in.

And C, how I've missed you.

## Why C

I'm choosing to do everything in C for the next 12 months for a few reasons.

### 1. It's Simple

After all the language exploration I've done, I've come to
admire that about C. It means I can work in C on the weekends and not forget
how to write Ruby code during the week.

It also means that I can look at someone else's C code and see what they're
doing with very little other context. I can't do that with C++ or Rust.

### 2. It Fosters Deep Understanding

I've noticed that many of the programmers that I really admire have
programmed in C for extended periods of time. They understand what the computer
is doing at very low levels. They understand nuances about performance that
I can understand in an academic way, but not yet intrinsically know.

### 3. It's Familiar

C is the first language that I learned. C feels to me like a refreshing beer
with an old friend. And despite writing concurrent airport planning simulators
and file systems and RTOS embedde code and bare-metal embedded code in it in
university, I still feel like I never truly mastered the language.

I feel like I hiked all around the foothills of that mountain, but never truly
went for the summit. What better time to do that, with all the learning and
growing I've done since university.

### 4. Escape from Dependency Hell

I work in interpreted web languages during the day, it's nice to sit down with
C in the evenings or on weekends and program without any of the dozens of
layers of abstractions that the modern web stack builds with. C gives me an
opportunity to go back to a place with no more browser API's, no more async
runtime, and no more `node_modules`.

A big part of this challenge is going to be doing everything with the least
dependencies I can. Unless it's a stable ABI at the lowest level possible, I
don't want to depend on it. At the end of this challenge, I really hope to have
only depended on the C standard language, berkeley sockets, and a graphics
library.

### 5. Low-Level Support

In the next 12 months I plan to do both some graphics programming and
some embedded programming. These are areas where C really shines.

I want my own custom screensaver and I want some smart devices in my house
running on my own ESP32 running my own C code.

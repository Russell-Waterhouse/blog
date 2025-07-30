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

## What I have done until now

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
running on my own ESP32. C is going to be great for those. Even if I wasn't
doing this challenge, I would still do those projects in C. And for everyone
saying that I could program an ESP32 in Rust, you're right! And the
documentation for how to do it sucked!


### 6. AI Sucks at C

I don't hate AI, but I also recognize that if I'm leaning on AI heavily I'm not
learning anything.

As far as I can tell, AI trained heavily on all the first year CS undergrads' C
projects. I'm not impressed with the C code that AI writes, and that's good for
me. I don't want to be using AI for my personal projects. My personal projects
are where I learn new concepts and try new things. I'm not doing personal
projects with the goal of having a final product. It's one of the reasons so
many projects on my GitHub are archived, and why so many of my personal
projects never even make it onto my GitHub. I learned the thing I wanted to
learn, and I moved on.

## The Preliminary Roadmap

So what projects do I have planned? Here's a list:

1. A program that generates C code, so I can have generic data structures without using `void*`.
  - As an aside, I very nearly chose zig for this challenge because I wanted generic data structures.
  - Repo is already public [here](https://github.com/russell-waterhouse/c_generators), though far from complete at the time of posting.
2. My own standard library.
  - Obviously, I'm not re-implementing everything from the C standard library, but I want a few typedefs for ints, a few extra functions for working with strings, and maybe my own dynamic array implemntation.
3. My own screensaver.
  - I've had an idea for a screensaver with dots moving around the screen and lines appearing between them. I'm sure I got the idea from some hacking website I saw at some point, but I want to make my own.
4. Advent of code 2025
  - I hope to get at least half the challenges done this year.
5. An ESP32-automated morning routine.
  - Curtains opened, coffee machine started, lights brought up slowly, music playing, all before I even get out of bed.
6. Port [my dev environment setup script](https://github.com/Russell-Waterhouse/dev_environment) to C.
  - It's in python now, why not do it in C?

And quite frankly, if I get all of that done in a year, it will have been a
good year. However, there's some stretch goals I have in mind.

1. A full (but small) web app in C (perhaps with some small JS scripts for client-side interactions).
  - We use Java, Ruby, Go, TypeScript, etc. for backend servers, I want to try one in C.
2. A full (but small) desktop app in C.
  - The king of desktop app development right now seems to be electron, I want to try one in C.

I really hope that I can get to these stretch goals and complete them.  
Even more than that, I really hope that I complete these stretch goals in a
reasonable amount of time. 

If I can do it reasonably efficiently, that would prove a theory that I have:
languages like Java and Ruby and frameworks like React and Electron are
*luxuries*, and beyond the initial bump of productivity the frameworks give
projects in very early stages, they don't offer the productivity advantage that
they claim. Moreover, once I write a web app in C and a desktop app in C, unless
the API that I'm building to changes (and I plan to build to fundamental
API's like GLIBC and OpenGL), my projects would be done. They wouldn't require
a dependabot setup.

And realistically speaking, I doubt anyone malicious looking for binary
exploits in my web server written in C when they could just ransomware a big
company that they got access to through social engineering, or write a bot to
drop a webshell on [every internet exposed
sharepoint](https://www.washingtonpost.com/technology/2025/07/20/microsoft-sharepoint-hack/).





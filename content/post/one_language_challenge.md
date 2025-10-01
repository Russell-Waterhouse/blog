---
title: "One Language Challenge"
author: "Russell Waterhouse"
description: "Can I use one language for a whole year?"
tags: ["one-language-challenge"]
date: 2025-07-15T09:48:33-06:00
draft: false
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

I've been exploring all of this to build a wide base of skills, and to explore
enough to know where I wanted to go deep. Over time, I've been
building a box of tools that I can reach for to complete most projects. 

In the last year, I've written programs in C++, Zig, Rust, and Go (among
others), trying to figure out which of those four are going to go into my box
of tools to reach for in the "I need a compiled language with good performance" situation.
I've been trying to figure out what they're good at and
which of them are going to become dominant.

And while I think I know more about each one than when I started, I haven't any clue of which
of them is going to be dominant or dead in ten years.

I did all of this exploration with the goal in mind that I would learn the winning
language at a super deep level and use it for five to ten years.
After all my exploration, my conclusion is that they're all
good languages with something to offer. What will decide their dominance or demise will
be the community that gets built with these languages and how they interact with each other
and quite frankly, I can't predict that, and I don't think anyone else can either. 

For now, I feel familiar enough with C++ and Rust and Go that if I
needed to start a big project with them, I could be productive in all of those
these languages in a few days.

If tomorrow I was told to write a new web backend, I could do it in Rust or I
could do it in Go, and I'd be productive by Friday.

If tomorrow I was told to write a project that needs interop with C or existing C++, I could
have some decent C++ banged out by the end of the week.

I still think Zig is too early to build long-maintained programs in.

I know these languages well enough to be a little future-proofed, and
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
admire the simplicity C. It means I can work in C on the weekends and not forget
how to write Ruby code during the week. It also means that two programmers
solving the same problem in C will probably use the same tools and language
features. I can't say that about C++ or Rust.


It also means that I can look at someone else's C code and see what they're
doing with very little other context. I can't do that with C++ or Rust.

### 2. It Fosters Deep Understanding

I've noticed that many of the programmers that I really admire have
programmed in C for extended periods of time. They understand what the computer
is doing at very low levels. They understand nuances about performance that
I can understand in an academic way, but not yet intrinsically know.

I want the deep understanding about programming that C programmers all seem to know.

### 3. It's Familiar

C is the first language that I learned. C feels to me like a refreshing beer
with an old friend. And despite writing concurrent airport planning simulators
and file systems and RTOS embedded code and bare-metal embedded code in it in
university, I still feel like I never truly mastered the language.

I feel like I hiked all around the foothills of that mountain, but never truly
went for the summit. What better time to do that, with all the learning and
growing I've done since university?

### 4. Escape from Dependency Hell

I work in interpreted web languages during the day, it's nice to sit down with
C in the evenings or on weekends and program without any of the dozens of
layers of abstractions that the modern web stack builds with. C gives me an
opportunity to go back to a place with no more browser API's, no more async
runtime, and no more `node_modules`.

A big part of this challenge is going to be doing everything with the least
dependencies I can. Unless it's a stable ABI at the lowest level possible, I
don't want to depend on it. At the end of this challenge, I really hope to have
only depended on the C standard library, berkeley sockets, and a graphics
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
learning.

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
they claim.

For reasons that I don't fully understand yet, there's this concept in application
development that C is the language for the Linux Kernel and nothing else. Real applications
are written in interpreted languages. I don't know where that started or why that started.
perhaps there's something about C that fundamentally makes it bad for building applications,
perhaps there's not. Either way, I'm going to find out for myself.

Moreover, once I write a web app in C and a desktop app in C, unless
the API that I'm building to changes (and I plan to build to fundamental
API's like GLIBC and OpenGL), my projects would be done. They wouldn't require
a dependabot setup.

And to those security-aware folks worried about me putting a web server written in C on
the open internet, let's speak plainly for a moment about the real security concerns there.
I doubt anyone malicious is going to be able to afford to take the time to look 
for binary exploits in my side project when they could just ransomware a big
company that they got access to through social engineering, or write a bot to
drop a webshell on [every internet exposed
sharepoint](https://www.washingtonpost.com/technology/2025/07/20/microsoft-sharepoint-hack/).

Cybersecurity is, right now, a balancing act between risk prevention,
risk mitigation, and risk acceptance, and when compiling with all the security
flags to prevent stack smashing and being a small side project with no monetary
incentive to hack, I accept the risks I'm creating here for memory exploits.


## What I'm Hoping For

I'm hoping that this challenge allows me to work in an environment where
performance matters, the abstractions are few, the dependencies are dependable,
and the software produced is rock-solid. I hope after a year, I'm a better
developer than I am now.

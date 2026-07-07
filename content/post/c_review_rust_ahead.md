---
title: "Reviewing a Year in C and Looking Forward"
author: "Russell Waterhouse"
description: "Reviewing my Year in C and looking ahead to Rust"
tags: ["C", "Rust"]
date: 2026-06-30T11:12:05-06:00
---

# Reviewing My Year in C and Looking Ahead to Rust

Nearly a year ago I challenged myself to
only use C for personal projects. I want to
review that year and talk about what's next.

## Why Did I Do It?

Quick recap only here, if you want more
details go back and read my post about it
[here](https://www.rwater.house/post/one_language_challenge/).

It mostly boils down to:
- Dependency fatigue.
- JavaScript fatigue.
- Craving simplicity.
- Craving deep understanding.

## What Were My Goals?

My goals were:

- Write a program that generates C code.
- Write my own standard library.
- Write my own screensaver.
- Use C for advent of code.
- Use C on an ESP32.
- Port my dev environment setup script to C.
- Write a web backend in C.
- Write a desktop app in C.

More important than any project, I wanted
to come away with two things:

1. A feeling like I had done non-trivial things in C.
2. A deeper understanding.

## How Did It Go?

Let's start with the projects

I decided not to write a C code generator.
Better options are to either use the macro system or write it yourself.
I opted to just write it myself.

I did write my own standard library. I'm
not 100% happy with it, and it's far from
what you would expect a "complete" standard library to be,
but it has helped immensely with everything I wanted to do,
and overall has been very useful.

I did write my own screensaver.

I did use C for advent of code, though like every year holiday festivities
took up more time than I thought they would.

I didn't get into embedded programming, just for lack of time.

I didn't port my dev environment setup script to C, just because on
further reflection that seemed like a waste of time.

I didn't write a web backend in C. Not because
it would have been too hard, just because after working on web servers
all day, I didn't really have much motivation to do it after work.

I am writing a desktop app in C, and it's nearly ready for use.
That has been the project that has taught me the most by far.


As for the feelings of non-trivial accomplishments and deep understanding,
I feel like I accomplished that.

I feel like I understand more, and I feel
like my desktop app has taught me a lot.
I had to do non-trivial things for that
project. I had to do double-frame-buffering,
many aspects of memory and resource management,
when to use arenas and when not to (arena-backed dynamic
arrays are a pain, for example). I had to pick data structures
and build them myself, and re-build them when I picked the wrong ones.

I had to debug segfaults and learn gdb commands
and figure out that one part of my code was expecting
zeroed memory and the allocating part wasn't zeroing it.

It was good learning for many reasons.

First, there were good programming techniques that I learned there that I used
in my day job, despite my day job being exclusively garbage-collected scripting
languages.

Second, I have a greater understanding of
the layers that I sit on top of.

Third, it has removed some fear of "not-invented-here" syndrome.
I think web developers in general rely on third-party open source
software too much, to the detriment of their products and their
happiness and productivity. The project in C has removed some of my
apprehensions about slipping into "not-invented-here" syndrome.

Overall, I feel like this has made me a better developer than I am now.

That's not to say that it has all been sunshine and rainbows.

Working with such a slim standard library is a pain, whether you're prototyping
or working on a final product. It's not the biggest cost, and if I had used
any AI it wouldn't be a cost at all.

## So Why Not Stick With It?

In February I wrote a post about picking a systems programming language. You
can find it [here](https://www.rwater.house/post/systems_lang/).

The conclusion of that boils down to the fact that languages like Odin, Zig,
and JAI aren't mature enough for me to bet on, and I would have a hard time
convincing any CISO to let start projects in C or C++ when Rust exists.
Not in the type of work I do, which is almost always connected to the internet.

I'm not entirely happy about that. If I didn't have to work for other people,
I'd probably choose Odin or Zig, as they appeal to my sensibilities and style
more than  Rust.

However, paying my mortgage is awesome, so I'm going to pick up Rust.

## My Plan for the Future

First, before I start Rust, I'm going to finish and release my desktop app.
I look forward to announcing that!

After that, I'll probably take some time to do the
[rustlings exercises](https://github.com/rust-lang/rustlings/), just to bring
me back up to speed. I've written Rust before but not in a long time.

After that, I plan the following projects:
- 
- 
- 



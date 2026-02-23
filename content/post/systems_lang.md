---
title: "Choosing a High-Performance Programming Language"
author: "Russell Waterhouse"
description: "Choosing another tool for my toolbox"
tags: ["C", "C++", "Rust"]
date: 2026-02-23T10:32:54-07:00
draft: false
---

# Choosing a High-Performance Programming Language

## What is it and why do I need it

In my jobs for the last 5 years, I've worked primarily in:
- Python
- TypeScript
- Ruby

With that, there hasn't yet been anything that I have been unable to do.

These languages are very powerful and have a vast ecosystem of tools.
They're very productive and have served me well.

They're all slow, interpreted languages.

And that is not always acceptable. I should have a tool in my toolbox for when
we cannot deal with the overhead of these languages.

## Criteria For My High-Performance Programming Language

Here are the qualifying criteria:
1. Must be compiled with no interpreter/JIT.
2. Must NOT be garbage-collected.
3. Must be realistically usable in my career.

Additionally, these are nice-to-have:
1. Simplicity of language, I should be able to not touch the language for a few
   months without having to re-learn the language completely from scratch.
2. Embedded Programming (I have a few side projects I'm planning).
3. Fun to program.

## Languages I'm Evaluating

- C
- C++
- Rust

## Languages I'm not Evaluating

- Go (disqualified because it's garbage-collected)
- JAI (still in closed BETA)
- Carbon (language still under development, things are changing too much)
- Zig (language still under development, things are changing too much)
- Odin (language still under development, things are changing too much)
- C3 (language still under development, things are changing too much)
- D (it's been around long enough to say it's not going to see widespread adoption)

## Evaluating C

Would C be usable in my career? There are a few situations that C would be
usable.

- Embedded programming.
- High-performance graphics-heavy work (like video games).
- Real-Time systems.

But I don't think I'd ever get security sign-off to say "Hey this new
microservice is expected to experience a heavy load, we should write it in a
high-performance programming language, let's choose C."

Even if C could totally do it, and even if I promised that I would use arena
allocators and Valgrind extensively to make sure that there was never a memory
leak or vulnerability, nobody from the security team would sign off on that
decision.

So while it has a lot that I like, I don't know how feasible it is that I would
actually get to use it in my current career trajectory.

Strong contender, but that's a serious mark against it.

It is simple, and I admire that and find it to be a breath of fresh air.

It is the king of embedded, and I often find it fun to program, though I will
admit that the total lack of standard data structures is annoying. If I ever
finished my library of data structures, that would no longer be an issue.

Overall, it wins in simplicity, embedded, and fun, but today's security culture
and my web specialization make it difficult to envision me using it at work.

I should say that I don't necessarily agree with that, but I also can see
that this is the current reality.

## Evaluating C++

Like C, C++ meets the performance requirements.

However, it's not nearly as simple to program as C, and if I put it down for a
few months the odds are low that I'm going to remember all the different kinds
of constructors, ways to initialize things, when to use `static_cast` and when
not to, how to build programs in a way that doesn't blow out compile times,
what functions in the standard library shouldn't be used (toUpper/toLower
doesn't handle unicode), etc.

C++ has a TON of that kind of complexity, and that makes it very hard to have
that in my back pocket when I won't be working in C++ every day.

Additionally, I think that we are seeing it suffer from the same problem I
described in evaluating C. If I was building a game or a game engine, nobody
would bat an eye at choosing C++. However, if I wanted to build a
high-performance microservice, I'm not convinced I could convince the security
team to approve C++.

I'm not sure what the embedded support for C++ is, but I'm assuming it's
probably second only to C.

Lastly, while I did find it reasonably enjoyable to program while I was
evaluating it, I found "safe modern C++" with `unique_ptr` and all that to feel
like Rust with worse developer experience.

## Evaluating Rust

Rust really shines when thinking about how likely it is that I'll use it in my
career. If I want to write a microservice in Rust, nobody in the security
team is going to bawk at it.

Other developers may have objections, though they would likely have the same
objections to C or C++, so I'm not going to count that against Rust.

Where Rust loses points is the complexity. It's not a simple language. I don't
think it's as complex as C++, simply because it doesn't have the backwards
compatibility requirements spanning back to the 1980's. But it's not simple
the same way C is simple.

Rust does have the ability to do embedded programming, though it is not nearly
as mature as embedded in C.

Lastly, I think Rust is fun to program.

## Conclusion

If this decision were purely around what's fun to program, I would probably
choose Zig or Odin or C or C3. However, this isn't why I'm choosing a new
language to learn. I'm choosing a new language to learn because I want to use
it on side projects AND I want to be able to use it at work, if it requires.

If I worked on video games, I would choose C++.

Right now, I work on lots of things, but video games aren't one, and almost
everything I work on is connected to the internet in some way or another.

So for that reason, I'm choosing Rust.


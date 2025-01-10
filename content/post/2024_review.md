---
title: "Winners and Losers of 2024"
author: "Russell Waterhouse"
description: "A quick review of what I've liked and what I haven't in 2024"
tags: ["newyear", "review", "2024"]
date: 2025-01-02T11:26:48-08:00
draft: false
---

# 2024's Winners and Losers

2024 is coming to a close, so I thought I'd do a quick review of what tech I've
used, what I've liked, and what I didn't.

## Winning Project
my favourite project in 2024 has been my development environment
setup script: [setup script](https://github.com/Russell-Waterhouse/dev_environment)

With this at what I would consider to be an alpha release, I'm already getting
tons of value out of it. I no longer need to add things to one machine that
I've already added to another. I no longer need to worry about borking my
machine. The workflow is exactly what I wanted.

## Winning Programming Languages

This year I've started putting HEAVY focus on using the right tool for the job,
and it has made programming far more enjoyable. Here are the languages I've
used the most this year:

| Use Case | Language |
| -------- | ---- |
| Run Simple Commands Often | Bash Scripting |
| General Scripting | Python Scripting |
| General Systems Programming (i.e. any program that isn't embedded programming or scripting) | TBD\* |


### \* Systems Programming
A few quick thoughts here about systems programming.

Originally what filled this space for me was Java (thanks university). However, there are a few
downsides to Java that make me want to move away from it.
1. It's interpreted, so it's not as fast as I'd like for this niche.
2. I find it uses far more memory than I'd like for this niche.
3. I find the "Java way" to be verbose at best and wasteful at worst.

Here's what I've experimented with so far, and my thoughts on each:

#### C++

I did 12 days of advent of code in modern C++. I like it a lot. Modern C++
appeals to many of my sensibilities as a programmer, and believe it's been
given far too hard a reputation. It's not as hard or verbose or bloated as
people make it out to be. Using C++ felt like working in a well-stocked shop.

Yes, there are many tools on the wall and in the drawers, some of them old,
some of them new. But when doing a project from scratch, just grab the tool you
need out of the toolbox and use it.

Yes, you do have to think about different things than you would in any other
programming language. That's true of all programming languages. I'm not
convinced I spent more time thinking about memory management in C++ than I
thought about JavaScript's event loop or whitespace in Python (that's a joke,
folks). Every language has some feature that you must be careful with. For some
reason everyone seems to think C++'s quirks are harder to deal with than other
languages' quirks. I'm unconvinced.

HOWEVER, that doesn't mean that C++ fits this niche for me. C++ has a range
unparalleled by any other language I've ever used. In no other language do I
have the range to work at literally level of abstraction level I've ever worked
in.

However, I would only want all that range if I planned to use it all, and right
now I'm just not working on any projects that need the lower-level features of
C++. Add to that fact the reality that to get the performance out of C++ that
you would expect from C++, you have to be somewhat experienced with it, and I'm
not there and don't have the bandwidth to get there right now. I'm a full-stack
developer at a small startup, so here's what I've worked with in the last
month:

- React
- Vue
- Express
- Rails
- Postgres
- Redis
- MSSQL
- Docker
- Kubernetes
- Terraform
- Azure
- Python
- Bash
- Perl
- CommonJS
- ES6
- R

Quite frankly, I don't have the time to get so good at C++ that I can use it
to its full potential.

#### Rust

I like the idea of Rust. However, for my use case it falls into the same pit
that C++ fell into above. Rust is complex, and you do need to be good at it to
use it to its full potential. I just don't have the time to get good enough
at Rust to make it worth it right now.

#### Go

I've been experimenting with Go for the last 2 weeks. I built a quick web
server on a plane ride with templ and HTMX, and I liked the experience. It took
me only about a day to read a book on the programming language,
and that appeals a lot to me. If I can learn the syntax in a day, there's a
good chance the overhead of gaining and maintaining skill in the language isn't
as heavy as C++ or Rust.

I'll be building a bigger project in Go to evaluate it further. 

## Winning Development Environment
1. Neovim
2. TMUX
3. Fedora Linux

I completely re-wrote my development environment this year, and I'm very happy
with the results. I've been using a Neovim/TMUX combo for about 10 months now,
and I've never worked faster or felt more in-control of my environment.

Fedora Linux is just everything I think Linux should be: minimal, fast,
configurable, with decent defaults. I've used it for years, and I've never had
any problems.

## Winning Frameworks
1. Remix

Remix was the framework that finally made me understand the appeal of React
and upgraded me from a backend/devops developer to a full-stack developer.

## Winning Devops Tools

1. Docker
2. AWS CDK

I've been using Docker for years, and it's always been a great tool. To
be able to wipe my computer, install Docker, clone a project, and immediately
be able to work in it is something special.

AWS CDK is something I've used for about 18 months now, and I find it to be a
better experience than tools like terraform.

## Winning Resources
1. GitHub Copilot
2. OpenAI's ChatGPT

I currently use Copilot to write comments and unit tests. I don't let it write
code because I've spent too many hours tracking down little bugs it's prone to
make that I feel I could have avoided if I'd just written the code myself.

I use GPT as a sort of "all documentation" search engine, and I use it as a
first step of research when I'm trying to figure out how to do something new.
For example, if I'm newly testing a non-deterministic algorithm, I'll start by
asking ChatGPT for common approaches to testing non-deterministic algorithms.

## Losing Programming Languages
For me, the biggest loser of 2024 was Perl. I'm new to it, and I don't like
the error handling. I've moved several Perl scripts to python just for better
error handling. Maybe it was great for its time, but I don't think it has
a place in my stack.

## Losing Development Environments
1. Windows

For a brief stint this year, I tried to use Windows as my main development
OS. Everything that used to be just a cli command on Linux was now an electron
app, which usually didn't install correctly the first time. The integration
with WSL just left me confused. I haven't had to think about any of the
"windows way" of doing things since I moved to Linux full-time in 2021, and
I just found myself frustrated with the amount of problems that I had to solve
that I didn't have to solve on Linux. I'm back on Fedora now, and I'm happy.

## Conclusion
2024 was a great year for me. I've branched out a lot, and I've built myself
a very solid set of tools to work with. I'm excited to see what 2025 brings.

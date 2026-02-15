---
title: "Trends in Software Development"
author: "Russell Waterhouse"
description: "Trends in Software Development"
tags: ["trends", "reflections", "2026"]
date: 2026-01-07T12:59:24-07:00
draft: false
---

# Some Reflections to Start 2026

I want to start 2026 with some reflections on my journey in software
development, and especially the things that I've tried that have really
improved my craft. I'm going to break this down by year and what I've learned.

I have simplified things slightly to fit a nice format, mostly by putting
a topic into a year that I went deep on it, even if I might have started in
November of the previous year or something like that.

## 2017: My Journey Begins

### I Take My First CSC Course in C in University.

This was my first time peering behind the veil of how computers actually work.
Before this, computers to me were for Microsoft Word and GMail, and
occasionally flash games.

Being an entry-level programming course, I learned if-statements, loops,
functions, file IO, pointers, malloc/free, and the linked-list data structure.
I'm sure that I didn't truly understand the linked-list, malloc/free, or file
IO 100%, I didn't understand 100% of why things were the way they were or what
was happening behind the scenes, but I understood enough to make working
programs. I was interested, but not yet passionate.

Assignments involved programs that calculated Fibonacci sequences in a loop,
converted decimals to Roman numerals, made SVG/HTML files, and probably a few
other things.

## 2018: Robotics, Java, HTML, CSS

### Robotics, January-April
In 2018, I took a course in University that required building and programming a
robot in a group. Having the highest marks in the previous semester's CSC
course, I became our group's programmer.

I remember the day I put together a basic robot with a sonar sensor and a drive
train and wrote a program that looked for the longest distance from the robot
with the ultrasonic sonar sensor, turned the robot that direction, drove 30cm
in that direction, then started the whole process again.

Then I set him loose in the halls of my dorm building and watched him go.
He drove down the hall, scanning his path, course correcting. When the
hall turned right, he turned right. When he reached the end, he turned around.

This was my aha moment. I had made a thing that could do what I wanted.
Not some command line applet that crunched Fibonacci numbers or put SVG
pumpkins on an HTML page, this was a real thing.

I could use this to do useful things.

Our robot did well at the end of the semester, despite several sensor failures.

This experience made me enter the Software Engineering Program.

Looking back, those sensor failures was where I learned that you have to
program defensively. You cannot rely on your sensors giving you accurate
information, and you should check the values they're returning to make sure
they're valid and possible. Handle that error-case however appropriate
(continue disregarding the data, log error, crash the process, blink a red LED,
return a 502, whatever.), but you must handle that error case.

### Java, May-December

In May, I was accepted into the Software Engineering Program.

Knowing I would need Java for my next Software Engineering Course, I set out to
learn the basics over the summer.

I got the hang of it pretty quickly, and that made that course that fall very
easy. It's where we learned the basic data structures like stacks, queues,
trees, and ideas like recursive tree traversal.

After I implemented all of those myself for assignments, we were taught that
Java's standard library had all of these data structures. The idea that we
didn't have to write everything from scratch every time dawned on me.

Somewhere in here I also started building my own Android app for planning
my degree.

This is where I learned the basics of the "good OO practices" like getters and
setters, encapsulation, polymorphism, inheritance, abstraction, that kind of
stuff.

I was still new to programming, so when in my second CSC class, I was taught
"this is just how things are done," I didn't question it much. When you don't
know any alternatives, like I didn't, how could you question an approach?

The only thing I remember questioning at the time was getters and setters.

For the life of me, I actually couldn't figure out why it was okay to make
public accessor methods but not a public instance variable. But there were so
many things that I didn't know, I filed it away under "there must be a reason I
don't understand yet".

### HTML & CSS, September-December

Around that CSC course, I started building a portfolio website. I had picked up
a book on HTML and CSS in a bookstore somewhere, and was using that to figure
out how to do things. Like most programming books, it was somewhat outdated. It
didn't have things like Flexbox in it, so all my CSS was some sort of
left-floating madness. Eventually, I did get something working.

It was just a few static HTML and CSS files that I served statically, first
from an AWS S3 bucket, then from GitHub pages. It was written entirely in
Notepad++ like a prof of mine suggested.

The navigation was copy-pasted into each static HTML file, and I quickly lost
track of what CSS was actually being used, and what wasn't, so the CSS file was
a mess.

But hey, I could link to it in my resume. And later, when I learned better ways
of doing things, like Flexbox CSS Styles or TailWindCSS, I understood the problems
they were solving, because I had experienced those problems.


## 2019: Clean Code, Design Patterns, TDD, and Android App Dev.

In 2019, I started an internship doing Android App Development for a small
startup. Being a small company, I was their only tech person. I had no mentor,
nobody to review my code, and nobody to ask technical questions. Initially,
this scared the pants off of me and was very hard. Nothing in my two CSC
classes prepared me to add features to an android app that some contractor had
made and sold long ago. In the beginning, the most basic things tripped me up.
How this weird syntax worked (it was a ternary), how logs print when I put them
in this function that isn't called anywhere in my code base (it was using an
annotations' processor to set up an event bus that called the function, I'd
never seen an annotation before and had wrongly assumed it was a type of
comment).

I was in over my head, but too inexperienced to know it. So I bought books,
looked for best-practices online, and found it.

- I found Clean Code by Rob Martin and read it cover-to-cover.
- I found Head First Design Patterns and read it twice.
- I found Working Effectively with Legacy Code and read every chapter I could.
- I found Java Concurrency in Practice and read as much of it as I could.

This is where two things happened in sequence: First, my code got better, and my
job got easier.

Then my code got worse, and my job got harder.

The first part of that is easy to understand and explain. I was gaining experience
and had a framework for organizing my code. From no experience and no
organizing framework to some experience with some organization, of course things got
better. 

At the time, I still had so much left to learn that I didn't question the
second part of that. Why, as a project neared its initial release, did adding
features take so much longer than they used to? Probably because I'm still
learning, I thought. There's some design pattern I'm not using, my test
coverage isn't good enough, I chose the wrong design pattern here, etc. etc.

Now, I view it differently, but at the time I had 2 CSC courses and 8 months of
work experience, and I didn't know what I didn't know.

Looking back, there were some things there that were good to learn. 

## 2020: Deeper in OO: Dependency inversion, rigorous TDD

Before COVID really took hold, I started and finished my second app, a word
guessing game. In this app, I went all in on Kotlin, OO, Dependency inversion,
and TDD. Honestly, I don't think the project had enough lines of code to really
get into the issues of this approach. I do remember feeling as though it wasn't
as good as everyone on the internet said it should be. I suppose I wrote it off
as inexperience.

I think the rest of 2020 was just spent on coursework and adapting to the
realities of living through a pandemic.

## 2021: More Java

In 2021, I got an internship at a company using a common java tech stack. With
all my app dev experience, the jump to backend web technology with Java Spring
wasn't too bad.

The people were lovely, and the company was good to me, but I remember leaving
this job with the unshakeable feeling that something was wrong with Java and OO.

At the time, I remember the best that I could articulate my feeling with the
simple sentence "Java does not push you into the pit of success".

This started me on a journey to alternatives, one that I continue today.

Looking for alternatives to the enterprise OO-style of writing code, I stumbled
into some GOTO conference talk about functional programming.

Years later I would find that you can make a mess in Haskell too, but at the time
I was enamoured by the promises of functional programming.

Code that's easier to reason about, fewer bugs from mutable state, composability,
better concurrency support, easier testing, fearless refactoring, and so on.

All of this was promised to me, and I was desperate to try it and experience
the functional programming nirvana that the Haskell and F# talked about online.

## 2022: Haskell

In 2022, I continued learning Haskell while I finished my degree. I didn't
learn much else about programming, as I was going deep into cybersecurity with
dreams of red-teaming. What I learned about cybersecurity was very helpful
later, but there's no need to get into it in this blog post.

## 2023: Haskell and Ruby

In 2023, I got a job writing Haskell and Ruby.
Very quickly, I learned two things.

1. It's VERY possible to make a mess in Haskell. All the promised benefits of
   functional programming go out the window if you let it.
2. I cannot stand interpreted dynamic name resolution without static checking
   in Ruby.

For real, here's such a common problem that I encountered more than I should
have.
```ruby
def foo(bar)
  baz2 = baz(bar)
  begin
    do_foo(baz2)
  rescue => e
    log_error("Failed to do foo with bar #{bat}")
    handle_error_correctly
  end
```

A small typo in your error logging code, bat instead of bar, which you may or may not be able to
trigger easily in test or development, and now that error isn't being handled
correctly.

It was 2023. We should be adults and have a system in place to prevent this
kind of error. Not Rubocop rules that can silently break on your machine, hard
constraints that don't involve me writing convoluted tests to test error
handling.

However, what idiomatic ruby lacks in safety it makes up for in aversion to
abstraction.

Ruby devs didn't feel the need to write a FileWriterFactoryProxy, they opened a file,
wrote the contents to it, and closed it.

And that was a breath of fresh air.

## 2024: JavaScript and TypeScript

In 2024, I sat down and finally got good at JavaScript/TypeScript, instead of
just dabbling.

JavaScript devs also don't write OO factoryProxy, but they will write code like this.


```javascript
async function foo(bar, baz) {
  /* a hundred lines of setup */
  const fooBar = await bar(baz);
  /* a hundred lines of cleanup */
  return fooBar;
}
async function baz2(foo) {
  /* a hundred lines of nonsense */
}

const baz3 = initBaz3();
const baz4 = await foo(baz2, baz3);
console.log(JSON.stringify(baz4));
```

And they'll do this when the function foo is only called once, with the function
parameter baz2. And it's not future-proofing, they'll do it when it would never
make sense to call anything other than baz2 from foo.

For the love of God, it doesn't need to be a function parameter. Just call the
function. Or, inline everything if that makes sense. But don't do this.

I will not mince words here. This is just as bad as layers of obtuse
inheritance. 

## 2025: Rust, Zig, Go, and C.

Most of my learning in 2025 has been going deep on kubernetes and terraform,
neither of which is the focus of this blog post.

The small remaining time I had in 2025 I spent looking at Rust and Zig and Go
and C and C++.

I did this with the plan to pick one of these languages to learn deeply as my
go to compiled language. I have yet to pick one, but I have learned
a lot of patterns from these languages and each one has changed how I program
in one way or another.

## 2026 and Beyond

So how do I look at this journey now?

Speaking just of quality of final product and how easy it is to work on that
project in the future, I've determined the following:

- Every error case should be handled appropriately.
- Avoid every layer of abstraction that you can: it's MUCH easier to add the right abstraction later than to work with the wrong one.
  - This includes inheritance and function parameters, ESPECIALLY when neither one is used yet.
- Be picky about dependencies. It's often better to write your own implementation
 of a simple thing than to import a dependency.
- End-to-end tests are invaluable.
- Unit test everything that's pure functions.
- Good dev and preview environments are invaluable.

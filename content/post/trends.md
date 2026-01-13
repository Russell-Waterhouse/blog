---
title: "Trends in Software Development"
author: "Russell Waterhouse"
description: "Trends in Software Development"
tags: ["", ""]
date: 2026-01-07T12:59:24-07:00
draft: true
---

# Some Reflections to Start 2026

I want to start 2026 with some reflections on my journey in software
development, and especially the things that I've tried that have really
improved my craft. I'm going to break this down by year and what I've learned.

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

Assignments involved programs that calculated fibonacci sequences in a loop,
converted decimals to roman numerals, made SVG/HTML files, and probably a few
other things.

## 2018: Robotics, Java, HTML, CSS

### Robotics, January - April
In 2018, I took a course in University that required building and programming a
robot in a group. Having the highest marks in the previous semester's CSC
course, I became our group's programmer.

I remember one day I put together a basic robot with a sonar sensor and a drive
train and wrote a program that looked for the longest distance from the robot
with the ultrasonic sonar sensor, turned the robot, that direction, drove 30cm
in that direction, then started the whole process again.

Then I set him loose in the halls of my dorm building and watched him go.

This was my programmers moment. I had made a thing that could do what I wanted.
Not some command line applet that crunched fibonnacci numbers or put SVG
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

### Java, May - December

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

### HTML & CSS, September - December

Around that CSC course, I started building a portfolio website. I had picked up
a book on HTML and CSS in a bookstore somewhere, and was using that to figure
out how to do things. Like most programming books, it was somewhat outdated. It
didn't have things like flexbox in it, so all my CSS was some sort of
left-floating madness. Eventually, I did get something working.

It was just a few static HTML and CSS files that I served statically, first
from an AWS S3 bucket, then from GitHub pages. It was written entirely in
Notepad++ like a prof of mine suggested.

The navigation was copy-pasted into each static HTML file, and I quickly lost
track of what CSS was actually being used, and what wasn't, so the CSS file was
a mess.

But hey, I could link to it in my resume. And later, when I learned better ways
of doing things, like Flexbox CSS Styles or TailWind, I understood the problems
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
annotations processor to set up an event bus that called the function, I'd
never seen an annotation before and had wrongly assumed it was a type of
comment).

I was in over my head, but too inexperienced to know it. So I bought books,
looked for best-practices online, and found it.

I found Clean Code by Rob Martin and read it conver-to-cover.  
I found Head First Design Patterns and read it twice.  
I found Working Effectively with Legacy Code and read every chapter I could.  
I found Java Concurrency in Practice and read as much of it as I could.  

This is where two things happened in sequence: First, my code got better and my
job got easier, then my code got worse and my job got harder.

At the time, I still had so much left to learn that I didn't question the
second part of that. Why, as a project neared its initial release, did adding
features take so much longer than they used to? Probably because I'm still
learning, I thought. There's some design pattern I'm not using, my test
coverage isn't good enough, I chose the wrong design pattern here, etc. etc.

Now, I view it differently, but at the time I had 2 CSC courses and 8 months of
work experience, and I didn't know what I didn't know.

Looking back, there were some things there that were good to learn. 

## 2020: Deeper in OO: Dependency inversion, rigorous TDD

## 2021: More Java

In 2021 I got an internship at
a java stack company. With all my app dev
experience, the jump to backend web technology
with Java Spring wasn't too bad. 

The people were lovely and the company was good to me,
but I remember leaving this job with the unshakable feeling
that something was wrong with Java and OO.

At the time, I remember the best that I could articulate ny
feeling with the simple sentence "Java does not push you into the pit of success".

This started me on a journey to alternatives.

I found functional programming and Haskell. 
Years later I would find that you can make a mess in Haskell too.


## 2022: Haskell

## 2023: Haskell and Ruby

## 2024: 

## 2025: 

## 2026 and Beyond

So how do I look at this journey now?

Speaking just of quality of final product and how easy it is to work on that
project in the future, I've determined the following:

- Every error case should be handled appropriately.
- Avoid every layer of abstraction that you can: it's MUCH easier to add the right abstraction later than to work with the wrong one.
  - This includes inheritance and function parameters, ESPECIALLY when neither one is used yet.
- be picky about dependencies.
- end-to-end tests are invaluable
- unit test everything that's pure functions
- good dev and preview environments are invaluable

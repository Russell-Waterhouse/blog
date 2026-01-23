---
title: "One Language Challenge Update 1"
author: "Russell Waterhouse"
description: "Can I use one language for a whole year?"
tags: ["one-language-challenge"]
date: 2026-01-22T09:48:33-06:00
draft: false
---

# [UPDATE] One Language Challenge

I've been writing all my side projects in only C
for 6 months. I want to share my thoughts so far.

## What have I done?
1. A large part of my C core library.
2. My screensaver
3. A few days of Advent of Code.
4. Started my own PDF Library.

## What do I Love?

I love the simplicity. I love that the only complexity
in these projects is the complexity I build.

I also love that I depend only on LibC.
I'm writing software that turns data steuctures into
a pdf and I have no dependencies. I need to know the PDF
spec, which does not change, not some PDF
library that changes every ten minutes.

Both of those feel amazing.

### What do I Hate?

I hate how the nonexistent stamdard library and
no dependencies kills my prototyping speed.

Take my PDF Library as an example. 

I can't just model the PDF types as a struct, because
one of the basic PDF object types is a string key-value type.

Now, instead of modeling everything cleanly and
immediately diving into how to populare a PDF XREF table,
I have to make a string hashmap implementation.

And it's not a hard thing to do. I did it in Java in university.
And once I've done it once in C, I never have to do it again.

But it's tedious, an instead of having my xref table working right now,
I have an arena allocated String Linked List,
and a concat_strs function that iterates over that data structure
and concatenates it all into one string, with only one call
to malloc.

After that, I still have to do the hashmap.

And then rewrite maybe 80% of my core library to use
an arena allocator because as soon as I started into
a real project I immediately saw the benefits of the arena allocator,
and I hadn't built a bunch of my library with that allocation style
in mind.

And after that, THEN I'll be able to do the xref table
in my PDF writer.

And while that's cool, I know that I could have had the
xref implementation done tonight if I just already
had basic string manipulation and data structures
in the standard library. 

And there were a bunch of things I had to figure out that
didn't have anything to do with data structures or algorithms
or file formats. It's taken me a long time to get
my build set up in a way I'm truly happy with. I had to try
STB-style header libraries and unity builds and some make stuff and
none of that really got me any closer to a working project.

And yes, I now know how to do it, and I like what I've landed on,
and I understand pretty well when you might want to use some of the other
approaches.

But was any of that the goal when I started this challenge?
Did any of it make me a better developer?

Not really, no.

## Conclusions

I'm sticking with it for now, but the PDF writer
is an exploration for work, so I might do that in some
other language. From the very beginning, I've said that I
would exclude "any exploration work I’m doing that will help my day job."
from this challenge, and it might be time to ring that bell
for PDF while I finish up my core library of data structures.

I can always port it to C later.
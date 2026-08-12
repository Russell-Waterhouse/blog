---
title: "Landmines"
author: "Russell Waterhouse"
description: "A Guide Through The Minefield For Future Generations"
tags: ["", ""]
date: 2026-08-11T18:40:42-06:00
draft: false
---


# Landmines, Landmines, Everywhere

Hello, reader from the future! Why is my proverbial leg gone, you ask?

You see, I've stepped on many programming's landmines.

Programming, as an industry, is strangely religious. For something that was
supposedly backed by "computer science," there isn't a lot of science to be
found here.

Some of these programming religions are harmless. Some are good. And some
drive you into a minefield, where you will inevitably step on a landmine
and blow off your foot.

I wish someone would have warned me about them, but alas, I didn't have anyone
to do that.

I would like to fill this role for you. Hopefully, my stories of minefields
traversed and my leaky stumps will be enough of a warning for you to avoid
stepping on some of the same landmines I did. With any luck, you'll find
new landmines to step on.

If you want the summary of this article, I can give it to you now. Most
problems in industry aren't that hard. There are no silver bullets. Anyone
trying to sell you a silver bullet has probably downplayed the costs of their
religion. You need a good bullshit detector. If you feel like there's constant
pain with something you're doing, you have probably stepped on a landmine, and
that's an excellent time to stop walking and figure out exactly what turn led
you into the minefield.

You can stop here if you want, or you can keep going to get the details and
more specific advice.

Still reading? Good, you'll do good work in this industry. Reading is good.

## Minefield 1: AI Psychosis

Now, I'll admit, I haven't blown off my leg with this one. But I've seen legs
blown off and I'm missing my eyebrows, so I'm pretty confident this is a
minefield. And looking at how the programming community argues about it, I
think it's a big one.

Here's the most succinct way I've found to describe why this is a minefield:

Programmers do two things: make decisions about what the computer should do,
then write down those decisions in detailed-enough instructions (i.e. code)
that a computer can execute them.

AI is great at writing down instructions that a computer can execute. It will
do it all day long and never complain.

Making the decisions... No. AI isn't that good at that.

Good programmers are making decisions at an incredible pace when they're
programming. They're making decisions about architecture, security,
abstraction, performance, regulatory concerns, maintainability, cybersecurity,
observability, and much more.

I don't think most people know that's what we do. I think there's even many
programmers don't know that's what we do. But that's the truth of it, and to
offload all your programming to an LLM is to offload all your decisions to an
LLM, and they just aren't that good at making these decisions. Maybe one day
they will be, but not today.

In healthy quantities, AI can be a useful tool. Just don't offload decision making
and don't go crazy. If you want to see how I currently do that, read this post
// TODO: link post here.


## Minefield 2: SOLID, DRY, Clean Code, OO, GoF Design Patterns

This one isn't a single thing, like AI psychosis, but it's more of a style of
code that is pushed as a somewhat cohesive unit.

This one is tricky because these principles are taught at many respectable
institutions, and they were considered industry standard at one point to large
subsections of the industry (and I think many practitioners would argue these
still are industry standard).

And as techniques, on their own, some aren't bad. But as a cohesive unit, I've
only ever seen this lead me to a minefield.

Which is unfortunate, because there are not bad odds that if you end up working
in a code base like this, you'll be forced to follow this style of programming
by your team.

In this style of code, everything you work with is an interface. Data is
very tightly coupled to behaviour.

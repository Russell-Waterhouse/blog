---
title: "AI In August of 2026"
author: "Russell Waterhouse"
description: "How I've changed how I use AI (1 new rule plus examples)"
tags: ["AI"]
date: 2026-08-11T17:11:30-06:00
draft: false
---

# How I've Changed How I Use AI In August of 2026

In June of 2026 I posted how I was using AI.
The list was this:
1. If the code is going to be thrown away, toss an AI agent at it, don’t bother reviewing output.
2. If the code is going to be maintained and I don’t know exactly how I would implement it, don’t use any AI code (though a little brainstorming with AI is OK as a jumping off point).
3. If the code is going to be maintained and I know exactly how I would implement it, throw an AI agent at it once. If an agent can’t get it in one shot, don’t try again. Review the output closely and edit it manually.
4. Use agents, not tab-complete.

The reasons were thus:
- Where I want to move fast and have the confidence and knowledge to move fast, I can move faster with AI.
- Where I don’t have the knowledge to move fast, I’m forced to slow down and learn.
- I never get trapped into a loop of “pull the slot machine and hope.”
- I still know how the code works and can still write code very quickly. My skills are not degrading.

## What's My New Rule?

The rules from June were good. I think many code bases and professional
developers could do well with these rules. However, with two more months of
programming in this new world with agentic AI, I have one additional rule.

5. An AI Agent isn't allowed to write more than three hundred lines of code
   that needs to be maintained in one shot. Two hundred is more ideal.

This new rule is a soft rule. I'm obviously not counting the lines of code that are
output and tossing it out if it hits 301. Lines of code isn't a great way to
measure most things. It's a north star that I use.

"But why on Earth would you do that?! That's limiting what these machines can do!"
I hear you screaming into your computer.

And you're right. I am limiting what these machines can do. The same way that,
before AI, code review and QA and testing and code standards documents and
linters and type checkers limited what developers could do.

We traded speed of writing code for increased correctness. We made that trade
because correctness was important. Not just immediate correctness, but
correctness as the system evolved.

I found that without this rule, even though I was reviewing every line of code
and still knew the code base, code that shouldn't be there still snuck in.
Usually, not in the happy path. If you tried it, and you didn't hit an error,
the code would appear to work. But errors wouldn't be handled correctly.
Network requests wouldn't have retry logic. Asserts that should page on-call
would fail silently, or not even be checked. Logging would be missing.
Performance would take a nosedive. Edge cases would be handled incorrectly.
In a few cases, even the requirements were misinterpreted.

While I caught much of it in review, there were many points where I was going
through the code days to months later and would find some function somewhere
that just wasn't up to my standards. AI had written it, I had reviewed it, but
because I had reviewed it along with two thousand other lines of code, things
got missed.

And yes, I use AI for code review. I like safety nets, of course I use AI as a
safety net too. The solution to this problem isn't more AI, it's just to slow
down a tiny little bit.

## Some Examples
Within these rules, there is still A LOT that I can use AI for!

- Need to make a change to my hot-reloading development environment? AI.
- Need to look at five different ways to lay out a page? AI. (and then pull out the bits you like yourself and throw the rest away)
- Need to look at two different approaches to solve a problem? AI. (and then pull out the bits you like yourself and throw the rest away)
- Need to review your changes before submitting them for review to the rest of your team? AI. (and decide yourself what's a real change you should make and what isn't)
- Need to sift through some error logs and find a bug and make the change? AI.
- Need a script to do some menial task? AI.
- Need some helper function for the service you're writing? AI.

And all of that is awesome.

However, in cases like the following, I slow down.
- Working with an API you're unfamiliar with? Read the docs, write most of it by hand. Helper functions < 300 lines of code can be AI.
- Working on a large or complicated feature? Write most of it by hand. Helper functions < 300 lines of code can be AI.

The fundamental nature of code hasn't changed with AI. In code, the details matter.
Every line matters, and the lines that you don't include matter too.

Let me illustrate this with an example. Let's say you have two hundred lines
of code that solve a problem.

In that two hundred lines of code, there's more than just two hundred decisions
made, because the decision to not do XYZ thing in that two hundred lines of
code was also made hundreds of times.

In that two hundred lines of code, there might be two hundred and one
non-trivial decisions, there might be ten thousand. I suppose you could count
them all, but I think it would be a waste of time.

My gut feeling is that for every three lines of code I write, there's one
decision I made that didn't make it into code.

And in order for you to deliver working robust software, pretty much all of
those decisions need to be right.

There might be multiple right options, so the number of possible solutions is
not just one. There are multiple permutations of more or less than two hundred
lines of code that would solve that problem. What decisions are made are so
tightly tied to a problem's requirements that it's very hard to generalize.

And that's what developers did before AI. They take requirements and problem
definitions, and make the hundreds of decisions about what a computer should do
to fill that requirement, and write down the decisions in enough detail for the
computer to follow them. And these AI systems are magically good at writing
down the decisions, and in short bursts they will sometimes do a passable job
at making those decisions.

But "In short bursts they will sometimes do a passable job" isn't good enough
for programming. There's too many details. Problems proliferate and failures
cascade.

You can't just put "log everything that isn't PII so that we have enough info
to troubleshoot problems in production easily." into a .md file and expect to
have logging that's good enough. After working with these agents for years,
I certainly don't trust them enough to actually follow through with an
instruction like that. They just can't make decisions about

- What is PII in this context?
- What would be useful when troubleshooting?

And logging, while important, is a somewhat trivial example. If AI can't make
good decisions about that, and for me it certainly hasn't, why would you trust
it to make decisions about how to use an API for which you are unfamiliar with
and therefore can't determine right from wrong.

And to those companies running ads where "anyone can code now," you're not just
asking AI to make decisions about logging and how to use an API, you're asking
AI to make decisions about:

- What APIs to use
- Architecture
- Cybersecurity
- Testing
- Observability
- Maintainability
- Performance
- Abstractions
- Regulatory concerns
- ...and so much more

And if the decisions about all of that and much more don't matter, if the
decisions about all of that in this hypothetical software that you're building
doesn't matter, then fair enough, fling the AI at it and ship at the speed
of fibre optic cable.

But I do have to wonder, what is your software doing that is worth doing but
not worth doing correctly? That sounds like a hostile question, but I don't mean
it to be; I simply can't find a way of wording the question that doesn't sound
like that.

I can't think of a software project that I could blindly throw an AI at, read
none of the code, and ship it, and have it be worth my time and money.

And I know that if you squint, that comes off gatekeep-ey. I don't mean it that
way either. If anyone wants to do things with computers, be that for a career
or a project they want to do on the side or whatever, I encourage you to go for
it! There's so many resources free online, and so many helpful people, and so
many good books. If you reach out to me, I would even be happy to be a mentor
to you! I've spent many afternoons in coffee shops and on discord calls with
junior developers sharing all that I know with them.


---
title: "Pivot Fast"
author: "Russell Waterhouse"
description: "A brief blog post about decision making"
tags: ["decision making", "software engineering"]
date: 2023-09-26T12:04:12-07:00
draft: false
---

![images/pivot.png](/post/images/pivot.png)

# When, How, and Why to Pivot Fast


In this article I'm going to be reflection on something that I've 
experienced a few times over the last few weeks and I want to 
formalize my thoughts on.


## What is Pivoting Fast?

I don't claim to be coining a term, as a quick google search will show tons of
other advice on the topic, however I do claim to have made this discovery
independently. Pivoting fast is the idea that as soon as you get an indicator
that you're taking the wrong approach to a problem, pivot to a different
approach.

That's a little vague, so let me try to clarify with an example. Say you're
working on a new feature for your software, and you're unsure if you should
take approach A or approach B. They both seem about equally well suited to your
use case on paper, and both approaches are about equally popular.

Eventually, you make a decision and try it. An hour in, you find yourself
frustrated with the workflow and ergonomics of the solution, so you go back and
try approach B.  That's fast pivoting.

The quicker that you make the decision, the faster the pivot. If you can make
that decision after a half hour, even better.


## When to Pivot Fast.

Fast pivoting should be reserved for when you have other options. 
And you should know what options you have, because in software you almost 
always have more than one option. Hell, if you work with JavaScript, you 
normally have more than 10 other options. 

If you're deciding between solution A and solution B like in the example above,
that's an ideal time to commit to pivoting fast. 

While that sounds like a very specific statement, it applies in far more 
places than you might expect. If your boss puts you on a mission-critical 
task that you find you're not qualified for, you should go back to your boss
and say, "Hey, I appreciate the vote of confidence here but I'm just not 
qualified for this.  If there was more time to complete it so that I could 
dive deep into learning the problem-space, or if it wasn't mission-critical, 
I would keep on trucking, but since it is, I think it would be wise to give it
to [Co-worker X, who is more qualified than you]."

Then, your boss has all the information to make an informed decision. 
He or she may decide that you are the best resource for the job, despite the 
qualifications, or he or she may decide that you are right. 

Both are better than spinning your wheels on a problem for days before speaking
up.

Or, say that you're deciding between frameworks. Or deciding between 
refactoring or rewriting, or just working with, some gross legacy code. 

If you're making product decisions and trying to grow your market share, 
you should be pivoting fast constantly,
because the odds that you understand all of your potential customers so well
that you can intuit what they will purchase is so small. You should pivot 
extremely quickly based on feedback from the markets.

All of these are great places to commit to pivoting fast. 


## Why to Pivot Fast

Pivoting fast does a few very important things for you.

First, it reduces time spent on the wrong path. If you were inevitably going 
to pivot your approach, the faster that you can do it, the more time you save,
and the faster you'll land on the right approach.

Second, and I think more importantly, it prevents you from falling into the
sunk cost fallacy and never pivoting at all. 

It's easy to do, at the end of a project you have something that works, but it's
the wrong approach in some way. Are you going to re-write it, or are you going 
to ship it? Of course you're going to ship it! It works, after all, and you're
not going to get to the rest of your backlog if you take forever on this one
ticket. There are features to build and security vulnerabilities to patch 
and paypal just dropped API support for one of your critical payment paths, 
so of course you ship instead. 

This creates technical debt, and there are 2 ways around that. 
1. Pay it down over time, at the cost of building features and fixing bugs faster.
2. Default on the debt and re-write the whole thing, usually creating 
about as much tech debt as you had previously in the process.

Neither one is good, and both are painful in the long term. If the creation 
of technical debt has a reasonable chance of creating more developer hours 
than it will take to fix, then it should probably be done. Usually this means
that your technical debt will result in so much more company revenue that they'll
be able to hire more developers. It can sometimes mean that your technical debt
is replacing something that was even worse. That's refinancing debt, and 
makes sense. As far as I can see, all other technical debt is bad debt. The
monetary example would be going into debt to buy a sewing machine to start 
your own clothing business vs. going into debt to buy a second sports car.
One of these is good debt, and the other is bad debt, and should be avoided.

## When Not to Pivot Fast

Now, pivoting fast is a good thing in many many situations. 
However, there is one that it would be a disasterous mistake: when 
people depend on you not pivoting. If you make banking software, people
are counting on you not changing your mortgage calculating software radically.

With this kind of softwore, where someone else's workflow depends on you not
changing, pivots should be made carefully and with great consideration. 

You may in fact commit to never changing that version of your product, 
and instead doing a new realease with any changes. 

While costly, it allows you to not break backwards compatability while still
growing and adapting and pivoting.

## Conclusion

Unless you're working on very stable software, try to pivot faster, just this
week. You may be surprised at how much you like it and how good for your workflow
it is. It will mean abandoning approaches faster, and it may feel like you're 
wasting time trying more things, but you're far too clever to be caught in a 
sunk cost fallacy like those feelings, right?


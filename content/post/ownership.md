---
title: "Business, Ownership, Complexity, Bugs, and AI"
author: "Russell Waterhouse"
description: "Why I believe AI can't replace software developers"
tags: ["complexity", "AI"]
date: 2026-02-08T00:00:00-06:00
draft: false
---


# Business, Ownership, Complexity, Bugs, and AI

What a title eh? Where could this be going?
Let's jump in and find out. 

## Business 101

"But Russ," I hear you complain."I'm a software
developer, not a business major."

Hush, this will be quick and painless and helpful.

If a business wants to make more money, it can do
one of three things.


1. take money from more customers.
2. take more money from each customer.
3. reduce cost to give your customer their product or service.

That's it. Those are the only three choices. 


So, assuming you're working for a company
that sells software, either as a subscription or a one-time-payment,
you're an asset to the business
in a couple of ways.

1. You can build new features that make the software useful to more people, allowing marketing and sales to sell to more customers.
2. You can build new features that make the software more useful to your current customers, allowing you to charge more money for a more useful product.
3. You can write software that is more efficient, reducing overhead compute costs (applicable only when you run your software).

And these are all really good to know. However, equally good to know are all
of the ways you might be a liability to the company.

1. You can write software that is "bad" enough that people don't want to pay money for it.
2. You can write software that is "bad" enough to land the company in legal trouble.

Let's ignore #2 right now, that's a topic for a different blog post.

Let's talk about the different ways you could make software "bad"
enough that a user doesn't want to pay.

1. The software doesn't provide the features the user needs.
2. The software is buggy and/or unreliable.
3. The software is more painful to use than a viable alternative.

Now let's ignore number 1, because that's a whole discussion about product design/product market fit.
Again, another blog post for another day. We'll assume you're productive
and shipping the right features for now.

So, we're an asset if we build features that attract new customers
or are valuable enough that current customers would pay more.
We're a liability if those features are buggy, unreliable, or unpleasant to use.

That's it. That's how we as software developers fit into the business.

With all of that in mind, I want to talk about ownership and incentives.

## Ownership

Quick definition before I get started here, I define ownership as
a combination of authority and responsibility. 
Authority to make decisions in your domain, and responsibility for the consequences
of those decisions.

I think the best way to become a better software developer faster
is to own something that customers use. That might be a microservice
at a major company or the MVP at a startup, but you should own it.

You should be the one that gets customer complaints about bugs if you have
shipped a buggy product. 
And you should be the one that has to fix these bugs.
And you should be the one that has to tell customers that
either you
1. can't build that new feature because you're fixing bugs or
2. can't fix that bug because you're building features.

You will quickly learn what makes reliable software that is easy to troubleshoot under pressure,
and what makes an obscure buggy mess that is hard to troubleshoot.

You'll find out what is a code style that allows you to add new features easily,
and what is a code style that forces you to re-write your entire project every third feature.

## Complexity, Bugs, and AI

I've been a developer for a while now.
Here's an assertion that I will make that I hope
most people will agree with:

Some code techniques are more error-prone than others.

Some code is good code. I don't think that should be
super divisive. Exactly what techniques are more or less
error prone, that's up for debate, but we can all agree that
some ways of writing code are better.

Here's one that I believe to be true:

Code where a change in one file can cause a bug
14 files away much later in a process is more error-prone.
Let's call this kind of code "Complex Code."

Usually, if I'm writing a simple HTTP REST endpoint, 
the code that I'm writing will often span a single function.
For a complicated endpoint, it might span 2-4 functions. 

However, if I'm writing code that kicks off a complicated
job with 25 steps, where each step is a different file/function,
it's VERY easy to make a change in step 3 that causes a bug in step 13, even
if the change in step 3 was to fix a bug appearing in step 8.
It's also very easy to make a change in step 3 that causes a bug in step 13
under specific conditions, which happen to not be conditions you test for.

Now make that job span a web UI frontend and 3 microservices, and you're rapidly losing hope that you'll
be able to fully understand any change you make.

This leads to a "whack-a-mole" problem, where changes in one part of the code
cause problems elsewhere in unexpected ways. I first heard the problem
described clearly by the internet of bugs youtube channel (though the example
about the job is entirely my own, inspired by real experience).

I think, so far, I've laid out a solid argument that most people could agree with.
However, here is where I'm about to make two claims that some
will disagree with.

1. At a certain point, all non-trivial software will have some processes in it that
will look like my complex example.
2. AI makes this situation worse, not better.

In my experience, every non-trivial production app I have worked on
has had at least one workflow similar to the complex job I described above. Some because that
workflow wrapped real complexity, and some because of incidental complexity.
Either way, it seems to be a feature of software that emerges
after a few thousand lines of code are in the project.

And AI makes this worse because its context window is so small that it cannot
see that a change in file X will cause a bug in file Y 9 steps later in some process.

The only one that can see that is a developer who understands that whole
process, who can see the whole product and how the systems depend on
each other.

I've tried to throw AI at these problems, and it has done nothing but write
patches that cause bugs later instead of fixing the root cause of a problem.

This means that, in order to continue to write features that attract more customers
and to minimize bugs that churn out your users, you have to understand the system you're building.

This means that you cannot have AI writing code you do not
understand. You must choose an archtecture, and if you choose to use AI to
implement any part of it, you must be reviewing it closely and enforcing your architecture.

If you hope to have a working bug-free product that provides a good
experience to your users, you cannot just tell AI to make you something and merge the code
without review. You must still own the code.

All of this is to say, until AI can solve this kind of problem
profitably, I think software developers should still
have jobs.

Because this is what we do.

And honestly, this example is overkill. In February of 2026,
I still can't get AI to *Reliably* generate simple helper functions that are
10 lines long. Sure, for something that small it might get it right 90% of the time,
but a 10% failure rate is not reliable. 

I think we have jobs for a while. 

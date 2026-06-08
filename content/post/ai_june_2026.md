---
title: "My Thoughts on AI in February of 2026"
author: "Russell Waterhouse"
description: "What's Real and What's Not"
tags: ["AI"]
date: 2026-06-03T12:38:36-07:00
draft: false
---

# My Thoughts on AI in June of 2026

I want to clarify my take on AI for
myself and others, so here we are.

If you don't want to read another article about AI (and who could blame you?),
here's the TL;DR: I think AI makes the average dev maybe 5-20% more efficient
when used intelligently. It's far from replacing developers anywhere that you
want a shred of reliability. It's also far from useless and has saved me time.
I have a set of rules for when I use AI and when I don't.
I have concerns about the economics of the AI companies.

## First, Some Premises

I want to start off with some premises that will be super important to
understanding my thinking later.

First, I'm going to be talking about NET benefit here, across ALL the
activities that I do as a full-stack developer. This includes frontend,
backend, dev-ops, infra-as-code, algorithm development, working in greenfield
projects, working in legacy code, etc. I work in a startup, it's no secret that
I'm doing many things. This also makes me more qualified to talk about AI's
impact as a whole to the entire field, instead of just one aspect of it. We're
sacrificing a little depth for a lot of breadth with my analysis, and if you're
instead looking at how AI will impact one niche corner of the tech industry,
you're reading the wrong blog post.

And when I say net benefit, I mean adding the benefits that AI can give me and
subtracting the problems that AI causes.

I've been a software developer non-stop since 2017. That's 9 years now. In
those 9 years, I've learned the kinds of bugs that I write. I know where I'm
weak. Therefore, when I track down a bug that I introduced with AI, I can tell
whether I would have written the same kind of bug. Conversely, after having
used AI in my development workflow since about ChatGPT-4, when I track down a
bug that I introduced without AI I can generally tell whether AI would have
written the same kind of bug.

Lastly, I expect the code to work, and to work in a way that does not introduce
bugs elsewhere in the program.

If AI is writing react and writes it such that a `useEffect` will be infinitely
triggered as soon as the component throws an `Error`, that must be fixed.

## Let's Start With The Lies

The tech industry is constantly subjected to two lies from opposite ends of the
spectrum:

1. AI is good enough to replace software developers right now (or it will be soon).
2. There is no spot in software development for AI, literally every use-case for AI in software development is a net-negative.

And I think both of those are false, perpetuated by people that either have a
vested interest in their side, or people that have heard an opinion on the
internet and haven't bothered to investigate it for themselves.

Neither one matches my experience. I can't
prompt AI more than a few times before it will
shoot itself in the foot. Often, in a way only
a skilled software developer would notice. It will use a `useEffect`
in react in a way that creates an infinite render loop.
It will change authentication middleware in an insecure way.
It will re-implement something you already have a service for, and the re-implementation
will be wrong. 

But if you're aware you'll have to re-write at least
20% of any given output, why not take the cheap 80%?

## How I use AI

My experience with the weird medium ground that
software development falls into has 
led me to my rules of software
development with AI:

1. If the code is going to be thrown away, toss an AI agent at it, don't bother reviewing output.
2. If the code is going to be maintained and I don't know exactly how I would implement it, don't use any AI code (though a little brainstorming with AI is OK as a jumping off point).
3. If the code is going to be maintained and I know exactly how I would implement it, throw an AI agent at it once. If an agent can't get it in one shot, don't try again. Review the output closely and edit it manually. 
4. Use agents, not tab-complete. 

This does a few things:

1. Where I want to move fast and have the confidence and knowledge to move fast, I can move faster with AI.
2. Where I don't have the knowledge to move fast, I'm forced to slow down and learn.
3. I never get trapped into a loop of "pull the slot machine and hope."
4. I still know how the code works and can still write code very quickly. My skills aren't degrading.

And where things are right now, I feel I could sustain
this for years.


## The Economics

When Deepseek first cane out, I did the math to figure out
what you would need to charge as a subscription to make running that model worth it.

It was a lot. I've lost the math, but it was way more
than any AI company was charging for a subscription
at the time.

Since then, we have seen the AI companies move to token-based
billing as they look to change from grabbing market share to
profitability.

I'm still not convinced token prices of today are sustainable,
but I bet they are closer to sustainable than the subscriptions
they were running.

So here is my warning. Right now, I use cursor with a $20/month
plan. Most of the time, I use the auto feature to send my request to
a model of appropriate capability.

I usually use most of my plan's token credits per month.

I wouldn't change a thing if the cost of my plan changed by 2x, or 4x,
and probably wouldn't even change anything at 8x.

But if I'm right, and the cost we are being charged per token is
less than the cost they need to charge to make a profit, we could see
the cost of tokens increase. By how much, who knows? OpenAI and Anthropic
insiders, but they aren't exactly posting that number online for the rest of
us.

So as a word of caution, if you're using AI right now,
and wouldn't still be using it the same way if it was 8x more expensive,
you may wish to come up with a plan to manage that risk.

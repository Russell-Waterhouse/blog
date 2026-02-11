---
title: "My Thoughts on AI in February of 2026"
author: "Russell Waterhouse"
description: "What's Real and What's Not"
tags: ["AI"]
date: 2026-02-03T12:38:36-07:00
draft: false
---

# My Thoughts on AI in February of 2026

On the internet, people will not like this post. However, everyone I've talked
to in-person has generally agreed with my take on AI. I want to clarify it for
myself and others, so here we are.

If you don't want to read another article about AI (and who could blame you?),
here's the TL;DR: I think AI makes the average dev maybe 20% more efficient
when used intelligently. It's far from replacing developers anywhere that you
want a shred of reliability. It's also far from useless and has saved me time.
Also, I have concerns about the economics of the AI companies.

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

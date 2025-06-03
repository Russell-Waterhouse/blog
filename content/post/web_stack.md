---
title: "Choosing a Web Stack for 2035"
author: "Russell Waterhouse"
description: "I want a web framework that will last me 10 years."
tags: ["", ""]
date: 2025-06-02T14:59:29-06:00
draft: false
---

# A Frontend Web Framework for 2035

The year is 2025, and web code written in 2015 is either:
- a) unmaintained
- b) outdated
- c) required at least one major re-write since 2015
- d) some combination of the above

So what do you do if you're a small team or an individual dev that's moving
fast and doesn't want to bear the cost of re-writing and re-architecting your
project every few years? What if you want to start a project today that you can
maintain easily until 2035? That's the question I plan to ask (and hopefully
answer) here in this blog post.

## A brief overview of web dev trends up to 2025

If you've been living in the normal world and touching grass in the last few years,
good for you. Guess you've decided to give that up and read blog posts about
web development on the internet. I'll catch you up on what you've missed.

These are the highlights as I see them. The below are NOT data-driven summaries of events,
but my opinion of what has happened and what trends are happening now.
1. React dominated frontend web development. What isn't a React SPA is a Vue/Angular/Solid/Svelte SPA. MPA's are rare.
2. Create-react-app died and has been replaced by vite.
3. TypeScript dominates almost every new frontend project, no matter what JS framework you're using.
4. "Meta-frameworks" became super popular. NextJS and Remix/React Router v7 are popular on React, Nuxt is popular in the Vue Ecosystem, SvelteKit for Svelte, etc.
5. TailWindCSS got to be the most-loved CSS solution.
6. What I'll call "Simple web frameworks" (HTMX and AlpineJS) got some hype online, but I'm unconvinced they're seeing wide-spread adoption outside a few tech influencers.
7. AI should be in here somewhere, but everyone is still arguing about where. Some say that it's already replaced web developers, others say that it hasn't changed anything. I think both extremes can be demonstrated to be wrong.

## Criteria for a 2035 Web Stack

1. Frameworks must be popular enough today, and in 10 years, that hiring people with those skills is not an issue. No Yesod Haskell framework.
2. Frameworks must have enough of an ecosystem today, and in 10 years, that we can add dependencies without worry of the dependencies being abandoned.
3. Frameworks must not change so much that code written today will need to be re-written before 2035. Re-writes after 2035 are expected, 10 years in tech is a good run.
4. Frameworks must form one cohesive tech stack, which together should be able to make something as complex as a social media clone web app.
5. Frameworks must not have any extenuating circumstances that would prevent me from picking them. For example, I wouldn't choose WordPress right now, as wordpress.org has started legal action against one of their users.

## Disclaimers Before We Start Evaluation

1. I'm considering today's AI capabilities when I'm considering AI influence on
   this decision. Here's a list of prompts that I do not believe any AI model
   would be able to satisfactorily complete given a code base with more than a
   dozen files or so:

- "Upgrade this from React 18 to React 19"
- "Refactor this to replace React with Svelte"
- "Replace all of my React class components with new Functional components"
- "Port all of my JS to TS"

My source on that is the following:
- I've tried to use AI to port some Remix v2 code to React Router v7. It failed.
- I've tried to use AI to port 3 Rust CSV parsing files to python. It failed.

THEREFORE: I WILL NOT CONSIDER CHANGES LIKE THIS FREE.

There are a lot of people that will tell you changes like this are free thanks
to AI now. One of the following must be true about these people.
- Their programs are SIGNIFICANTLY smaller than 3 Rust CSV parsing files.
- Their standards for "working code at near-zero cost" is SIGNIFICANTLY different from mine.
- They've got some special prompting skills that I do not possess.
- They're full of shit.

I suspect a combo of all of the above is at play.

## Analysis

So frontends must be popular enough to hire skilled devs, have enough of an
ecosystem to maintain dependencies, stable enough to stand a decade, and have
enough features to be able to do all the things you would expect today's web
apps to do.

That sounds reasonable, let's get to work.


### React Meta-frameworks

Let's start here, because it seems to be how most new web projects are started.

The two most common are Next and Remix. Let's look at them.

#### Next

NextJS is arguably winning the race in terms of popularity. However, there is
one thing that give me hesitation to use their framework.

 There has been some questionable stuff going on with Vercel (hosting platform that is a heavy sponsor of NextJS).
I've seen reports of features that are "stable in NextJS" being nearly or completely impossible to use unless you're deploying to Vercel.
It's toeing the line for "Extenuating circumstances that mean that I shouldn't choose it".

I don't like the idea of a hosting provider owning my code that much.

#### Remix

Remix is second-place in this race and, until a few days ago, I believed it to
be the right answer. However, there are a few things that have happened that
give me pause.

Remix eventually became "framework mode" in React Router v7. At this point, if
you wanted all the nice Remix features, you just used React Router v7, and Remix
as a framework was done.  I was okay with this.

Then, a few days ago, they came out with Remix v3, which is starting with a fork
of Preact, and isn't related in any way at all to Remix v2 or React Router v7.

Speaking candidly, I do not know what they were doing when they made this decision,
and it leads me to question the future of both Remix AND React Router v7.

When the people in charge of this framework are forking frameworks and completely
abandoning versioning conventions, I question whether either "Framework mode React Router v7"
OR Remix will last 10 years without requiring everyone who uses their frameworks
to completely re-write their frontends.

### Other Meta-Frameworks

#### Angular/Analog

Angular is infamous for the hard migration from AngularJS to Angular 2.
I have no idea if they learned their lesson.

#### Vue/Nuxt

The Vue 2 to Vue 3 migration was apparently very hard. Googling "How was the
Vue 2 to Vue 3 migration" gave me nothing but horror stories of long painful
migrations.

#### Svelte/SvelteKit
Not nearly as popular as Vue or Angular when looking at NPM downloads, skipping for now.

#### Solid/SolidStart

Not nearly as popular as Vue or Angular when looking at NPM downloads, skipping for now.


### And, the Dilemma

Finally, I've arrived at the crux of my issue with frontend web dev currently.
If I believe that meta-frameworks are the future (which I do), then I would want to start
a project with Next, React Router v7, Nuxt, Analog, SvelteKit, or SolidStart.

HOWEVER, each of those has things that concern me.
- Next's ties with Vercel concern me. I worry I would need to re-write my frontend after failing to deploy without Vercel enough times.
- Remix/React Router v7's erratic versioning concerns me. I worry these maintainers will force me to re-write my frontend entirely at some point or another.
- Angular's willingness to make sweeping breaking changes concerns me.
- Vue's willingness to make sweeping breaking changes concerns me.
- Svelte's popularity concerns me.
- Solid's popularity concerns me.

So, for the frontend in my web stack, my choices are either:
1. Go with something popular that feels unstable.
2. Go with something less popular (that doesn't necessarily feel more stable).

So what about avoiding the meta-framework stuff and just using vanilla React?

Well, vanilla react has actually been pretty good about backwards
compatibility. While not up to "modern standards," class components still run
on modern react versions. However, I think that way of developing frontend apps
is slowly losing to meta-frameworks. That would be a bet that people are still
starting vanilla react web apps with a separate backend in 9 years. I'm not
sure the trend supports that.

I think if I was starting something new today, I would just use vanilla react
and know that in 8 years my codebase is going to look dated to anyone who
started their web dev life in the age of NextJS. I can eat the cost of an extra
day here or there when onboarding to explain to new devs "this is like NextJS
but without XYZ". I can't eat the cost of months to years of rewriting my
frontend.

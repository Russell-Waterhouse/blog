---
title: "Jail for JavaScript Developers"
author: "Russell Waterhouse"
description: "Fellow Web Devs, what are we doing?"
tags: ["webdev", "javascript"]
date: 2026-01-13T19:45:11-07:00
draft: false
---

# Jail for JavaScript Developers

This is going to be a rant. The arguments will not be coherent, and there will
be flaws in my logic. I hope that you, dearest reader, can look past the steam
that I'm blowing off here to see the point that I'm trying to make.

## What we do, fundamentally

Web devs put information in front of a user, structured as HTML, styled with
CSS, sent from a central server, usually with data from a central database.

That's it.

That's all we do.

We draw some \<h1> and some \<p> on the screen of a user who has a web browser.

We change the format that we send over the wire (HTML or XML or JSON or
binary or whatever), and we change what database we use, and we change what
language we use on the backend, and we change what framework we use to tie it
all together on the frontend, and we change what subset of CSS we're using and
where we write the CSS, but at the end of the day we're mostly drawing \<h1>
and \<p> and \<li>.

And we have made a god-awful mess of it.

## The Mess, in Detail

And in making a god-awful mess of it, I don't think we've had it right even
for ten minutes. There's still so much work to be done.

We were right that instead of viewing static documents, users should be able
to have some interactivity, and we used JavaScript for it. A language filled with
so many holes and incomplete features that we've had to patch on:
1. equality checking (===).
2. A new module system (no, it doesn't play nice with the old one without work).
3. Async/await (but only ever on one CPU Core).
4. String interpolation using backticks.
5. A type system (complete with the `any` type, so you can discover new and exciting ways you're shooting yourself in the foot!)

We were right that we should be able to write a whole web app in one language,
but instead of making WebAssembly good we brought JS to the server. You know,
JavaScript, the language that I just said only runs on one CPU core at a time.
Yeah, we put it on the server.

And we were right that we should focus some effort on tooling because tooling
is important and helpful. Now we have more tools than you could shake a stick
at, and none of them work with each other out of the box. Each has a different
assumption for what module system you're targeting and what runtime they're
running in, and they might have TypeScript types, or they might not.

We were right that web devs probably shouldn't reinvent the wheel every ten
minutes, so we set up a package system and ecosystem, but then we made
`node_modules` Gigabytes in size, and reinvented the wheel every ten minutes
anyway. How do you trust all of your dependencies when package-lock.json is
thousands of lines long? How many NPM hacks and supply-chain attacks do we have
to endure before we have to change? Evidently, more than we've endured so far.

And we said that because so much is written based on web tech, we can't change
anything about CSS or HTML or JavaScript, and then we killed flash, a
technology that hundreds of thousands of sites used, including government tax
portals.

But not once did we realize that forcing every web-dev to completely rewrite
major parts of their application every few years is unhinged behaviour.

And for those that would say "React is great about backwards compatibility",
You and I both know react class components are just tech debt at this point,
don't lie to me like that.

And in all of this churn, what is the point of writing code to last a decade?
If it's getting rewritten next quarter, why bother breaking out the memory
profiler or even doing basic QA or gracefully handling errors?

Every single time we do even a fraction of engineering work
and measure something in this industry, we always find that
initial page load and time to first interaction and
reaction times to user actions ALL make our services better for the end-user.
These metrics correlate to more sales and less churn.

Then we ignore it, and the frontend guy fetches 25 MB of bundle and data in
several round trips for an initial page load and the backend guy uses the ORM
to write a query that takes 4 seconds and the devops guy deploys a docker image
7.8 GB in size with 239 CVE's, and we pretend that GraphQL will save us.

What have we done?

Right now, if I open a Chrome tab to Microsoft Teams and leave it open for 20
minutes, that single Chrome tab will take 1 Gigabyte of memory. For reference,
the King James .txt version of the bible is 4.4 MB. That means that Microsoft
Teams is keeping 227.27 King James Bible's worth of text in memory. I haven't
had 227.27 Bible's worth of conversations, so I'm really not sure what's
actually being kept in memory.

And that's everywhere. YouTube's play button just guesses if the video is
playing or not. Outlook's web client is just guessing at whether I've
read the email. Latest estimates show ~60% of web traffic is from mobile
devices now, but we can't even ship things that work on chrome AND Firefox on
the desktop, never mind mobile browsers.

I actually can't believe we've made it this far doing this bad.

Before anyone says "but what about X? They don't have these problems that
you're complaining about" Yes, there are pockets of web developers that haven't
lost their mind. There are people that care. There are people who take pride in
their work and are doing an excellent job. This isn't a post about them.

This is about the majority. This is about how the odds are in my favour that if
you're a web developer, you probably have seen an initial page load of 25 MB,
and the odds are in my favour that you probably have seen a 7.8 GB docker image
in production, and the odds are in my favour that you probably have seen
db queries run in production that take multiple seconds.

Even if you're just a web user, I bet you've seen a web portal or two with a
"don't click the button more than once" warning on there, as if disabling a
button and showing a loading spinner is a research project that we just don't
have the budget for this quarter. This post is all about the normalization of
insanity that any self-respecting field would not tolerate.

Web dev has serious problems, and everyone's just clocking into work pretending
everything's fine.

Everything is not fine; it's not fine because we've made it not fine, and it's
going to take work for things to ever be fine again.


P.S. Yes, I am aware that on mobile my tags, social media, and table of
contents all load after the main contents of my post. Yes, I am also aware of
the irony of that.

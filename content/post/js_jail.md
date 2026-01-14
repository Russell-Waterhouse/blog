---
title: "Jail for JavaScript Developers."
author: "Russell Waterhouse"
description: "Fellow Web Devs, what are we doing?"
tags: ["", ""]
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
protobuf or whatever), and we change what database we use and we change what
language we use on the backend and we change what framework we use to tie it
all together on the frontend and we change what subset of CSS we're using and
where we write the CSS, but at the end of the day we're mostly drawing \<h1>
and \<p> and \<li>.

And we have made a god-aweful mess of it.

And in making a god-aweful mess of it, I don't think we've had it right even
for ten minutes. There's still so much work to be done.

We were right that instead of viewing static documents, users should be able
to have some interactivity, and we used JavaScript for it.

We were right that we should be able to write a whole web app in one language,
but instead of making webassembly good we brought js to the server.

We were right that web devs probably shouldn't reinvent the wheel every ten
minutes, but then we made `node_modules` Gigabytes in size, and reinvented the wheel
every ten minutes anyways.

And we said that because so much is written based on web tech, we can't change
anything about CSS or HTML or JavaScript, and then we killed flash.

But not once did we realize that forcing every web-dev to completely rewrite
major parts of their application every few years is unhinged behaviour.

And for those that would say "React is great about backwards compatability",
you obviously haven't ever had to re-write a whole frontend because some new
thing your tech lead wanted to use didn't work well with class components.
You and I both know react class components are just tech debt at this point,
don't lie to me like that.

Not once did we realize that ...
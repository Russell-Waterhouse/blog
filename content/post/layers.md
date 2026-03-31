---
title: "TODO"
author: "Russell Waterhouse"
description: "TODO"
tags: ["one-language-challenge"]
date: 2026-03-07T09:48:33-06:00
draft: false
---

# TODO: title here.

I'm not sure what the thesis of this blog
post is, but I know I have enough ideas
that are all interrelated that if I get
them all down into one post, something coherent
will come out. After editing, of course.

## Idea 1: no wheels in software.

I was watching some handmade hero streams
by Casey Muratori today, and he said something
that really resonated with me.

Someone asked him why he was doing things from
scratch and re-inventing the wheel. His answer
was twofold. The first part of his answer was about how
learning the underlying fundamentals is good and useful. The second
part of his answer he said,
"nothing we have developed in the past thirty years
of game development is a wheel. We do not have a single wheel.
If you think Unity is a wheel, or you think Unreal is a wheel, that is just
plain shortsighted."

And what a poignient thing to say.

And I don't believe that just applies to game programming
and game engines. I don't believe that there is a single
wheel in all of software engineering.

What could we point to and say "that's a wheel.
It would be foolhardy to try and re-invent that.
That will work without any modification for the next thousand years.
It has no sharp edges, it does what you expect with a minimal of maintenance
and strife. We might make minor alterations to it for extreme requirements,
but more-or-less this will just work out-of-the-box."

The if-statement, maybe?

But anything above that? I don't think so.

Maybe C? But if C is so perfect, why is C3, Zig, and Odin trying to improve it,
and all in different ways?

Maybe not C++ either, because Carbon and Jai and Rust are trying to replace
that.

And it's not just game engines and programming languages.

If you want to build a website with the criteria that your entire stack is
stable, maintainable, performant, what could you do?

Performant as possible means no Node, no Django.
Go has GC runs, so we should avoid that too.

Rust or C++ for the backend then? And you better hope the Axum or Drogon
frameworks don't decide to force any major changes on you in the next 10 years.

And how do you do client-side interactivity? WASM DOM manipulations are slow,
so you need at least a little bit of JS in there, even if it's HTMX, AlpineJS,
Datastar, or your own custom JS scripts.

And how are we deploying this? If we really wanted all the performance we could
get, we'd have to run on bare metal.
If we want all the scalability, we'd want kubernetes and docker.

And who looks at kubernetes and says "It has no sharp edges, it does what you
expect with a minimal of maintenance and strife."

And what principle engineer at any web tech company could propose any of that
and still have a job by lunch?

"Hey guys, for this new web app we're building, let's use as little JS as
possible, write the backend in Rust or C++, and we're going to use Kubernetes
to deploy it to our own hardware. No, we won't be able to find people that know
how to maintain web apps written like this because nobody does it like this."

If we were good at what we do, everything I described above
would be seen as MORE sane and rational than running:
- NodeJS interpreted JS Code
- With hundreds of dependencies
- in docker
- in kubernetes
- on a VM
- sending a React Bundle to the frontend to do DOM manipulations in single-threaded scripting language.

And here's the crazy thing. A quick spike to set up Rust, Axum, and Datastar
showed me the developer experience feels about as good as React and Express.
For every hiccup I encountered in a quick spike, I could point to at least one
hiccup that React and Express have given me in a project of similar complexity.

So, we made this giant trade for... preference for JavaScript?

JavaScript, the language renown for being so beloved?

But let us say we wanted to abandon the web for thick clients. If we want thick
clients, we'll have to make the user download our application and run it.

Okay, cool, cut out the browser, I'm all for it.

So how should we put the bits on the screen?

Electron? I sure hope you like spending money on RAM and spinning CPU fans.

OpenGL? Hasn't been updated on MacOS in years.

So, Vulkan? You'll be eating more complexity cost there, but sure.

...


okay so as I write this, I think I feel less stressed.
what WAS worrying me in what I said above was that there aren't
any good options as dependencies upon which to build things.
can't rely on the operating systems, graphics libraries, anything
on the web, etc, etc. 

but, that's kinda not true. Axum is fine. Datastar is fine.
I bet Vulkan is fine. We just keep not choosing these.

that's actually what's bothering me. 


so, building a web stack from the ground up,
I'd use:

OS: Linux
HTTPS handling, rate limiting, etc: NginX
backend: Rust with Actix or Axum
frontend interactivity: Datastar
CSS: tailwind (probably? I think tailwind is the one part of modern web dev that's correct)
Data layer: Postgres
deployment: bare metal server until I NEED to eat the cost of something like Kubernetes.

I'm happy enough with that.

That eliminates:
- Docker
- Kubernetes
- VM
- JS (at least, most of what I have to write)


and if I didn't want to work with the web for a
client, I might want to use:

- Dear IMGui or EGUI

and if I wanted a desktop app, a mobile app, and a website,
well the backend could just have a flag for how it's
serializing, and if you build your desktop app
as a library, you might just have to maintain 2 platform layers,
not 2 code bases.

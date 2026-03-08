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

someone asked him why he was doing things from
scratch and re-inventing the wheel. His answer
was twofold. The first part of his answer was about how
learning the underlying fundamentals is good and useful. the second
part of his answer he said,
"nothing we have developed in the past thirty years
of game development is a wheel. we do not have a single wheel.
if you think unity is a wheel, or you think unreal is a wheel, that is just
plain shortsighted."

And what a poignient thing to say.

And I don't believe that just applies to game programming
and game engines. I don't believe that there is a single
wheel in all of software engineering. 

What could we point to and say "that's a wheel.
It would be foolhardy to try and re-invent that.
That will work without any modification for the next thousand years."

The if-statement, maybe?

But anything above that? I don't think so.

Maybe C? But if C is so perfect, why is C3,
Zig, and Odin trying to improve it, and all in different
ways?

Maybe not C++ either, because Carbon and Jai and Rust
are trying to replace that.

and it's not just game engines and programming languages.

If you want to build a website with the criteria that
your entire stack is stable, maintainable, and as performant as possible, what could you do?

Performant as possible means no Node, no django.
Go has GC runs, so we should avoid that too.

Rust or C++ for the backend then? And you better hope the Axum
or drogon frameworks don't decide to force any major changes on you in the
next 10 years. And how do you
do client-side interactivity? WASM dom manipulations are slow, so
you need at least a little bit of JS in there, even if it's 
HTMX, AlpineJS, or datastar.

and how are we deploying this? If we really wanted all the performance we could get, we'd have to
run on bare metal, not a VM or kubernetes or docker.

And what principle engineer at any web tech company could propose any of that
and still have a job by lunch?

If we were good at what we do, everything I described above
would be seen as MORE sane and rational than running:
- NodeJS interpreted JS Code
- With hundreds of dependencies
- in docker
- in kubernetes
- on a VM
- sending a react Bundle to the frontend to do DOM manipilations in single-threaded scripting lanuage

And here's the crazy thing. A quick spike to setup Rust, Axum, and datastar
showed me the developer experience feels just as good as react and express.

So, we made this giant trade for... preference for JavaScript?

But lets say we wanted to abandon the web for thick clients. if we want thick clients, we'll have to
make the user download our application and run it.

Okay, cool, cut out the browser, I'm all for it.

so how should we put the bits on the screen?

electron? i sure hope you like spending money on RAM andspinning
CPU fans.

OpenGL? hasn't been updated on MacOS in years.

So, Vulkan? You'll be eating more complexity cost there, but sure.



okay so as I write this, I think I feel less stressed.
what WAS worrying me in what I said above was that there aren't
any good options as dependencies upon which to build things.
can't rely on the operating systems, graphics libraries, anything
on the web, etc, etc. 

but, that's kinda not true. Axum is fine. datastar is fine.
I bet Vulkan is fine. We just keep not choosing these.

that's actually what's bothering me. 


so, building a web stack from the ground up,
I'd use:

OS: linux
HTTPS handling, rate limiting, etc: NginX
backend: Rust with Actix/Axum
frontend interactivity: datastar
css: inline styles or tailwind?
Data layer: postgres
deployment: bare metal server. 

like I'm happy enough with that.

that eliminates:
- docker
- kubernetes
- VM
- JS (at least, most of what I hae to write)


and if I didn't want to work with the web for a
client, I might want to use:

Vulkan
+ SDL2
+ Clay
+ miniaudio
 
all of that eliminates electron
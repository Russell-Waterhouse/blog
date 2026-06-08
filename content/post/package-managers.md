---
title: "Are Package Managers a Good Idea?"
author: "Russell Waterhouse"
description: "Are Package Managers a Good Idea?"
tags: ["package-managers"]
date: 2026-03-30T20:32:17-06:00
draft: false
---

# Package Managers, a Reflection

First, a few disclaimers.

I'm about to make some very specific claims. These specific claims apply to
some kinds of software. If you're not writing this kind of software, it does
NOT apply to you.

If you're writing MVP startup software where you don't have product-market fit,
your first, second, third, forth, fifth, sixth, and ONLY goal is to find
product-market fit. You're not worried about performance or stability or small
binary sizes or build times or anything that I'm about to talk about. Read the
security section, because if you're making things attached to the internet you
have to be security-conscious, but ignore the rest.

Second, I'm not making an argument against packages. If there is a dependency
that you can use that's stable, performant, easy to integrate, and saves you
time or provides a feature to your user that you would otherwise not have the
time to provide them, use it! You probably don't have to write an HTTP server
from scratch using sockets, and it would probably be a waste of your time.

Okay, with that out of the way, here's my claim.

## Package Managers are a Poor Fit for Production Software

Package managers are starting to feel like a poor fit for production software.

I'm talking about the package managers for languages like npm and cargo, not
the ones for installing software like homebrew and apt.

I'm using the term "production software" here as a loosely defined term for
software that has found product-market fit, and this is the version of software
that is either the final release (like a game) or you plan to maintain for a
long period of time (i.e. years).

In that kind of software, things like performance, stability, executable size,
etc. usually start to matter. Security matters anytime you have something
on the internet, so that goes without saying.

I think package managers work against all of these.

And the wort part is that in theory, package managers SHOULD make all of these
better. Yet, when I look at what package managers actually give me in practice,
that's not what I see. As I once heard a wise man say, "Theory always works, in
theory"

## Package Managers Hurt Security

Package managers are supposed to help security. They're supposed to allow you
to easily patch your software so that the vulnerability in your transitive
dependency just disappears with one CLI command and one deploy.

And sometimes, they do. However, sometimes, they make it so much harder.

Often, there are vulnerabilities in a package 4 transitive dependencies deep.
If transitive dependency number 2 doesn't release a patched version that
depends on the patched version of transitive dependency number 3 that depends
on the patched version of transitive dependency number 4, what are your options?

1. Analyze the bug and how it is triggered and decide if there's any actual
code path between your code and the vulnerable code. You'd have to understand
how 4 packages work together to do this, but sometimes it can be done.
2. Fork these 4 dependencies, update all of their code, push these on NPM or pip,
and update your dependency to point to your own forked versions.
3. Hope.

If you're lucky, transitive dependency 2 isn't abandoned. I haven't always been
that lucky. Maybe you have been.

Now, if you had just vendored them into your own project, you would still have
to update those 4 dependencies, like option 2. However, once you did that, you
wouldn't have to push them to NPM or pip. You would just build your project like
normal and move on with life. If the license required, you may have to publish
your changes, but that's besides my point.

People often say that "every line of code that you write is a liability" as a
justification for why you should depend on third-party dependencies
where possible. However, if there's a bug in code that you depend on, that's
your liability too. A more accurate way to put that might be "every line of
code that your project runs is a liability." It's still not right, because
that completely ignores that code can be an asset, not just a liability, but
I think my point is made.

If you're responsible for every line of code that runs in your project, using
a package manager to pull in all of these dependencies means that you now have
all of these liabilities, and it's HARDER to manage that responsibility.

Again, I want to stress that this is the exact opposite of what is advertised,
and what common sense would imply. However, this is what I've observed again
and again in every system that I touch that uses a package manager.

And none of this even mentions the growing possibility of supply-chain attacks
that the package manager makes so much more dangerous.

The biggest supply-chain attack recently was
[Axios,](https://cloud.google.com/blog/topics/threat-intelligence/north-korea-threat-actor-targets-axios-npm-package/)
a common networking package.

The malicious package was only available for 3.5 hours or so, but because
many people use `npm install` instead of `npm ci` in their CI pipelines, many
people's package-lock.json was ignored, and the malicious minor version was
pulled, and those people are now trying to figure out how to evict North Korean
hackers from their environment and how to roll all the credentials that got
exfiltrated. If people had vendored Axios (or even better, used the `fetch`
API literally build into the browser and NodeJS), only people manually upgrading
their dependencies in that 3.5 hour window would have been owned, instead of
anyone that ran CI in that time.

But while the most flashy attack recently, it's far from the only one.
[TeamPCP](https://www.reversinglabs.com/blog/teampcp-supply-chain-attack-spreads)
has been causing chaos in the PyPI world,
[crates.io has been attacked](https://socket.dev/blog/two-malicious-rust-crates-impersonate-popular-logger-to-steal-wallet-keys),
and the list goes on.

Again, package managers don't make supply-chain attacks easier or harder for
the attacker, but they do make it easier to accidentally be a victim of one.

## Package Managers Make Bloat Easy

Here again, what I've observed in package managers is the opposite of what
package managers advertise and what common sense would imply.

Package managers should imply that if you have the same transitive dependency
in 2 dependencies in the same project, you could just pull that dependency once and have both dependencies
use it.

Yet, when I build a project that uses npm or cargo or pip or ruby bundler,
I always find that the dependencies pulled are gigabytes in size, even for
simple projects.

That's insane. That's unhinged. A Gigabyte of code to run a simple HTTP server?
Are you kidding me? A Gigabyte of code to read from a socket, route to a
function, serve templated responses and static files, and serialize data for a
response?

For this cargo.toml, my `target/debug/deps` folder is 1.5 GiB.
```
[package]
name = "data-star-test"
version = "0.1.0"
edition = "2024"

[dependencies]
askama = "0.15.4"
asynk-strim = "0.1.5"
axum = "0.8.8"
datastar = { version = "0.3.1", features = ["axum"] }
serde = "1.0.228"
serde_json = "1.0.149"
tokio = { version = "1.49.0", features = ["full"] }
tower = "0.5.3"
tower-http = { version = "0.6.8", features = ["full"] }
tracing = "0.1.44"
tracing-subscriber = { version = "0.3.22", features = ["env-filter"] }
```

Maybe if this was vendored, this would be the same, or worse.

But maybe, if you had to actually think about adding a dependency, you wouldn't
pull in an entire package just to use one function.

Package managers make it mindless. Need to left-pad a string? Why write the
ten lines of code to do that when you could `npm install left-pad`?


## What I'm Doing About It

At work, I'm continuing to use the
industry-standard package managers.

For my personal projects, I'm vendoring
everything. And in doing so, I've resolved to
build more of what I need myself. It is undeniably
slower. However, it's also undeniably more stable,
I have infinitely more control, and I feel more sane.
More frustrated too, at times, as
I'll sit down to build a feature and instead of the feature,
I'll only have enough time to set up the infrastructure and
tools the feature will need.

For now, I'm going to stick with that.
I'll find out in a few years whether I'm right.

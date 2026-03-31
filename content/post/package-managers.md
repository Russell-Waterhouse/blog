---
title: "Are Package Managers a Good Idea?"
author: "Russell Waterhouse"
description: "Are Package Managers a Good Idea?"
tags: ["package-managers"]
date: 2026-03-30T20:32:17-06:00
draft: false
---

# Package Managers, a Reflection

First, a disclaimer.

I'm about to make some very specific claims. These specific claims apply to
some kinds of software. If you're not writing this kind of software, it does
NOT apply to you.

If you're writing MVP startup software where you don't have product-market fit,
your first, second, third, forth, fifth, sixth, and ONLY goal is to find
product-market fit. You're not worried about performance or stability or small
binary sizes or build times or anything that I'm about to talk about. Read the
security section, because if you're making things attached to the internet you
have to be security-conscious, but ignore the rest.

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

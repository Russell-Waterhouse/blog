---
title: "Api Design"
author: "Russell Waterhouse"
description: "Notes on API design"
tags: ["API Design", "Component"]
date: 2026-04-14T12:47:35-06:00
draft: false
---

# API Design that works in Practice


These are going to be my notes on
[Casey Muratori's talk on design and evaluation of reusable components](https://caseymuratori.com/blog_0024)
[Youtube video here](https://www.youtube.com/watch?v=ZQ5_u8Lgvyk)

Quick disclaimer first.

DISCLAIMER: My notes on a 50-minute lecture are going to be worse in every
single way than just going and watching it yourself and taking your own notes.
I publish these notes not to rob you of the best lecture in API design that
I've ever seen, or to claim that any of these ideas are in any way my own, but
to clarify my thoughts on them and maybe be able to spread knowledge of this
lecture and the ideas within to someone else. Seriously, you can skim my notes,
but they're for me, not you.

There are three kinds of reusable APIs

![Three Types of Reuse](/post/images/types-of-reuse.png)
Image taken from the YouTube video linked at the start.


A "Layer" in the image above is an API to abstract some service. An example
of it is Direct3D for talking to graphics cards.

An "Engine" in the image above is an API that controls everything and you write
code that it calls. An example of this is Unreal Engine.

A "Component" is an API that you hand stuff to, and it hands stuff back to you.
An example is character animation or physics.

Layers have two problems.

1. They require a well-defined service at the bottom to abstract over (3d hardware works, but doing something like AI doesn't make sense as a layer).
2. Two layers can conflict. For example, you could never use openGL AND Direct3D at the same time in a project.


Integrating components is not linear and not a unit-step function. Integration
evolves over time.

In this integration, there isn't usually just one way to integrate the
component into a system. There's usually many ways, some which require very
little work and some which require a lot of work. Usually, the more work is
required to integrate a component, the more benefit your system will gain from
using that component.

As your system evolves, you will often find yourself requiring "more" from a
component. We'll get into what "more" means in a little bit.

There are two situations you want to avoid here:
1. Your requirements change and the API does not support what you need to do.
2. Your requirements change and the API does support what you need to do, but it would be a massive amount of work to do it.

Casey calls situation number two above an "Integration Discontinuity."

Casey states that the goal of reusable APIs is to "eliminate API
discontinuities."

## Characteristics

The characteristics that Casey identifies for evaluating APIs are as follows:

1. Granularity - A or BC
2. Redundancy - A or B
3. Coupling - A implies B
4. Retention - A mirrors B
5. Flow Control - A invokes B

### Granularity

If an API does A, it has more granularity if a direct call to A can be replaced
by direct calls to B and C.

### Redundancy

If an API does A in a specific way, it has more redundancy if there is another
API call B, that does the same thing that A does, but in a different
way. For example, A takes a set of parameters and B takes a different set of
parameters.

For example, maybe there are two APIs for doing 3d math, one that takes a 3x3
matrix and one that takes a quaternion.

### Coupling

When "If you've done A, you must also do B" or "If you plan to do B, you must
first do A."

This is almost always bad but is sometimes unavoidable.

There are several types.
1. Inter-object coupling: When actions taken on a subset of objects effects many objects.
2. APIs that depend on some state that you set.
3. Code that enforces serial operations (GLBegin and GLEnd, for example)
4. Are internal buffers something we need to know about and couple together otherwise unrelated actions.
5. Coupling allocation to initialization.
6. Coupling to a specific type. For example, if the API defines a type that you don't want to use, forcing you to constantly be creating them.
7. Coupling an object initialization to the component's file reading and file formats.

### Retention

When the API has two things, one on your side of the other API, and one on the
other side of the API. Usually this is when you give the API something, and
it keeps a copy of that for its own use. It could be defining relations between
data that the API uses, passing in functions for the API to use (i.e. READ, OPEN, etc.)
or defining data that you want the API to use.

### Flow Control

Who calls what. Does the main program call the component and nothing else?
Does the library callback into the main program? Do they call each other back
and forth? Does the library use exceptions for flow control?

## Tradeoffs

- Less Granularity: Simplicity.
- More Granularity: Flexibility.
- Less Redundancy: Orthogonality (i.e. simple to figure out what you need).
- More Redundancy: Convenience.
- Coupling: Less is always better.
- Less Retention: If the API can retain data, the component API may be able to automate things that you would otherwise have to handle.
- More Retention: User has to synchronize all the retained data, and that's hard.
- Flow Control: Keeping the flow control in YOUR calling code, not the component API code, is always better.

Noteworthy: What tradeoffs you want WILL CHANGE. At the beginning, you'll
favor simplicity and orthogonality.

As your code gets more complicated, you'll favor flexibility and convenience,
and probably less retention.

## Notes on Retention

If you're working with a retain-mode API, you'll constantly be diffing what's
retained by that API compared to what action you want to tell that API to take
in response to some event.

Rather than write code like this (COPIED FROM THE LECTURE AT 42:00)
```c
if (XButtonDown)
{
  if (!Hookline)
  {
    Hookline = CreateJoint(Rocket, Pole);
  }
}
else if (Hookline)
{
  DeleteJoint(Hookline);
  Hookline = 0;
}
Simulate();
```

it would be much easier to write code like this:
```c
if (XButtonDown) DoJoint(Rocket, Pole);
Simulate();
```

## The Optimal API

The optimal API is one which is gradually tiered, highly decouples, with
no retention at its most granular tier, and always lets the game dictate
the flow of control.


## Cheat sheet summary

- When you sit down to write an API, write the code that uses the API first.
- When you sit down to evaluate an API, write the code that uses the API first, then pick the one that looks closest to what you wrote.
- All retain mode constructs have an immediate-mode equivalent.
- For every API that uses callbacks or inheritance, there is an equivalent that does neither.
- No API requires the use of an API-specific datatype for which the average user will have an equivalent.
- Any API function that may not be considered atomic by the client programmer can be re-written using 2-4 more granular APIs.
- Any data that does not have a clear reason for being opaque should be transparent in all possible ways (construction, access, I/O, etc.)
  - Rephrased by me: If touching some data in an API would break fundamental assumptions, you can hide that. Otherwise, you should give the client programmer complete control over all the data.
- Use of the component's resource management (memory, file, string, etc.) is completely optional.
- Use of the component's file format is completely optional.
- Full runtime source code is available.


## Why I Love this Lecture (My own thoughts here)

This lecture has reflected what I have experienced myself when integrating
APIs into my own code.

I've worked with APIs that followed the SOLID principles, for example.

It has only a single responsibility, follows the open/closed principle and
Liskov substitution principle and interface segregation principle and the
dependency inversion principle.

And as soon as I try to do something that the API does not expect, it is
immediately a month of work to do what a more granular API with less coupling
would be able to do in one line.

SOLID API design lacks words to even explain what went wrong there, other than
a "no true Scotsman" argument of "you didn't do it correctly."

Casey's lecture here gives me the words for it. The API coupled several data
types together and did not offer the granularity or redundancy to do what I
needed to do.

Lastly, Casey offers the best piece of API design advice I've ever gotten, and
using it has improved my API design skill IMMENSELY.

Just write the API use code before you write the API.

It's so simple, it's so easy, and it's so effective.


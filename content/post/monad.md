---
title: "The Obligatory Monad Post"
author: "Russell Waterhouse"
description: "Monads finally clicked for me, and I am now obligated to create one more terrible monad post"
tags: ["Haskell", "Functional Programming", "Monad"]
date: 2022-09-14T20:43:05-07:00
draft: true
---

# What is a Monad?

I see no reason to beat around the bush. A monad is just a slick way of composing together functions that deal with embellished data. Here are the two concepts to understand to understand monads.

1. What do I mean when I say embellished data?

In this case, I just mean data that is wrapped up in some way. A good example of this is the Maybe typeclass in haskell, which is used somewhat similar to Optional<?> in Java - it can be Nothing or Just (value).

Another common example is a List.

2. What is composition?

Composition is a fairly simple concept, even for those that aren't programmers.

If you have a function f1 that takes an element a and transforms it to an element b
f1 = ( a -> b)

And you have a function f2 that takes an element b and transforms it to an element c
f2 = (b -> c)

then you can compose together function f1 and f2 to get a function f3 that takes an element a and transforms it to element c (a -> c).

f1 . f2 = f3 = (a -> c)

That's it. That's all monads do. They compose together functions that work with the same embellished data.  If you were just looking for what a monad is, that's the answer. It's not wild or complex. You can stop reading here, satisfied with your answer. If you would like to know how they do this and how to use them, then continue reading. Just remember that composing these functions together is the end goal.

# How do Monads work?

Monads work by using 2 functions, bind and return.

## Return

Return is unfortunately named. If you come from a imperative programming background (and let's be honest, almost all of us do), you're familiar with the idea that "return" makes a function return a value. Return in a monad is just a defined function that embellishes the data for the monad. It can be used anywhere in the function, and does not mean that the function is returning that value, it just means the data is now wrapped.

For example, the return function for the list monad just takes a piece of data and returns a list with that single element in it.

return (list implementation)
a -> [a]

While it is poorly named, it is a simple concept.

## Bind

You may see bind represented as >>=. I'm using the word bind here because it is very hard to pronounce >>=, even if you are just reading this in your head.

Bind ... //TODO

How to use a Monad?

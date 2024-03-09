---
title: "1 Year With Haskell, Part I"
author: "Russell Waterhouse"
description: "My thoughts about the last year of writing production Haskell"
tags: ["haskell", "functional programming"]
date: 2024-03-08T16:07:11-08:00
draft: false
---

# Haskell, A Year in Production

## Foreword

First, a few disclaimers.

All of my thoughts and opinions here are entirely my own, and do not reflect
the opinions of my associates, my employer, or anyone else.

I am not an expert in Haskell. I have a year of shipping it, and most of that
year has been focused on a single repository. It is entirely possible that
every negative thing I have to say about Haskell is my own skill issue. That
being said, if you haven't shipped Haskell for a year, think long and hard
before dropping "skill issue" in the comments.

I encourage you to scrutinize my claims before taking anything I've said and
making decisions based off of it.

Second, if you just want to know about my thoughts, skip to that section.
However, if you want the full story, which I believe is far more valuable, read
the whole blog post. I know it's long, but it is years of experience condensed
into a 15-minute read.

## How did I get here?

Picture this: it's 2021, and you're a young passionate software engineering
student who just finished his 16th month of co-op in Java.

16 months of writing and shipping Java professionally. You read [Clean
Code](https://www.amazon.ca/Clean-Code-Handbook-Software-Craftsmanship/dp/0132350882),
you read [Head First Design
Patterns](https://www.amazon.ca/Head-First-Design-Patterns-Brain-Friendly/dp/0596007124/).
You tried TDD, and learned all the Java Mocking libraries.  And some of it
helped, for a time.  But nothing seemed to fix the underlying issue, whatever
that was.

Nothing seemed to make Java development as good as development should feel.

Kotlin felt good, C felt good, Python felt good. But all the code that you got
paid for? That felt terrible.

And not for any reason that you can point to. Your ability to take a feeling
about code and turn it into actionable wisdom just doesn't exist yet.

That's the position I found myself in at about September 2021.

And instead of experimenting myself with what felt good and what didn't, to try
to come to some sort of independent empirical conclusion, I did something far
more dangerous and far more lazy.

I went looking for opinions on the internet.

And boy did I find opinions.

Here's a short list of opinions I found, and my thoughts on them at the time.

- Remote work was the problem (no, I still liked working remotely in python)
- You aren't doing TDD right (no, I was following all the classic advice to a
  T)
- You aren't using enough design patterns (I'm sure I am).
- You are using too many design patterns (Possible, but not likely. I think
  it's a tasteful amount).
- Your system isn't architected correctly (everybody's definition of
  "correctly" changes too often).
- You haven't done the single responsibility principle correctly (somehow each
  of my classes has both 1/4 responsibility and 3 responsibilities at the same
  time).

You get the idea. I had tried enough of the band-aids to figure out that a
band-aid wasn't going cut it.

"Just do it better" wasn't working for me.

> I'm going to talk more about what I think the actual problem was, and
what the real solutions were, in a Part 2. I'm not saying anything about this
now, other than that these answers, and dozens others, didn't satisfy me at the
time.

And then, I found a Goto conference talk about functional programming. It put
into words a lot of the issues that I had been having, but hadn't been able to
formalize.

The more I dug into this functional programming idea, the more it seemed like
the answer to all of my problems. Problems like:
- Mundane changes breaking things in unexpected ways.
- Unbearable system complexity.
- Scalability of the system.
- Insane amounts of code duplication.
- Systems that were hard to debug.
- Null Pointer Exceptions
- Incomprehensible loops

It also promised a lot of other things that I hadn't even struggled with yet:
- Fearless concurrency, which was important because the future of hardware was
  more concurrency with GPU's and CPU's with more cores.
- Reduced logical errors because the code is easier to read.
- Provably correct programs
- Easier debugging and unit testing

So with slick internet salesmen ensuring me that Haskell was both the future of
software development AND the answer to all my problems, I set out to learn it.

## Learning Haskell.

I started out with small, LeetCode style programs. I eventually made one or two
bigger programs.  I understood Monads.  I watched a few lectures on Category
theory on YouTube.  I was not an expert by any definition, but I knew more
Haskell than most programmers ever will.  

Then school got busy, I helped found the [University of Victoria Cybersecurity
Club](https://github.com/VikeSec), and Haskell just wasn't my biggest priority.
I put it on the shelf.

## How I Started Shipping Haskell

Before I knew it, it was January 2023, I had graduated, and the tech market had
crashed. And somehow, in all of that, I managed to find a job building
leanpub.com, where they have some book generation systems in, you guessed it,
Haskell. You can read more about it on their website
[here](https://ruboss.com/blog/for-potential-coops)

## What are My Thoughts After 1 Year

I think that Haskell is like everything else. Some good, some bad, some parts
overrated, some parts underrated. It's far more interesting to break it down by
feature. Here's my thoughts on every noteworthy feature, in no particular order.

### The Type System

I think that the type system in Haskell is incredible. I think that a strict,
static type system with Generics, Product Types, Sum Types, and no NULL (the
Maybe Monad does not count), along with type inferencing and good LSP support,
is a magical combination that makes building programs very pleasant.

It gives me the flexibility to model the real world in my code with a precision
and ease that I haven't found in most other languages. For those that haven't
experienced that or don't know what I'm talking about, follow [this link to the
Simple Haskell Handbook](https://leanpub.com/simple-haskell-book), buy the
book, and see how the author builds a program that precisely models what's
happening in the real world with Haskell's types. It's currently a minimum of
$10, and that's a steal.

It's a combo that's not unique to Haskell, and you don't need every piece to
start to get the benefits. Rust's type system, from my experience with it so
far, offers pretty much the same experience. Even Kotlin's null safety and type
inferencing combo offers most of the benefits that Haskell has.

Every time I write code in TypeScript or Ruby or Python, I really wish I had
Haskell's type system.

### The Formatting Conventions

I hate them. For every further Haskell example you see, I'm going to format
them in a way that makes sense. I refuse to write this:

```haskell
data Book = Book
  { bookId :: Int
  , title :: String
  , author :: String
  , isbn :: String
  , price :: Double
  }
```

And instead I like this:

```haskell
data Book = Book {
      bookId :: Int,
      title :: String,
      author :: String,
      isbn :: String,
      price :: Double
    }
```

Also, every single list variable is `xs` (pronounced X's, as in several of X).
It's never `books` or `items` or `blocks`, but literally `xs`. I learned in
first year programming that 1-letter variable names that aren't descriptive are
a bad idea. Why Haskell programmers haven't figured it out yet is beyond me.

### The IO Limitations

This feels like it was kinda snake oil to me. The whole point of this
restriction is you're not supposed to be able to do IO actions just anywhere in
your code all willy-nilly, thus increasing the amount of code that you have
that is totally deterministic (those lovely pure functions that everybody loves
so much). However, in my experience, IO gets brought along with other custom
monads that I'm working in, that I'm never more than a function or two deeper
than an IO monad.

### The Immutability

This is by far my least-favorite part of Haskell. I have two problems with it.
1. I don't think it delivers the claim of reducing logical bugs
2. I think it encourages gross code.

Let me show you what I mean, using just enough Haskell so that everyone knows I
actually know what I'm talking about without using so much that nobody
understands my point. Say we have a data type in an inventory management
system.

```haskell 
data Item = Item {
        id :: Int,
        description :: String,
        category :: String,
        count :: Int
    }
```

And a function that does some set of transformations to a list of this data.

```haskell 
transformData :: [Item] -> [Item]
transformData inputData = functionC (functionB (functionA inputData))

functionA :: [Item] -> [Item] functionA = undefined

functionB :: [Item] -> [Item] functionB = undefined

functionC :: [Item] -> [Item] functionC = undefined 
```

For those of you that know Haskell, you could also do this. 

```haskell
transformData :: [Item] -> [Item] 
transformData = functionC . functionB . functionA
```

What functions A, B, and C do to the data isn't really important. Just know
that the output from A is passed to B, which passes its output to C.

If you modify what function A does to the data, you will modify the data that B
and C get.

Now if you remember, the whole reason that we do the immutability thing in
Haskell is because we don't want the effects of our changes in one part of the
program to cause problems in another part. That hasn't been my experience. In
the exact same pattern as described above, I've caused bugs in function B
because I changed function A. Maybe if I had previously used a ton of global
mutable variables, immutability would have been revolutionary for me.

So far, the only effect I've really seen is that I now find code like this
sometimes.

```haskell 

functionD :: [Item] -> [Item]
functionD xs = let
        xs' = functionA xs
        other1 = functionB xs'
        xs'' = functionC xs'
        other2 = functionD xs''
        xs''' = functionE xs''
    in
        finalFunction xs''' other1 other2 
```

With mutability (and better formatting conventions), that could look like this.

```haskell
functionD :: [Item] -> [Item]
functionD items = let
        items = functionA items
        other1 = functionB items
        items = functionC
        items other2 = functionD items
        items = functionE items
    in
        finalFunction items other1 other2
```


### Fearless Concurrency

I haven't done any concurrency, but I think that's noteworthy and I want to
talk about it for a second. Most of the programs that we write take some data
from somewhere, modify it a little, and put it somewhere else.  

That's it.  

And you can make that concurrent at the per-data level, where each input is
processed concurrently, the way that modern webservers or databases do.

But for each input, usually the data has to go through transformation A, then
B, then C, then the result is spit out wherever you're putting data, be that
CSV, Database, or HTTP response. And if C depends on B which depends on A,
which it almost always does in my experience, you can't make that any more
concurrent.

So, maybe Haskell has a great concurrency experience, and maybe it has a
terrible one, but I think the fact that I have no idea after a year of shipping
it tells us that the answer probably doesn't matter as much as is advertised.

### Testability

I haven't really found Haskell to be more testable than any other language. I
can write a mess of code in the IO monad that's totally testable, or I can
break business logic out into discrete functions that are easily tested. Same
way I can in Ruby or Java or Python or Rust or C or Kotlin. You get the point.


### The Ecosystem and Developer Experience

The LSP is good, not great. I occasionally see errors highlighted that aren't
actually errors, but more often than not it's working, which is more than I can
say for my experience with TypeScript's Language Server.

Installation with [ghcup](https://www.haskell.org/ghcup/) is pretty easy and
I've never had any real problems with it.

I mainly resort to print debugging with `Debug.trace`, because between the
time it takes to start a `stack repl` and construct the deeply nested data
that I actually need to debug, it's usually just quicker to throw in 3 print
statements and recompile and run on the actual test data that's giving me
issues.

### Lazy Evaluation

It makes print debugging slightly more difficult. Instead of doing this:

```haskell
func :: [Item] -> [Item]
func items =
    let foo = functionA items
    let bar = functionB items
    let not_evaluated = Debug.trace ("the value of foo is: " <> show foo)
    in
        functionC foo bar
```

You have to do something like this to make sure the trace actually gets evaluated:

```haskell
func :: [Item] -> [Item]
func items =
    let foo = functionA items
    let bar = functionB items
    let bar' = Debug.trace ("the value of foo is: " <> show foo) bar
    in
        functionC foo bar'
```

All this to say, Lazy evaluation means almost nothing to me in my day-to-day
development experience.

## My Conclusions

Overall, I think that Haskell does some things better than any other language
that I know. However, Pure Functional Programming isn't one of them. For me,
learning Haskell has made me a better developer, but not for the reasons
advertised to me. It has made me a better developer because it has allowed me
to see what makes good code and what makes bad code in very different contexts.
What it has done for me is given me an environment to isolate the true enemies
of programming.

It has allowed me to see that, regardless of programming paradigm, any time
code does many complex things, there is going to be a lot of code, and if that
code's complexity isn't managed carefully, it grows unwieldy.

And any time that you extract code that does business logic from code that does
IO, the system gets simpler to understand and easier to test. I have a hunch it
also makes the result less faulty, though I have no data to support that.

That's what I'm going to be talking about in Part 2 - the true enemies of
programming that Haskell has unmasked for me.


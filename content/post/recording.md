---
title: "What I Learned from Recording my Coding"
author: "Russell Waterhouse"
description: "What I've Learned and What I'm Changing"
tags: ["", ""]
date: 2023-12-13T20:56:50-08:00
draft: false
---

# What I've Learned from Recording Myself Coding

Recently, I read [this article](https://danluu.com/p95-skill/), 
talking about how the way to become better, if not one of the best, at
any skill. I agreed with some of the article, and disagreed with some of the 
article. If nothing else, it got me thinking about how I'm trying to be a
better engineer. In the article, the author talks about recording yourself
while working on your craft, and using this recording as a way to make your 
mistakes easier to spot and correct. 

So, always looking for a new way to be a better developer, I've decided to 
give it a try. 

## The Experiment
The setup for my experiment was fairly simple. Screen record myself coding
for an hour, and watch it back at 2x speed and take notes on my observations.

## My Thoughts on Watching Back
In my first recording, I was working on a piece of ruby code that did some text
processing. Here are my thoughts: 

1. TDD is a win for tasks like this. 
- For tasks like this (text parsing and string manipulation), especially that
  which has very little or no other IO (like file IO, network calls, etc), I've
  found TDD to be a massive win. Watching this recording, I feel I can confirm
  what my gut was telling me about that. With this particular task, there are a
  lot of very small details and edge cases that need to be correct. I can see
  in the recording that I'm using these test cases to make sure that my code is
  correct, and it gives me a very tight feedback cycle. 
2. I should know the string manipulation libraries much better.
- For a big chunk of this recording I struggle with a few different string
  manipulation methods, because I started off using the wrong one. This is why,
  for whatever language you use, you should know the language AND the standard
  libraries. For me, this is difficult. As a glue engineer at Leanpub, I
  work in Ruby, TypeScript, Python, and Haskell. That being said, in the
  new year I plan to be doing some deep diving into the standard libraries
  of all of these languages, plus C++ (because I want to write more C++).
3. I should know how to type numbers faster. 
- The difference between me typing just letters and me typing letters, numbers,
  and punctuation is kinda comical to watch. I go from nearly 100wpm for just
  letters down to probably 50 for letters, numbers, and punctuation. In the new
  year, I'll have to spend some time practicing that specifically.
4. Vim Motions was still a good choice. 
- I'm blown away by the speed at which I can edit text with vim. I learned vim
  motions in 2021, and that was a great investment. I would like to find a way
  to continuously learn new motions though. For example, only this year have I
  learned Vim Marks, which is a great way to navigate. Perhaps I'll have a
  "what I'm learning this week" blog post up with all the things that I'm
  learning, and add a vim motion to it each week. 
5. I need a way to record thoughts when I have them in an organized way for
later.
- In the middle of this, I find myself googling "Why do my ruby specs take 15
  secons to load". While that question is worthwhile to answer, that's not what
  I was doing at the time. I would find it easier to focus on what I'm working
  on if I had a really solid way of capturing thoughts like that. I'll add that
  to my "investigate in 2024" list.
6. Copilot is still a win
- As much as I don't want to admit this, github copilot is a win for me. I
  mostly use it for when I need to write comments, test cases with similar
  structure, or other boilerplate. It writes very little production code for
  me, simply because I find it's really not that great at that. However, making
  boiler plate go away with just the type of a tab key very efficient, and it
  really shows in the recording.
7. Silly mistakes don't actually take up as much time as what I thought. 
- While recording, it feels like I took so long to notice a really obvious bug,
  but in reality it actually only took me 10 minutes, and I fixed 3 other bugs
  and wrote an extra test case also in that 10 minutes. Actual time trying to
  figure out that one error was actually probably only like 2 minutes. I would
  have thought that took so much longer.
8. Getting good with regular expressions makes me a text-processing powerhouse
- Somewhere in the last 2 years, I've gotten really good with regular
  expressions. There was a fairly niche regular expression bug in my initial
  implementation of what I was working on, and I found and fixed it in the
  matter of 10 seconds. That was worth learning, and like vim, I should invest
  a little more time into maintaining and growing that skill, because the
  initial investment is paying dividends.
9. Watching more of these recordings can show me where and what kind of
mistakes I usually make.
- By the end of the recording, I pretty much have all of my tests passing and
  the kinks worked out of my code. However, watching the recordings I can see
  exactly where and how I introduce bugs. For example, in this recording at
  35:14 I extract a method, but do it sloppy and miss half a line in a
  copy-paste, and forget to update 2 variable names. I wouldn't notice and fix
  these 2 mistakes until they are caught by unit tests and debugged by 42:00.
  That's not the only thing I did in that time, I also wrote a unit test and
  fixed a different issue, but the point still stands that if I know exactly
  where I make mistakes, I can avoid them while I'm doing them instead of
  catching them a few minutes later.


Overall, this was a really good exercise, and I plan to do it more often.

## What I'm Changing as a Result of This Experiment

1. I'm going to do this exercise more regularly, as I feel I got a lot of use
out of it. I also feel like if I can watch myself make the mistakes in
the recordings I'll be better at catching myself when I'm making them on the
job.
2. I'm going to re-invest in some of what was really useful to me. In 2024, 
I'm going to dump some self-development time into going deeper with 
vim motions and regular expressions, because those initial investments I made 
are already paying dividends, and we love to bet on winning horses.
3. I'm going to spend some time with memorizing the standard libraries in 
the languages that I work with all of the time.
4. I need to find a place to record thoughts that need to be dealt with later, 
not when I'm in the zone.
5. I need to spend some time practicing typing numbers and curly braces, and 
get that as fast as the rest of my typing.


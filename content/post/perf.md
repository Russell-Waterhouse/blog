---
title: "Performance Testing"
author: "Russell Waterhouse"
description: "description here"
tags: ["performance testing", "resource measuring"]
date: 2023-09-01T15:00:08-07:00
draft: false
---

# How to do Performance Testing

In this blog post, I'm going to go in-depth into how to do performance testing
on your software.

## What is Performance Testing?

Performance testing is the act of measuring some aspect of your code. It 
usually falls into measuring one or more of the following categories:

- Runtime
- Memory usage
- CPU usage
- Footprint (size of compiled binary or bundle)
- Time to serve requests

## Why do Performance Testing?

The first question you should ask yourself is why you're doing performance 
testing at all.  There are usually 3 really good reasons to do performance 
testing.

1. You are experiencing a bottleneck somewhere and you need to figure out where.
2. You are comparing 2 approaches to solving a problem and need to know which one is 
more performant.
3. You are learning how to do performance testing.

Each of the 3 above require different approaches, so I'll break them down
in their own section below.

## 1. Our Code is Using Up Too Much Resource X While it's Running

Your code is taking too long or using up too much memory or taking up too many
CPU cycles.  It needs to be optimized in some way.  Your path to success is 
as follows:

1. Use a profiling tool to measure your code as it runs in either the production
environment or as realistic of a simulation for it as possible. 
2. Using this profile output as your map, create a benchmark around the 
use case that you intend to optimize. 
3. Run your benchmarks to get a full "before" measurement of what you intend to 
improve.
4. Make performance optimizations to the target section of code.
5. Run your benchmarks again to see what effect your improvements had, if any.

Note that I said benchmark there, not micro-benchmark. Micro-benchmarks
often lie because they do not cover enough of the conditions that your code will
be expected to perform under in the real world. Maybe the data structure that
you created is quick to create, but takes a long time to traverse. Maybe 
you never create enough memory in the micro-benchmark to trigger a garbage
collection event. When creating a benchmark, make sure to exercise the code
path under multiple conditions for this exact reason.

As an aside, if you want to see a really good example of micro-benchmarks lying
you can find a youtube video about it 
[here](https://www.youtube.com/watch?v=PHvbLmLPX6s)

Profiling your code will probably look different in every language, and some 
will be much easier than others. However, I have compiled a list of profiling
resources for different languages and environments below:

1. Python: 
2. Javascript
3. C
4. Haskell
5. Ruby
6. Java

I'll dive deep into how to do the benchmarking part of this in the next 
section below.

## 2. I Need to Measure the Difference Between 2 Different Implementations
//TODO: Benchmarking goes here

### 2.1 Runtime
### 2.2 Memory Usage
### 2.3 Footprint
### 2.4 Request Service Time


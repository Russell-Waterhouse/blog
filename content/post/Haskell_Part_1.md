---
title: "Haskell Tutorial Part 1"
author: "Russell Waterhouse"
description: "A brief introduction to a series of posts teaching those new to Haskell and functional programming about the paradigms and concepts needed for success. "
tags: ["Haskell", "Functional Programming", "Tutorial"]
date: 2023-02-16T13:30:06-08:00
draft: False
---

# Haskell Tutorial Part 1: Introduction to the Language and Concepts

## Part 1: What is Haskell?
Haskell is a general purpose programming language, like Java or Python. It is compiled, 
often with the GHC compiler, and like Java, it has strong static typing. Unlike Python or Java, Haskell follows a Functional Programming paradigm, but more on that in Part 2. 
Haskell is also lazy-evaluated, meaning that any code that isn't needed for a return value in a function is never evaluated. 

## Part 2: What is Functional Programming? 
Functional programming is a paradigm all its own. Other programming paradigms of note are Object Oriented programming seen in Java or procedural programming seen in C. 
In object oriented programming, pointers are replaced with object references that encapsulate both some internal state and the operations that can be applied to that state. 
In functional programming, mutable state is replaced with "pure functions," functions that always produce the same output given the same input, and tend not to have any 
"side effects." When functional programmers talk about "side effects," they're usually referring to effects seen in the real world, such as network calls, writing to a database, 
or updating a file.   
There are other notable features of functional programming, such as treating functions like any other data type, in that they can be passed as parameters to functions or 
returned from functions. This is known as treating functions as "first-class citizens."  
There are a lot of features of functional programming, but they all stem out of this paradigm of using functions instead of mutable state. 
Later in this series, we will dive deeper into the hallmarks of functional programming, but for now you get the idea. 

## Part 3: Why learn Haskell? 
Learning Haskell forces you to think about programming in an entirely new way, and in my opinion, makes you a better programmer. In my eyes, it is far more worth 
learning Haskell and seeing programming in a new way than learning another programming language that uses the same paradigm you are used to. 
  
  
With that, let's jump into it!


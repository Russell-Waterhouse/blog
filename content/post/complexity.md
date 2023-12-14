---
title: "The True Enemy of Developers"
author: "Russell Waterhouse"
description: "Everything I've learned in my time as a developer"
tags: ["", ""]
date: 2023-12-08T13:28:36-08:00
draft: false
---

# OO vs. Functional, JS Frameworks vs. HTMX, and the Issue Under It All

Now, that may look like a clickbait title, but clickbait is only bait if I
cannot deliver a comprehensible blog post that encompasses all of these, and
does it in a satisfying way. Without further ado, here it is. 


## OO vs. Functional Let's start with the OO vs. functional debate.

I have written production code in Haskell, Java, Kotlin, Python, Ruby, SQL, and
TypeScript (in alphabetical order). Since I'm one of the 4 worldwide developers
that have written production Haskell code, I'm uniquely suited to have opinions
here.

I have seen and written good production code that is a pleasure to work with in
all of the above languages.

I have also seen and written bad production code that is horrendous to work
with in all of the above languages. 

The paradigm of each language did not affect how much I liked or didn't like
working with that code. 

Once you get used to it, a language is a tool and a programming paradigm is an
aspect of that tool. I can write programs in Java or Haskell or Kotlin, and
they'll all do the same thing, more or less. 

No, what I found that makes the difference in how much I like that code is how
much complexity that code has to handle and how well it handles it. 

I want to point out someting important to me in that last sentence. I did not
say "how complex the code is". I said "how much complexity the code handles and
how well it handles it."  That's a VERY important distinction. The real world
is complex. Every developer working on anything nontrivial must handle some
amount of complexity somewhere.

I would go so far as to claim that the difference between a hobbiest programmer
and a professional programmer is how much complexity you're willing and able to
handle. 

Not convinced? Let me walk you through a short thought experiment. 

## The Hobbiest vs. The Professionals 

Pretend you're a hobbiest programmer, and
you want to stop using microsoft word because reasons. You think "It's a simple
word processor, I can whip one of those up in a few hours." 

So you flash up your favourite IDE and start tippity-tapping on your keyboard
and a few hours later, you have a text editor that takes text, saves files, and
can produce a pdf.  "Awesome!", you think.  "I've done what all of microsoft
did for me in an afternoon!"  "Not paying microsoft for an Office365
subscription this year."

And if you only ever produce the most basic PDF, you'd be right. But if you
want to add spellcheck, or footnotes, or automatic references, support for
emojis, support for right-to-left languages (someone has to quote that famous
arabic poem, it might as well be you), ultra-high definition images, centered
text, word art, running headers, export in formats that aren't pdf, export
PDF's that work on Ebook readers, or any of the other thousands of pieces of
complexity that Word handles, you would have to put in months or years of work,
depending on how many features you want supported and how well that complexity
will be handled.

Professionals will handle this complexity and sell it to you for a fair price.

## JavaScript Frameworks Vs. Traditional Multi-Page Applications

Since you like my opinions so much, I'll give you mine on something that's been
a bit of a hot topic recently: JavaScript Frameworks.

Over my time as a developer, I've written basic
multi-page applications with python/django, java/spring, and ruby/rails, and
written basic single-page applications with typescript/react and
typescript/svelte. Some of that experience was professional, and some of it
was in small personal projects.

Here's the thing. None of my opinions have been formed by small personal 
projects.

Why?  

Because by definition, a small project isn't complex enough to form a
professional opinion. 

I don't care how good or bad a UI framework is when making a basic javascript
calculator app.  I care how good or bad a UI framework is when building the
next amazon, because that's what we're all out here trying to do.  To know how
something really performs, you need to handle some complexity. 

Have some users and hit some edge-casees and handle it as well as you can, and
then we can compare notes. Until then, I'll withhold judgement.

Not understanding this, I think, is part of the reason our industry has so
many hype trains. 

Imagine you're a senior developer making architecture-level decisions about your
product, with whatever fancy title goes along with that role. You get home from
your job, where you inevitably handle edge-case after edge-case and manage
insane amounts of complexity. You have a little dinner, play with your kids, 
put them to bed, and open up your personal dev environment to the personal 
project where you've been playing around with the newest technology. 
You've been working on this during evenings and weekends for a month, and 
you are loving it. It fits so many of the use cases that your product needs. 
And more importantly, it is SO much better to work with than what you did today at work.

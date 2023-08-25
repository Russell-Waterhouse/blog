---
title: "Path_to_good_code"
author: "Russell Waterhouse"
description: "description here"
tags: ["", ""]
date: 2023-08-24T12:13:22-07:00
draft: false
---

# The Path To Good Code (August 2023)

While I may not have 30 years experience, I have seen and written enough code
to have developed opinions on what is good and what is bad. I have also 
observed that some policies tend to lead to good code and some tend to lead to 
bad code. With this article, I want to cement some of my opinions on this in
writing. I don't believe for a second that everything I write here today is 
what I'll believe this time next year, but I do believe that writing down 
everything that I think right now is a worthwhile exercise. 

With it written down I can catch myself straying from the path easier, and 
I can also more clearly realize when something doesn't work. Also, articulating
my thoughts is always a good idea.

As an aside, isn't it amazing that we haven't settled on what is good in 
our industry? I wonder if civil engineers building hospitals or mechanical 
engineers building cars have endless discussions about whether the industry 
standard practice for 20 years is actually an anti-pattern the way we do 
with inheritance in OO programming.


## What is Good Code?

Of course, we can't define what leads to good code without first defining what 
good code is. As much as the engineer in all of us wants clearly defined 
requirements for every feature and service we build, the real world rarely gives
these to us. Thus, we work with what we have. I cannot possibly 
describe good in a way that will cover all use cases without generalizing a bit,
so here is my generalized list of desirable code attributes (in no particular 
order)


### 1. It Should Work

I know, I know. This should seem obvious. But for me, it's the most important.
I will take unmaintainable, unclean, inefficient, abstract, dirty, horrendous
code that works over the most maintainable, efficient, perfectly abstracted, 
beautiful code that doesn't. 

Do you know why this is? Because clients want this too.
I don't run arch linux anymore because my USB drivers broke during the 
University of Victoria Engineering Competition, meaning that I couldn't program
our robot on my laptop (all our code was uploaded to the cortex via USB). 
Now naturally, me and my team had 5 spare laptops. 
We still finished first place, and we still went on to compete in the 
Western Engineering Competition. For most of it, I actually helped out on 
mechanical building a big gearbox because that was taking up more time and there 
were many skilled developers on my team. This 'disaster' was totally recoverable.
It had no real-world consequences. Nobody lost any money, nobody got hurt, 
nobody even suffered any consequences, real or imaginary.

However, I couldn't trust my system anymore. So 2 days later, I was running 
Fedora Linux. 

Any code that doesn't work is the worst code.

There are very rare exceptions to this that I would accept. 

1. This is exploratory code, and not deployed to consumers.
- Send all the broken code here that you want. A good 3-day code spike is worth
about 10 days of planning, in my experience.

2. We are doing something so cutting edge that we actually can't predict what can
go wrong. If things go wrong, we can code a fix and redeploy before any real-world 
harm is done.
- I get it, and I think a lot of us dealing with integrating new AI systems 
or on other cutting edges also get it. Be careful, still do your research, 
don't fail because of things you can control, like null pointers or not
error handling request timeouts correctly, but once you've covered the bases
that you know, send it out and see what sticks.

That's it. I think any other time your code should work. 


### 2. It is Maintainable as Possible (from a code perspective)

Unfortunately, this one might require some hand waving to nail down, but stick 
with me.

I define maintainable to be the following: 
```
A competent Junior Engineer, familiar with data structures and algorithms, but unfamiliar
with your language, framework, libraries used, and code base, should be able to get set up and 
push 1 (one) bug fix in their first week with little to no help from senior 
engineers. 
```

Notice that I didn't say SOLID, or Bob Martin's Clean Code, or maximizing use of
pure functions, or completely covered with unit and integration tests,
or anything else that attempts a more hard and fast rule of what is good or bad.

I said that a competent junior engineer with no context can be effective in 
their first week on the job. 

I don't say that because I think SOLID is bad to live by, or that Clean Code is 
outdated (Indeed, I believe SOLID to be generally good advice, and I will always
love clean code if for no other reason than that I read it during my first co-op
and it introduced me to the idea that there was good code and bad code and that,
with practice and discipline, we can create more good code. 

Take, for example, some code that I wrote a few years ago in my second year 
of university as an example: 
```
TODO: Insert code example from Kotlin app here that follows solid but is dogwater
```

### 3. It is Maintainable as Possible (from a deployment perspective)
//TODO: Is this necessary? I want to talk here about "will something that this
app depends on be here next year? Next 5 years? Next Decade?"


### 4. It is as Secure as Possible

### 5. It is Performant as Necessary

Some code needs to be performant, and some does not. Most exists somewhere in 
the middle. I can't tell you how strict to be with performance, I can, however, 
tell you that you should have a working version and a performance test telling 
you that you need more performance and where to put that performance optimization before 
you start optimizing for performance.


## What Produces this Magical 'Good Code'

I've noticed some things produce good code, and some don't. In no particular order,
here is what DOES produce some good code.


### Refactor When You're Annoyed

I have recently found that any time I find myself annoyed, I will do refactoring
until I'm no longer annoyed, then I will implement my feature or fix my bug. 
This means that I am usually working in something that I understand and find 
agreeable.

For bigger refactorings, I'll usually ask my team first. A simple
"Hey this module has been bugging me, I'm thinking about refactoring it to X instead
of the current Y" in the slack channel for large refactorings is usually a pretty 
good gauge of whether or not it is actually a good idea.

"That would make this so much easier, especially for feature Z that we're doing next month" -> DO IT  
"I'm not sure that would be better, Bob tried 3 years ago and it didn't go well, go talk to him" -> Probably don't (depending on what Bob says).

For little refactorings, just do it.

### Have Someone Versed in Security Audit your Project
// TODO: 

### Unit Test Pure Logic

### Have a Good Local Testing Environment

## What Produces 'Bad Code'

In no particular order: 

### 1. Fear-Inducing Deadlines

Developers scared of a deadline will often not go back and refactor,
won't think about performance, won't thoroughly test, and won't make good 
engineering decisions.  This is the fastest way I have seen to create bad code.
I'm not saying that there isn't a place for deadlines, there is. 
Stakeholders should be able to plan around promises that we make to them.
However, the big fear-inducing looming "do it or you're fired", or worse, 
"do it or the company goes under" deadlines are a bad strategy every time.


### 2. Premature Abstraction
I'm not too sure, but I think that abstraction should be 
done in the refactor or the re-write, not the initial writing.  
The reason I think this is that it is VERY easy to pick the wrong abstraction.

It's very easy to pick inheritance when composition will show to be right in 3 
months. It's very easy to 

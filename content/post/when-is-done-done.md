---
title: "When Is Done Actually Done?"
author: "Russell Waterhouse"
description: "What is 'good enough', and what is not? I'm going to explore how I draw that line."
tags: ["softwareengineering", "engineering"]
date: 2024-01-07T11:34:19-08:00
draft: false
---

# When is Something 'Good Enough'?

I introduced my last blog post with a short story, and I really liked how
that felt, so I'm going to do that again here. 

## A Short Story to Illustrate the Question

### Story 1: Hanger 
Imagine that you've gotten home from a long day at work. It was a long and hard
day, with many fires to be put out.   
You're tired.  
You're greasy.  
You're hangry.  

It's 9:30pm, and you haven't eaten since lunch at noon. You had planned to
go grocery shopping after work at 5, but that just wasn't in the cards today.
The grocery stores close at 10:00pm. Do you?

- A) That freezer pizza you keep for just such an emergency?
- B) A 3-course feast with pork roast, tossed fresh salad, homemade salad dressing, and pumpkin pie?


Of course you eat that frozen pizza, because that's what the situation calls for. 

Sure, you could have done "Better." You could have had the home-cooked meal with
vegetables, homemade salad dressing, a little red meat to keep your iron up, and
some dessert for the soul. It would be healthier and tastier!

### Story 2: Royalty Visits
Imagine that you've somehow managed to convince the King of England to come to
your place for dinner. If it goes well, you're going to get a position as one 
of his aides. It's a good position that pays millions of dollars a year 
(remember, I said imagine). You've known that this dinner is happening for 
3 months, and you've had all that time to prepare. What do you serve the King
of England? 

- A) That freezer pizza you keep for just such an emergency? 
- B) A 3-course feast with pork roast, tossed fresh salad, homemade salad dressing, and pumpkin pie?


Of course you do up the pork roast. The King would not be impressed with freezer
pizza, no matter how catchy the commercial jingle was. 

Sure, you could have done "Better". Freezer pizza is so much Cheaper!
And faster! And Easier!

## The Question: Resource Allocation
There are several questions here, and I'll try to boil them down.

What is considered "Good Enough"?
What is considered "Better"?
What is considered "Too Costly to Implement"?
What is considered "Too Costly to Do Wrong"?

Usually, when I'm working with this problem day-to-day, the question looks 
something like this:

*What problems require you to go the extra mile, and what do not?*

That's the question of Resource Allocation and Prioritization.

So how do we effectively allocate resources, and more importantly, how do we formalize it in a
way that we can explain others. Throughout my career, nobody has explicitly told me this,
and often just yelled at me when I got it wrong. I hope to prevent that from befalling
any other new engineer in the workforce.

The answer is simple, and the answer, like always, is that of cost.

## What is the Cost of Delay
I'm going to introduce you, dear reader, to the concept of "Cost of Delay".
Cost of delay is simple to understand, but widely applicable. Cost of Delay is
simply the cost that the organization occurs to NOT do something this week.

If the cost of not doing something is zero, then we probably shouldn't put a lot of
resources into doing it. If the cost of not doing something is millions of dollars,
then we should probably do it, and do it before anything that only costs us hundreds of
dollars to not do.

Now you might be wondering why we calculate the cost of delay instead of the expected net present
value or something like that. The answer is simple: things that we must do for compliance, or to keep
customers from leaving, have a low expected net present value, but have a massive cost that should be
considered. For example, doing a lot of QA on a new feature that you're building to make sure that you've
not introduced any regressions has a very low expected value, but it prevents customers from leaving your
service because they think that it's unstable.

Now, let's apply this to the scenario that I've laid out above.


## Applying the Cost of Delay to the Scenarios above

Let's start with scenario 1, shall we? 

### Story 1: Hanger

It's late, you're hungry, whatcha gonna do? Let's look at it with the cost of delay metric!

What's the cost of freezer pizza? Well, about 5.99 in immediate price, a tiny, nearly insignificant cost to 
your health, assuming that you don't eat a freezer pizza very often. 

What's the cost of delay of the freezer pizza? Well, let's assume that if you don't get a good night of 
sleep, you'll be in a worse mood, putting you at a 5% chance of getting fired and a 35% chance of quitting. 
Suddenly, the cost of not doing that freezer pizza became 40% of your salary (Yes, I know that both my 
math is wrong AND that this is a little ridiculous, but the point still stands.) 
This freezer pizza is DEFINITELY worth doing. 

What about the alternative? 
That 3-course feast with pork roast, tossed fresh salad, homemade salad dressing, and pumpkin pie?
The cost of doing a really good meal is, say, $100 and your time to prepare it, which we won't count. 
The cost of delay is pretty much zero. There is no meaningful reason that we should put that much effort into
this meal that we wouldn't get by putting that much effort into a meal next week.

So, we conclude the same as our gut told us when using the cost of delay: we should eat the freezer pizza.


### Story 2: Royalty Visits

Your networking has finally paid off and you have a dinner with royalty! How exciting!

The costs remain the same as before, but the cost of delay has changed. 

There is no urgency forcing us to get a meal and go to bed anymore, so the cost of delay of the freezer
pizza is zero. 

But the big fancy feast? The cost of delay of that is the position as one of the King's aides. That position that
was going to pay you millions of dollars a year in a secure and cushy position.
The cost of losing that position is massive. Even if the fancy feast only has a 10% chance of convincing the King
to give you that position, the expected cost of 10% of millions of dollars in salary is worth that $100 cost.
Make that meal!


Again, the cost of delay metric gives us the same solution as our gut did: we should make that big meal and get
that big cheque!

### A More Realistic Scenario
"But Russell!" I hear you screaming, "Those scenarios are ridiculous, and you just made them up to serve a point and to look good!"

And to that I say "Yes, yes I did."

But I understand that you want something more realistic, so let me walk you through a scenario 
that you might come across in your day job as a developer.

Say there's a ticket that says that for a small portion of my user base, say ~3%, my service is producing 
corrupted files that cannot be read correctly.

Let's say I was given this hypothetical ticket. I diagnose the problem quickly, and produce a patch 
that appears to fix the problem.

Now, I have some decisions to make.

How much time should I spend adding comments to this code?

How much time should I spend documenting this code change?

How much time should I spend doing manual QA of this code?

Let's break down the costs and the cost of delay!

Remember, this is a patch that appears to work for a bug that is active in production systems and affecting a small subset of our users.
Also, let's say this is a surgical patch, ~6 lines of code or so. Not a big change.

The cost of adding comments to code before shipping is nonzero, but the cost of delay is zero. Those comments can be added 
after we have shipped and fixed the problem in production. I don't believe in that "if you don't do it right away you won't ever
do it" line. I go back and add comments to code that I worked on that was urgent afterwards. If you're not disciplined enough to 
follow through with that, maybe you would do this math differently. 

Thus, I add the comments in a separate PR that I do after the patch was live in production systems.
It is much the same story with the documentation.

Next, manual QA. The cost of doing enough manual QA such that I was reasonably confident that we aren't breaking things worse
is about an hour of my time with this patch. As a side note, while we do have automated tests that run in our deploy pipeline,
I have yet to work at a company where the automated tests caught 100% of all bugs that would have reached users, and thus consider
a good round of manual QA by the developer to be a professional standard. However, the cost of not doing that QA pass could have
been releasing bigger and worse bugs to our users, and the cost of that could have been incredible amounts of lost revenue from
angry users leaving our platform.

Thus, I did the QA before I deployed that patch to production systems. The cost of delay of that QA was way higher than the
cost of doing it, even though it was fixing a bug that was active in production. The cost of introducing more bugs would have
been higher.


## Conclusions

Hopefully this mental model helps you answer a lot of those tough questions. Also, if anyone asks you why you did or 
did not do something, you can explain your mental model and reasoning to them. This is especially useful with managers.


---
title: "Ai_for_non_programming_decision_makers"
author: "Russell Waterhouse"
description: "description here"
tags: ["", ""]
date: 2026-08-11T19:20:24-06:00
draft: false
---

# AI And Programming Explained To Those Who Don't Program

Hello! T'is I, the nephew you call when your email stops
working!

There's this thing that's been in the news a lot lately, AI.

A lot of things have been said about it. Most of them aren't really true.

I want to explain some of it to you in a way that neither babies you nor
overwhelms you.

## DISCLAIMER

First, a quick warning. In this article, I'm going to talk about the finances
of AI and the companies involved in it. THIS IS NOT INVESTING ADVICE. Indeed,
if you took my words as investment advice, you would have done terribly in this
raging bull market. You make your investment decisions by talking to a
professional who has a feduciary duty to you and your money, not by reading
some dude's blog on the internet, got it? Good.

Second, a quick note to my fellow tech people. If you know what TCP stands for,
or if you know what a compiler is, this article isn't for you. I'm going to
simplify a lot for the common computer user. I'm not going to talk about the
differences between interpreted languages and compiled languages and how JIT
can kinda make one work like the other. I know all of this, but the target
reader of this article doesn't, and doesn't need to. I'm just going to say the
computer can read code and move on, because that's what this reader needs to
know. This isn't written for users that have an opinion on the difference
between Chrome or Edge. This is written for the user that thinks both the
colourful logo and the green/blue logo can go to Facebook and Email.

Ok, let's go!

## So, Why are We Talking About This?

Well, two reasons. First, everyone is talking about it in tech and finance. They
haven't stopped talking about it since 2023. Don't you want to be one of the cool kids talking
about the cool topics? Second, and more importantly,
this little tech and finance fascination has grown so much bigger than you could know
unless you're very plugged in. It has grown so big for so many reasons. Some I understand,
and some I don't. But it has grown bigger than the fundamentals of the technology
can support. To me, and many of my peers, it looks like a gargantuan bubble that
is set to pop. I want to give you a peek behind that curtain for how we got
here and how everyone got it so wrong. 

## The Scale of The Bubble

// TODO


## AI For Programming

## What Programmers Actually Do

At the heart of it, we, the people that put the pixels on your screens usually
work like this:

1. Someone tells us what a computer needs to do, at a high level.
2. We decide what that means in great detail.
3. We write down those decisions as instructions the computer can read (this is code).

Here's a quick example.
1. Our boss tells us "when the user clicks the 'like' button on Facebook, the button should turn blue."
2. We decide that means that:
  1. We turn the 'like' button blue immediately so the user gets instant feedback.
  2. We start saving the fact that the like button was pressed, so we can show other users the correct number of 'likes' on the post.
  3. If that save fails, we turn the like button back to the colour it was, and send a message to one of our engineers letting them know the save process is broken and they should look into it.
3. We write the code to make the above three steps happen, in that order.

Now of course, it's more complicated than that in real life, but this paints a
picture we can work with, so we're going to roll with it.

### What the Boosters Promise

The boosters promise that with AI, you'll
be able to tell your AI agent,

"when the user clicks the 'like' button on Facebook, the button should turn blue."

and your agent will go off and write and deploy
the correct code.

No need to hire programmers, no need to fuss.

### Why that Doesn't Work

This doesn't work because there's actually a lot
that "turn the like button blue" could mean to an AI.

If the AI is really braindead that day, it might literally
just turn the button blue and never save the fact that you
liked this post. They're not usually this braindead, but every
once in a while they are.

However, the AI might start the save process and wait for it to finish
successfully before turning the button blue, which might offer a worse
experience to the user, who wants instant feedback knowing the button
press was registered.

And the AI often will not write the code for "if the save fails, do X."
That means that every time the save process fails, nobody knows.
If the save process works 100% of the time, there's no issue.
In the real world, nothing works first try 100% of the time.

Maybe the AI will decide that if the save process fails, it should just try
again until it succeeds. That means if your save service goes down
for a few minutes, when it comes back up, it will immediately be hit
with every single save request that happened in those few minutes all at once, because
all of those users' computers are constantly retrying the save. 

If the AI didn't design the servers to immediately scale to this kind of load,
it will end in more downtime.

This is a trivial example, and already there is more complexity
than the average non-programmer would have thought.

Now, there are more reasonable ways to use AI.

A programmer might give their agent a detailed design document
explaining all the nuance and more about what this feature means and how
to implement it, then check the output code to ensure the AI agent
actually followed the instructions. 

But remember, that's far smaller of a market than what the boosters
are promising, and it's far smaller a market than the scale of the investment
needs in order to pay off. It also doesn't replace programmers, because
someone who understands all the nuance about retry logic and error
handling still needs to be the one making the design document. 

It also doesn't offer incredible speedups in writing code,
because the time to make all of those decisions is larger than the
amount of
time it takes to actually write it all down.

If the boosters had said "For programming the technology
will make small trivial things instant and big expensive things
5-25% faster," and everyone had invested into the technology
with this in mind, there would be no bubble. The fundamentals
would match the investment, and I wouldn't be writing this post while
on vacation. 

This is not what has happened. 


## The Metaverse, Crypto, Growth, and Tech Thought Leaders

So naturally, you might be wondering, "why does this random developer on
the internet think he knows more than all these brilliant CEO's. Surely
the people running these giant companies and their boards and their
investors can't all be wrong at this scale."

I wish you were right. I really do. 

Surely, some don't believe it. Some are just playing the game, saying the right things
to make their stock go higher in a frothy bull market.

But some of these CEO's have spent more money than these companies have ever invested in
anything betting that this wins.

And it's not the first time CEOs and investors and boards have invested big and lost
it all. 

Remember a few years ago when everyone was saying BitCoin would be the
new money? Nobody checked how long it takes on average for a transaction to
settle. The average is thirty minutes per transaction, and it's not guaranteed
the transaction will ever settle.

Maybe you've heard people say "crypto won't be the next dollar, but it
will be the next gold. It will be a durable store of wealth."

Imagine if, on a beautiful day in June of 2016,
someone stole over 4% of all of the world's gold.

Then, in response to that, everyone that had gold or knew about gold
disagreed one what to do: return the stolen gold, or ignore it.

The solution they finally came up with was to announce gold 2.
Everyone that had one ounce of gold before the big theft happened would get one
ounce of gold 2. 

You might very well look at gold and gold 2 and say,
"This is clearly not how I want to store the funds that I plan to
use in retirement, it doesn't seem that this is reliable enough for
me to rely on it."

But that's what happened to Etherium,the number two most well-known
cryptocurrency in the world, behind bitcoin.

You might look at all of this and say "it would be
foolhardy to sink __ billion dollars into building a
virtual world for everyone to use that would run on this
cryptocurrency and rename my company after this
new virtual world. There would be no chance at a return
on investment of that __ billion dollars."

But that's what the Metaverse was. The metaverse, a project that
Meta, formerly Facebook, invested __ dollars into, and last month finally
killed, after earning __ dollars on their investment, for a net loss
of __ dollars. 

To me, that was also ovbiously insane at the time of the
peak.

I actually took the blockchain and cryptocurrencies course
in University because I thought there MUST be something
I was missing. How could this thing that looked so insane
to me possibly be this big? Surely I was missing something.

I wasn't, and the more I learned in that course, the worse it looked.

My final essay was actually a detailed technical explanation of why
cryptocurrencies couldn't possibly live up to the expectations.
it earned an 89%. 

## What? How?

If your head is spinning, and you're wondering how the hell
all of this has happened, and how nobody ever bothered to mention it,
good. That was the point of this article.

But I don't want to just leave you dazed and confused. I want to
try to explain how the hell we got here. 

This is going to be difficult. Details will be missed.
I'm going to try to weave together enough threads that
you can see the picture in the tapestry, and this is where
talk of tech will fade into talk of finance of tech.

Since computers were invented and have become widespread,
tech companies have been making so much money
building things on computers that are so much more efficient
than their pre-computer equivalent.

Apple, Dell, IBM, Lenovo, AMD, Nvidia, Intel, and many others have made a
killing selling computer hardware.

Microsoft has made a killing selling services for Email (far more
efficient than real mail), Excel (far more efficient and powerful
than doing everything that excel does with pencil and paper),
word, powerpoint, etc.

Amazon, google, and Microsoft have made billions renting servers
to every other internet company through AWS, GCP, and Azure.

Amazon has made a killing doing the more efficient version of what
Sears and Etons used to do with catalogs.

During the time of these companies' growth, anyone who
invested in them made a ton of money. 

Since there was money to be made, startup funding
started getting big.

Now despite what you might expect me to say here, startup
investors aren't stupid. They know that there
are too many factors influencing who wins and who loses
for them to pick winners 100% of the time. They know that
if they invest in 100 companies, 80 might fail, 18 will turn into
successful companies, and 2 might turn into companies so big that
it makes investing in the 80 failed companies totally worth it.
They also know that if 3 get that big, they all get a bonus
so big they never have to work again.

Because this is the nature of what they're doing, anyone
that approaches them and says "I want to start a business that will
grow at a healthy pace and be a profitable company worth running,"
HAS TO BE IGNORED. 

A startup that says this has a zero percent chance of turning into
the behemoth success that will make their portfolio profitable.

They can ONLY make these bets on startups that promise to
become the next Uber or Facebook. These startups have that 1%
chance of making their portfolio beat the market, and that's what they need.

So anyone running a startup that needs investment has
to make big claims about their total addressable market.
They get no funding otherwise.

The equity markets drive the big companies into
outlandish things too. All of the Mag seven, even before the
AI hype wave started, were valued as growth companies.

Were they to show persistent signs that they were no longer growing,
equity markets might decide that they should no longer value these
companies as growth companies. Boards and current shareholders
would not appreciate that. This puts large pressures on the
executive teams of these companies to continue to show
growth and investment into projects that could feasibly grow.

The metaverse makes more sense as an investment when you
understand that every time Meta's exec's dumped more money into
the metaverse, their stock price went up. //TODO FACT CHECK THAT

And when none of the people investing in this technology
and the executives running these companies aren't trying to write
production code with them (because they're running investment firms or
running companies, not programming. They're doing their jobs).

When someone tells them that it's going to be the next big thing,
and it sounds exactly like what Jeff Bezos said when he said Amazon
would be huge, they think that they have found the next Amazon.

And then, if they try to do their owm research and sit down with it,
when they try to program with it, the like button from
my example before turns blue. It looks convincing. 

And all of a sudden, the bubble starts to make sense.

Except for one thing. 

"If all of this is so obvious to you, Russell, the
writer of this blog, why aren't all the programmers
flooding the media with this opinion."

And there's a few reasons for that.

First, none of us started multi-billion
dollar companies, so we don't exactly get the
same airtime as the CEOs do. Elon Musk can call
ip CNBC and get airtime that afternoon. I can't.

Second, many of have been. TODO EXPAND

And third, many of the people that claim to be
programmers just aren't that good. This isn't a
regulated industry. All you need to do to be a programmer at
Amazon is to convince the recruiting team at amazon
that you can write code at Amazon.



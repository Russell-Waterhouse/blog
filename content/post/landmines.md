---
title: "Landmines"
author: "Russell Waterhouse"
description: "A Guide Through The Minefield For Future Generations"
tags: ["AI", "OOP", "FP", "DVORAK"]
date: 2026-08-11T18:40:42-06:00
draft: false
---


# Landmines, Landmines, Everywhere

Hello, reader from the future! Why is my proverbial leg gone, you ask?

I've lost it, you see; I've stepped on many of programming's landmines.

Programming, as an industry, is strangely religious. For something that was
supposedly backed by "computer science," there isn't a lot of science to be
found here.

Some of these programming religions are harmless. Some are good. And some
drive you into a minefield, where you will inevitably step on a landmine
and blow off your foot.

I wish someone would have warned me about them, but alas, I didn't have anyone
to do that.

I would like to fill this role for you. Hopefully, my stories of minefields
traversed and my leaky stumps will be enough of a warning for you to avoid
stepping on some of the same landmines I did. With any luck, you'll find
new landmines to step on.

If you want the summary of this article, I can give it to you now. Most
problems in industry aren't that hard. There are no silver bullets. Anyone
trying to sell you a silver bullet has probably downplayed the costs of their
religion. You need a good bullshit detector. If you feel like there's constant
pain with something you're doing, you have probably stepped on a landmine, and
that's an excellent time to stop walking and figure out exactly what turn led
you into the minefield.

You can stop here if you want, or you can keep going to get the details and
more specific advice.

Still reading? Good, you'll do good work in this industry. Reading is good.

## Minefield 1: AI Psychosis

Now, I'll admit, I haven't blown off my leg with this one. But I've seen legs
blown off and I'm missing my eyebrows, so I'm pretty confident this is a
minefield. And looking at how the programming community argues about it, I
think it's a big one.

Here's the most succinct way I've found to describe why this is a minefield:

Programmers do two things: make decisions about what the computer should do,
then write down those decisions in detailed-enough instructions (i.e. code)
that a computer can execute them.

AI is great at writing down instructions that a computer can execute. It will
do it all day long and never complain.

Making the decisions... No. AI isn't that good at that.

Good programmers are making decisions at an incredible pace when they're
programming. They're making decisions about architecture, security,
abstraction, performance, regulatory concerns, maintainability, cybersecurity,
observability, and much more.

I don't think most people know that's what we do. I think there's even many
programmers that don't know that's what we do. But that's the truth of it, and to
offload all your programming to an LLM is to offload all your decisions to an
LLM, and they just aren't that good at making these decisions. Maybe one day
they will be, but not today.

This cult will read my take and say "good luck in your next career."
To them I say, "good luck shipping anything that works when you've outsourced decision
making to the technology that tells you to walk to the car wash."

These people were crypto grifters before AI and they'll move on when the bubble pops.

In healthy quantities, AI can be a useful tool. Just don't offload decision making
and don't go crazy. If you want to see how I currently do that, read this post
// TODO: link post here.


## Minefield 2: SOLID, DRY, Clean Code, OO, Gang of Four Design Patterns

This one isn't a single thing, like AI psychosis, but it's more of a style of
code that is pushed as a somewhat loosely cohesive unit.

This one is tricky because these principles are taught at many respectable
institutions, and they were considered industry standard at one point to large
subsections of the industry (and I think many practitioners would argue these
still are industry standard).

Many developers today only know this cult, and have never experienced anything else.

And as techniques, on their own, some aren't bad. But as a cohesive unit, I've
only ever seen this lead me to a minefield.

Which is unfortunate, because there are not bad odds that if you end up working
in a code base like this, you'll be forced to follow this style of programming
by your team.

In this style of code, everything you work with is an interface. Data is
very tightly coupled to behaviour. Inheritance is used liberally. Methods
are all very short. Gang of Four design patterns are found everywhere. 

Now, because many of these qualities cannot be measured,
and some not even qualified, saying things like
"wading through nine hundred small methods to get the most trivial
of work done doesn't feel very good," is met with a lot of
no true Scotsman arguments. Things like "well if it feels bad you
obviously violated the single responsibility principle" or "you didn't design for
the open/closed principle" get thrown around
on the internet (or at least did, before we all decided to
nonstop argue about AI).

Don't listen to this kind of argument. This flavour of code
leads to too much abstraction, not enough granularity, too tight of
coupling, and a general tendency towards more complexity than is needed.

I'll give two quick examples in Java, because the Java ecosystem
loves this kind of code. 

Example 1: getters and setters.

If you have this code in Java, how should it be called?

```java
class User {
  private String userId;

  public void setUserId(String userId) {
    this.userId = userId;
  }

  public String getUserId() {
    return this.userId;
  }

  public void doThing() {
    Standard.Out.printLine("thing happened");
  }
}

// somewhere else in the program

{
  User user = new User();
  user.setUserId(userId);
  user.doThing();
}
```

Every new Java programmer is taught code like this is
"best practice." That this ensures "encapsulation."

Functionally, it provides no different semantics 
for the user than the following:

```Java
class User {
  public String userId;

  public void doThing() {
    Standard.Out.printLine("thing happened");
  }
}

// somewhere else in the program

{
  User user = new User();
  user.userId = userId;
  user.doThing();
}
```

Yet Java developers that follow this dogma will never write that code,
despite the second version being quicker to compile and/or more performant
(depending on how much your compiler is optimizing and how well your
JIT is working). The first version either has the extra cost that
the compiler has to calculate the function call does nothing and
optimize it out,
or we're doing a function call with every memory access. That's setting up the
stack frame, managing registers, and whatever else a function call entails in
Java. And it's more tedious to write.

Now, getters and setters can be useful.

When a chunk of data needs validation,
a private variable with a public setter is great.
But then, the setter should return an error Option (my preference)
or throw an exception, not ever just fail validation silently.

Second example, here's how I would write a function to send an email
to a user.

```java

enum FromAddress {
  Info: info@company.com,
  NoReply: no-reply@company.com
}

class Email {
  public static Result scheduleEmailSend(String userId, String subject, String body, FromAddress fromAddress, IsoTimestamp sendTime) {
    // schedule email to send
  }

  public static Result sendEmailNow(String userId, String subject, String body, FromAddress fromAddress) {
     // do email send
  }
}

```

That would be it. That's the whole thing. These two functions handle
turning the `userID` into an email address (I'm assuming you've set up access control
so your db tables with PII don’t mix with your tables without PII, right?)
sending the email, logging the results, and everything else it should do.

Because the residents of this minefield are obsessed with
unit tests and, therefore, dependency injection (because you could not unit test this
kind of a function without dependency injection, so you could inject a mock function
pointer that you could then `assert(sendEmail.wasCalledOnce());` in your unit tests)
they would immediately decry this function as not testable.

Not so. You would just test these functions in an integration test.
You call the function, and check that the email was received at the right time
with the right contents. You might not ever run the integration test on your
machine, but you would run it in CI on every deploy.

Of course, the next rebuttal is that integration tests are flaky.

No. They're not. Your code is flaky. Integration tests just show you that.

My integration test suite runs on every deploy and in the last year has only failed
when there is a bug in my code. It runs in CI, and it is slow, and it doesn't bother me
at all because it's running in CI, and while it's running in CI I'm working on my next ticket.

"What if the email service I use goes down!? Then the test
will fail and that's not my fault! There's nothing I can do about that!"

Well, two things.
1. Put some retry and error handling logic in there so your email service returning a 500 doesn't lose your email, you bozo.
2. If your email service is going down so often that your failing tests are causing you deployment issues, it's time to find a different email service. 

Seriously, if YOUR customers aren't getting YOUR emails, that is YOUR problem
to solve. Don't rely on that which is unreliable. Find a better partner and sign a contract.
And when you sign a contract and have to migrate your code, there's only one function to change: `sendEmailNow()`.

"Integration tests don't show you what's wrong with the same granularity that unit tests do!"
Yeah. That's why we have logging and alerting, and far more advanced observability tools if you
want to get fancy.

And on it goes. Every one of the decisions made by this cult is justified with
a statement that just isn't true, or is true but besides the point.

The only statement I will accept from this group is the following.
"yeah, these aren't really the best practices anymore, but the entire code base was written
before we knew that, so best to follow the style and standards that are already there, rather than
add new styles and standards."

Fair enough. Legacy code is our burden, and there is a non-trivial cost to a code
base that isn't cohesive.

I spent a long time in this minefield. Stay out if you can.

## Minefield 3: Functional Programming, Specifically the Haskell Flavour

Now, if you wade around in the OO minefield for a few years, then
one day wake up and realize you're in a minefield, you might do the logical
thing of looking for a map to get out of the minefield and into the glowing pastures of
happiness.

You may stumble, as I did, into the Functional programming cult.
At its core, functional programming makes all of their decisions based on
one core tenet: "most bugs in programs happen because of mutability. Remove mutability
and your programs become better."

Now, at face value, sure, some bugs have been caused by mutability where none was expected.
You can fix this with `const` in js/ts or `final` in Java/Kotlin or not using `mut` in Rust.

But most bugs have, in my experience, been caused by two distant parts of a system depending
on each other in ways that are unclear, or typos, or bad/nonexistent error handling code
or an edge case that wasn't considered. Mutability isn't the problem in most of these places.

But if you assume that mutability is the root issue and const
isn't good enough, you get Haskell. And like the Java example with getters and setters,
you can hack together something with the State Monad that semantically works like a mutable
variable, but now there's countless thunks on the stack and debugging is harder.

This cult does have some merritts. The type system in Rust that everyone loves came from here, for example.
Array.map() came from here, and that's great. I use it all the time.

But largely, this is a mine field. You can write fucked up hard to read too abstract
functional code too. Debugging closures that have been passed through nineteen functions
isn't fun, and if you write enough Haskell, you'll walk into that mine eventually.

Mutable data is OK. Doing IO is OK. Both of those are what we built computers to do.
Trying to fight those only serve to make our jobs harder.

Also, the claims about concurrent optimizations are largely a falsehood.
Using immutable data structures does not automatically mean your program will run in 1/32 the
time on 32 threads. Haskell models data as if time doesn't exist, but time does exist,
and some things happen before other things, and because of that fact, you can't just parallelize everything,
even when your data is "immutable."

I spent quite a bit of time in this minefield too. Again, I would stay out if you can.

## Minefield 4: DVORAK

Not as big of a minefield, but worth mentioning. If your wrists hurt,
you need an ergonomic keyboard, not to learn a new keyboard layout.

Seriously, look at all the symbols programmers type, and then look at
the dvorak keyboard layout, and realize the right pinky is pressing a nontrivial
percent of your programming symbol keys in that layout, and then don't try dvorak.

If you want to type faster, just practice typing faster. That helps far more than
dvorak.

 

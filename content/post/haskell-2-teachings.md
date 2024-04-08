---
title: "Haskell Reflections Part 2: What Haskell Taught Me"
author: "Russell Waterhouse"
description: "A brief overview of what a year shipping Haskell code has taught me"
tags: ["haskell", "functionalprogramming"]
date: 2024-03-29T01:01:47-07:00
draft: false
---

# Haskell Reflections Part 2: What Haskell Taught Me

## Disclaimers

All of my thoughts and opinions here are entirely my own, and do not reflect the opinions of my associates, my employer, or anyone else.

## What Haskell Has Taught Me

In my [last blog post](https://www.rwater.house/post/haskell-1-year), I talked
about what I thought about the Haskell programming language, and how it stacked
up to my expectations of it. If you haven't read it yet, I would recommend
reading it before reading this post. However, if you don't want to do that, the
TL;DR is this:

Haskell was promised to be the solution to all of my problems, and I don't
believe that it actually is. However, I do believe that it is a fun and quirky
language with an amazing type system that has taught me a lot, just not in the
ways that you expect. For me, it taught me programming principles that remain
true in any environment.

First, let's define what I think these principles lead to. I think that the
primary job of the software engineer is to create code that has the lowest
possible fault rates and the lowest possible maintenance costs.

It is the job of the product designer to make a product that people will want to
buy. It is the job of the software engineer to keep the costs of that product
down while building those features.

## The Principles of Good Code

Here are the principles of Good Code in an easily-digested list:

1. Correct in all inputs. This includes function parameters AND IO.
2. Never produces surprising outputs. This includes function returns AND IO.
3. Manages all resources correctly.
4. As secure as necessary.
5. As performant as necessary.
6. Encapsulates necessary complexity behind an elegant API.
7. Avoids all unnecessary abstraction.
8. Adheres to the style guide of the project.
9. Makes you proud to show it to your peers.

As far as I can tell, these are the universal truths of software engineering.

Let me be clear here. I am stating that ALL code that satisfies these 9
principles is good code. I am also stating that all code that doesn't satisfy
these 9 principles is not good code.

Note, this list talks just about the quality of code, not the utility of it.
I'm talking just about the code, not the product. I can write totally useless
code that satisfies my requirements, and that would be good code to me.
What makes a good product is a totally different discussion.

Also note that I'm not making a case against bad code. I don't believe that all
bad code is unacceptable and should be deleted. There is utility in cutting
some corners, especially in proof of concept code. Technical debt, like
financial debt, makes sense if it's profitable.

It's not SOLID, it's not Uncle Bob's Clean Code, it's not DRY, it's not any of
that stuff that Twitter talks about. Mind you, I think a lot of those point in
a similar direction to what I'm proposing here, but I believe there to be
distinct differences. I believe that all of those either

- Don't make sense outside an object-oriented context.
- Will lead you astray in some or all situations.

So let me dive a little deeper into what I'm talking about here with some
examples.

### Principle 1: Correct under all inputs, even IO inputs

This sounds trivial, but it is easy to get wrong. Let's look at a simple C
program to show my example.

```c
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {
    FILE* file = fopen(argv[1], "r");

    char ch;

    while((ch=fgetc(file)) != EOF) {
        putchar(ch);
    }

    fclose(file);

    return EXIT_SUCCESS;
}
```

This simple program prints the file located at the path passed in as an
argument. However, if no argument is passed in, this program segfaults.

My favourite design pattern to fix this is the [Guard
Clause](https://en.wikipedia.org/wiki/Guard_(computer_science)), otherwise
known as the "early return". Here's what that looks like:

```c
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
  if (argc != 2) {
    puts("Please call this program with exactly one argument, the file you "
         "wish to print");
    return EXIT_FAILURE;
  }

  FILE *file = fopen(argv[1], "r");

  char ch;

  while ((ch = fgetc(file)) != EOF) {
    putchar(ch);
  }

  fclose(file);

  return EXIT_SUCCESS;
}
```

Great! Big improvement, but we're not done yet. The second half of this
statement is still broken. If the file does not exist, this program segfaults.
That's not "valid under all IO inputs".

Again, we can add a simple guard clause to fix this problem.

```c
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
  if (argc != 2) {
    puts("Please call this program with exactly one argument, the file you "
         "wish to print");
    return EXIT_FAILURE;
  }

  FILE *file = fopen(argv[1], "r");
  if(file == NULL) {
      puts("Error opening that file. Please check that it exists and you have "
           "the correct permissions to access it");
      return EXIT_FAILURE;
  }

  char ch;

  while ((ch = fgetc(file)) != EOF) {
    putchar(ch);
  }

  fclose(file);

  return EXIT_SUCCESS;
}
```

With that, this program now follows principle 1.


### Principle 2: Never Produces Surprising Outputs, including IO outputs.

### Principle 3: Manages All Resources Correctly

Open files need to be closed. Memory needs to be freed. Connections need to be
closed. Database transactions need to be committed or rolled back.

Like all the other principles on this list, it's a simple principle, but we
often forget it. I don't feel like I need to give an example here. Know what
resources you're using and how to manage them correctly.


### Principle 4: As Secure as Necessary

Security is hard. You, as an engineer, should know the biggest security risks
of the project that you're working on. For web developers, this is the [OWASP
Top 10](https://owasp.org/www-project-top-ten/). You should know the threat
model of your project. You should know how to identify and mitigate the most
common security risks. Most importantly, you should know when you are out of
your depth, and require the help of a security professional.

If you're writing banking software, your software better be pretty damn secure.
If you're writing code for an ice cream machine that doesn't connect to the
internet, your code doesn't have to be secured to nearly the same level.

Lastly, when you have the choice between taking 2 different approaches to solve
a problem, if all other things are equal, choose the option that is more likely
to be secure.

### Principle 5: As Performant as Necessary

You should know the performance requirements of your system, and you should
profile your system to know where the bottlenecks are, and take steps to
mitigate those bottlenecks when your system falls below the performance
requirements.

Like security, if you're trying to choose between 2 different solutions to a
problem and all other things are equal, choose the more performant solution.

### Principle 6: Encapsulates Necessary Complexity Behind an Elegant API

There is real complexity in the world. This complexity will creep into your
code. Handle the complexity one time, in the most simple way possible, and
put that complexity behind a good API.

How do you know an API is elegant? It has the following characteristics:

1. It is well-documented
2. It does not leak implementation details.
3. It does not surprise the client programmer.

My favourite example of this is ... // TODO


### Principle 7: Avoids Any Unnecessary Abstraction

This is the principle that frustrates me most as a developer. I have no stats
to back up this claim, but I think this is the principle most often violated in
programming.

When you have a necessary piece of complexity, you wrap it behind an elegant
API. Unnecessary abstraction is when you add a layer of indirection on top of
this, usually to either:

1. Save keystrokes.
2. Reduce repetition
3. "Developer Experience"

So, how can you tell when you've encapsulated necessary complexity versus added
an unnecessary layer of abstraction? Here are what I think the best heuristics
are:

1. If I need to know how the underlying implementation works, it's probably not
a necessary abstraction. If I need to know how the underlying implementation
works, then you haven't truly abstracted anything away, and now I need to
understand both the underlying implementation AND the new abstraction, instead
of just the underlying implementation. For example, I don't need to know how
assembly works to write C code, but I do need to know how HTML works to write
Haml.


2. If this abstraction predicts some sort of future requirement, it's probably
a bad abstraction. Often we choose the wrong abstraction for our current
requirements, the chance that we get the right abstraction for future
requirements is slim to none. The exception to this rule is if the abstraction
adds "slop" to the system, and allows for future requirements to be added with
minimal changes to the system. For example, defining a protocol that has a few
extra bytes of padding, so that future requirements can be added without
breaking the protocol.


### Principle 8: Adheres to the Style Guide of the Project

If your project requires javadoc-style comments, unit tests for all of your
business logic, and proper logging and monitoring set up, then the code that
you submit in a PR to that project should contain javadoc-style comments,
unit tests for all of your business logic, and proper logging and monitoring.

Now, you may not like the style guide of the project, and you may disagree with
it. You may even be right. But a single pull request is no place to challenge
that style guide. The place to challenge that style guide is in a meeting with
the repository maintainers present and data backing up your position.

Also, a consistent code base is worth something, so until you can make a
coherent and convincing case that breaking this consistency has a better value
than consistency, keep the consistency.

### Principle 9: Makes You Proud to Show it to Your Peers

This is the last catchall principle. You should not be proud of code littered
with TODO comments. Business logic code without any regression tests should
bring you shame.



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

## The Principles of Good Code

Here are the principles of Good Code in an easily-digested list:

1. Correct in all inputs. This includes function parameters AND IO.
2. Never produces surprising outputs. This includes function returns AND IO.
3. Manages all resources correctly.
4. As secure as necessary.
5. As performant as necessary.
6. Encapsulates necessary complexity behind an elegant abstraction.
7. Avoids all unnecessary abstraction.
8. Adheres to the style guide of the project.
9. Makes you proud to show it to your peers.

As far as I can tell, these are the universal truths of software engineering.

It's not SOLID, it's not Uncle Bob's Clean Code, it's not DRY, it's not any of
that stuff that Twitter talks about. Mind you, I think a lot of those point in
a similar direction to what I'm proposing here, but I believe there to be
distinct differences. I believe that all of those either

- Don't make sense outside an object-oriented context
- Will lead you astray in some or all situations.

So let me dive a little deeper into what I'm talking about here with some
examples.

## Principle 1: Correct under all inputs, even IO inputs

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


## Principle 2: Never Produces Surprising Outputs, including IO outputs.

## Principle 3: Manages All Resources Correctly

Open files need to be closed. Memory needs to be freed. Connections need to be
closed. Database transactions need to be committed or rolled back.

Like all the other principles on this list, it's a simple principle, but we
often forget it. I don't feel like I need to give an example here. Know what
resources you're using and how to manage them correctly.


## Principle 4: As Secure as Necessary

Security is hard. You, as an engineer, should know the biggest security risks
of the project that you're working on. For web developers, this is the [OWASP
Top 10](https://owasp.org/www-project-top-ten/). You should know the threat
model of your project.

## Principle 5: As Performant as Necessary

## Principle 6: Encapsulates Necessary Complexity Behind an Elegant Abstraction

## Principle 7: Avoids Any Unnecessary Abstraction

## Principle 8: Adheres to the Style Guide of the Project

## Principle 9: Makes You Proud to Show it to Your Peers




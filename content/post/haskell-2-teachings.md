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

1. Correct with all inputs. This includes function parameters AND IO.
2. Never produces surprising outputs. This includes function returns AND IO.
3. Manages all resources correctly.
4. As secure as necessary.
5. As performant as necessary.
6. Encapsulates necessary complexity behind an elegant API.
7. Avoids all unnecessary abstraction.
8. Adheres to the style guide of the project.

As far as I can tell, these are the universal truths of software engineering.

Let me be clear here. I am stating that ALL code that satisfies these 8
principles is good code. I am also stating that all code that doesn't satisfy
these 8 principles is not good code.

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

If you're calling a function called `add`, you would expect that `add(1, 2)`
would return `3`.

Under no circumstances would you expect it to return
`9999999999999999999999999`, nor would you expect it to raise an exception, nor
would you expect it to read or write from a database, nor would you expect it to
return a string, nor would you expect it to make a POST request to any server
anywhere.

If your function does any of those unexpected things, it is not good code.
At best, you've tried to do too many things in one function and documented it
poorly. At worst, you've intentionally deceived the client calling your code.

Haskell accomplishes this with the type system, which includes the IO monad.
However, you don't need Haskell to accomplish this. You can accomplish
the same with good naming and documentation in a language like Ruby.

Take for example these ruby function signatures. Can you tell what outputs they
should produce?

```ruby
def add(a, b)

def get_user(id)

def store_file_in_cloud(file, cloud_file_path)
```

`add` probably takes 2 integers and returns an int, and it might raise an exception
if you pass in a non-integer object. `get_user` probably takes an int and returns a user
object, and it might raise an exception if the user doesn't exist, or if the db
is down. You can also assume it does some sort of IO action to find that user.
`store_file_in_cloud` probably takes a file and a cloud file path, and
returns nothing, and it might raise an exception if the cloud is down, or if the
POST request it makes fails for some reason, like if the file is too big.

Also, Haskell's type system doesn't prevent you from violating this principle.
You can easily write code so obtuse that it's impossible to tell what outputs
the client programmer should reasonably expect.

Here's an example of a function that violates this principle:

```haskell

doAllTheBadThings :: IO ()

```

We don't know what it does, all we know is that it does bad things with IO.
Is it removing all the files on your computer? Is it sending all of your
passwords to a foreign server? Is it framing you for murder? Who knows!

### Principle 3: Manages All Resources Correctly

Open files need to be closed. Memory needs to be freed. Connections need to be
closed. Database transactions need to be committed or rolled back.

Like all the other principles on this list, it's a simple principle, but we
often forget it. I don't feel like I need to give an example here. Know what
resources you're using and how to manage them correctly in the programming
language you're using.


### Principle 4: As Secure as Necessary

Security is hard. You, as an engineer, should know the biggest security risks
of the project that you're working on. For web developers, this is the [OWASP
Top 10](https://owasp.org/www-project-top-ten/). You should know the threat
model of your project. You should know how to identify and mitigate the most
common security risks. Most importantly, you should know when you are out of
your depth, and require the help of a security professional.

If you're writing banking software, your software better be pretty damn secure.
You should understand the security threat model of your software, you should
have security professionals review your code, you should have a security
team run regular penetration tests on your code, you should have an incident
response plan. You should ALWAYS sacrifice new features for security.
This is not a "move fast and break things" environment.

If you're writing code for an ice cream machine that doesn't connect to the
internet, your code doesn't have to be secured to nearly the same level.
For that kind of a project, you can do the minimum required to reasonably secure
your code, and that's good enough. If someone finds a way to hack an ice cream
machine that doesn't connect to the internet, the impact of that is minimal to
none.

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

1. Is well-documented.
2. Does not leak implementation details (except when providing "escape hatches").
3. Does not surprise the client programmer.

My favourite example of this is the C programming language. There is
necessary complexity in assembly. C takes the necessary complexity of not just
one assembly language, but many assembly languages, and puts it behind an elegant
API. Writing code that needs to run on ARM and x86? C's got your back.


C is well-documented.

C doesn't leak implementation details. You don't need to know how to add 2 numbers
in assembly to write the following C code:
```c
int add(int a, int b) {
    return a + b;
}
```
However, if you're working on a project that requires you to write assembly, you
can write inline assembly in C. This is an "escape hatch" that allows you to
access the underlying complexity if you need to. This makes the easy things easy,
and the hard things possible.

C doesn't usually surprise the client programmer. If you're writing C code, you
normally don't have to look at the assembly code that the C compiler produces.

Is C flawless? Absolutely not. But it is a good example of a good abstraction.

### Principle 7: Avoids Any Unnecessary Abstraction

This is the principle that frustrates me most as a developer. I have no stats
to back up this claim, but I think this is the principle most often violated in
programming.

When you have a necessary piece of complexity, you wrap it behind an elegant
API. Unnecessary abstraction is when you add a layer of indirection on top of
this, usually to for one of the following reasons:

1. Save keystrokes.
2. Reduce repetition.
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
requirements is slim to none. The exception to this heuristic is if the abstraction
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

## Conclusion

And that's it. That's what Haskell has taught me. Good code isn't about OO or
FP or procedural code. Good code isn't about knowing the GoF design patterns or
TDD. Good code is about following these 8 principles.


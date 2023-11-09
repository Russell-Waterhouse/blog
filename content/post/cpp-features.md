---
title: "Every C++ Feature You Need to Get Started"
author: "Russell Waterhouse"
description: "A Reference Guide for Every Modern C++ Feature"
tags: ["Cpp"]
date: 2023-11-08T19:16:25-08:00
draft: false
---

# Every C++ Feature You Need to Get Started
I'm going to be learning C++ during advent of code 2023. 
In advance of this, I'm going to make a quick reference guide for myself
for the language. Hopefully, I can get everything that I'll need in December
all in one place. 

## Primitive Types
- int
- char
- bool
- float
- double
- void
- wchar_t (idk google that)

```C++
int foo = 10;
char bar = 'c';
bool baz = true;
float quz = 10.1;
double quuz = 10.00000001;
```

## Operators
```C++
1 + 1 // addition
1 - 1 // subtraction
10 % 2 // modulo
true && false // logical AND
true || false // logical OR
0b00000001 & 0b00000001 // bitwise AND
0b00000001 | 0b00000001 // bitwise OR
3 > 2 // greater than
2 < 3 // Less than
3 >= 2 // greater than or equal to
2 <= 3 // Less than or equal to
```

## NULL 

## References
Like pointers but more strict.  
Denoted with `&`
```C++
int foo = 10;
int& bar = {foo}; // initialization with a special term I need to google
// both foo and bar now point to the same variable
foo = 20; //foo and bar are both 20
bar = 30; //foo and bar are both 30
```

## Pointer
Don't use those, use References or Smart Pointers.

## Smart Pointers

## Other Keywords
Things like const go here

## Common Data Structures
- Vector

## Conditionals
(if)

## Loops

## Exceptions and Error Handling

## Structs
idk if you should use these, more research required

## Unions
idk if you should use these, more research required

## Enums
I love enums

## Classes

## Objects

## Instance Variables

## Methods

## Class Functions
(like static in Java)

## Inheritance

## Concepts
```C++
template <typename T>
concept Integral = std::is_integral_v<T>;

template <Integral T>
void foo(T value) {
    // Do something with an integral type
}
```

## Modules

## Program IO
std::cout && std::cin

## File IO

## Network IO

## Functions

## Debugger

## Language Server

## Test Framework

## Concurrency

### Coroutines

## Package Manager

## Packages




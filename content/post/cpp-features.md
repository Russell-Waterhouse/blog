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

## Disclaimers: 
1. I don't know C++, and while I did have people who do know C++ proofread this
blog post, I don't claim that I am correct. All errors are my own. 
2. Most of this code won't compile, has no main, etc. Don't be sending me 
"Your code on your blog post would never compile" messages. It's a reference 
guide. Imagine that I didn't miss that semicolon and move on. 

## Naming Conventions
I'll be adhering to 
[Google's naming conventions](https://google.github.io/styleguide/cppguide.html)
as much as possible. 

Here is a short overview.
| Concept | Example | Explanation |
| ------- | ------- | ----------- |
| File Name | my-file-name.cc | All lower case and use - or _. I like - more. |
| Type Names | MyClass | Mixed case, starting with a capital. Classes, structs, enums, etc all follow this. | 
| Variable names (almost everything) | my_variable | snake_case | 
| Variable names (Data members of classes) | my_class_data_member_ | Trailing underscore (_) | 
| Variable names (Data members of classes) | my_class_data_member_ | Trailing underscore (_) | 
| Constant | kConstant | Use snakeCase and are prepended with `k` |
| Functions | DeleteTable | Mixed case, starting with a capital | 
| Namespace names | web_search::search | snake case |
| Enums | kOk | Same as constants | 
| Macro names | #define DAYS_IN_WEEK 7 | screaming snake case |


## Primitive Types
- int
- char
- bool
- float
- double
- void
- wchar_t (for unicode support)

```cpp
int foo = 10;
char bar = 'c';
bool baz = true;
float quz = 10.1;
double quuz = 10.00000001;
```

## Operators
```cpp
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
- `NULL` is a macro for null pointers (pointers that point nowhere). 
- `nullptr` is the ponter literal which specifies a null pointer value (introduced
in C++11).  
- `void` is a keyword that represents a lack of type or empty type.

## Uniform Initialization
This is a slick way to to say "give me a sane default variable of X type"
where X type decides what that sane default is. For int, it's 0, for instance.

```cpp
int i {}; // i is 0
int j {999}; // j is 999
float k {10.2}; // k is 10.2
```

## References
Like pointers but more strict.  
Denoted with `&`
```cpp
int foo = 10;
int& bar = {foo}; // uniform initialization again
// both foo and bar now point to the same variable
foo = 20; //foo and bar are both 20
bar = 30; //foo and bar are both 30
```

## Const
Used to signify that this variable does not and can not change.

```cpp
const int foo = 5; //foo is always 5

// This function doesn't take a copy, but doesn't modify the parameter
int add10(const int& bar) {
    baz = bar + 10;
    return baz;
}

```


## Conditionals
- if
- else
- else if
- switch (example below
```cpp
switch (day_of_week) {
    case 1: 
        std::cout << "I Hate Mondays" << std::endl;
        break;
    case 2: 
        std::cout << "I Hate Tuesdays" << std::endl;
        break;
    case 3: 
        std::cout << "I Hate Wednesdays" << std::endl;
        break;
    case 4: 
        std::cout << "I Hate Thursdays" << std::endl;
        break;
    case 5: 
        std::cout << "I Love Fridays" << std::endl;
        break;
    case 6: 
        std::cout << "I Love Saturdays" << std::endl;
        break;
    case 7: 
        std::cout << "I Love Sundays" << std::endl;
        break;
}
```
## Loops
while loops: 
```cpp
int i = 0;
while (i < 10) {
    std::cout << "Another one" << std::endl;
    i++;
}
```

do while loops: 
```cpp
int i = 0;
do {
    std::cout << "Another one" << std::endl;
    i++;
} while (i < 10);
```

for loops: 
```cpp
for (int i = 0; i < 99; i++) {
    std::cout << "Another one" << std::endl;
}
```

for-each loops: 
```cpp
Vector<int> v = {0, 1, 2, 3}
for(int number: v) {
    std::cout << number << std::endl;
}
```

`break` and `continue` offer more control of iteration in loops.

## Common Data Structures
This entire section is basically just the 
[codecademy cheat sheet](https://www.codecademy.com/learn/c-plus-plus-for-programmers/modules/cpp-built-in-data-structures/cheatsheet).
All I did was throw it in a table and exclude arrays because why would I use 
one of those while learning C++ when Vectors Exist?  
| Data Structure | #include Library | Quick Explanation | 
| -------------- | ---------------- | ----------------- |
| Vecor          | #include <vector> | Dynamically sized arrays | 
| Stacks         | #include <stack> | Stacks            |
| Queues         | #include <queue> | Queues            | 
| Sets           | #include <set>   | Set               |
| Hash Map       | #include map     | Key Value Pairs   | 

## Structs
These should be used when you have simple data and don't want the features that
classes provide.
Here's an example: 
```cpp
struct Location {
    double latitude {0};
    double longitude {0};
}

int main() {
    Location foo {};
    Location bar {100.0. 100.0};
    return 0;
}
```

## Unions
I read a few people on the internet who had the opinion that we shouldn't use
unions in modern C++, so probably just don't. Nobody on the internet has
ever been wrong.

## Enums
I love enums.
```cpp
enum class WeekDay {
    kMonday,
    kTuesday,
    kWednesday,
    kThursday,
    kFriday,
    kSaturday,
    kSunday
};
```

## Functions


## Exceptions and Error Handling

## Classes
Classic object oriented programming stuff here. 
```cpp
class Car {
    string brand;
    string model;
    int year;

    void drive() {
        std::cout << "vrooooom" << std::endl;
    }
}
```

## Objects

## Instance Variables

## Methods

## Class Functions
(like static in Java)

## Inheritance
// Like inheritance in Java.

## Concepts
// Like interfaces in Java.

## Pointer
Don't use those, use References or Smart Pointers.

## Smart Pointers

## Macros
I'm not going to define macros. You probably shouldn't either.

## Modules

## Program Arguments

## Program IO
Input from a user (stdin)
```cpp
string s; 
std::cin >> s
std::cout << "The user said: " << s << std::endl;
```

## File IO

## Network IO

## Functions

## Concurrency
In the world of C++ concurrency, you really have 2 options: Threads and 
Coroutines.  Coroutines were introduced in C++20 and Threads are a classic. 
Use whatever you're more familiar with, and if you're unfamiliar with concurrency, 
I recommend coroutines. I'll probably use threads because I'm more familiar with
them, but I might learn coroutines for fun.

I'll do a brief overview of the two methods below, but like everything else 
in this post, don't mistake it for a full turorial. 

### Coroutines

### Threads

## Compiler
There are many C++ compilers, but I'll be using g++ because it's already on
my machine (Fedora 38 at the time of writing).    
To compile with g++, just use the following command: 
```bash
g++ -Wall -std=c++20 -o <output_binary_name> <input_file.cc>
```
In order, the arguments mean the following: 
- -Wall - Print all warnings
- -std=c++20 - Use the C++ 20 standard (the most recent one at the time of writing)
- -o name for the output file, default is `a.out`

## Debugger

## Language Server

## Test Framework

## Package Manager
There are many C++ Packages, but I'll be using the most popular, which 
is [Conan](https://conan.io/).

## Packages




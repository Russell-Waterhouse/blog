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
- `nullptr` is the pointer literal which specifies a null pointer value (introduced
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
| Vecor          | #include \<vector> | Dynamically sized arrays | 
| Stacks         | #include \<stack> | Stacks            |
| Queues         | #include \<queue> | Queues            | 
| Sets           | #include \<set>  | Set               |
| Hash Map       | #include \<map>  | Key Value Pairs   | 

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
Functions take parameters and return values. Default is pass by value.
```cpp
int printInt(int i) {
    //i is a copy of whatever was passed in
    std::cout << i << std::endl;
    return 0;
}

int printReference(int& j) {
    // j is a reference to the original variable
    // modifying j would also modify the original variable
    std::cout << j << std::endl;
    return 0;
}

int main() {
    int x {99};
    int& y {x};
    printInt(x);
    printReference(y);
    return 0;
}
```

## Error Handling
C++ is a really fun language, it has both c-style segfaults and java-style 
exception handling.

### Throwing Exceptions
```cpp
#include <iostream>
#include <stdexcept>

int main() {
    throw std::runtime_error("This is a runtime error");
    return -1;
}
```

### Catching Exceptions
```cpp
#include <iostream>
#include <stdexcept>

int main() {
    try {
        throw std::runtime_error("This is a runtime error");
    } catch (const std::exception& e) {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }

    return 0;
}
```

### Debugging Segfaults
1. Compile your program with debug information (the `-g` flag)
2. Run your program with gdb (`gdb ./program_name`)
3. Examine the output. Example: 

Program that could segfault in several places: 
```cpp
// DON'T WRITE ANY CODE LIKE THIS, 
// IT'S LITERALLY ALL UNSAFE
#include <iostream>
#include <vector>

int& CreateSegfault() {
    int x = 4;
    int& y = {x};
    return y;
}

int main() {
    int& a = CreateSegfault();
    int b = 99;
    int c = a + b;
    a++;
    c++;

    std::vector<int> j = {1, 2, 3};
    int& k = j.at(1);
    j.clear();
    k++;

    int& m = *(int*)NULL;
    m++;
    return 0;
}
```
As an aside, isn't it crazy that on my machine that compiles without any warnings?  
I think that if C++ cannot fix that, Rust will win eventually. 
I also think that eventually is probably 10 years away.

Output when run: 
```cpp
./segfault
Segmentation fault (core dumped)
```

GDB output: 
```bash
gdb ./segfault
GNU gdb (GDB) Fedora Linux 13.2-6.fc38
Copyright (C) 2023 Free Software Foundation, Inc.
License GPLv3+: GNU GPL version 3 or later <http://gnu.org/licenses/gpl.html>
This is free software: you are free to change and redistribute it.
There is NO WARRANTY, to the extent permitted by law.
Type "show copying" and "show warranty" for details.
This GDB was configured as "x86_64-redhat-linux-gnu".
Type "show configuration" for configuration details.
For bug reporting instructions, please see:
<https://www.gnu.org/software/gdb/bugs/>.
Find the GDB manual and other documentation resources online at:
    <http://www.gnu.org/software/gdb/documentation/>.

For help, type "help".
Type "apropos word" to search for commands related to "word"...
Reading symbols from ./segfault...
(gdb) run
Starting program: /home/russ/repos/programming-tools/tools/debuggers/gdb/segfault

This GDB supports auto-downloading debuginfo from the following URLs:
  <https://debuginfod.fedoraproject.org/>
Enable debuginfod for this session? (y or [n]) n
Debuginfod has been disabled.
To make this setting permanent, add 'set debuginfod enabled off' to .gdbinit.
[Thread debugging using libthread_db enabled]
Using host libthread_db library "/lib64/libthread_db.so.1".

Program received signal SIGSEGV, Segmentation fault.
0x000000000040129b in main () at segfaults.cc:23
23          m++;
```

We can see clearly here that we crash on line 23 when incrementing the `m` 
variable.

### Preventing Errors
These aren't anything that C++ enforces, I'm just going to quickly describe a 
holistic approach I'm taking here to make sure that I limit the number of
errors that I create. 
- Use smart pointers or references instead of raw pointers.
- Returning std::optional<> when I might return a value.
- Limit the use of NULL, void, and null_ptr.
- Avoid macros.
- Return status codes from functions that might have problems instead of throwing exceptions.
- Not doing any weird typecasting, have safe functions for converting types.
- Using for-each loops when iterating through a data structure.
- generous use of `const` and only mutating data when necessary.
- Keep things as simple as possible.

I do the above to limit the following class of bugs: 
- Memory related problems(segfaults, memory leaks, use after free, etc.).
- NullPointerException.
- Macro confusion.
- Typecasting errors
- Off by 1 errors
- Side effect errors (Haskell programmers know what I'm talking about)

## Classes
Classic object oriented programming stuff here. 
```cpp
```

## Objects
There are a few ways to create objects. 

### Stack Allocated Objects (Autumatically Managed)
Do this when at all possible.
```cpp

```

### Heap Allocated Objects (Manually Managed)
You probably don't want to do this, see the section on smart pointers
below. 
That being said, here's how you would if you wanted to. 
```cpp

```


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
In C++, you access program arguments the same way that you do in C. 

Your main function gets an `int argc` and a `char* argv[]`.
These c-style string arguments can be converted to C++ strings 
by doing the following: 
```cpp
std::string arg = argv[index];
```

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
Coroutines. Coroutines were introduced in C++20 and Threads are a classic. 
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
For a debugger, I don't think I can do better than GDB, the GNU Debugger.
I'll be using that while learning C++.

## Language Server
For a language server, I'm going to be using 
[clangd](https://clangd.llvm.org/)

In the little experiments I've been doing while writing this blog post, it's
been more than sufficient for my needs. 

## Test Framework
I'll probably be using gtest, Google's C++ testing framework.
Here's an example gpt generated about using it: 
```cpp
#include <gtest/gtest.h>

int add(int a, int b) {
    return a + b;
}

TEST(AdditionTest, HandlesPositiveInput) {
    EXPECT_EQ(3, add(1, 2));
}

TEST(AdditionTest, HandlesNegativeInput) {
    EXPECT_EQ(-1, add(-1, 0));
}

// More tests...

```
Finally, compile your main file with gtest linked, run your code, and watch
the tests pass. 
```cpp
#include <gtest/gtest.h>

// ... (your test cases)

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
```

## Package Manager
There are many C++ Packages, but I'll be using the most popular, which 
is [Conan](https://conan.io/).

I'll be using 
[this tutorial by ForgottenUmbrella on GitHub](https://gist.github.com/ForgottenUmbrella/0f32f6446b2948a3a5a99687b264910d)
to set it up and get using it

## Packages
I'm not going to list every popular package on Conan's center, but I will 
highlight a few that I might use very soon. 
- OpenSSL: Needs no introduction
- fmt: A safe and fast alternative to printf and IOStreams
- gtest: Google's C++ testing framework
- nlohmann_json: C++ json parser
- spdlog: C++ Logging library
- libbacktrace: Can be linked into a C++ program to produce symbolic backtraces.



---
title: "Ruby Parameter Passing: A Quick Reference"
author: "Russell Waterhouse"
description: "A quick reference about ruby's many ways to pass arguments to functions"
tags: ["ruby"]
date: 2023-09-15T10:26:05-07:00
draft: false
---

# Ruby Variables: A Quick Reference


![](/post/images/ruby-small.png)


This is meant to be a quick reference to bookmark if you don't work on Ruby 
code all that often, it's not meant to be a deep dive into the language

## Passing Values into Functions
There are several ways to pass values into functions.


### Regular Parameter Passing
This is the standard way of doing things, and it looks like this:
```ruby
def foo(val1, val2)
  puts val1
  puts val2
end

def bar()
  foo("Hello,", "World")
end

bar()
```

output: 
```
Hello,
World
```

### Default Values
This is how to define default values for parameters, making them optional:
```ruby

def foo(printStr="Hello, Default Value!")
  puts printStr
end


def bar()
  foo()
  foo("Hello with some other value")
end

bar()
```

and the output is as follows: 
```
Hello, Default Value!
Hello with some other value
```

### Keyword Arguments
This was introduced in Ruby2 and allows you to pass key-value pairs into
functions. Personally, I find it makes client code (i.e. the code 
calling my function) more readible.
```ruby
def foo(val1:, val2:)
  puts val1
  puts val2
end

def bar()
  foo(val1: "Hello,", val2: "world!")
end

bar()
```

it producest the following: 
```
Hello,
world!
```

### Keyword Arguments with Defaults

This allows you to define defaults for the keyword arguments passed in as
key-value pairs. It looks like this:

```ruby
def foo(val1: "Hello,", val2: "World")
  puts val1
  puts val2
end

def bar()
  foo()
  foo(val1: "this is NOT", val2: "the default values")
end

bar()

```

It produces the following: 
```
Hello,
World
this is NOT
the default values
```

### Variable Number of Arguments in an Array

This allows you to define a function that takes in a variable number of
arguments in an array. This is done with the splat operator (`*`), 
and it looks like  this: 

```ruby
def foo(*vals)
  puts "The function was called\n"
  vals.each do |value|
    puts value
  end
end

def bar()
  foo()
  foo(10)
  foo("Hello", "World", "!", "42")
end

bar()
```


It produces the following: 
```
The function was called
The function was called
10
The function was called
Hello
World
!
42
```


### Variable Number of Arguments in a Hash

Finally, you can accept a variable number of arguments in a hash with 
the double splat (`**`) operator.  It looks like this when used: 

```ruby
def foo(**vals)
  puts "The function was called\n"
  vals.each do |key, value|
    puts "Key: #{key}; value: #{value}"
  end
end


def bar()
  foo()
  foo(age: 10)
  foo(msg1: "Hello", msg2: "World", msg3: "!", msg4: "42")
end

bar()
```

And the output of that example is this: 
```
The function was called
The function was called
Key: age; value: 10
The function was called
Key: msg1; value: Hello
Key: msg2; value: World
Key: msg3; value: !
Key: msg4; value: 42
```


That's all of the ones that I'm going to cover! I hope this is useful 
to all you devs working with a rails backend once a month!


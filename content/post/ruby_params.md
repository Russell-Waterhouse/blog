---
title: "Ruby_params"
author: "Russell Waterhouse"
description: "description here"
tags: ["", ""]
date: 2023-09-15T10:26:05-07:00
draft: false
---

# Ruby Variables


## A Quick Reference
This is meant to be a quick reference to bookmark if you don't work on Ruby 
code all that often, it's not meant to be a deep dive into the language

### Passing Values into Functions
There are several ways to pass values into functions.


#### Regular Parameter Passing
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

#### Default Values
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

#### Keyword Arguments
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

#### Keyword Arguments with Defaults

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



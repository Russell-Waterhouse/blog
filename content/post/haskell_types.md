---
title: "Haskell type keyword reference manual"
author: "Russell Waterhouse"
description: "A quick reference for some Haskell keywords"
tags: ["Haskell", "Functional Programming"]
date: 2021-12-31T20:38:00-07:00
---

In this short blog post, I will explain the difference between data, type,
newtype, class, and instance keywords in haskell and how they all work
together. This is not meant to be an in-depth tutorial, but just a reference
guide. If you program occasionally in haskell and just want a quick reference,
bookmark this page.

## data:

This just defines a new data type in haskell. Several examples are below:

Record Syntax (a row in a database): 
```
data Book = Book {
  bookId :: Int,
  title :: String,
  author :: String,
  isbn :: String,
  price :: Double
}
```
Here a book can have an id, title, author, isbn, and a price. Of course this is
a massively simplified example, and I've used a Double to represent currency,
which should never be done in the real world. Nonetheless, this example gets
the point across.


Algebraic Types (sums):
```
data MyBool = MyTrue | MyFalse
```

Algebraic Types (products):
```
data Pair = P Int Double
```
This example was taken from 
[wiki.haskell.org](https://wiki.haskell.org/Algebraic_data_type)
"is a pair of numbers, an Int and a Double together. The tag P is used (in
constructors and pattern matching) to combine the contained values into a
single structure that can be assigned to a variable."

Parametarized types (Generics in other languages)
```
data Optional a = Empty | Full a 
```
Here the Optional Type can be `Empty` or it can hold data of any type (a)


## type:

This is just a synonym for an existing type. An example of this is `String` and
`[char]`. You can use one interchangably with the other.

## newtype:

This gives an existing type a new identity. It is often used to make
typechecking more strict.

For example:

```
type EmailAddress = EmailAddress String
type Address = Address String
```

With these 2 types defined, the type checker would notice if you accidentally
put an address string in a parameter that should have taken an email address
string. If the parameter just accepts any string, this mistake would not be
caught until runtime. It is generally considered good practice to define and
use types like this within your code base for this reason. Remember, one of the
goals of good software development is to catch bugs as early as possible. This
is the reason for tdd, static typechecking, etc. If we can catch a bug at
compile time, the end user will never see it. Okay, rant over, onto the class
keyword.

## class:

A class is a generic interface that defines a common feature set that can be
used over a wide variety of types. Examples of this are ord (for ordering) or
eq (for testing equality) in haskell. A simplified implementation of the eq
typeclass is shown below, taken from page 130 of the book "Real world Haskell"
by Bryan O’Sullivan, John Goerzen, and Don Stewart.

```
class BasicEq a where
isEqual :: a -> a -> Bool
```

It should be noted that a class must be declared in its own file

## instance:

instance is the keyword used to define an implementation of a class. This is
demonstrated below, using an example from page 131 of "Real World Haskell"

```
instance BasicEq Bool where
isEqual True True = True
isEqual False False = True
isEqual _ _ = False
```

As long as this is defined, you'll be able to use the isEqual function on Bool
types.

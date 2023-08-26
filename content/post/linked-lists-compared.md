---
title: "Linked Lists Compared"
author: "Russell Waterhouse"
description: "A short overview of linked lists implemented in functional, procedural, and an object-oriented way"
tags: ["linked-list", "data structures", "algorithms", "functional programming", "procedural programming", "object oriented programming"]
date: 2023-08-26T09:23:27-07:00
draft: false
---

# Linked Lists Functional, Procedural, and Object Oriented
![A picture of Linked Lists on a chalkboard](/post/images/linked-lists.jpg
"Linked Lists in all Flavours!")

Over the last 2 weeks, I've been building a singly linked list implementation 
from scratch in Haskell, Ruby, and C. I originally did it just to become 
a little bit more sharp in these languages, but what I found was really 
interesting, so I thought I would share my findings in a blog post.

## What is a Linked List?

A linked list is one of the most foundational data structures in computer 
science. In fact, they come as a base language feature 
in many languages such as ruby, python, and haskell.  They work by allocating
memory for the data (in my implementations this is an integer), as well as 
a pointer to the next node in the list. Of course, you can embellish them further
to turn them into doubly linked lists, circular lists, arraylists, etc. but for 
the sake of simplicity, I've just implemented vanilla singly-linked lists.

//TODO: Insert draw.io of linked list here

In terms of theoretical time efficiency, it has the following properties on its
basic operations:

| Operation | Efficiency |
|-----------|------------|
| `insertHead(data)` | O(1) |
| `insertTail(data)` | O(n) |
| `deleteNode(Node)` | O(n) |
| `printList()`      | O(n) |
| `size()`           | O(n) or O(1) - implementation dependant | 


In practice, it will usually be much more efficient, both in memory and time,
to use an array, because you will get a massive speed boost from your CPU's 
cache, and save memory because you don't need to store an extra pointer for
each node.  However, many developers, if not most developers, don't need to
worry about efficiency because we don't work with systems that will see enough 
load for this to make a meaningful difference.

## The C Implementation

The C implementation can be found in my programming tools repo 
[here](https://github.com/Russell-Waterhouse/programming-tools/tree/main/data-structures/linked-list/c)
I'll keep that version updated if I find any issues in my implementation, 
but here's a copy of it so that you don't need to open too many tabs to read 
this blog post.

Don't bother reading all of the code in depth, just take a glance and move on,
we'll do our analysis once we've seen all of the implementations.


linked-list.h: 
```
typedef struct Node {
    struct Node* next;
    int value;
} Node;
    
typedef struct List {
    Node* head;
} List;

char* print_list(List* list);
List* tail_insert(List* list, int val);
List* head_insert(List* list, int val);
List* remove_node(List* list, Node* node);
int free_list(List* list);
int size(List* list);
```



linked-list.c:
```
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "linked-list.h"

#define INIT_PRINT_BUFFER_SIZE 255
#define MAX_STR_SIZE_FOR_INT 10
#define SIZE_OF_ARROW_STR 4

char* int_to_string(int n) {
    int size_of_string_representation = snprintf(NULL, 0, "%d", n);
    size_of_string_representation++; // add 1 for terminating '\0' character
    char* buffer = malloc(sizeof(size_of_string_representation));
    snprintf(buffer, size_of_string_representation, "%d", n);
    return buffer;
}

char* print_list(List* list) {
    int buffer_size = INIT_PRINT_BUFFER_SIZE;
    char* print_buffer = malloc(buffer_size);
    Node* curr = list -> head;
    int i = 0;
    while (curr != NULL) {
        char* curr_val_str = int_to_string(curr -> value);
        int curr_val_str_len = strlen(curr_val_str);

        // double buffer size if we're running out
        while (i + curr_val_str_len + MAX_STR_SIZE_FOR_INT  + SIZE_OF_ARROW_STR > buffer_size){
            buffer_size = buffer_size * 2;
            print_buffer = realloc(print_buffer, buffer_size);
        }

        // Copy current value into print_buffer
        for(int j = 0; j < curr_val_str_len; j++) {
            print_buffer[i++] = curr_val_str[j];
        }
        free(curr_val_str);
        print_buffer[i++] = ' ';
        print_buffer[i++] = '-';
        print_buffer[i++] = '>';
        print_buffer[i++] = ' ';
        curr = curr -> next;
    }
    print_buffer[i] = '\0';
    return print_buffer;
}

List* tail_insert(List* list, int val) {
    Node* head = list -> head;
    if(head == NULL) {
        Node* item = malloc(sizeof(Node));
        if (item == NULL) {
            printf("Malloc failed");
            return NULL;
        }
        item -> next = NULL;
        item -> value = val;
        list -> head = item;
        return list;
    }

    Node* curr = head;
    while (curr -> next != NULL) {
        curr = curr -> next;
    }
    Node* item = malloc(sizeof(Node));
    if (item == NULL) {
        printf("Malloc failed");
        return list;
    }
    item -> next = NULL;
    item -> value = val;
    curr -> next = item;
    return list;
}

List* head_insert(List* list, int val) { 
    Node* new = malloc(sizeof(Node));
    if (new == NULL) { 
        printf("Malloc failed");
        return list;
    }
    new -> value = val;
    new -> next = list -> head;
    list -> head = new;
    return list;
}

List* remove_node(List* list, Node* node) {
    if (list == NULL) {
        printf("cannot remove item from a null list");
        return list;
    }
    Node* curr = list -> head;
    if(curr == node) {
        list -> head = curr ->next;
        free (node);
        return list;
    }
    while (curr -> next != node) {
        if (curr == NULL) {
            printf("node not found in list");
            return list;
        }
        curr = curr -> next;
    }
    Node* n = curr -> next;
    curr -> next = curr -> next -> next;
    free(n);
    return list;
}

int free_list(List* list) {
    Node* curr = list -> head;
    while(curr != NULL) {
        Node* next = curr -> next;
        free(curr);
        curr = next;
    }
    free(list);
    return 0;
}

int size(List* list) {
    Node* curr = list -> head;
    int list_size = 0;
    while (curr != NULL) {
        list_size++;
        curr = curr -> next;
    }
    return list_size;
}
```
Again, don't bother reading it all now, just take a look and move on.


## The Ruby Implementation
The Ruby implementation can be found in my programming tools repo 
[here](https://github.com/Russell-Waterhouse/programming-tools/tree/main/data-structures/linked-list/ruby)

Again, don't bother reading it all in depth, just take a look at it, see the 
forest, not the trees, and move on.

node.rb:
```
class Node

  @val
  @next

  def initialize(value:, next_node:)
    @val = value
    @next = next_node
  end

  def val
    @val
  end

  def next
    @next
  end

  def set_val(value)
    @val = value
  end

  def set_next(next_node)
    @next = next_node
  end
end
```

linked_list.rb:
```
require_relative "node"

class LinkedList

  @size
  @head

  def initialize()
    @size = 0
    @head = nil
  end

  def insert_head(val)
    new_head = Node.new(value: val, next_node: @head)
    @head = new_head
    @size += 1
    self
  end

  def insert_tail(val)
    if @head == nil
      @head = Node.new(value: val, next_node: nil)
      @size += 1
      return
    end
    current = @head
    while current.next != nil
      current = current.next
    end
    current.set_next Node.new(value: val, next_node: nil)
    @size += 1
  end

  def delete_node(node)
    if @head == node
      @head = node.next
      @size -= 1
      return
    end

    current = @head
    while current.next != node
      current = current.next
    end
    if current.next != node
      puts "not found"
      return
    end
    current.set_next current.next.next
    @size -= 1
    return
  end

  def size()
    @size
  end

  def to_string()
    current = @head
    list_str = ""
    while current != nil do
      list_str += "Node: #{current.val} -> "
      current = current.next
    end
    list_str
  end

  def head()
    @head
  end
end
```


## The Haskell Implementation

The Haskell implementation can be found in my programming tools repo 
[here](https://github.com/Russell-Waterhouse/programming-tools/tree/main/data-structures/linked-list/haskell)

Again, don't worry about understanding it all in depth right now, just
take a look and move on. I'll explain things in more detail in the analysis 
section.

```
module LinkedList where

data Node = Node 
    { val :: Int
    , next :: Node
    } | EmptyNode deriving (Show, Eq)


tailInsert :: Node -> Int -> Node
tailInsert EmptyNode value = Node value EmptyNode
tailInsert head value = Node (val head) (tailInsert (next head) value)


headInsert :: Node -> Int -> Node
headInsert head value = Node value head


printList :: Node -> String
printList EmptyNode = ""
printList node = show (val node) ++ " -> " ++ printList (next node)


removeNode :: Node -> Node -> Node
removeNode EmptyNode _ = EmptyNode
removeNode head nodeToRemove = let
        headIsValue = nodeToRemove == head
    in
        if headIsValue then
            removeNode (next head) nodeToRemove
        else
            Node (val head) $ removeNode (next head) nodeToRemove

size :: Node -> Int
size EmptyNode = 0
size node = 1 + size (next node)
```


## Analysis


### Development Time

First, let's talk about the most visible cost to an engineer thinking about
using any of these languages: development time.

I didn't keep track of my development time in any of these languages, simply 
because I didn't think it would make a fair comparison between them, because I 
am not equally efficient in these languages. However, we don't need to 
know exact billable hours to determine a winner here. Haskell took me the least
amount of time to implement, followed by Ruby, followed by C. 

I think this should be visible why this is in the following table:

| Language | Total lines of code (all implementation files) | 
|----------|------------------------------------------------|
| Haskell  | 35  |
| Ruby     | 97  |
| C        | 147 |


Why is that? It's the same data structure, implemented by the same developer.
Let's take a look at each `print_list` implementation to see why first.

For all aof the implementations, it returns a string representation of the list
formatted as such:  
```
34 -> 42 -> -42 -> 
```

Let's start with the C implementation:

```
#define INIT_PRINT_BUFFER_SIZE 255
#define MAX_STR_SIZE_FOR_INT 10
#define SIZE_OF_ARROW_STR 4

char* int_to_string(int n) {
    int size_of_string_representation = snprintf(NULL, 0, "%d", n);
    size_of_string_representation++; // add 1 for terminating '\0' character
    char* buffer = malloc(sizeof(size_of_string_representation));
    snprintf(buffer, size_of_string_representation, "%d", n);
    return buffer;
}

char* print_list(List* list) {
    int buffer_size = INIT_PRINT_BUFFER_SIZE;
    char* print_buffer = malloc(buffer_size);
    Node* curr = list -> head;
    int i = 0;
    while (curr != NULL) {
        char* curr_val_str = int_to_string(curr -> value);
        int curr_val_str_len = strlen(curr_val_str);

        // double buffer size if we're running out
        while (i + curr_val_str_len + MAX_STR_SIZE_FOR_INT  + SIZE_OF_ARROW_STR > buffer_size){
            buffer_size = buffer_size * 2;
            print_buffer = realloc(print_buffer, buffer_size);
        }

        // Copy current value into print_buffer
        for(int j = 0; j < curr_val_str_len; j++) {
            print_buffer[i++] = curr_val_str[j];
        }
        free(curr_val_str);
        print_buffer[i++] = ' ';
        print_buffer[i++] = '-';
        print_buffer[i++] = '>';
        print_buffer[i++] = ' ';
        curr = curr -> next;
    }
    print_buffer[i] = '\0';
    return print_buffer;
}
```
That's 36 lines of code *just to print the list*. That's one more line of code
than the entire haskell linked list implementation. 

Why it's so long is clearly visible immediately: memory management. 
Neither haskell nor ruby has to double the size of the string buffer if it gets 
too large, neither one had to remember to add the null terminator.

I'm aware that there are ways to make my implementation smaller, but the point 
still stands: *Manual Memory Management comes with a development overhead*

If you've never seen C code before or worked manually with memory, you would 
have a very hard time understanding what's going on here. 
It might take you a long time to understand that I'm iterating through my 
linked list and iterating through arrays of characters (the canonical C string
implementation) to concatenate together the final returned value.

C's traditional function naming style doesn't help here either. Why does
`snprintf` get called twice in the `int_to_string` method in two seemingly 
unrelated ways? 


What about the ruby implementation?

```
  def to_string()
    current = @head
    list_str = ""
    while current != nil do
      list_str += "Node: #{current.val} -> "
      current = current.next
    end
    list_str
  end
```

That's much more concise. Since Ruby has a really nice string class and string
interpolation to build on top of, it's much more concise than the C version.

However, even though it's more concise, it's still legible to a programmer that 
has never seen ruby code before. 

The final step in this journey is the haskell implementation.

```
printList :: Node -> String
printList EmptyNode = ""
printList node = show (val node) ++ " -> " ++ printList (next node)
```

Wow, that is concise, bordering on terse. If you've never seen haskell before,
you may not understand what is going on here. And, on top of that, it's 
recursive, a concept that people usually take longer to grasp than loops.

Note, that in both the C and ruby implementations, I could have implemented 
the functions recursively, but people would have looked at me funny. Fact is,
outside of pure functional languages that don't have loops, recursion isn't 
used as often as loops in industry, even if they would make more concise code.



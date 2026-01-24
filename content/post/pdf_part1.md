---
title: "How to Make a PDF From Scratch Part 1"
author: "Russell Waterhouse"
description: "The Format that Runs the World"
tags: ["PDF", "Deep-Dive"]
date: 2026-01-24T10:30:54-07:00
draft: false
---


##

I'm going to be explaining this not in the order a PDF editor would parse it,
because a PDF has trees and cross references and is designed to be parsed
in any order, but in the order that you would write it, if you opened up a text
editor and wanted to edit a PDF from scratch. It's not that hard of a format,
if you're writing it. If you're reading PDF's and need to support the full spec,
different story. But writing isn't so bad.

## The beginning

Every PDF starts with the string `%PDF-<VERSION>` where <VERSION> is the magic
number pdf version. We will use Version 2.0 in this example.

And every PDF ends with the string `%%EOF`.
```pdf
%PDF-2.0
%%EOF
```

## Objects and other elements.

Outside of these beginning and ending strings, there are only a few required elements
to make a valid PDF file. They are:
- 9 PDF object types.
- The `xref` table.
- The `trailer`.
- The `startxref` pointer.

Quoting directly from wikipedia, the 9 object types are as follows:


BEGIN QUOTE FROM WIKIPEDIA


A PDF file is organized using ASCII characters, except for certain elements that may have binary content. The file starts with a header containing a magic number (as a readable string) and the version of the format, for example %PDF-1.7. The format is a subset of a COS ("Carousel" Object Structure) format.[25] A COS tree file consists primarily of objects, of which there are nine types:[18]
-     Boolean values, representing true or false
-     Real numbers
-     Integers
-     Strings, enclosed within parentheses ((...)) or represented as hexadecimal within single angle brackets (<...>). Strings may contain 8-bit characters.
-     Names, starting with a forward slash (/)
-     Arrays, ordered collections of objects enclosed within square brackets ([...])
-     Dictionaries, collections of objects indexed by names enclosed within double angle brackets (<<...>>)
-     Streams, usually containing large amounts of optionally compressed binary data, preceded by a dictionary and enclosed between the stream and endstream keywords.
-     The null object


END QUOTE FROM WIKIPEDIA


[https://en.wikipedia.org/wiki/PDF]

Every object starts with the object id, a space, the object generation (TODO: explain),
and the `obj` keyword.
The obj continues until the `endobj` keyword is reached.

Lastly, and not required, comments start with `%` and end at the next `\n`

I'll go into detail for each of these as we use them, but for now just know there
is't much more to it, and we'll move on.

## The Document Catalog

Every PDF Needs a root document cataglog. This is a PDF dictionary object that points to
the root pages

It has a `/Type` of `Catalog` and an indirect object reference to the root of the
pages tree.

Let's put the document cataglog as the first object in our PDF, and let's put
the root of the pages tree next. Then our PDF now looks like this.

```pdf
%PDF-2.0
1 0 obj
<<
/Type Catalog
/Pages 2 0 R
>>
endobj
%%EOF
```

## The Pages Root

## The `xref` table

The xref table starts with the `xref` keyword and ends before the `trailer`
keyword.

The next line in the xref table is two numbers. The first number is the number
of the first object in the table. TODO: USUALLY 0?

The second number is the number of entries in the table.

The following lines are the entries in the cross reference table. These consist
of the byte offset of that object from the start of the file, leftpadded by
zeros.  Then a space, then the generation number of the object. We'll use 0 in our
example.
The first entry is the 0th entry. It always seems to be `0000000000 65535
f` TODO WHY.

So our xref table would look like this.
```pdf
0 3
0000000000 65535 f
0000000009 00000 n
0000000057 00000 n
```

Our PDF Now 

```
%PDF-2.0
1 0 obj
<<
/Type Catalog
/Pages 2 0 R
>>
endobj
2 0 obj
null
endobj
xref
0 1
0000000000 65535 f
0000000009 00000 n
0000000057 00000 n
%%EOF
```

## The Trailer

## The `startxref` pointer

```
%PDF-2.0
1 0 obj
<<
/Type Catalog
/Pages 2 0 R
>>
endobj
2 0 obj
null
endobj
xref
0 1
0000000000 65535 f
0000000009 00000 n
0000000057 00000 n
trailer <<
/Root 1 0 R
/Size 2
>>
startxref
29
%%EOF
```

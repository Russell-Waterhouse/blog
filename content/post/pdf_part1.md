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

The Pages root is a dictionary of pages. It must contain the following keys.
- `/Type /Pages`
- `/Count 1`
- `/Kids [<INDIRECT OBJEC REFERENCES TO PAGES>]`

`/Count 1` Says that there is only one (1) page in the PDF.

`/Kids [<INDIRECT OBJEC REFERENCES TO PAGES>]` Is an array of object references.
For our example, we'll make the first page the next object in the PDF.
```
2 0 obj
<<
/Type /Pages
/Count 1
/Kids [3 0 R]
>>
endobj
```
Now our PDF has a document catalog, and a Pages Root. It looks like this.

```pdf
%PDF-2.0
1 0 obj
<<
/Type Catalog
/Pages 2 0 R
>>
endobj
2 0 obj
<<
/Type /Pages
/Count 1
/Kids [3 0 R]
>>
endobj
%%EOF
>>
```

## The First page and some page contents

Let's make a page for the page root to point to.
A page is a dictionary with `/Type /Page`, an indirect object reference named
`/Contents`, and an indirect object reference to the `/Parent`

```pdf 
3 0 obj
<<
/Type /Page
/Contents 4 0 R
/Parent 2 0 R
>>
endobj
```

We're going to make the contents point to the null object to say that
"There's nothing in this PDF page".
```
4 0 obj
null
endobj
```

Altogether, we now have

```
%PDF-2.0
1 0 obj
<<
/Type Catalog
/Pages 2 0 R
>>
endobj
2 0 obj
<<
/Type /Pages
/Count 1
/Kids [3 0 R]
>>
endobj
3 0 obj
<<
/Type /Page
/Contents 4 0 R
/Parent 2 0 R
>>
endobj
4 0 obj
null
endobj
%%EOF
```

This is all the contents that I'm going to put in the first PDF we do. If you
wanted more contents, you would continue like this, adding objects to the pdf
as we have been doing so far.

We'll go deeper into what can be put in the contents of the PDF in part 2,
part 1 here is just for the structure of the PDF format.

Let's finish up with the xref table and trailer.


## The `xref` table

I'll explain how the xref table joins everything together at the end. For now,
we'll just explain the structure and format of it.

The xref table starts with the `xref` keyword and ends before the `trailer`
keyword.

The next line in the xref table is two numbers. The first number is the number
of the first object in the table. TODO: USUALLY 0?

The second number is the number of entries in the table.

The following lines are the entries in the cross reference table. These consist
of the byte offset of that object from the start of the file, leftpadded by
zeros.  Then a space, then the generation number of the object. We'll use 0 in
our example. The first entry is the 0th entry. It always seems to be
`0000000000 65535 f` TODO WHY.

So our xref table would look like this.
```pdf
xref
0 5
0000000000 65535 f
0000000009 00000 n
0000000057 00000 n
0000000114 00000 n
0000000177 00000 n
%%EOF
```

Note that the xref table is not a PDF object, so it does not start with obj
or end with endobj.

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
<<
/Type /Pages
/Count 1
/Kids [3 0 R]
>>
endobj
3 0 obj
<<
/Type /Page
/Contents 4 0 R
/Parent 2 0 R
>>
endobj
4 0 obj
null
endobj
xref
0 5
0000000000 65535 f
0000000009 00000 n
0000000057 00000 n
0000000114 00000 n
0000000177 00000 n
%%EOF
```

## The Trailer

The trailer starts with the line `trailer <<` and ends with `>>`

The first line by an indirect object reference to the document catalog `/Root 1
0 R` Then it has a size field that indicates how many entries are in the xref
table.


## The `startxref` pointer

The last thing that every PDF needs is a `startxref` pointer. This tells a PDF
reader the bytes offset to the `xref` table. It will use this table when looking
up objects in the PDF.

In our example, the xref table starts at byte 197, so our xref pointer
looks like this:
```
startxref
197
```

Putting it all together, we now have a complete PDF.

```
%PDF-2.0
1 0 obj
<<
/Type Catalog
/Pages 2 0 R
>>
endobj
2 0 obj
<<
/Type /Pages
/Count 1
/Kids [3 0 R]
>>
endobj
3 0 obj
<<
/Type /Page
/Contents 4 0 R
/Parent 2 0 R
>>
endobj
4 0 obj
null
endobj
xref
0 5
0000000000 65535 f
0000000009 00000 n
0000000057 00000 n
0000000114 00000 n
0000000177 00000 n
trailer <<
/Root 1 0 R
/Size 5
>>
startxref
197
%%EOF
```

## How it all works together

When a PDF reader opens a PDF file, it goes to the back of the file, finds
the `startxref` pointer, and stores that byte offset to remember where the xref
table is.

In our case, it sees
```
startxref
197
%%EOF
```
And knows that the xref table starts at byte 197.

It will thenn back up to the trailer to find the document root.
```
trailer <<
/Root 1 0 R
/Size 5
>>
```
It sees that the root is Object 1, and that there are 5 objects in the xref table.

It would then go to byte 197, the start of the xref table, and look for the first
entry in the table (zero-indexed)

```
xref
0 5
0000000000 65535 f <-- IGNORED, this is the 0th index.
0000000009 00000 n <-- READ, this is the 1st index.
```

It sees from the table that the first object, the document root, is at byte 9.
It will then read from byte 9 to the `endobj` keyword.

```
1 0 obj
<<
/Type Catalog
/Pages 2 0 R
>>
endobj
```

It sees that the `/Pages` Root is object 2. Again, it will use the `xref` table
to find object 2.

```
xref
0 5
0000000000 65535 f
0000000009 00000 n
0000000057 00000 n <-- object 2
0000000114 00000 n
0000000177 00000 n
```

It sees object 2 is at byte 57, so it jumps to byte 57 and reads until it finds
an `endobj` tag

```
2 0 obj
<<
/Type /Pages
/Count 1
/Kids [3 0 R]
>>
```

Let's assume you want to open the first page. The first page is object 3.
Again, we go back to the xref table for object 3's byte offset.

```
xref
0 5
0000000000 65535 f
0000000009 00000 n
0000000057 00000 n
0000000114 00000 n <-- object 3
0000000177 00000 n
```

Object 3 is at byte 114, so we jump there and read the object.

```
3 0 obj
<<
/Type /Page
/Contents 4 0 R
/Parent 2 0 R
>>
endobj
```

The contents for the page are object 4, so we check the xref table to see where
object 4 is:

```
xref
0 5
0000000000 65535 f
0000000009 00000 n
0000000057 00000 n
0000000114 00000 n
0000000177 00000 n <-- object 4
```

So we jump to byte 177 and see what to render for this page.
```
endobj
4 0 obj
null
endobj
```
Object 4 is the null object, so this page's contents are null.

And with that, we've read the entire PDF.

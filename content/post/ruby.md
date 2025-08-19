---
title: "Why I Avoid Ruby for new Projects"
author: "Russell Waterhouse"
description: "I worry about Ruby's ecosystem"
tags: ["Ruby", "RubyOnRails"]
date: 2025-07-30T11:54:09-06:00
draft: false
---


# Why I Avoid Ruby for New Projects


1. Azure SDK for Ruby is archived: (https://github.com/Azure/azure-sdk-for-ruby)[https://github.com/Azure/azure-sdk-for-ruby]
2. PayPal deleted their Ruby SDK and started another one that only contains 3 of PayPal's API endpoints at the time of writing: (https://github.com/paypal/PayPal-Ruby-Server-SDK)[https://github.com/paypal/PayPal-Ruby-Server-SDK]
3. Azure storage client library for Ruby is deprecated: (https://github.com/azure/azure-storage-ruby)[https://github.com/azure/azure-storage-ruby]

In general, if I use the dependencies that Shopify or GitHub use, the ecosystem
seems to be flourishing. However, if I step one toe outside of that well-trodden
path, I find myself in a place where I either need to use archived dependencies
for security-critical functions, such as accessing an Azure Key Vault, or I
need to roll my own code for those security-critical functions.

And yes, I can read the Azure documentation for how to format a GET request to
an Azure Key Vault. Or I could fork the open-source archived repo and vendor my
own version that I maintain. However, when I could just start a project in a
more popular language with a bigger ecosystem where I don't have to write that
code, and the dependencies are maintained by Azure itself, why would I pick
Ruby for a new project?

Now, I love Ruby. I think there's a fundamental care for developers that Ruby
has that I haven't seen replicated in any other language I've ever used.
The fact that array.size and array.length BOTH exist because the developers
knew we'd try using both... why hasn't every other language done that?

But when I'm making business decisions, I'm not sure that I'm so much more
productive in ruby that it's worth the time it would take for me to absorb the
cost of this ecosystem.

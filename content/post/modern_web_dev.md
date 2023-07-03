---
title: "Modern_web_dev"
author: "Russell Waterhouse"
description: "description here"
tags: ["", ""]
date: 2023-07-02T19:17:17-07:00
draft: true
---

# Web Dev Explained Simply

If you're new to the web dev scene, you're almost certainly overwhelmed with the number of technologies that exist and how they all link together.

Figuring out what's current best practice, what technology replaces what, and how different technologies link together is mind boggling.
I want to try to explain it to you in the simplest terms.

## The Web Server
When a user goes to https://example.com, their web browser send a GET request to https://example.com.

With some networking magic of DNS resolvers and TCP routing that I'm not going to explain here, your 
server will receive a GET request to its port 443 (if everything is set up correctly). 

The technology that takes that GET request at port 443 and handles it correctly is 
the web server. The two most popular are NGinX and Apache. 


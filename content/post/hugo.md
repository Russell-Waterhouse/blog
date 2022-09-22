---
title: "Using Hugo To Create A Blog"
author: "Russell Waterhouse"
description: "description here"
date: 2022-09-21
toc: false
tags: ["Hugo", "JAMStack", "Static Site Generators", "Blog"]
---

## Situation Background
When I decided to finally take my personal blog off of my LAN and put it up on the open internet, I had 
to decide What technologies I wanted to use. 
While the blog was still small with only a few posts, now was a good time to make any migrations that I wanted to make. 

## What I had Before
Previously, my blog an old WordPress instance running on an old laptop I had flashed with a copy of Ubuntu Server. 

Honestly, WordPress offered more features than I needed or wanted, and I'm a strong proponent for minimizing
attack surface. This is even more important when exposing services to the open internet. With wordpress, 
all it would take would be me being one day too slow to patch my wordpress instance before my blog was owned. 

For a student going into finals season, I can't guarantee myself to always be on top of patching with the required 
amount of consistency. 

## What I Decided to Try
With all the hype around JAMStack (JavaScript, API's, Markdown) websites, I thought I would try a static site generator. I won't get too deep 
into the JAMStack here, as I'm not using any JavaScript or API's here on my blog (yet). 

It's in the "Always Learning" spirit, it provides me with a more secure website, and it allows me to have my site hosted for free. 
So, for now it's what I'm using. If I see something better, I'll be sure to try it, but right now it's the solution I've got. 

## My Setup
I first downloaded HUGO onto my laptop. I then created a folder and used hugo to make a blank website. 
I then went onto Hugo's website and downloaded a theme that I liked. I spent another hour customizing the theme, 
and deemed it good to go. 

Including all the time reading the documentation, that was about 2 hours of work. I spent another hour copy-pasting all my 
blog posts from my LAN WordPress instance to the markdown folder on my computer. 

After that, I setup a GitHub repo, and pushed my project to it. That took less than 10 minutes. 

I signed up for an account with Netlify, who I use to host the blog (for free). They connect directly into the GitHub Repo and update the website every time 
there's an update to the main branch. It took less than a half hour to have everything configured. 

Lastly, I bought a domain on namecheap. This part took the longest, as I had to wait for verification and 
DNS records to propagate, and I messed it up the first time. So that part took 10 minutes of work, and 2 days of waiting. 

That gives me a whole blog and CI setup for zero hosting cost, the cost of a domain, and less than 4 hours of work.

## Initial Impressions of the Workflow
I've only been using HUGO for a week, but I already like the workflow I've set up. 
It looks something like this. 
1. I open my computer and write a blog post in a .md file
2. I use 
    ```bash
    hugo serve
    ```
    to test that the blog post looks ok locally  
3. I push my changes to github and open a PR  
4. I look at the deploy preview, to make sure there are no glaring mistakes.   
5. I merge the PR  

That's it. The infrastructure does the deployment. The whole process is streamline and easy. 

So far, it was everything I hoped for. It's a static website where I don't have to worry about the CSS, the hosting, or writing <html> tags by hand. 
It's as secure as I need it to be, and gives me a place to post my ramblings. 

It's perfect for my current use case



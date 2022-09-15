---
title: "How I’m Improving my Operational Security (OpSec)"
author: "Russell Waterhouse"
description: "A summary of my opsec improvements for 2022"
tags: ["security", "cybersecurity"]
date: 2022-01-18T12:04:55-07:00
---
I’m always trying to improve my daily OpSec. This will be a tutorial examining and explaining this process, as I have done it. I have put each step I’ve taken in the increasing order of difficulty.  Many of these steps are platform-agnostic, so if you’re using windows or mac there will be things for you to learn too!

# What Have I Already Done

## Keep Software Updated

This is probably the most important item on this list, and it is first for a reason. If you’re running windows 10/windows 11 or MacOS, these updates happen automatically. This is a GOOD thing! MANY attacks rely on vulnerabilities for which patches are available but the victim hasn’t yet downloaded.

If you’re running Linux, you probably have the freedom to decide when you update your packages. If you’re disciplined, you can keep doing it by hand. That’s what I do, and my system is updated 2-3 times a week. If you’re more likely to forget to run these updates, set up a cron job for it and never worry about it again.

If you don’t get anything else from this blog post, just remember to keep your system updated.

## Use a Password Manager
I started using KeepassXC a few months ago, and I love it. I’m never going back to memorizing passwords again.   This wasn’t a switch I just flipped one day where I moved all my passwords over at once. Instead, I just started changing passwords when I logged into things. The more often I logged into a service, the quicker it was updated to a password manager password.  There are probably still a few services that I don’t have setup on my password manager, but these are things that I haven’t used in 6 months or more.

These passwords are long and very random. If one is compromised other passwords are still safe. I don’t have to bother remembering these passwords, and I don’t ever have to go through that pesky “I forgot my password email me a reset link” process. For me, it’s both more convenient and more secure.

KeepassXC isn’t a service that does remote backups of your passwords, and you cannot access them on other devices. This works well for me, and I always keep 2 physical backups of my passwords on external drives (keepass makes that process very easy). If you don’t want a system with this much maintenance, use a different password manager. I haven’t heard a good reason not to use the one that ships with your web browser, so I would recommend that.

## Sign up for 2-Factor Authentication
This one is pretty simple. Take advantage of the feature on any website that allows you to sign up with 2FA. When you do accidentally click on that phishing link (and we all do eventually), 2FA will be the thing that saves you.

## Use the Right Browser/Search Engine

Your web browser is your biggest attack surface when it comes to the outside world, and you should use one that is both secure and private.

We’ll start with my recommendation here for those that just want a simple answer: just use the Brave browser and Brave search. I have been for months on both my laptop and my phone and it provides a wonderful experience and breaks very little.

Now, we’ll move into what I do. I have 4 browsers, each with a different use case. I’ll break them down from most to least often used.
### Brave with BraveSearch

I use this browser for most things day-to-day, especially things that I need to log into.
### Firefox with DuckDuckGo

I turned off cookies and JavaScript on Firefox and use this when I’m just browsing the internet. Most often, this is the browser I use if I’m reading the news or looking for tech answers on the arch wiki or stack overflow.

This setup breaks a LOT of websites. Some load without ads or cookies or JavaScript, and display only the content that I want to see. Some just never load at all. Some load all the text, but no images. It’s a mixed bag, but I don’t use it for anything that isn’t acceptable. The point of this browser is somewhat anonymous and secure casual browsing.
### Chromium with Google

This isn’t used very often, but has 2 important use cases.

1. Where security is the most important (i.e. for logging into my online banking portal).  

You can say as many bad things you want about Google, but their security team has my utmost respect. If you don’t follow cybersecurity news, just trust me when I say they are doing a good job. When they catch wind of a vulnerability, they often release a patch within a day or two.  Compare this to other companies that wait for months, and you can start to see why Google has my respect here.

2. Where Brave or Firefox break. 

Because Chrome is such a popular browser and I’m running stock chromium, you can almost guarantee that any website that breaks on Brave or my locked down Firefox will work without complaint in Chromium.

### Tor with DuckDuckGo

Again, this one isn’t used very often, but occasionally I’ll hear an interesting piece of cybersecurity news that I want to know more about. I would rather the search “how does X malware work” not be tied to me.  While I’m searching for information like that purely for my own interest, it doesn’t look good.


# Things I Plan to  Implement

Just a word of warning, everything in this section is a big project.  These projects range from mostly done to not yet started, but all are large and require their own write up. I will keep this page updated, and when I have all the details concisely written up, I will post them.  The following are presented in no particular order.
## Use a firewall

Linux offers a wide range of software options and settings to accomplish this, and I would rather only do this once. I’m currently comparing features to my threat model and I will post the write up here once the project is complete.
## Sandboxing

I plan to setup my system with some fairly strict sandboxing options. This just generally prevents apps in my system from acting in a malicious way.  It is well documented that supply chain attacks are very hard to mitigate on open source platforms, so this is one of my more important projects.
## Setting up a RaspberryPi for DNS blocking

I have lots of plans for my raspberry pi, and this is just the start. Updates coming as soon as the chip shortage ends!

## Remove my Information from the Web

I can improve my security position all I want, but this won’t stop other companies from getting hacked and releasing my information anyways. Thus, I plan to delete as many old accounts and remove as much information as possible. Some will stay, for example this blog and my Linkedin aren’t going anywhere, but a lot will go. If I’m not happy with the changes, I can always open a new account again.

I’ve started this project with Microsoft, and my move to Linux and clearing of my OneDrive.

Next on the list is likely to be Facebook, which I haven’t actively used in a very long time.

After that, maybe Google? I haven’t decided on that one yet. That one would take the most time, but the reward might be worth it.

This is a massive project that will take A LOT of time. Regardless, I plan to take it on anyways. I’m currently writing up a plan of attack, which I will post before I

## Keep Good Backups.

This is mostly to mitigate the threat of ransomeware, with the added mitigation of data corruption problems. Currently, I manually backup any files that I am done using every quarter, but that leaves me open to devastating losses of data, if something bad were to happen a week before one of my scheduled backup sessions. The process is also far too manual – I’m currently manually selecting files and moving them to my external hard drive. I’ll be looking at setting up a good backup system in the near future, one that is automated and runs as often as possible.


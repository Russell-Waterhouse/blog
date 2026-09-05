---
title: "The Most Prolific Web Dev Myth"
author: "Russell Waterhouse"
description: "The most common web dev myth examined"
tags: ["Ruby", "JavaScript", "Python"]
date: 2026-09-03T16:36:11-06:00
draft: false
---

# The Most Prolific Web Dev Myth

Tell me if you've heard this before:

"It doesn't matter that the server is slow, most of the latency will be in the
db call or the network."

I have.

This is bad for two reasons. It's bad because the part of it that's somewhat
true, nobody actually actually uses, and it's bad because the part of it
that isn't true everyone takes as gospel.

The part that's true is the second part. Most of a user's latency will probably
be in the network call and the db call.

The part that isn't true is the first part. It ABSOLUTELY matters if the server
is slow.

Now notice that this doesn't say "performance doesn't matter." It says "the
server's performance doesn't matter." These are two different arguments.

If you want to know why the "performance doesn't matter" argument is bunk, take
26 minutes and watch ["Performance Excuses
Debunked"](https://youtu.be/x2EOOJg8FkA?si=uuGSmnY5tCtgH-Cp) from Casey
Muratori.

If you want to know why the "server's performance doesn't matter" argument
is bad, keep reading.

## The Part That's Not True

The part that's not true is that the speed of your server doesn't matter. It
matters. This is usually used to justify using Python or Ruby or JavaScript on
the server. These languages are known to be both slow and memory-hogs. For this
reason I'm going to talk both about memory AND speed, not just speed, even
though the common saying is "it doesn't matter if it's slow." I think that's
fair.

### Memory

The cool thing about the cloud is that you pay for CPU and memory.

This means if your server process uses less memory, you spend less money.
Often by a lot.

If you're running your server process serverless, every megabyte of memory you
don't use you aren't charged for.

If you're running kubernetes, every megabyte you save, you save at least twice, because
you always have at least two pods running. This means saving memory can usually save you a VM
size, if not several.

If you're buying your own servers and not in the cloud, you're paying RAM
prices directly. You can't escape the savings from using less memory.

### Speed

So what about the speed?

I think a lot of people think that the speed of a web language doesn't
matter.

For a single request, they might be right. But for many requests?
The speed hit that slow interpreted languages take means they degrade
much quicker.

Take a look at Anton Putra's YouTube channel, where he frequently pushes
different web technologies like
[NodeJS and Go](https://youtu.be/ZslbMp_T90k?si=QF8-MuYJhgJjix0R) to their
breaking point.

In every one, the slow interpreted language gets trounced by the fast one.

Saturation is how your web app will fail at scale, and by then it's too late.
You're in a hell of horizontal scaling, vertical scaling, caching, and rewrites.

## The Part That's True

The part that's true is a bunch of the user's time is going
to be taken by network calls. How bad of a problem is that? Let's find out!

### Breaking Down The "Napkin Math" Numbers

So what are the numbers, roughly? If the user clicks "submit" on your
web app, how long should it take to show the result of that action, assuming
you're not doing anything smart with caching, pre-fetching, or pre-sending.

I'm not even going to go very deep here. Everything I'm about to say is so so
surface-level.

I'm not even going to look at the google results, just the AI overview, because
that's how surface-level this is. If I wanted real numbers, I would measure
them myself.

Google query: "how long does an SQL query take in an indexed database in the same data centre as my server?"

AI Overview answer: "A simple indexed SQL query in the same data centre usually takes between 1 and 5 milliseconds to finish.
Time Breakdown
- Network Latency: Moving data between your server and the database inside the same building takes about 0.2 to 1 millisecond.
- Query Execution: Finding the row using an index and reading it takes about 0.5 to 4 milliseconds for simple lookups."

Google query: "how long does a network request take to go from Canada to Australia"

AI Overview answer: "A round-trip network request (ping) between Canada and Australia typically takes 180 to 240 milliseconds (ms).
Key Breakdown of Network Speed
- One-Way Travel Time: A single-direction request takes about 90 to 120 ms to go from one country to the other."

So let's say you have a user in Canada and a server in Australia, and that's
all you have. No data centre closer to your customers. What's the worst case?

Your submit button should be able to show a response in something like
4 + 1 + 1 + 240 = 246ms,
assuming you're doing something smart like re-using a connection and not doing
the TCP 3-way handshake on every request.

That's not exactly 60fps, but ~250ms is pretty quick for Canada to Australia,
which has got to be somewhat close to a worst-case scenario. For reference, the
average blink takes 100-400ms (again, according to google AI overview).

So the worst case is the blink of an eye. What's the best case, for a user
closer to your data centre, or if you were doing something fancy with a CDN?

Let's take all the faster ranges of the numbers above: db lookup network latency
of 0.2ms each way, db lookup time of 0.5 ms, and your customer is close to your
data centre and network takes 20ms, which is what I get right now if I ping
8.8.8.8 (google's DNS server), your total response time is 20 + 2(0.2) + 0.5 =
20.9ms. That is 47fps if ya nasty, which is faster than all the 30fps games
that I grew up playing and loved.

If I ping 1.1.1.1 (CloudFlare DNS) I get 2ms ping times, setting our upper
bound at 2 + 2(0.2) + 0.5 = 2.9 ms. As that speed the user's 60hz monitor
wouldn't be able to refresh fast enough to display the results of their submit
button.

So, how many web apps do you use where every interaction you have takes a
quarter of a second, in the worst case? How many web apps do you use where
every interaction resolves about as fast as you could blink, if not faster?

None?

Me neither.

And that's my point. If the massive lag we see on most web apps is just about
network and database, without even doing anything like pre-loading or caching,
we could get much better performance.

### So, Why so Laggy?

So if the network call or the database only accounts for 250ms, why does 
every web app you log into take multiple seconds to load?

Mostly bad design. 

The initial page load isn't one request, it's seven hundred (in the
case of microsoft teams, that's not an exageration).
And those seven hundred aren't in parallel, they're in series.
And each request isn't hitting the database once, it's hitting multiple
times.

## So What Can You Do?

First, I have to say that if you don't have buy-in from your team and your
management, everything I'm about to propose will be hard, if not impossible.
Here's what you can
probably do without the buy in.

1. Put indexes on database tables and keep them up to date.

It's a small win, but it's a win.

Everything else is going to take buy-in.

I leave it to you to figure out how to get buy-in. 

Maybe you mention that there are whole new waves of products that are taking
market share almost purely on performance features. [FilePilot, the fast file
explorer for windows is replacing Windows Native File
Explorer,](https://filepilot.tech/) [Linear is replacing
Jira,](https://linear.app/) and [Blick Video Editor just hit open
beta](https://blickeditor.com/)

Maybe you mention the [massive re-writes in Facebook, Twitter (now X), Uber,
Slack, Netflix, Yelp, Shopify, LinkedIn, eBay, HubSpot, PayPal, SalesForce,
and Microsoft where the entire point of the rewrite was to improve
performance.](https://www.computerenhance.com/p/performance-excuses-debunked)

Maybe you mention that ["every 100ms in added page load time costs amazon 1% of
revenue."](https://www.conductor.com/academy/page-speed-resources/faq/amazon-page-speed-study/)

I leave that to your discretion.

Assuming you have buy in, here's what you can do:

1. Use a compiled language on the server. I would choose Go or Rust.
2. Track performance metrics throughout development. Failing to meet a certain
   bar should block a merge.
3. Do things with performance in mind. JSON is actually pretty CPU-expensive to
serialize and de-serialize. Look at alternatives.
4. Take the time to find the SQL Query that performs best.
5. Try a few different ways to speed up your db queries. Redis caches, read replicas, and so on.
6. Pre-fetch other pages in the background. If the user just clicked to page 2 of a paginated table, why not pre-fetch page 3?
7. Batch large operations. Loading a page should really only take one network request.
8. Look at smart ways to use network resources. Maybe re-use connections so you aren't round-tripping 3x for every request for the TCP handshake.

A bunch of that isn't very hard, objectively speaking. The hardest part will be that it's not
normal.
You might have to combine two GET endpoints like api/v1/user/theme and api/v1/user/settings
into /api/v1/page/settings.
In that endpoint, you might have to do a join. 
In that join, you might have to fiddle with the raw SQL a few ways to get it to perform well.
Maybe a db index is required.
You might have to not serialize with JSON. Maybe protobuf, maybe you just send the raw html
and use a framework like data-star.
You might have to pre-fetch that data so that when the user clicks it, page is ready on
the next frame. 

But you could do all of that. Literally none of what I just said is impossible. 

Most of it isn't even hard. The idea of pre-fetching requests or batching network data
into one request isn't radical, it's just different from what we normally do in web dev.

But it doesn't have to be.

---
title: "Web Development Myths"
author: "Russell Waterhouse"
description: ""
tags: ["", ""]
date: 2026-09-03T16:36:11-06:00
draft: true
---

# TODO: title here

Tell me if you've heard this before:

"It doesn't matter that the server is slow, most of the latency will be in the
db call or the network."

I have.

This is bad for two reasons. It's bad because the part of it that's somewhat
true, nobody actually believes, and it's bad because the part of it that isn't
true everyone believes.

The part that's true is the second part. Most of a user's latency will probably
be in the network call and the db call.

The part that isn't true is the first part. It ABSOLUTELY matters if the server
is slow.

## The Part That's True

I define belief as "you think something is true and act accordingly."

If you believe cars are dangerous to pedestrians, you will look both ways before
crossing the road.

If you actually believed "it doesn't matter that the server is slow, most of the latency will be in the
db call or the network.", here are some things you would do:

1. Have indexes on all of your common db queries.
2. Have tried different versions of your most common queries to see what performs best with your database.
3. Have tried different ways to speed up your db queries. Redis caches, read replicas, and so on.
4. Have read browser HTML specifications so that you can take advantage of browser caching so network requests don't need to be repeated.
5. Batch large operations. Loading a page should really only take one network request.
6. Pre-load other pages in the background. If the user just clicked to page 2 of a paginated table, why not pre-load page 3?

I could go on, I didn't even mention anything fancy like a CDN, but here's my
point: if you actually thought that your database and network were going to be
the biggest problems, you would adopt strategies that would actually measurably
mitigate that.

Most web apps are pretty bad. I suspect most have, at most, put indexes
on their database once and never updated them.

This does make an opportunity for you though. If you were to do all of these,
you could provide an experience that is so much better than the competition.

Or even if you're just a developer who is a cog in a machine and don't care
about your customer, it's gotta look good when you tell your manager you
reduced latency by 90%. According to everything published that I've read, drops
in latency almost universally equate to a more successful product, both
financially and from a user-experience perspective.

However, it would mean having to do things differently than what's done
traditionally. Batching large operations means you can't just have a GET and
POST and PATCH endpoint for each of your models and call it a day, because in
my experience, the most-used pages in a web app will interact with several
models at once.

You might have to make an endpoint like GET /api/v1/page/welcome which loads all
of the data for the welcome page. The query on the backend might have to do a
join. You might have to do some database work to make that join perform well.


## The Part That's Not True

The part that's not true is that the speed of your server doesn't matter. It
matters. This is usually used to justify using python or ruby or javascript on
the server. These languages are known to be both slow and memory-hogs. For this
reason I'm going to talk both about memory AND speed, not just speed, even
though the common saying is "it doesn't matter if it's slow." I think that's
fair.


### Memory

The cool thing about the cloud is that you pay for CPU and memory. 

This means if your server process uses less memory, you spend less money.
Often, by a lot.

If you're running your server process serverless, every megabyte of memory you
don't use you aren't charged for.

If you're running kubernetes, every megabyte you save, you save at least twice, because
you always have at least two pods running. This means saving memory can usually save you a VM
size.

If you're buying your own servers and not in the cloud, you're paying RAM
prices directly. You can't escape the savings from using less memory.

### Speed

So what about the speed? 

I think a lot of people think that the speed of a web language doesn't
matter. 

## Appendix A: Breaking Down The "Napkin Math" Numbers

So what are the numbers, roughly? If the user clicks "submit" on your
web app, how long should it take to show the result of that action, assuming
you're not doing anything smart with caching, pre-fetching, or pre-sending.

I'm not even going to go very deep here. Everything I'm about to say is so so
surface-level.

I'm not even going to look at the google results, just the AI overview, because
that's how surface-level this is. If I wanted real numbers, I would measure
them myself.

Google query: "how long does an SQL query take in an indexed database in the same data center as my server?"
AI Overview answer: "A simple indexed SQL query in the same data center usually takes between 1 and 5 milliseconds to finish.
Time Breakdown
- Network Latency: Moving data between your server and the database inside the same building takes about 0.2 to 1 millisecond.
- Query Execution: Finding the row using an index and reading it takes about 0.5 to 4 milliseconds for simple lookups."

Google query: "how long does a network request take to go from Canada to Australia"
AI Overview answer: "A round-trip network request (ping) between Canada and Australia typically takes 180 to 240 milliseconds (ms).
Key Breakdown of Network Speed
- One-Way Travel Time: A single-direction request takes about 90 to 120 ms to go from one country to the other."

So let's say you have a user in Canada and a server in Australia, and that's
all you have. No data center closer to your customers. What's the worst case?

Your submit button should be able to show a response in something like
4 + 1 + 1 + 240 = 246ms,
assuming you're doing something smart like re-using a connection and not doing
the TCP 3-way handshake on every request.

That's not exactly 60fps, but ~250ms is pretty quick for Canada to Australia,
which has got to be somewhat close to a worst-case scenario. For reference, the
average blink takes 100-400ms (again, according to google AI overview).

So the worst case is the blink of an eye. What's the best case, for a user
closer to your data center, or if you were doing something fancy with a CDN?

Let's take all the upper ranges of the numbers above: db lookup network latency
of 0.2ms each way, db lookup time of 0.5 ms, and your customer is close to your
data center and network takes 20ms, which is what I get right now if I ping
8.8.8.8 (google's DNS server), your total response time is 20 + 2(0.2) + 0.5 =
20.9ms. That is 47fps if ya nasty, which is faster than all the 30fps games
that I grew up playing and loved.

If I ping 1.1.1.1 (cloudflare's DNS) I get 2ms ping times, setting our upper
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


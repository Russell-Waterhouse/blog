# Dear Software Engineers: Your Requirements Are All That Matter

Browsing through whatever tech forum
you choose, you'll see blog posts and
rants from different engineers and
influencers telling you that you should
go slower or faster or test more or test
less or replace JavaScript with TypeScrip 
or replace TypeScript with JavaScript
or whatever. 

Every single one of these opinions is wrong,
and I have no respect for anyone who
propagates these absolutes. 

Perhaps you work in an environment
where TDD is the right answer 
100% of the time. 

Not everyone does, and everyone that doesn't
thinks that you're an idiot for proclaiming
that it's the One True Way to write software. 

What we as engineers should do is
understand the requirements and make design
choices based off of that. 

Nobody likes that, because it's hard. 

It's hard because gathering good requirements is
hard. It's hard because understanding tradeoffs
is hard. It's hard because just listing 
different ways to solve a problem is hard. 

But that's why we get paid, because we do hard things. 

Here's a little table to get you started. 

| Requirement | Decision I recommend |
| ----------- | --------- |
| You're building a website that's mostly forms that doesn't need to scale to infinity, but needs to be built fast. Minimal client-side interactivity is needed.  | Ruby on Rails or Django, no SPA |

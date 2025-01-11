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

Most people don't like that, because most people think it's hard.  

But here's the big secret, it doesn't need to be hard. 

Let me give you some examples.

# Example 1: Tax Software

Let's say you're writing tax software for the general public to use during tax season.  How should you design that? Well, let's just dtart with some obvious facts about this. 

1. Taxes have to be correct. Incorrect values are unacceptable.
2. Tax codes change all the time.
3. Everyone does their taxes all pretty much at once.
4. Nobody cares if their taxes take 5 seconds to calculate the final result. 

Based on these statements, we can draw requirements. 
1. All tax calculating parts of the software need to have high correctness.
2. All tax calculation code should be easily modifiable.
3. This tax software should be able to handle a massive number of concurrent users.
4. This solution does not need to be blazingly fast.

And from the requirements, design decisions are also pretty easily made. 
1. Perhaps all tax calculations need to have 100% code coverage. Perhaps this part of the code should have invariance testing (TODO: link to what that is). Perhaps these calculations should be checked by tax professionals.
2. All tax calculation code should be pure functions with no side effects to make modifying them easy. That module should have very loose coupling so updating one tax calculations does not affect others that should not be affeccted.
3. Depending on how you define massive, perhaps you should wrap this service in docker and autoscale it horizontally and verticalky behind some load balancers. perhaps uou run several instances in different AWS zones.
4. We probably don't have to write it in C++ or Rust, we can probably just use Python or something like that.

As you can see, facts about the environment lead naturally to requirements which lead naturally to design decisions. 

Now of course, you might think that I've chosen bad design decisions from the requirements, and fair enough. But now that we have both the context and the requirement, we can actually have a hope of discussing the design decision in a way that makes sense. 


# So some other header here

I would like to see the industry move towards a standardized set of tools that we all agree work best in X context which has Y requirements. 

Here's a little table to get us started. 

| Requirement | Decision I recommend |
| ----------- | --------- |
| You're building a website that's mostly forms that doesn't need to scale to infinity, but needs to be built fast. Minimal client-side interactivity is needed.  | Ruby on Rails or Django, no SPA |
| You're building a website that needs to have high amounts of client-side interactivity, with multiple UI components depending on each other updating in real time as the client interacts with your site. | SPA Franework like React or Svelte |
| You're building an application that needs so much performance that it cannkt be interpreted, and this application is going to be open to the internet, so memory corruption vulnerabilities are unacceptable. | Write it in Rust |
| You're working on an embedded project where you need to integrate deeply with some C or C++ libraries. your project is never going to be connected to the internet. | Use C or C++ | 
| You're writing a section of purely computational code with reasonably well-defined requirements that is complicated | Use TDD |
| You're a bootstrapped startup trying to quickly find product-market fit | move as fast as you can without being negligant |
| You're a bank writing e-transfer software | Do literally every check and balance under the sun |

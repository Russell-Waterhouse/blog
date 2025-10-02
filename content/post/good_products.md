---
title: "What Makes a Good Product?"
author: "Russell Waterhouse"
description: "What does a good software product look like to me"
tags: ["productdesign"]
date: 2025-08-25T15:42:44-06:00
draft: true
---

## 1. Has an intuitive UI.

This rule is a bit fuzzy, but I can break down some of the qualities of an
intuitive UI.

- Every action the user can take has immediate (30fps or faster) feedback.
- The user should be able to tell what actions are available on the page
  they're on just by looking at it.
- The user should be able to tell how to navigate to the page that has the
  action they're looking for.
- The user should be able to undo any action they take, or be warned before taking
  the action that it is irreversible.

## 2. Has a responsive UI.

The user should know what's going on at all times. The UI should
never hang. When updates cannot happen at 30 fps or faster, loading animations
should be used. Updates happening at 30 fps or faster are preferable to loading
animations.


## 3. Secure
- Dependencies updated.
- No pre-auth actions allowed.


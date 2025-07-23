---
title: "My_style"
author: "Russell Waterhouse"
description: "description here"
tags: ["", ""]
date: 2025-07-23T16:40:21-06:00
draft: true
---

# The type of code that I like to write

## 1. Has no known bugs.

## 2. Has a responsive UI.
- Good performance.

## 3. Has an intuitive UI.
- Every action the user can take has feedback.
- The user should be able to tell what actions are available on the page they're on just by looking at it.
- The user should be able to tell how to navigate to the page that has the action they're looking for.

## 4. Handles errors correctly per error case.

Errors that should not happen:
- An error message with debug information is logged.
- An alert is sent to on-call person.
- An error message is displayed to user explaining that they didn't do anything wrong.

All IO return values are checked, and errors handled correctly.
## 5. Has a suite of e2e tests that test core functionality

## 6. Has a suite of unit tests to test pure functions

## 7. Has a CI/CD pipeline that runs these tests before deployment, but not on every push.

## 8. Secure
- Dependencies updated.
- No pre-auth actions allowed.

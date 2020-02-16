---
title: "git abandon"
draft: false
weight: 34
---

## Description

Remove already published local branches. If option `--force` is given, will delete branch by force, just like `git branch -D <branch-name>`.

`git abandon` is an alias command of `git-repo`.


## Usage

    git abandon [options]

## Options

Available options:

+ `--all`: Abandon all branches.
+ `-b`, `--branch`: Abandon specific branch.
+ `--force`: Delete by force, even local branch is not published yet.

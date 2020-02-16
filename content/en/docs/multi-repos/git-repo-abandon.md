---
title: "git repo abandon"
draft: false
weight: 50
---

## Description

Remove already published local branches. If option `--force` is given, will delete branch by force, just like `git branch -D <branch-name>`.

## Usage

    git-repo abandon [options] [<project>...]


## Options

Available options:

+ `--all`: Abandon all branches.
+ `-b`, `--branch`: Abandon the specific branch.
+ `--force`: Delete by force, even local branch is not published yet.

---
title: "git download"
draft: false
weight: 33
---

## Description

Download commits of the specific code review, and check out the tip commit by default.

`git download` is an alias command of `git-repo`.

## Usage

    git download [options] <Merge-Request-ID>
    git download [options] <Change-ID>/<Patch-ID>

Note:

+ For AGit-Flow and other compatible services, use `<Merge-Request-ID>` as a argument.
+ For Gerrit service, use `<Change-ID>/<Patch-ID>` format argument.


## Options

Available options:

+ `-c`, `--cherry-pick`: Run `cherry-pick` after fetching.
+ `-f`, `--ff-only`: Run `merge --ff-only` after fetching.
+ `-r`, `--revert`: Revert specific change of Gerrit.

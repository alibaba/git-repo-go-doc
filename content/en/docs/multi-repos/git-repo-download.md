---
title: "git repo download"
draft: false
weight: 47
---

## Description

Download commits of the specific code review, and check out the tip commit by default.


## Usage

    git repo download [options] <project> <Merge-Request-ID> ...
    git repo download [options] <project> <Change-ID>/<Patch-ID> ...

Note:

+ For AGit-Flow and other compatible services, use `<Merge-Request-ID>` argument.
+ For Gerrit service, use `<Change-ID>/<Patch-ID>` format argument.


## Options

Available options:

+ `-c`, `--cherry-pick`: Run `cherry-pick` after download.
+ `-f`, `--ff-only`: Run `merge --ff-only` after download.
+ `-r`, `--revert`: Revert specific change of Gerrit.

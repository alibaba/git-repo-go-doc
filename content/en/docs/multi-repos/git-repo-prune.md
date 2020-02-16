---
title: "git repo prune"
draft: false
weight: 51
---

## Description

Delete all published local branches.

It equivalent to `git repo abandon --all [<project>...]` command. `git repo prune` does not allow `--force` option, so it is safer.

## Usage

    git-repo prune [<project>...]

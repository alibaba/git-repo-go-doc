---
title: "Running"
draft: false
weight: 13
enableToc: false
---

## Execute git-repo for the first time

`git-repo` will perform some initialization tasks on the first execution. See: [git config extensions](../../gitconfig). Running any command will trigger the initialization tasks.

    $ git repo --version

Note: `git-repo` will be recognized as git subcommand so that we can execute `git repo` (without a dash).


## Manual for git-repo

Show help message of `git-repo`:

    $ git repo -h

or

    $ git repo

Show help message of of subcommands of `git-repo`, see the following examples:

    $ git repo help init
    $ git repo help sync

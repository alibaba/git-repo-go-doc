---
title: "git repo init"
draft: false
weight: 43
---

## Description

Initialize the current workspace or re-initialize workspace with different options.

Will create `.repo` directory inside workspace while executing `git repo init`. There are one manifest repository and manifest file `.repo/manifest.xml` inside it.

Some options of `git repo init` will save as git configs in the `.repo/manifests.git` repository, such as `-m <name>`, `-g <groups>` options.


## Usage

    git repo init -u <URL> [options...]


## Options

Available options:

+ `-u <URL>`: URL of manifest project.
+ `-b <branch>`: Manifest branch or revision to be checked out (default "master").
+ `-m <name>`: Manifest file name used to initialize workspace (default "default.xml").
+ `-g <groups>`: Restrict manifest projects to ones with specified group(s) [default|all|G1,G2,G3|G4,-G5,-G6] (default "default").

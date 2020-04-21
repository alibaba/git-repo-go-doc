---
title: "git repo forall"
draft: false
weight: 48
---

## Description

This command provides an iterator, run a specific shell command on each project.

The following environments can be used in a shell command:

+ `REPO_PROJECT`: Name of project.
+ `REPO_PATH`: Relative path to the project.
+ `REPO_REMOTE`: Name of the remote in the manifest.


## Usage

    git repo forall [project-list] -c command


## Options

Available options:

+ `-c`: Command and arguments for each project to run.
+ `-e`: If fail once, quit immediately.
+ `-p`: Show project name before output message.
+ `-g <groups>`: Filter projects by groups.
+ `-r <regexp>`: Search project name by regular expression, the matched project will execute the specific command.
+ `-i <regexp>`: Exclude project name by regular expression, the unmatched project will execute the specific command.

## Examples

1. Execute shell command to show the current working directory on each project.

        $ git repo forall  -c 'echo "Project $REPO_PROJECT in `pwd`"'
        Project git-repo/demo in /Users/jiangxin/work/aliyun/git-repo-demo/demo
        Project git-repo/demo-vendor in /Users/jiangxin/work/aliyun/git-repo-demo/demo/vendor
        Project git-repo/demo-doc in /Users/jiangxin/work/aliyun/git-repo-demo/doc

2. Show the latest git commit message on all projects.
       
        $ git repo forall -p -- git log -1 --oneline
        project demo/
        649941d topic1: initial

        project demo/vendor/
        443693b Initial vendor for project demo

        project doc/
        32f0be3 Initial doc for demo

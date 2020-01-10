---
title: "git repo forall"
draft: false
weight: 80
---

## 功能

该命令提供一个迭代器。可以为指定的每个项目运行指定的 shell 命令。

在 `git repo forall` 的 shell 命令中，可使用下列额外的环境变量：

+ `REPO_PROJECT` 是项目的唯一名称。
+ `REPO_PATH` 是相对于客户端根目录的路径。
+ `REPO_REMOTE` 是清单中远程系统的名称。


## 命令格式

    git repo forall [project-list] -c command


## 选项

主要的选项如下：

+ `-c`：要运行的命令和参数。此命令会通过 /bin/sh 进行评估，它之后的任何参数都将作为 shell 位置参数传递。
+ `-e`：如果一条命令执行失败，整个命令终止执行。
+ `-p`：在所指定命令的输出结果之前显示项目标头。
+ `-g <groups>`：通过组筛选项目，只对筛选后的项目执行指定命令。
+ `-r <regexp>`：通过正则表达式匹配项目名称，匹配的项目执行指定命令。
+ `-i <regexp>`：通过正则表达式排除项目名称，没有匹配的项目执行指定命令。

## 示例

1. 在每个项目中执行 shell 命令，查看当前目录

        $ git repo forall  -c 'echo "Project $REPO_PROJECT in `pwd`"'
        Project git-repo/demo in /Users/jiangxin/work/teambition/git-repo-demo/demo
        Project git-repo/demo-vendor in /Users/jiangxin/work/teambition/git-repo-demo/demo/vendor
        Project git-repo/demo-doc in /Users/jiangxin/work/teambition/git-repo-demo/doc

2. 显示最新一条 git 日志
       
        $ git repo forall -p -- git log -1 --oneline
        project demo/
        649941d topic1: initial

        project demo/vendor/
        443693b Initial vendor for project demo

        project doc/
        32f0be3 Initial doc for demo

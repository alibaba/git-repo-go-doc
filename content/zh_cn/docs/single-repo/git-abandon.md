---
title: "git abandon"
draft: false
weight: 34
---

## 功能

`git abandon` 是 `git-repo` 的一个别名命令，清理已经发起代码评审的本地分支。

如果使用 `--force` 参数，强制删除分支，等价于 `git branch -D <branchname>` 命令。

如果不使用 `--force` 参数（默认），则只清理已经发起代码评审的本地分支。


## 命令格式

    git abandon [options]

## 选项

主要的选项如下：

+ `--all`: 删除所有分支。
+ `-b`, `--branch`：只删除指定分支。
+ `--force`：强制删除，即使本地分支尚未发起代码评审。

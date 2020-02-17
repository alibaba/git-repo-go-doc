---
title: "git repo prune"
draft: false
weight: 51
---

## 功能

清理本地分支，删除已经被上游合并的本地分支。

该命令等价于 `git repo abandon --all [<project>...]`。相比 `git repo abandon` 支持 `--force` 参数，本命名更加安全。

## 命令格式

    git-repo prune [<project>...]

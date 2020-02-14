---
title: "git download"
draft: false
weight: 33
---

## 功能

`git download` 是 `git-repo` 的一个别名命令，实现下载代码评审的源代码。默认使用 checkout 命令检出待评审的提交。

## 命令格式

    git download [options] <Merge-Request-ID>
    git download [options] <Change-ID>/<Patch-ID>

说明:

+ 对于支持 AGit-Flow 协议的仓库，使用 `<Merge-Request-ID>` 格式下载评审代码。
+ 对于属于 Gerrit 服务上的仓库，则使用 `<Change-ID>/<Patch-ID>` 格式，即斜线分隔的两个数字。


## 选项

主要的选项如下：

+ `-c`, `--cherry-pick`：使用 cherry-pick 命令拣选代码评审的提交。
+ `-f`, `--ff-only`：使用 --ff-only 参数合并代码评审的提交。
+ `-r`, `--revert`：只适用于 Gerrit，撤销评审的提交。

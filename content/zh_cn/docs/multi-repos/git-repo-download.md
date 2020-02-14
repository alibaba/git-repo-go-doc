---
title: "git repo download"
draft: false
weight: 47
---

## 功能

实现下载代码评审的源代码。默认使用 checkout 命令检出待评审的提交。


## 命令格式

    git repo download [options] <project> <Merge-Request-ID> ...
    git repo download [options] <project> <Change-ID>/<Patch-ID> ...

说明:

+ `<project>` 和代码评审ID 成对出现。如果省略 `<project>` 默认为当前仓库。
+ 对于阿里巴巴代码平台上的仓库，使用 `<Merge-Request-ID>` 下载评审代码。
+ 对于 Gerrit 上的仓库，要使用 `<Change-ID>/<Patch-ID>`，即斜线分隔的两个数字。


## 选项

主要的选项如下：

+ `-c`, `--cherry-pick`：使用 cherry-pick 命令拣选代码评审的提交。
+ `-f`, `--ff-only`：使用 --ff-only 参数合并代码评审的提交。
+ `-r`, `--revert`：只适用于 Gerrit，撤销评审的提交。

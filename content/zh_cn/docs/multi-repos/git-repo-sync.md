---
title: "git repo sync"
draft: false
weight: 50
---

## 功能

执行 sync 子命令，会在工作区克隆、检出、更新 manifest 清单中包含的仓库。

首先更新 manfiest 仓库。

和上一次更新的项目列表（`.repo/project.list` 文件）做对比，如果 manifest 中包含新增项目，则克隆和检出新项目，如果 manifest 清单中移除部分项目，则工作区中删除相关项目（如果这些项目中未做修改的话）。

然后逐一更新工作区中的项目。

+ 如果项目尚未同步到工作区，则 `git repo sync` 相当于 `git clone`。

+ 如果项目已经同步到工作区，则 `git repo sync` 相当于：

        git remote update
        git rebase origin/branch

+ 如果 `git rebase` 操作导致合并冲突，请使用常规 git 命令（例如 `git rebase --continue`）解决冲突。


## 命令格式

    git repo sync [options...]


## 选项

主要的选项如下：

+ `-c`：只从服务端获取当前分支。

+ `-d`：工作区项目进入分离头指针状态，并切换到 manifest 清单文件指定的提交。该参数对于编译构建时严格按照 manifest 清单文件检出提交，丢弃工作区本地修改，非常有用。

+ `-f`：即使某个项目同步失败，也继续同步其他项目。

+ `-j <num>`：设定并发数。默认 4 个并发。

+ `-n`：只做网络端操作。即相当于只进行 `git fetch` 操作，不修改本地仓库的检出。

+ `-l`：只做本地端操作。即相当于只进行 `git checkout` 操作，而不进行任何网络操作。

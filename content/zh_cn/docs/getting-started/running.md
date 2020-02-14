---
title: "运行 git-repo"
draft: false
weight: 13
enableToc: false
---

## 运行 git-repo

初次运行任意 `git-repo` 子命令，会完成一些初始化工作，例如：[对 Git 配置文件进行扩展](../../gitconfig)。

因此 `git-repo` 安装完毕后，可以执行如下命令。

    $ git repo --version


说明：上面命令中 git 和 repo 之间可以不再需要短线，因为 Git 自动将具有类似 `git-<subcmd>` 的可执行文件视为自己的子命令。


## 查看 git-repo 的帮助

执行下面命令查看 git-repo 的帮助：

    $ git repo -h

或者

    $ git repo

注意：如果使用 `git repo --help` 或者 `git help repo`，则无法显示 git-repo 的帮助。因为这些命令激活了 git 的 man 手册，而非 git-repo 内置的帮助系统。

git repo 有很多子命令。可以用如下命令查看子命令的帮助：

    $ git repo help init
    $ git repo help sync

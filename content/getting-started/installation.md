---
title: "安装 git-repo"
draft: false
weight: 12
---

## 依赖

git-repo 依赖 git，在安装 git-repo 之前，需要确保已经安装了 git。


## 下载和安装 git-repo

1. 访问 git-repo 的下载页面: [https://github.com/aliyun/git-repo-go/releases](https://github.com/aliyun/git-repo-go/releases)。
   根据您的平台类型（Linux、Mac、或是 Windows），CPU 类型（amd64 或 386）下载并展开压缩包。

2. 如果是 Linux 或者 Mac OS X 平台，为下载文件设置可执行权限。例如：

        $ chmod a+x git-repo

3. 将下载的可执行文件复制到可执行目录。对于 Linux 和 Mac OS X 平台，这个目录可以是
   /usr/local/bin 或者其他目录。对于 Windows 平台，这个目录可能是 `C:\Windows\system32`。

        $ cp git-repo /usr/local/bin/

## 运行 git-repo

安装完毕，尝试执行下面命令。注意下面命令中 git 和 repo 之间可以不再需要短线，
因为repo 命令已经自动注册为 git 的一个子命令。

    $ git repo --version


## 查看 git-repo 的帮助

执行下面命令查看 git-repo 的帮助：

    $ git repo -h

或者

    $ git repo

注意：如果使用 `git repo --help` 或者 `git help repo`，则无法显示 git-repo 的帮助。
因为这些命令激活了 git 的 man 手册，而非 git-repo 内置的帮助系统。

git repo 有很多子命令。可以用如下命令查看子命令的帮助：

    $ git repo help sync

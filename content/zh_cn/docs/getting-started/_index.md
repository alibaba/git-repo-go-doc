---
title: "开始"
draft: false
weight: 10
---

## 快速开始

### Step 1：安装 git-repo

访问 git-repo 的下载页面: [http://git-repo.info/download.html](http://git-repo.info/download.html)。

将下载的 `git-repo` 可执行文件移动到可执行目录，如 `/usr/local/bin` 下，即完成安装。


### Step 2：运行 git-repo

运行一下 git-repo 命令，完成一些初始化工作：

    git repo version


### Step 3：单仓库下发起代码评审

进入本地检出的仓库工作区，执行如下命令，发起代码审核：

    git pr


### Step 4：多仓库工作流

`git-repo` 支持 Android 式的多仓库工作流。以 git-repo 代码仓为例：

1. 创建工作区。

        $ mkdir workspace
        $ cd workspace

2. 通过克隆 manifest 清单仓库，完成工作区的初始化。

        $ git repo init -u https://codeup.teambition.com/git-repo/manifests.git

3. 创建开发分支

        $ git repo start --all jx/topic1

4. 在工作区中开发，每个仓库的改动单独完成本地提交。

5. 执行下面命令，会扫描工作区所有仓库的改动，逐个向上游仓库发起代码评审。

        $ git repo upload

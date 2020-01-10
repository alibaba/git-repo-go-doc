---
title: "首页"
---

想像一下：

* 能否让贡献代码（创建代码评审）就像执行 `git push` 命令一样的简单？
* 开发者不用切换工具，将原来需要几分钟才能完成的创建代码评审的时间，缩短到几秒钟，是不是很酷？

这个工具就是 `git-repo`，它为 git 插上了翅膀。

# git-repo

git-repo 是一款客户端工具，实现从客户端直接发起代码评审，可以用在阿里巴巴的代码平台、以及
Gerrit 服务器上。

git-repo 并不会改变 git 用户的使用习惯，而是提供了对 git 命令的扩展。git-repo
安装之后，为 Git 提供了一系列的子命令（git repo, git peer-review, ...）。

![创建 Merge Request 速度大比拼](/images/compare-pull-request-creation.png)

传统的 GitHub 工作模式，代码贡献者要将代码推送到个人派生的项目，或者源项目中的个人/主题分支，再通过 Web 界面发起创建 Merge Request （Pull Request）。整个过程要经历多个步骤，开发者要切换到不同的工具才能完成。既耗时，又会在仓库中留下大量杂乱的主题分支（或者大量不同步的派生仓库）。

而使用 `git-repo`，一个用户只要拥有仓库的读取权限，就可以在本地工作区中执行下面的一条命令，将个人的代码贡献以 Merge Request 的方式贡献到服务端。

    $ git peer-review

## 服务端支持

git-repo 要求 Git 服务端提供相应的支持。我们在阿里巴巴的代码平台中设计了新的集中式工作流，能够完美支持 git-repo 工具的这种通过命令行模式发起代码评审。这种集中式工作流无需在仓库中为代码贡献者创建主题分支，就可以实现开发者围绕同一个代码仓库进行开发，代码贡献以 Merge Request 方式进行代码评审。

git-repo 也同样支持 Gerrit 服务器。阿里巴巴代码平台的集中式工作流和
Gerrit 工作流的异同：

1. 都是通过调用 git push 命令来创建代码评审。在 git push 命令使用了特殊的引用表达式，类似于：`git push origin HEAD:refs/for/master/...`

2. Gerrit 要求用户本地仓库安装 `commit-msg` 钩子，以便在提交说明中嵌入 `Change-Id`，实现开发者本地提交和服务器端代码评审之间的对应。而阿里巴巴的代码平台则通过传递 `<session>`，实现开发者的开发行为和服务端 Merge Request 的对应和追踪，而不需要客户端安装特殊钩子。

3. Gerrit 是每一个提交创建一个代码评审任务，一个特性的多个提交会创建多个评审任务，任务之间存在依赖，会因为依赖关系造成评审任务处于 pending 不能合入。而阿里巴巴的代码平台使用 Merge Request 方式进行代码评审，其中包含特性所有相关的提交，既提供对整个特性完整的代码评审，也提供逐个提交评审的能力。

4. 阿里巴巴代码平台支持 push option，通过 `git push` 命令 的 `-o options` 参数实现对 Merge Request 更多的控制，如设置 Merge Request 标题和描述等。

5. Gerrit 服务端通过名为 `gerrit receive-pack` 的应用响应客户端特殊的 push 命令。而阿里巴巴代码平台则通过 `agit-receive-pack` 应用来响应客户端特殊的 push 命令。

## git-repo 与 Android repo

Android 采用 Gerrit 提供代码评审服务，用名为 repo 的工具，实现多仓库管理以及和 Gerrit 服务器互动（下载代码、发起代码评审等）。因为 Gerrit 部署简单，很多项目都使用 Gerrit 管理代码。Gerrit 是一个合格的项目管理工具，但是缺乏项目、组织的抽象，让它很难成为一个统一的平台。如果一个公司使用 Gerrit，有多少个项目，就会有多少个 Gerrit 服务器，对于运维是一个灾难，也难以形成跨项目的代码协作。

为了方便 Gerrit 用户使用我们的代码平台，git-repo 完全兼容 Android repo 工具（部分子命令在开发中）。

1. Android repo 只支持 Gerrit 服务器。`git-repo` 采用了一套新的服务发现协议，同时支持阿里巴巴代码平台的集中式工作流（或者与之兼容的工作流）和 Gerrit 工作流。

2. Android repo 使用了符号链接等难以移植到 Windows 操作，难以在 Windows 平台使用。`git-repo` 在设计时考虑到了 Windows 使用的兼容性问题。

3. Android repo 只支持 manifests 仓库管理下的多仓库，而 `git-repo` 在此基础上，还支持单一 Git 代码仓的集中式工作流协同，并提供快捷的别名命令 `git peer-review`，或 `git pr`。

4. Android repo 使用 Python 脚本语言开发，`git-repo` 使用 Go 语言开发。

5. `git-repo` 命令的命名方式采用 `git-<subcmd>` 格式，扩展了 git 的命令集，即为 git 增加了一个名为 repo 的子命令。而且可以用 git 别名为 `git-repo` 设置别名命令，如 `git peer-review` 命令即是 `git repo upload --single` 的别名命令。

---
title: "标准化 Git 配置"
weight: 15
draft: false
---

`git-repo` 初次安装，需要执行任意一个 git-repo 命令以完成初始化。例如：

    $ git repo version

第一次运行的初始化工作，包含了对 git 配置的扩展。

`git-repo` 在用户主目录下创建了扩展的 Git 配置文件：`.git-repo/gitconfig`。该文件由 `git-repo` 自动管理，不要手工修改，因为手工修改会因为文件升级而丢失。


## 新增 git 别名命令

通过 git 配置文件扩展，增加了一些单仓库提效相关的 git-repo 别名命令：

别名命令         |  实际命令
:----------------|:--------------------------
git peer-review  | git repo upload --single
git pr           | git repo upload --single
git review（*）  | git repo upload --single

其中：

+ `git review` 别名命令与 OpenStack 社区的 `git-review` 工具重名，尽量使用 `git pr` 别名命令。

此外，还增加了一些常用的别名命令：

常用别名命令     |  实际命令
:----------------|:--------------------------
git br           | git branch
git ci           | git commit -s
git co           | git checkout
git cp           | git cherry-pick
git logf         | git log --pretty=fuller
git logs         | git log --pretty=refs --date=short


## 适配中文环境

如果提交中包含中文路径的文件变更，则 git-repo 为 Git 自动增添的如下面设置，能帮助中文路径正确地显示。

    [core]
            quotepath = false


## 其它可增强用户体验的 Git 设置

还增加了一些有助于提效的配置，如：

+ 在 git rebase -i 命令时，自动增加 `--autosquash` 参数，自动匹配 fixup 提交。

        [rebase]
                autosquash = true

+ 分支合并时创建的合并提交，提交说明中自动包含合入提交的简要说明。

        [merge]
                log = true

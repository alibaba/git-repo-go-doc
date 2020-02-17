---
title: "Git 配置文件扩展"
weight: 20
draft: false
enableToc: true
---

## 安装 git 配置扩展

`git-repo` 初次安装后，执行任意一个 `git-repo` 命令，即可自动完成 git 配置文件的扩展。例如执行命令：

    $ git repo version

`git-repo` 会在用户主目录下创建扩展的 Git 配置文件：`.git-repo/gitconfig`。该文件由 `git-repo` 自动管理，不要手工修改。如果手工修改该文件，会因为配置文件升级而丢失。


## 新增 git 别名命令

扩展的 git 配置文件中，包含了几条针对单仓库的集中式工作流的常用别名命令：

别名命令         |  实际命令
:----------------|:--------------------------
git peer-review  | git repo upload --single
git pr           | git repo upload --single
git review       | git repo upload --single
git download     | git repo download --single
git abandon      | git repo abandon --single

**注意**： `git review` 别名命令与 OpenStack 社区的 `git-review` 工具重名，尽量使用 `git pr` 别名命令。

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

提交中改动文件名如果包含中文，如下设置能帮助正确地显示中文路径。

    [core]
            quotepath = false


## 其它可增强用户体验的 Git 设置

在 `git rebase -i` 命令时，自动增加 `--autosquash` 参数，自动将 fixup 等提交适配到对应提交上。

    [rebase]
            autosquash = true

分支合并时创建的合并提交，提交说明中自动包含合入提交的简要说明。

    [merge]
            log = true

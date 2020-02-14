---
title: "git repo init"
draft: false
weight: 43
---

## 功能

初始化当前工作区，或修改前一次 git repo init 执行时的参数设置。

当 `git repo init` 命令执行完毕后，会在工作区中创建子目录 `.repo`。其中包含 manifest 清单仓库（`.repo/manifests`），以及清单文件（`.repo/manifest.xml`）文件。

部分 `git repo init` 命令的参数会以 git 配置变量方式保存在 `.repo/manifests.git` 仓中，例如 `-m <name>`、`-g <groups>` 参数，就记录在 git 配置文件的 `[manifest]` 小节中。


## 命令格式

    git repo init -u <URL> [options...]


## 选项

主要的选项如下：

+ `-u <URL>`：指定 manifests 清单仓库的 URL 地址。
+ `-b <branch>`：指定检出的 manifests 清单仓库分支，默认使用 `master` 分支。 
+ `-m <name>`：指定使用的 manifest 清单文件名称，默认使用 `default.xml` 文件。 
+ `-g <groups>`：指定项目分组。可以使用逗号分隔多个分组。分组在 manifest 清单文件中定义。

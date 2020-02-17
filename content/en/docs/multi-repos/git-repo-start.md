---
title: "git repo start"
draft: false
weight: 45
---

## 功能

以 manifest 清单仓库指定的版本为基准，为项目创建分支或切换分支。

## 命令格式

只对指定的项目，创建或切换分支：

    git repo start <branch-name> [project...]

为所有项目创建或切换分支，分支名 <branch-name>：

    git repo start --all <branch-name>

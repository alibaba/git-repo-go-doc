---
title: "升级 git-repo"
draft: false
weight: 14
enableToc: false
---

## 升级 git-repo

运行下面命令升级 `git-repo`：

    $ git repo upgrade

自动下载相应平台的 `git-repo` 升级包，完成应用的替换和升级。

如果由于文件权限或者其它原因导致升级失败，会给出错误提示。例如：

    $ git repo upgrade
    Download git-repo: ############################################################ 100%
    +--------------------------------------------------------------------------------+
    | Fail to upgrade. Please copy                                                   |
    |         /var/folders/5d/21v9l2z12j/T/git-repo-0.2.0-619707833                  |
    | to                                                                             |
    |         /usr/bin/git-repo                                                      |
    | by hands                                                                       |
    +--------------------------------------------------------------------------------+
    Error: upgrade failed

遇到类似上面的错误提示，手工完成文件复制。例如：

    $ sudo cp /var/folders/5d/21v9l2z12j/T/git-repo-0.2.0-619707833 /usr/bin/git-repo

---
title: "升级 git-repo"
draft: false
weight: 16
---

运行下面命令升级 git-repo：

    $ git repo upgrade

从[升级服务器](http://git-repo.info/download)自动下载相应平台的 git-repo 升级包，完成应用的替换和升级。

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

    sudo cp /var/folders/5d/21v9l2z12j/T/git-repo-0.2.0-619707833 /usr/bin/git-repo

## 命令格式

    git repo upgrade [options...]


## 选项

主要的选项如下：

+ `--url <URL>`：使用指定的升级服务器地址。默认使用 `http://git-repo.info/download` 作为升级服务器地址。
+ `--test`：升级到测试版本。测试版本是由升级服务器的 `version.yml` 的 test 字段定义的。

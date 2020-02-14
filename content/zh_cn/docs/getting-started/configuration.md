---
title: "配置 git-repo"
draft: false
weight: 14
---

在用户主目录下的 `.git-repo/config.yml` 文件，可以修改 git-repo 默认设置。如：

* verbose: 1 

        1: 显示 Info 级别日志；2: 显示 Debug 级别数据。

* loglevel: warning

        设置打印到日志时的日志级别

* logrotate: `<size>`

        日志回滚大小，默认 20MB

* logfile: `<file>`

        设置日志文件名称

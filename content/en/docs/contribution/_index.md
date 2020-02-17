---
title: "代码贡献"
draft: false
weight: 99
---

git-repo 采用 go 语言开发，设计中参考了 Android 的 repo 工具，在多仓库管理命令上和 repo 保持兼容。

参与 `git-repo` 开发，请向 `git-repo` 仓库发送代码评审请求。


## 代码仓库

+ 代码: https://github.com/aliyun/git-repo-go
+ 文档: https://github.com/aliyun/git-repo-go-doc


## 构建 git-repo

`git-repo` 使用了 go 1.12 中的 `go mod` 特性，编译 `git-repo` 请使用 go 1.12 或更高版本。

 
1. 克隆 git-repo 仓库

        $ git clone https://github.com/aliyun/git-repo-go.git

2. 构建

        $ cd git-repo-go
        $ make

    构建完毕，在当前目录下生成可执行文件 `git-repo`。

3. 编码风格测试

        $ golint github.com/aliyun/git-repo-go/...

4. 单元测试

        $ go test github.com/aliyun/git-repo-go/...

5. 集成测试

        $ make -C test


## 编写测试用例

单元测试用例使用 go 的 test 框架。

集成测试则使用 [sharness](https://github.com/chriscool/sharness) 测试框架。集成测试脚本位于 test 目录下。


## Bug 和需求

提交 Bug 或需求，请访问: https://github.com/aliyun/git-repo-go

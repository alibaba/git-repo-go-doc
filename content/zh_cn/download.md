---
title: "下载"
draft: false
weight: 20
---

根据您的平台类型（Linux、Mac、或是 Windows），CPU 类型（amd64 或 386）下载合适的软件包。

现代个人笔记本电脑请选择amd64下载。Linux开发机输入`uname -a`，输出包含`x86_64`选择amd64下载，输出包含`i386`选择386下载。

注：

1. sha 文件是软件包的 sha256 校验码。
2. pgp 文件是校验码文件的 PGP 签名。签名者公钥: [公钥1](/download/pubkey/key1.pub)、[公钥2](/download/pubkey/key2.pub)

# 最新版本

## 0.7.8 (2021-11-19)

### 变更

Improvements:

* arm64: native Apple Silicon (M1) support to Mac builds
* sshinfo: check response of `ssh_info` for bad hostname
* ci: remove azure-pipeline, use github-action instead
* Setup githb action
* test: turn off git advice and warnings
* After load manifests, check and fixup missing attrs
* sync: check published ref if has --check-published option
* sync: clean obsolete mirror repositories
* sync: remove obsolete gitdir if obsolete project deleted
* init: do not init repo with InitByLink for mirror
* sync: refactor: move UpdateProjectList() to workspace
* sync: instead of removing obsolete projects, show instructions


### 文件

+ Linux (amd64): [git-repo-0.7.8-Linux-64.tar.gz](/releases/v0.7.8/git-repo-0.7.8-Linux-64.tar.gz)
  SHA-256: 92fe06087dea70d34e4cf62786b2bf58f51a47407a89775825a006b80acf0dc3

+ Linux (386): [git-repo-0.7.8-Linux-32.tar.gz](/releases/v0.7.8/git-repo-0.7.8-Linux-32.tar.gz)
  SHA-256: fe9828bdc4a0ef298535121fef36d62b897b47217c9c419084a7c4838e864a64 

+ macOS (amd64): [git-repo-0.7.8-macOS-64.tar.gz](/releases/v0.7.8/git-repo-0.7.8-macOS-64.tar.gz)
  SHA-256: 8e5d1656bfc43ac5a88895f6e8149769099dfd71d59660e233ace926f6e938fe

+ macOS (arm64): [git-repo-0.7.8-macOS-arm64.tar.gz](/releases/v0.7.8/git-repo-0.7.8-macOS-arm64.tar.gz)
  SHA-256: 1b73d6abe145cdac7513acff8fc1783204880306483da1b3bd5ac9e4d4c4938f

+ Windows (amd64): [git-repo-0.7.8-Windows-64.zip](/releases/v0.7.8/git-repo-0.7.8-Windows-64.zip)
  SHA-256: fed6b48b04ca8495eab66fd647eb3a26989d24782435083972755fb55e6ed191

+ Windows (386): [git-repo-0.7.8-Windows-32.zip](/releases/v0.7.8/git-repo-0.7.8-Windows-32.zip)
  SHA-256: b2eda9cd23034a5fc80a9c053ee574492f07a3a52e487b84a7d299adcb763e5c


# 历史版本

访问：

+ https://github.com/alibaba/git-repo-go/releases

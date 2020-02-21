---
title: "Contribute"
draft: false
weight: 99
---

## Repositories

`git-repo` is an open source software, feel free to contribute.

+ Source code: https://github.com/aliyun/git-repo-go
+ Documentation (for this website): https://github.com/aliyun/git-repo-go-doc


## Build and test git-repo

`git-repo` is developed using [Golang](https://golang.org/). Please use go 1.12 or above to compile it.

1. Clone repository of git-repo:

        $ git clone https://github.com/aliyun/git-repo-go.git

2. Compile:

        $ cd git-repo-go
        $ make

3. Check code style using golint:

        $ golint github.com/aliyun/git-repo-go/...

4. Unit test:

        $ go test github.com/aliyun/git-repo-go/...

5. Integration test:

        $ make -C test


## How to contribute

### git-repo

Send pull request to [https://github.com/aliyun/git-repo-go](https://github.com/aliyun/git-repo-go).

Test cases are in the `test/` directory, using [sharness](https://github.com/chriscool/sharness) as test framework.

### Documentations

Send pull request to [https://github.com/aliyun/git-repo-go-doc](https://github.com/aliyun/git-repo-go-doc).

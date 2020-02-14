---
title: "git peer-review"
draft: false
weight: 20
---

`git-repo` 针对常用的单仓库的工作区，提供了快捷的创建代码评审的命令：`git peer-review`。该命令可以简写为 `git pr` 或者 `git review`。


## 1. 创建代码评审

使用 `git peer-review` 命令创建代码评审的步骤如下：

### 1.1 克隆远程仓库到工作区

克隆远程仓库到本地工作区，例如克隆本 git-repo 网站的仓库。 （如果工作区中已经存在该仓库，则忽略此步骤。）

    $ git clone https://codeup.teambition.com/git-repo/demo.git

切换到本地仓库的工作区：

    $ cd demo


#### 1.2 创建特性分支

在本地工作区中创建新的工作分支。这个步骤不是必须的，使用当前分支（如 master 分支）也可以。但是如果需要在一个工作区目录切换不同特性的开发，则创建分支是需要的，否则多个特性的代码可能混在同一个代码评审任务中，或相互覆盖。

    $ git checkout -b topic1 origin/master

上面命令的两个参数要重点说明一下：

+ 参数 `-b topic1` 设定了新的工作分支的名称。
+ 最后的 `origin/master` 参数，则是为了将新建分支和上游的 master 分支建立关联。这个参数很重要，如果忘了添加该参数，则在用 `git peer-review` 创建代码评审时，会提示补救措施。


### 1.3 工作区内开发和提交

在工作区中进行代码开发工作，使用标准的 git 命令进行提交。


### 1.4 发起代码评审

当完成本地开发后，需要将代码推送到上游仓库，并创建代码评审时，执行如下命令：

    $ git pr

该命令的参数有很多，可以设置代码评审需要的各项参数，例如：

* 指定评审者和关注者。多个用户名之间可以用（半角）逗号分开。

        $ git pr --reviewers 星楚,澳明 --cc 知忧

* 设定代码评审处于草稿状态，可以发表评审意见，但是不能合入。

        $ git pr --draft

如果当前分支相比远程分支没有新提交，则不会创建代码评审，显示提示信息如下：

    $ git pr
    NOTE: no branches ready for upload

如果已经发起过一次代码评审，且之后没有代码改动，也不会执行。显示的提示信息如下：

    $ git pr
    NOTE: no change in project . (branch topic1) since last upload
    NOTE: no branches ready for upload

如果本地分支未跟踪某一个远程分支，则 `git peer-review` 命令不知道该向哪个远程分支发起代码评审。必须设置本地分支和远程分支的跟踪，才可以发起代码评审。命令报错信息如下：

    $ git pr
    FATAL: upload failed: cannot find tracking branch
    
    Please run command "git branch -u <upstream>" to track a remote branch. E.g.:
    
        git branch -u origin/master

参照提示信息中的命令，建立工作区本地分支和远程分支的跟踪关系。


### 1.5 代码评审的编辑界面

输入 `git pr` 命令后，会打开一个编辑器，内容是此次代码评审的各项可定制的参数，内容如下：

    ##############################################################################
    # Step 1: Input your options for code review
    #
    # Note: Input your options below the comments and keep the comments unchanged
    ##############################################################################
    
    # [Title]       : one line message below as the title of code review
    
    # [Description] : multiple lines of text as the description of code review
    
    # [Issue]       : multiple lines of issue IDs for cross references
    
    # [Reviewer]    : multiple lines of user names as the reviewers for code review
    
    # [Cc]          : multiple lines of user names as the watchers for code review
    
    # [Draft]       : a boolean (yes/no, or true/false) to turn on/off draft mode
    
    # [Private]     : a boolean (yes/no, or true/false) to turn on/off private mode
    
    
    ##############################################################################
    # Step 2: Select project and branches for upload
    #
    # Note: Uncomment the branches to upload, and not touch the project lines
    ##############################################################################
    
    #
    # project ./:
       branch topic1 ( 3 commit(s)) to remote branch master:
    #         03c01e211122b49fe05f48e08fd3e1dd1c52e57e
    #         ec78989440697fbc13bfbd3ea082fe9b3fc5f2d7
    #         4e599aa284ed64ba12ba1b5b06fbbd3199846434

		
其中以字符 "#" 开始的行是注释，不要改动注释行，因为 `git-repo` 要根据注释行的内容判断用户输入内容用于更改哪项代码评审的参数设置。 例如：

+ 在 "# [Title]" 行的下面添加的内容，成为代码评审的标题。默认用提交说明的标题作为代码评审标题。
+ 在 "# [Description]" 行的下面添加的内容，成为代码评审的详细描述。默认用提交说明的内容作为代码评审的详细描述。
+ 在 "# [Issue]" 行的下面如果添加 Issue ID，则将代码评审和问题之间的建立关联。
+ 在 "# [Reviewer]" 行的下面添加代码评审者姓名，一个一行，或者用逗号分隔。
+ 在 "# [Cc]" 行的下面添加代码评审的关注者姓名，一个一行，或者用逗号分隔。
+ 在 "# [Draft]" 行的下面如果输入 yes，则表明要创建一个草稿模式的代码评审。
+ 在最下面的 "Step 2" 区域，显示当前项目将要上传到远程仓库的分支和提交列表。检查提交列表，如果不想创建此次代码评审，则将 "branch ..." 的行注释掉，或者删掉，则此次创建代码评审的任务终止。

保存内容，退出编辑器，则开始向服务端推送代码，并开始代码评审的创建。

编辑的内容会以模板的方式保存，以便在下一次执行 `git peer-review` 时复用。


### 1.6 完成代码评审的创建

`git peer-review` 命令执行完毕后，显示代码评审创建成功的消息，示例如下：

    remote: +----------------------------------------------------------------+
    remote: | Merge Request #7937 was created or updated.                    |
    remote: | View merge request at URL:                                     |
    remote: | https://codeup.teambition.com/git-repo/demo/merge_request/7937 |
    remote: +----------------------------------------------------------------+
    To ssh://codeup.teambition.com/git-repo/demo.git
     * [new branch]      topic1 -> refs/for/master/topic1

注意到提示信息中包含创建成功的代码评审的 URL 地址，通过浏览器访问该地址，显示创建好的代码评审。


### 1.7 服务器端仓库的变化

通过命令行工具在服务器端创建代码评审，服务端不会创建新的分支，但是为了方便用户远程下载评审代码，仓库中生成了一个特殊的引用。

例如上面创建的第 7937 号代码评审，会创建包含该评审 ID 号的，名为 `refs/merge-requests/7937/head` 的特殊引用。下载该待评审的代码，可以使用如下命令：

    $ git fetch origin refs/merge-requests/7937/head
    From https://codeup.teambition.com/git-repo/demo.git
     * branch            refs/merge-requests/7937/head -> FETCH_HEAD

检出相关代码：

    $ git checkout FETCH_HEAD

`git-repo` 提供了一个便捷的 `download` 子命令完成上述操作。

## 2. 重新发送，刷新代码评审

代码评审很少一蹴而就，针对评审者的意见，开发者（评审任务的创建者）往往需要重新上传代码刷新代码评审。对于阿里巴巴代码平台上创建的代码评审任务，重复执行 `git peer-review` 命令即可。

1. 开发者首先在本地工作区修改代码。

2. 执行如下命令，向远程仓库推送并刷新代码评审任务：

        $ git pr


## 3. 支持的服务端类型

目前 `git peer-review` 支持两种类型的 Git 服务器，一种是 Gerrit 服务器，另一种就是阿里巴巴的代码平台。而其它平台并不支持。

在 git-repo（包括 git peer-review）在执行时，会检查服务器是否支持集中式代码评审。对于使用 HTTP（HTTPS）协议下载的仓库，会向该 HTTP 网站的 `ssh_info` API 发起 Get 请求。

### 3.1 HTTP 协议的服务探测

阿里巴巴代码平台的 `ssh_info` API 返回一个 JSON 数据：

    $ curl https://codeup.teambition.com/ssh_info
    {"host":"codeup.teambition.com","port":22,"type":"agit","version":2}

其中 host 和 port 是 SSH 协议上传代码的主机名和端口号。type 字段是服务器类型，这里的值为 `agit`，是 Alibaba-Git extension 的缩写。

Gerrit 平台的 `ssh_info` API 返回一个字符串，内容是 SSH 协议的主机名和端口号：

    $ curl https://review.opendev.org/ssh_info
    review.opendev.org 29418

### 3.2 SSH 协议的服务探测

如果是 SSH 协议，会执行服务端的 `ssh_info` 命令来判断服务器类型：

    $ ssh git@codeup.teambition.com ssh_info
    {"type":"agit","version":2}

### 3.3 Gerrit 的 commit-msg 钩子脚本

阿里巴巴代码平台是通过 Session 来判断，是创建新的代码评审，还是刷新老的代码评审。而 Gerrit 则采用另外一套方案。

Gerrit 需要在提交说明中嵌入唯一的 Change-Id 编号，在用户将提交推送到服务器后，通过检索 Change-Id 的方式来判断是创建新的评审，还是刷新老的评审任务。在提交中嵌入 Change-Id 是通过在客户端安装 `commit-msg` 钩子的方式进行的。

    $ scp -p -P 29418 <your_name>@<gerrit-server>:hooks/commit-msg \
      $(git rev-parse --git-dir)/hooks/

也可以运行 `git-repo` 的命令 【TODO】安装 commit-msg 钩子。


## 4. SSH 协议创建代码评审的授权

git-repo 在创建代码评审时，会优先使用 SSH 协议。SSH 协议针对集中式评审设计了新的授权模型，只要拥有仓库的读取权限，就能向仓库发起代码评审。实现了仓库的人人可写。

通过 SSH 协议的写操作，会传递 `--receive-pack` 参数，该参数可以指定服务器启动的 receive-pack 应用名。例如阿里巴巴代码平台指定的 receive-pack 应用为 `agit-receive-pack`。针对该应用采用了不同的授权模型：只要拥有仓库的读权限，就能向仓库创建代码评审。

## 5. 第三方应覆盖了别名命令

OpenStack 社区的代码评审工具名为 `git-review`，如果系统中安装了 OpenStack 社区的 `git-review` 工具，则 `git-repo` 注册的别名命令 `git-review` 在运行时被覆盖。

执行 `git repo` 命令，如果发现存在别名命令被覆盖的情况，会显示警告信息。

    $ git repo
    WARNING: you cannot use the git-repo alias command 'git-review', it is overrided by '/usr/local/bin/git-review' installed
    ... ...

遇到这种情况，请使用其它未占用的别名命令，如：`git pr`。

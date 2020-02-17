---
title: "git repo upload"
draft: false
weight: 46
---

## 功能

创建代码评审。

对于指定的项目，`git-repo` 会将本地分支与上一次执行 `git repo upload` 时上传的提交做比较，（上一次上传提交记录在 `refs/published/<branch-name>` 的引用中），提示您选择一个或多个尚未上传可供审核的分支。

`git repo upload` 命令会启动一个编辑器，编辑器中的内容是此次代码评审的各项可定制的参数，以及待上传的项目和分支列表。

示例如下：

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
    # project foo:
    #  branch topic1 ( 3 commit(s)) to remote branch master:
    #         03c01e211122b49fe05f48e08fd3e1dd1c52e57e
    #         ec78989440697fbc13bfbd3ea082fe9b3fc5f2d7
    #         4e599aa284ed64ba12ba1b5b06fbbd3199846434
    #
    # project bar:
    #  branch topic1 ( 2 commit(s)) to remote branch master:
    #         47a3cae46019893db78a19906dda97825279f288
    #         ced1a1d6e16bc3f8051f87621eb69ba2a7e10672 

		
Step 1 中以字符 "#" 开始的行是注释，不要改动注释行，因为 `git-repo` 要根据注释行的内容判断用户输入内容用于更改哪项代码评审的参数设置。 例如：

+ 在 "# [Title]" 行的下面添加的内容，成为代码评审的标题。默认用提交说明的标题作为代码评审标题。
+ 在 "# [Description]" 行的下面添加的内容，成为代码评审的详细描述。默认用提交说明的内容作为代码评审的详细描述。
+ 在 "# [Issue]" 行的下面如果添加 Issue ID，则将代码评审和问题之间的建立关联。
+ 在 "# [Reviewer]" 行的下面添加代码评审者姓名，一个一行，或者用逗号分隔。
+ 在 "# [Cc]" 行的下面添加代码评审的关注者姓名，一个一行，或者用逗号分隔。
+ 在 "# [Draft]" 行的下面如果输入 yes，则表明要创建一个草稿模式的代码评审。

在最下面的 "Step 2" 区域，显示当前项目将要上传到远程仓库的分支和提交列表。检查提交列表，如果不想创建此次代码评审，则将 "branch ..." 的行注释掉，或者删掉，如果需要为此项目和分支创建代码评审，则打开对应的 "branch ..." 行。

例如将 project foo 的 branch topic1 所在行的注释去掉，而保留 project bar 的 branch topic1 行的注释。如下：

    ##############################################################################
    # Step 2: Select project and branches for upload
    #
    # Note: Uncomment the branches to upload, and not touch the project lines
    ##############################################################################
    #
    # project foo:
      branch topic1 ( 3 commit(s)) to remote branch master:
    #         03c01e211122b49fe05f48e08fd3e1dd1c52e57e
    #         ec78989440697fbc13bfbd3ea082fe9b3fc5f2d7
    #         4e599aa284ed64ba12ba1b5b06fbbd3199846434
    #
    # project bar:
    #  branch topic1 ( 2 commit(s)) to remote branch master:
    #         47a3cae46019893db78a19906dda97825279f288
    #         ced1a1d6e16bc3f8051f87621eb69ba2a7e10672 

保存并退出编辑器，则只向 project foo 发起代码评审，而不会向 project bar 发起代码评审。


## 命令格式

    git repo upload [options...] [project...]


## 选项

主要的选项如下：

+ `--cbr`：为当前分支的修改创建代码评审。
+ `--br <branch-name>`：为指定的分支中的修改创建代码评审。
+ `--re <user1,user2,...>`：设置代码评审人。
+ `--cc <user1,user2,...>`：设置代码评审的关注人。
+ `--title <title>`：设置代码评审的标题。
+ `--description <description>`：设置代码评审的描述。
+ `--single`：单仓模式，可用于不使用 manifest 清单仓库的单仓库项目。

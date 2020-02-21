---
title: "Manifest 格式"
draft: false
weight: 42
---

## Manifest 清单仓库和 Manifest 清单文件

定义多仓库关联的清单文件（manifest 文件）保存于一个仓库中，这个仓库称为 manifest 仓库。仓库中默认的 manifest 清单文件名为 `default.xml`，示例如下。（仓库中可以包含多个 XML 文件，但是除了默认的 `default.xml` 之外，其他 XML 文件需要通过命令行的相关参数显式的指定。）

    <?xml version="1.0" encoding="UTF-8"?>
    <manifest>
      <remote  name="origin"
    	   fetch=".."
    	   revision="master"
    	   review="https://codeup.teambition.com" />
      <remote  name="github"
    	   fetch="https://github.com"
    	   revision="master"
    	   review="" />
      <default remote="origin"
               revision="master"
    	   sync-j="4" />
    
      <project name="aliyun/git-repo-go" path="git-repo" groups="app">
        <linkfile src="README.md" dest="README.md"></linkfile>
      </project>
      <project name="aliyun/git-repo-go-doc" path="website" groups="app"/>
      <project name="jiangxin/goconfig" path="lib/goconfig" groups="lib" remote="github" />
      <project name="jiangxin/multi-log" path="lib/multi-log" groups="lib" remote="github" />
    </manifest>

这是一个标准的 XML 文件，根元素为 manifest，关于该文件格式的解读如下。

## remote 元素

一个 Manifest 文件中可以包含多个 remote 元素。每一个 remote 元素定义了一个远程服务器。每个 project 元素都关联唯一一个 remote 元素。remote 元素包括的属性如下：

+ name 定义 remote 的名称。仓库克隆时将以该名称建立和远程仓库的关联。
+ fetch 定义服务器 URL 地址。如果是 fetch 是相对地址，则以 manifest 仓库地址（`git-repo init -u <URL>` 设定的地址）为基准，计算得出。当一个项目被克隆时，将通过 fetch 定义的服务器 URL 地址和项目 name 字段组合得到仓库的克隆地址。
+ revision 定义项目的默认分支。
+ review 参数设置 `git-repo` 发动集中式评审的服务器地址。

## default 元素

当项目（project）元素没有设置 remote、revison 等属性，则直接使用 default 元素中相关设置。即 default 元素为 project 元素相关属性的缺省值。

## project 元素

每一个 project 元素定义一个仓库。其中关键属性如下：

+ 属性 name 既作为项目的名称，又和 remote 的 fetch 字段一起组合出仓库的 URL 地址。
+ 属性 path 是一个相对路径，是仓库在本地工作区的检出路径。
+ 属性 groups 将项目分组，用作项目的筛选。例如在 `git repo init -g <gorup` 命令中进行设置。
+ 属性 remote 设置项目对应的远程源仓库。

元素 project 还可以嵌套，嵌套内部的 project 路径以嵌套外部项目的路径为基准。

元素 project 还可以包含 linkfile、copyfile 等元素，完成文件的链接和拷贝。

更多示例参见 Android 项目的 manifest 仓库：

    地址：https://android.googlesource.com/platform/manifest

---
title: "Manifest Format"
draft: false
weight: 42
---

## Manifest file example

In a manifest repository, there are one or more XML files, which define the relationship of all repositories of the project. The default manifest file in the manifest project is `default.xml`. See the following content of a manifest file as an example:

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

The root element of the manifest XML file is `manifest` and has many other elements.


## Element remote

One or more remote elements may be specified. Each remote element defines a remote server, which has a name, URL prefix, revision, and review URL. Every project should associate with one remote element.

Attributes of the remote element:

+ Attribute `name`: A short name unique to this manifest file. The name specified here is used as the remote name in each project's `.git/config`, and is therefore automatically available to commands like `git fetch`, `git remote`, `git pull`, and `git push`.
+ Attribute `alias`: The alias, if specified, is used to override name to be set as the remote name in each project's `.git/config`. Its value can be duplicated while attribute name has to be unique in the manifest file. This helps each project to be able to have same remote name, which actually points to different remote URL.
+ Attribute `fetch`: The Git URL prefix for all projects which use this remote. Each project's name is appended to this prefix to form the actual URL used to clone the project. If fetch points to a relative path, it will form a real URL prefix from manifest repository URL, which is given by `git repo init -u <URL>` command line.
+ Attribute `revision`: Name of a Git branch (e.g., master or refs/heads/master) or revision. Remotes with their own revision will override the default revision.
+ Attribute `review`: Hostname of the code review server where reviews are uploaded to by `git repo upload`. This attribute is optional; if not specified, then `git repo upload` will not function.

## Element default

At most one default element may be specified. Its remote and revision attributes are used when a project element does not specify its own remote or revision attribute.

## Element project

One or more project elements may be specified. Each element describes a single Git repository to be cloned into the client workspace. Project can be nested.

+ Attribute `name`: A unique name of the project. The project's name is appended onto its remote's fetch URL to generate the actual URL to configure the Git remote with.
+ Attribute `path`: An optional path relative to the top directory of the workspace where the Git working directory for this project should be placed. If not supplied, the project name is used. If the project has a parent element, its path will be prefixed by the parent's.
+ Attribute `groups`: List of groups to which this project belongs, whitespace or comma separated. All projects belong to the group "all", and each project automatically belongs to a group of its "name:`name`" and "path:`path`".
+ Attribute `remote`: Name of a previously defined remote element. If not supplied, the remote given by the default element is used.
+ Attribute `revision`: Name of the Git branch the manifest wants to track for this project, or revision used for checkout only. If not supplied, the revision given by the remote element is used if applicable, else the default element is used.

References:

+ [Manifest format of Android repo](https://gerrit.googlesource.com/git-repo/+/refs/heads/master/docs/manifest-format.md)
+ [Android manifest file example](https://android.googlesource.com/platform/manifest)

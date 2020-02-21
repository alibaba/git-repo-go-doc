---
title: "Overview"
draft: false
weight: 41
---

Git built-in solution for multiple repositories is `git submodule`. It is OK for the release of the source code of all related repositories, but it is bad for development because all sub repositories pin to specific commits.

Android project introduced a better solution for the management of multiple repositories that the relationship of repositories is defined in an XML file in a manifest project. Android also introduced a new command-line tool named `repo`, which helps manage repositories.

`git-repo` is compatible with Android `repo`, can also manage multiple repositories. Usage of `git-repo`:

    git repo <command> <arguments> ...

See help message, use:

    git repo help
    git repo help <command>


The following example is how to manage multiple repositories using `git-repo`:

{{< figure src="/images/git-repo-manifest.gif" caption="Fig: git-repo for multiple repositories" >}}

Main steps in the above example:

1. Create an empty directory as workspace.

        $ mkdir workspace
        $ cd workspace

2. Initialize workspace by cloning the manifest repository.

        $ git repo init -u <manifest-url>

    Example:

        $ git repo init -u https://codeup.teambition.com/git-repo/manifests.git

3. Fetch and check out all related repositories.

        $ git repo sync

4. Create a topic branch on all projects for development.

        $ git repo start --all <topic-branch>

    Example:

        $ git repo start --all jx/topic1

5. Work in the worktree, and create new commits.

6. Scan new commits in all repositories and publish new commits to create code reviews.

        $ git repo upload

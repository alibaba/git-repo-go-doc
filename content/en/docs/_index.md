---
title: "User Guide"
---

Linus, the founder of Git and Linux, revealed the secret of Git's success in an interview on Git's 10th anniversary:

> The big thing about distributed source control is that it makes one of the main issues with SCM's go away - the politics around "who can make changes."

The distributed nature of Git makes it possible for a project to have a more flexible workflow. Not only core members but also read-only users can contribute to the project in a more elegant way. GitHub invented a "Fork + Pull Request" development model, which is the most classic and widely used workflow so far. Instead of pushing the commits directly to a branch of the remote repository, a contributor can push his/her commits to his/her own forked fully controlled repository and create a code review (Pull Request) later using the web interface.

## AGit-Flow

Can we have a more convenient way to collaborate?

Inspired by Gerrit workflow (which using JGit instead of CGit as its backend), we created a centralized git workflow based on CGit with a minor changed git-core and several APIs. We implemented it in Alibaba's internal source code platform, and we call the workflow as "AGit-Flow". With the help of "AGit-Flow", it's unnecessary to fork a repository or create many feature branches inside a repository. Users can use `git push` command to create code review (pull request) directly.

*TODO*: Changes on git-core will be sent to the Git mailing list to become part of open source software. Any code platform can implement its own AGit-Flow compatible, centralized workflow. See [AGit-Flow and How to implement](../2020/03/agit-flow-and-git-repo/).

## git-repo

It's tedious to type long `git push` command for centralized workflow as AGit-Flow, so we developed a CLI tool named "git-repo". "git-repo" can be used for Gerrit, AGit-Flow and AGit-Flow alike workflows.

See the following demo about how we use `git pr` (an alias command of `git-repo`) to create a pull request on [Alibaba code platform](https://codeup.teambition.com) (only Chinese version available):

{{< figure src="/images/git-pr-demo.gif" caption="Create pull request using `git pr`" >}}

`git-repo` is compatible with the Android `repo` cmd tool, which can work with multiple repositories managed by a manifest repository. See [manage multiple repositories using git-repo](multi-repos/overview/).

`git-repo` is an open source software on GitHub, see [https://github.com/alibaba/git-repo-go](https://github.com/alibaba/git-repo-go).

## Differences between git-repo and Android repo

Android project uses Gerrit for code review and provides a client-side command line tool named `repo`. `git-repo` is compatible with `repo`, as having the same subcommands and the same user experiences. Why we reinvent the wheel?

1. Android `repo` only supports Gerrit servers, `git-repo` can be used for Gerrit, and AGit-Flow compatible servers.

2. Android `repo` only works on multiple repositories managed by a manifest repository, while `git-repo` can also work on a single repository, with the help of alias commands, such as `git pr`, `git download`, and `git abandon`, etc.

3. `git-repo` is developed using Golang and has full functional test cases. It is easy to install without any further software dependency except Git itself.

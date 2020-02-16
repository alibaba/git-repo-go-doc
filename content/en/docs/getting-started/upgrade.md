---
title: "Upgrade"
draft: false
weight: 14
enableToc: false
---

## Upgrade git-repo

Upgrade `git-repo`:

    $ git repo upgrade

Will download the latest version of `git-repo` and install.

If fail to install due to permissions or other reasons, will give an instruction as the solution. Please follow the instruction for upgrade. e.g.:

    $ git repo upgrade
    Download git-repo: ############################################################ 100%
    +--------------------------------------------------------------------------------+
    | Fail to upgrade. Please copy                                                   |
    |         /var/folders/5d/21v9l2z12j/T/git-repo-0.2.0-619707833                  |
    | to                                                                             |
    |         /usr/bin/git-repo                                                      |
    | by hands                                                                       |
    +--------------------------------------------------------------------------------+
    Error: upgrade failed

For this case, run the instruction given by the example, e.g.:

    $ sudo cp /var/folders/5d/21v9l2z12j/T/git-repo-0.2.0-619707833 /usr/bin/git-repo

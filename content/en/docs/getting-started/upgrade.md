---
title: "Upgrade"
draft: false
weight: 14
enableToc: false
---

## Upgrade git-repo

Upgrade `git-repo` to the latest version, using command:

    $ git repo upgrade

Will download and install the latest version of `git-repo`.

If the upgrade process failed because of permissions or other reasons, it would show instruction in the output message. Please follow the instruction for manual upgrade. 

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

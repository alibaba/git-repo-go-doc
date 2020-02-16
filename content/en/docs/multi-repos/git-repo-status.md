---
title: "git repo status"
draft: false
weight: 49
---

## Description

Show a summary of git status on each project. For each file in the project, a two-letter code is used. The first letter stands for changes of index, and the second letter stands for changes of worktree.

In the first column, an uppercase letter indicates how the staging area differs from the last committed state.

Letter | Meaning      | Description
-------|:-------------|:--------------------------------------
`-`    | No change    | Same in HEAD and index 
A      | Added        | Not in HEAD, in index
M      | Modified     | In HEAD, modified in index
D      | Deleted      | In HEAD, not in index 
R      | Renamed      | Not in HEAD, path changed in index
C      | Copied       | Not in HEAD, copied from another in index
T      | Mode changed | Same content in HEAD and index, mode changed
U      | Unmerged     |Conflict between HEAD and index; resolution required

In the second column, a lowercase letter indicates how the working directory differs from the index.

Letter | Meaning     | Description
-------|:------------|:--------------------------------------
`-`    | New/unknown | Not in index, in work tree 
m      | Modified    | In index, in work tree, modified
d      | Deleted     | In index, not in work tree

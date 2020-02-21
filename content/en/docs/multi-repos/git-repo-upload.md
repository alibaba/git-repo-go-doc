---
title: "git repo upload"
draft: false
weight: 46
---

## Description

Send changes to remote server to create code reviews.

For the specified projects, compares the local branches to the remote branches updated during the last `git repo sync`. `git-repo` prompts you to select one or more of the branches that haven't been uploaded for review.

`git repo upload` command will start an editor for you with the following text as an example. Add custom options and choose the branches that need to be uploaded in the editor.

    ##############################################################################
    # Step 1: Input your options for code review
    #
    # Note: Input your options below the comments and keep the comments unchanged
    ##############################################################################
    
    # [Title]       : one-line message below as the title of code review
    
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

The first section of the text is used for adding options for `git repo upload`. Lines begin with the character "#" are comments. Please do not change these comments, for `git-repo` needs to find parameter names in the comments.

+ Below the line started with "# [Title]", add one-line title for the code review to be generated.
+ Below the line started with "# [Description]", add description for the code review to be generated.
+ Below the line started with "# [Issue]", add issue number for reference.
+ Below the line started with "# [Reviewer]", add reviewers (one reviewer on each line, or separated by commas).
+ Below the line started with "# [Cc]", add watchers.
+ Below the line started with "# [Draft]", input "yes" to turn on draft mode.


The second section lists projects and branches that are ready to publish. Uncomment the branches you want to publish. `git-repo` will create code reviews for these publish branches.

If no branch is ready to publish (all branches are commented out), `git repo upload` will abort.

Save the content and quit the editor, `git-repo` will continue to send local commits to remote repositories to create/update code reviews.

For example: in the following text, the leading character "#" at the beginning of the line of `branch topic1` of `project foo` has been deleted, while other comment letter "#" are preserved:

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

Save and quit the editor, `git repo upload` will only send changes of project foo, and create code review for it.


## Usage

    git repo upload [options...] [project...]


## Options

Available options:

+ `--cbr`: Upload current git branch.
+ `--br <branch-name>`: Upload specific branch.
+ `--re <user1,user2,...>`: Request reviews from these people.
+ `--cc <user1,user2,...>`: Also send email to these watchers.
+ `--title <title>`: Set title for code review.
+ `--description <description>`: Set description for code review.

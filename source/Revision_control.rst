Revision control with Git
==========================

We'll start by exploring how version control can be used to keep track of what one person did and when.
Even if you aren't collaborating with other people, automated version control is much better than this situation:

.. image:: ../images/revisions.png
   :alt: A lot of files with not very descriptive names like final_final_final.txt

Which one is actually the final version? Which order to the files actually go in (in case 
I wanted to go back to a previous version)?

We've all been in this situation before: it seems unnecessary to have
multiple nearly-identical versions of the same document. Some word
processors let us deal with this a little better, such as Microsoft
Word's `Track Changes <https://support.office.com/en-us/article/Track-changes-in-Word-197ba630-0f5f-4a8e-9a77-3712475e806a>`_, 
Google Docs' `version history <https://support.google.com/docs/answer/190843?hl=en>`_, or 
LibreOffice's `Recording and Displaying Changes <https://help.libreoffice.org/Common/Recording_and_Displaying_Changes>`.

Version control systems start with a base version of the document and then record changes you make each step of the way. You can
think of it as a recording of your progress: you can rewind to start at the base document and play back each change you made, 
eventually arriving at your more recent version.

.. image:: ../images/play-changes.png
   :alt: Changes Are Saved Sequentially

Once you think of changes as separate from the document itself, you
can then think about "playing back" different sets of changes on the base document, ultimately
resulting in different versions of that document. For example, two users can make independent
sets of changes on the same document. 

.. image:: ../images/versions.png
   :alt: Different Versions Can be Saved

Unless multiple users make changes to the same section of the document - a conflict - you can 
incorporate two sets of changes into the same base document.

.. image:: ../images/merge.png
   :alt: Multiple Versions Can be Merged

A version control system is a tool that keeps track of these changes for us,
effectively creating different versions of our files. It allows us to decide
which changes will be made to the next version (each record of these changes is
called a commit and keeps useful metadata about them. The complete history of commits for a particular project and their
metadata make up a repository. Repositories can be kept in sync across different computers, facilitating
collaboration among different people.


..  admonition:: Learn more
    :class: toggle

    **The Long History of Version Control Systems**
    Automated version control systems are nothing new.
    Tools like `RCS <https://en.wikipedia.org/wiki/Revision_Control_System>`_, 
    `CVS <https://en.wikipedia.org/wiki/Concurrent_Versions_System>`_, or 
    `Subversion <https://en.wikipedia.org/wiki/Apache_Subversion>`_ have been around since the early 1980s and are used by 
    many large companies. However, many of these are now considered legacy systems (i.e., outdated) due to various 
    limitations in their capabilities.
    More modern systems, such as Git and [Mercurial](https://swcarpentry.github.io/hg-novice/),
    are *distributed*, meaning that they do not need a centralized server to host the repository.
    These modern systems also include powerful merging tools that make it possible for 
    multiple authors to work on the same files concurrently.


.. admonition:: Thought exercise

   **Paper Writing**
   
   *   Imagine you drafted an excellent paragraph for a paper you are writing, but later ruin 
       it. How would you retrieve the *excellent* version of your conclusion? Is it even possible?

   *   Imagine you have 5 co-authors. How would you manage the changes and comments 
       they make to your paper?  If you use LibreOffice Writer or Microsoft Word, what happens if 
       you accept changes made using the `Track Changes` option? Do you have a 
       history of those changes?

.. admonition:: Solution
   :class: toggle

   *   Recovering the excellent version is only possible if you created a copy
       of the old version of the paper. The danger of losing good versions
       often leads to the problematic workflow illustrated first image.
     
   *   Collaborative writing with traditional word processors is cumbersome.
       Either every collaborator has to work on a document sequentially
       (slowing down the process of writing), or you have to send out a
       version to all collaborators and manually merge their comments into  
       your document. The 'track changes' or 'record changes' option can
       highlight changes for you and simplifies merging, but as soon as you
       accept changes you will lose their history. You will then no longer
       know who suggested that change, why it was suggested, or when it was
       merged into the rest of the document. Even online word processors like
       Google Docs or Microsoft Office Online do not fully resolve these
       problems.


Setting up git
---------------

When we use Git on a new computer for the first time, we need to configure a few things. Below are a few examples
of configurations we will set as we get started with Git:

*   our name and email address,
*   what our preferred text editor is,
*   and that we want to use these settings globally (i.e. for every project).

On a command line, Git commands are written as ``git verb options``,
where ``verb`` is what we actually want to do and ``options`` is additional optional information which may be 
needed for the ``verb``. So here is how I might setup my new laptop:

.. code-block:: bash

   git config --global user.name "Jon Hill"
   git config --global user.email "jon.hill@york.ac.uk"


Please use your own name and email address instead of mine. This user name and email will be associated with your subsequent Git activity,
which means that any changes pushed to
`GitHub <https://github.com/>`_,
`BitBucket <https://bitbucket.org/>`_,
`GitLab <https://gitlab.com/>`_ or
another Git host server after this lesson will include this information.

For this lesson, we will be interacting with `GitHub <https://github.com/>`_ and so the email address used should be the 
same as the one used when setting up your GitHub account. If you are concerned about privacy, 
please review `GitHub's instructions for keeping your email address private <git-privacy>`_. 


.. caution::
   
   *Line Endings*

   As with other keys, when you hit :kbd:`Enter` or :kbd:`Return` on your keyboard,
   your computer encodes this input as a character.
   Different operating systems use different character(s) to represent the end of a line.
   (You may also hear these referred to as newlines or line breaks.)
   Because Git uses these characters to compare files,
   it may cause unexpected issues when editing a file on different machines. 
   Though it is beyond the scope of this lesson, you can read more about this issue 
   `in the Pro Git book <https://www.git-scm.com/book/en/v2/Customizing-Git-Git-Configuration#_core_autocrlf>`_.
   
   You can change the way Git recognizes and encodes line endings
   using the `core.autocrlf` command to `git config`.
   The following settings are recommended:
   On macOS and Linux:
    
   .. code-block:: bash
   
      git config --global core.autocrlf input

   And on Windows:

   .. code-block:: bat

      git config --global core.autocrlf false

We also need to set our favorite text editor, following this table:

.. list-table:: Editors and config
    :header-rows: 1

    * - Editor
      - Configuration command
    * - Atom
      - ``$ git config --global core.editor "atom --wait"``
    * - nano 
      - ``$ git config --global core.editor "nano -w"``    
    * - BBEdit (Mac, with command line tools)  
      - ``$ git config --global core.editor "bbedit -w"``    
    * - Sublime Text (Mac)  
      - ``$ git config --global core.editor "/Applications/Sublime\ Text.app/Contents/SharedSupport/bin/subl -n -w"`` 
    * - Sublime Text (Win, 32-bit install)  
      - ``$ git config --global core.editor "'c:/program files (x86)/sublime text 3/sublime_text.exe' -w"`` 
    * - Sublime Text (Win, 64-bit install) 
      - ``$ git config --global core.editor "'c:/program files/sublime text 3/sublime_text.exe' -w"`` 
    * - Notepad (Win)     
      - ``$ git config --global core.editor "c:/Windows/System32/notepad.exe"``
    * - Notepad++ (Win, 32-bit install)     
      - ``$ git config --global core.editor "'c:/program files (x86)/Notepad++/notepad++.exe' -multiInst -notabbar -nosession -noPlugin"``
    * - Notepad++ (Win, 64-bit install)     
      - ``$ git config --global core.editor "'c:/program files/Notepad++/notepad++.exe' -multiInst -notabbar -nosession -noPlugin"``
    * - Kate (Linux)        
      - ``$ git config --global core.editor "kate"``       
    * - Gedit (Linux)       
      - ``$ git config --global core.editor "gedit --wait --new-window"``   
    * - Scratch (Linux)        
      - ``$ git config --global core.editor "scratch-text-editor"``  
    * - Emacs               
      - ``$ git config --global core.editor "emacs"``   
    * - Vim                
      - ``$ git config --global core.editor "vim"``   
    * - VS Code                
      - ``$ git config --global core.editor "code --wait"``   

It is possible to reconfigure the text editor for Git whenever you want to change it.


.. caution::

   **Exiting Vim**
  
   Note that Vim is the default editor for many programs. If you haven't used Vim before and wish to exit a session without saving
   your changes, press :kbd:`Esc` then type ``:q!`` and hit :kbd:`Enter` or  :kbd:`Return`.
   If you want to save your changes and quit, press :kbd:`Esc` then type ``:wq`` and hit :kbd:`Enter` or :kbd:`Return`.


Git (2.28+) allows configuration of the name of the branch created when you
initialize any new repository.  We should use that feature to set it to `main` so 
it matches Gihub

.. code-block:: bash

   git config --global init.defaultBranch main

The five commands we just ran above only need to be run once: the flag `--global` tells Git
to use the settings for every project, in your user account, on this computer.

You can check your settings at any time:

.. code-block:: bash

   git config --list

You can change your configuration as many times as you want: use the
same commands to choose another editor or update your email address.

.. hint::

   **Git Help and Manual**

   Always remember that if you forget the subcommands or options of a `git` command, you can access the
   relevant list of options typing `git <command> -h` or access the corresponding Git manual by typing
   ``git <command> --help``, e.g.:

   .. code-block:: bash
   
      git config -h
      git config --help

   While viewing the manual, remember the ``:`` is a prompt waiting for commands and you can press :kbd:`Q` to exit the manual.
   More generally, you can get the list of available ``git`` commands and further resources of the Git manual typing:
 
   .. code-block:: bash

      git help


Our first repository
--------------------

Once Git is configured, we can start using it.

We will use a story of Muske and Branston who are investigating if it
is possible to send a planetary lander to Mars. 

First, let's create a new directory in the :file:`Desktop/` folder for our work and then change the current working directory to the newly created one:

.. code-block:: bash

   cd ~/Desktop
   mkdir planets
   cd planets

Then we tell Git to make :file:`planets/` a repository -- a place where Git can store versions of our files:


.. code-block:: bash

   git init

It is important to note that ``git init`` will create a repository that
can include subdirectories and their files -- there is no need to create
separate repositories nested within the ``planets`` repository, whether
subdirectories are present from the beginning or added later. Also, note
that the creation of the ``planets`` directory and its initialization as a
repository are completely separate processes.

If we use ``ls`` to show the directory's contents,
it appears that nothing has changed:

.. code-block:: bash

   ls

But if we add the ``-a`` flag to show everything,
we can see that Git has created a hidden directory within :file:`planets` called :file:`.git`:

.. code-block:: bash
 
   ls -a

| .	..	.git

Git uses this special subdirectory to store all the information about the project, 
including the tracked files and sub-directories located within the project's directory.
If we ever delete the ``.git`` subdirectory, we will lose the project's history.

Next, we will change the default branch to be called ``main``.
This might be the default branch depending on your settings and version
of git. See the :ref:`Setting up git` section above for more information on this change.

.. code-block:: bash
   
   git checkout -b main

   
| Switched to a new branch 'main'


We can check that everything is set up correctly
by asking Git to tell us the status of our project:

.. code-block:: bash

   git status

| On branch main
| 
| No commits yet
| 
| nothing to commit (create/copy files and use "git add" to track)

If you are using a different version of `git`, the exact
wording of the output might be slightly different.

.. admonition:: Thought exercise

  **Places to Create Git Repositories**

  Along with tracking information about planets (the project we have already created), 
  we would also like to track information about moons.
  Despite the project leader concerns, someone creates a `moons` project inside the `planets` 
  project with the following sequence of commands:
  
  .. code-block:: bash

    cd ~/Desktop   # return to Desktop directory
    cd planets     # go into planets directory, which is already a Git repository
    ls -a          # ensure the .git subdirectory is still present in the planets directory
    mkdir moons    # make a subdirectory planets/moons
    cd moons       # go into moons subdirectory
    git init       # make the moons subdirectory a Git repository
    ls -a          # ensure the .git subdirectory is present indicating we have created a new Git repository


  Is the `git init` command, run inside the `moons` subdirectory, required for 
  tracking files stored in the `moons` subdirectory?


.. admonition:: Solution
   :class: toggle

   No. The worker does not need to make the `moons` subdirectory a Git repository 
   because the `planets` repository can track any files, sub-directories, and 
   subdirectory files under the `planets` directory.  Thus, in order to track 
   all information about moons, The worker only needed to add the `moons` subdirectory
   to the `planets` directory.
 
   Additionally, Git repositories can interfere with each other if they are "nested":
   the outer repository will try to version-control
   the inner repository. Therefore, it's best to create each new Git
   repository in a separate directory. To be sure that there is no conflicting
   repository in the directory, check the output of `git status`. If it looks
   like the following, you are good to go to create a new repository as shown
   above:

   .. code-block:: bash

     git status

   | fatal: Not a git repository (or any of the parent directories): .git

.. admonition:: Thought exercise

  **Correcting `git init` Mistakes**
  
  The project manager explains how a nested repository is redundant and may cause confusion
  down the road. We would like to remove the nested repository. How can we undo 
  the last `git init` in the `moons` subdirectory?

.. admonition:: Solution
   :class: toggle
 
   **Background**
   
   Removing files from a Git repository needs to be done with caution. But we have not learned 
   yet how to tell Git to track a particular file; we will learn this in the next section. Files 
   that are not tracked by Git can easily be removed like any other "ordinary" files with

   .. code-block:: bash
   
      rm filename

   Similarly a directory can be removed using `rm -r dirname` or `rm -rf dirname`.
   If the files or folder being removed in this fashion are tracked by Git, then their removal 
   becomes another change that we will need to track, as we will see in the next section.

   **Solution**
   
   Git keeps all of its files in the `.git` directory.
   To recover from this little mistake, we can just remove the `.git`
   folder in the moons subdirectory by running the following command from inside the `planets` directory:

   .. code-block:: bash
   
      rm -rf moons/.git

   But be careful! Running this command in the wrong directory will remove
   the entire Git history of a project you might want to keep.
   Therefore, always check your current directory using the command `pwd`.



Adding files
------------

First let's make sure we're still in the right directory.
You should be in the `planets` directory.

.. code-block:: bash

   cd ~/Desktop/planets

Let's create a file called `mars.txt` that contains some notes
about the Red Planet's suitability as a base.
We'll use `nano` to edit the file; you can use whatever editor you like.
In particular, this does not have to be the `core.editor` you set globally earlier. But remember, 
the bash command to create or edit a new file will depend on the 
editor you choose (it might not be `nano`).

.. code-block:: bash

   nano mars.txt

Type the text below into the `mars.txt` file:

| Cold and dry, but everything is my favorite color

Let's first verify that the file was properly created by running the list command (`ls`):

.. code-block:: bash

   ls

| mars.txt

`mars.txt` contains a single line, which we can see by running:

.. code-block:: bash

   cat mars.txt

| Cold and dry, but everything is my favorite color

If we check the status of our project again,
Git tells us that it's noticed the new file:

.. code-block:: bash

   git status

| On branch main
| 
| No commits yet
| 
| Untracked files:
|  (use "git add <file>..." to include in what will be committed)
|
|	mars.txt
|
| nothing added to commit but untracked files present (use "git add" to track)

The "untracked files" message means that there's a file in the directory
that Git isn't keeping track of.
We can tell Git to track a file using `git add`:

.. code-block:: bash

   git add mars.txt

and then check that the right thing happened:

.. code-block:: bash
   
   git status

| On branch main
| 
| No commits yet
| 
| Changes to be committed:
|   (use "git rm --cached <file>..." to unstage)
|
| 	new file:   mars.txt
|

Git now knows that it's supposed to keep track of `mars.txt`,
but it hasn't recorded these changes as a commit yet.
To get it to do that, we need to run one more command:

.. code-block:: bash

   git commit -m "Start notes on Mars as a base"

| [main (root-commit) f22b25e] Start notes on Mars as a base
| 1 file changed, 1 insertion(+)
| create mode 100644 mars.txt

When we run ``git commit``, Git takes everything we have told it to save by using ``git add``
and stores a copy permanently inside the special ``.git`` directory.
This permanent copy is called a commit (or revision) and its short identifier is ``f22b25e``. Your commit may have another identifier.

We use the ``-m`` flag (for "message") to record a short, descriptive, and specific comment 
that will help us remember later on what we did and why.
If we just run ``git commit`` without the ``-m`` option, Git will launch ``nano`` (or whatever other editor we configured as ``core.editor``)
so that we can write a longer message.

.. hint::
   
   Good commit messages start with a brief (<50 characters) statement about the changes made in the commit.
   Generally, the message should complete the sentence "If applied, this commit will" <commit message here>.
   If you want to go into more detail, add a blank line between the summary line and your additional notes.
   Use this additional space to explain why you made changes and/or what their impact will be.

If we run ``git status`` now:

.. code-block:: bash

   git status

| On branch main
| nothing to commit, working tree clean

it tells us everything is up to date. If we want to know what we've done recently,
we can ask Git to show us the project's history using `git log`:

.. code-block:: bash

   git log

| commit f22b25e3233b4645dabd0d81e651fe074bd8e73b
| Author: Jon Hill <jon.hill@york.ac.uk>
| Date:   Thu Aug 22 09:51:46 2023 -0400
|
|    Start notes on Mars as a base

``git log`` lists all commits  made to a repository in reverse chronological order.
The listing for each commit includes

 - the commit's full identifier (which starts with the same characters as the short identifier printed by the `git commit` command earlier),
 - the commit's author,
 - when it was created,
 - and the log message Git was given when the commit was created.

..  admonition:: Learn more
    :class: toggle

    **Where Are My Changes?**

   If we run ``ls`` at this point, we will still see just one file called `mars.txt`.
   That's because Git saves information about files' history
   in the special :file:`.git` directory mentioned earlier
   so that our filesystem doesn't become cluttered
   (and so that we can't accidentally edit or delete an old version).

Now suppose we adds more information to the file.
(Again, we'll edit with `nano` and then `cat` the file to show its contents;
you may use a different editor, and don't need to `cat`.)

.. code-block:: bash

   nano mars.txt
   cat mars.txt

| Cold and dry, but everything is my favorite color
| The two moons may be a problem for werewolves

When we run ``git status`` now,
it tells us that a file it already knows about has been modified:

.. code-block:: bash

   git status

| On branch main
| Changes not staged for commit:
|   (use "git add <file>..." to update what will be committed)
|   (use "git checkout -- <file>..." to discard changes in working directory)
| 
| 	modified:   mars.txt
| 
| no changes added to commit (use "git add" and/or "git commit -a")

The last line is the key phrase:
"no changes added to commit".
We have changed this file,
but we haven't told Git we will want to save those changes
(which we do with ``git add``)
nor have we saved them (which we do with ``git commit``).
So let's do that now. It is good practice to always review
our changes before saving them. We do this using ``git diff``.
This shows us the differences between the current state
of the file and the most recently saved version:

.. code-block:: bash

   git diff

| diff --git a/mars.txt b/mars.txt
| index df0654a..315bf3a 100644
| --- a/mars.txt
| +++ b/mars.txt
| @@ -1 +1,2 @@
|  Cold and dry, but everything is my favorite color
| +The two moons may be a problem for werewolves

The output is cryptic because
it is actually a series of commands for tools like editors and ``patch``
telling them how to reconstruct one file given the other.
If we break it down into pieces:

1.  The first line tells us that Git is producing output similar to the Unix ``diff`` command
    comparing the old and new versions of the file.
2.  The second line tells exactly which versions of the file
    Git is comparing;
    ``df0654a`` and ``315bf3a`` are unique computer-generated labels for those versions.
3.  The third and fourth lines once again show the name of the file being changed.
4.  The remaining lines are the most interesting, they show us the actual differences
    and the lines on which they occur.
    In particular,
    the ``+`` marker in the first column shows where we added a line.

After reviewing our change, it's time to commit it:

.. code-block:: bash

   git commit -m "Add concerns about effects of Mars' moons on Wolfman"

| On branch main
| Changes not staged for commit:
|   (use "git add <file>..." to update what will be committed)
|   (use "git checkout -- <file>..." to discard changes in working directory)
|
| 	modified:   mars.txt

| no changes added to commit (use "git add" and/or "git commit -a")

Whoops:
Git won't commit because we didn't use ``git add`` first.
Let's fix that:

.. code-block:: bash

   git add mars.txt
   git commit -m "Add concerns about effects of Mars' moons on Wolfman"

| [main 34961b1] Add concerns about effects of Mars' moons on Wolfman
|  1 file changed, 1 insertion(+)

Git insists that we add files to the set we want to commit
before actually committing anything. This allows us to commit our
changes in stages and capture changes in logical portions rather than
only large batches. For example,
suppose we're adding a few citations to relevant research to our thesis.
We might want to commit those additions,
and the corresponding bibliography entries,
but *not* commit some of our work drafting the conclusion
(which we haven't finished yet).

To allow for this, Git has a special *staging area*
where it keeps track of things that have been added to
the current changeset but not yet committed.

.. admonition:: Learn more
    :class: toggle

    **Staging Area**

    If you think of Git as taking snapshots of changes over the life of a project,
    ``git add`` specifies *what* will go in a snapshot
    (putting things in the staging area),
    and ``git commit`` then *actually takes* the snapshot, and
    makes a permanent record of it (as a commit).
    If you don't have anything staged when you type ``git commit``,
    Git will prompt you to use ``git commit -a`` or ``git commit --all``,
    which is kind of like gathering *everyone* to take a group photo!
    However, it's almost always better to
    explicitly add things to the staging area, because you might
    commit changes you forgot you made. (Going back to the group photo simile,
    you might get an extra with incomplete makeup walking on
    the stage for the picture because you used ``-a``!)
    Try to stage things manually,
    or you might find yourself searching for "git undo commit" more
    than you would like!

.. image:: ../images/git-staging-area.png
   :alt: The git staging area

Let's watch as our changes to a file move from our editor
to the staging area and into long-term storage.
First, we'll add another line to the file:

.. code-block:: bash

   nano mars.txt
   cat mars.txt

| Cold and dry, but everything is my favorite color
| The two moons may be a problem for werewolves
| But the Mummy will appreciate the lack of humidity

.. code-block:: bash

  git diff

| diff --git a/mars.txt b/mars.txt
| index 315bf3a..b36abfd 100644
| --- a/mars.txt
| +++ b/mars.txt
| @@ -1,2 +1,3 @@
|  Cold and dry, but everything is my favorite color
|  The two moons may be a problem for werewolves
| +But the Mummy will appreciate the lack of humidity

So far, so good: we've added one line to the end of the file
(shown with a `+` in the first column). Now let's put that change in the staging area
and see what ``git diff`` reports:

.. code-block:: bash

    git add mars.txt
    git diff

There is no output:
as far as Git can tell,
there's no difference between what it's been asked to save permanently
and what's currently in the directory.
However, if we do this:

.. code-block:: bash

    git diff --staged

| diff --git a/mars.txt b/mars.txt
| index 315bf3a..b36abfd 100644
| --- a/mars.txt
| +++ b/mars.txt
| @@ -1,2 +1,3 @@
| Cold and dry, but everything is my favorite color
| The two moons may be a problem for werewolves
| But the Mummy will appreciate the lack of humidity


it shows us the difference between the last committed change
and what's in the staging area. Let's save our changes:

.. code-block:: bash

    git commit -m "Discuss concerns about Mars' climate for Mummy"

| [main 005937f] Discuss concerns about Mars' climate for Mummy
| 1 file changed, 1 insertion(+)

check our status:

.. code-block:: bash

    git status

| On branch main
| nothing to commit, working tree clean

and look at the history of what we've done so far:

.. code-block:: bash

    git log


| commit 005937fbe2a98fb83f0ade869025dc2636b4dad5 (HEAD -> main)
| Author: Vlad Dracula <vlad@tran.sylvan.ia>
| Date:   Thu Aug 22 10:14:07 2013 -0400
| 
|    Discuss concerns about Mars' climate for Mummy
|
| commit 34961b159c27df3b475cfe4415d94a6d1fcd064d
| Author: Vlad Dracula <vlad@tran.sylvan.ia>
| Date:   Thu Aug 22 10:07:21 2013 -0400
| 
|     Add concerns about effects of Mars' moons on Wolfman
|
| commit f22b25e3233b4645dabd0d81e651fe074bd8e73b
| Author: Vlad Dracula <vlad@tran.sylvan.ia>
| Date:   Thu Aug 22 09:51:46 2013 -0400
| 
|     Start notes on Mars as a base


.. admonition:: Learn more
    :class: toggle

    **Word-based diffing**

    Sometimes, e.g. in the case of the text documents a line-wise
    diff is too coarse. That is where the ``--color-words`` option of
    ``git diff`` comes in very useful as it highlights the changed 
    words using colors.

.. admonition:: Learn more
    :class: toggle

    **Paging the Log**

    When the output of ``git log`` is too long to fit in your screen,
    ``git`` uses a program to split it into pages of the size of your screen.
    When this "pager" is called, you will notice that the last line in your
    screen is a ``:``, instead of your usual prompt.
    
    *   To get out of the pager, press :kbd:`q`.
    *   To move to the next page, press :kbd:`Spacebar`.
    *   To search for `some_word` in all pages, press :kbd:`/` and type ``some_word``.
        Navigate through matches pressing :kbd:`n`.

.. admonition:: Learn more
    :class: toggle

    **Limit Log Size**

    To avoid having `git log` cover your entire terminal screen, you can limit the
    number of commits that Git lists by using `-N`, where `N` is the number of
    commits that you want to view. For example, if you only want information from
    the last commit you can use:

    .. code-block:: bash
        
        git log -1

    | commit 005937fbe2a98fb83f0ade869025dc2636b4dad5 (HEAD -> main)
    | Author: Vlad Dracula <vlad@tran.sylvan.ia>
    | Date:   Thu Aug 22 10:14:07 2013 -0400
    |
    | Discuss concerns about Mars' climate for Mummy

    You can also reduce the quantity of information using the ``--oneline`` option:

    .. code-block:: bash
    
        git log --oneline
    
    | 005937f (HEAD -> main) Discuss concerns about Mars' climate for Mummy
    | 34961b1 Add concerns about effects of Mars' moons on Wolfman
    | f22b25e Start notes on Mars as a base
    
    You can also combine the `--oneline` option with others. One useful
    combination adds `--graph` to display the commit history as a text-based
    graph and to indicate which commits are associated with the
    current `HEAD`, the current branch `main`, or
    [other Git references][git-references]:

    .. code-block:: bash
    
        git log --oneline --graph

    | * 005937f (HEAD -> main) Discuss concerns about Mars' climate for Mummy
    | * 34961b1 Add concerns about effects of Mars' moons on Wolfman
    | * f22b25e Start notes on Mars as a base


.. caution::

    **Directories**
    
    Two important facts you should know about directories in Git.
    
    1. Git does not track directories on their own, only files within them. Try it for yourself:
      
    .. code-block:: bash
    
        mkdir spaceships
        git status
        git add spaceships
        git status
    
    Note, our newly created empty directory `spaceships` does not appear in
    the list of untracked files even if we explicitly add it (*via* ``git add``) to our
    repository. This is the reason why you will sometimes see ``.gitkeep`` files
    in otherwise empty directories. Unlike ``.gitignore``, these files are not special
    and their sole purpose is to populate a directory so that Git adds it to
    the repository. In fact, you can name such files anything you like.
    
    2. If you create a directory in your Git repository and populate it with files,
       you can add all files in the directory at once by:
    
    .. code-block:: bash
          
           git add <directory-with-files>
    
    Try it for yourself:
    
     .. code-block:: bash
                
         touch spaceships/apollo-11 spaceships/sputnik-1
         git status
         git add spaceships
         git status
     
    Before moving on, we will commit these changes.
    
     .. code-block:: bash
         
        git commit -m "Add some initial thoughts on spaceships"


To recap, when we want to add changes to our repository,
we first need to add the changed files to the staging area
(``git add``) and then commit the staged changes to the
repository (``git commit``):

.. image:: ../images/git-committing.png
   :alt: The git commit process

.. admonition:: Thought exercise

   **Choosing a Commit Message**
   
   Which of the following commit messages would be most appropriate for the
   last commit made to `mars.txt`?
   
   1. "Changes"
   2. "Added line 'But the Mummy will appreciate the lack of humidity' to mars.txt"
   3. "Discuss effects of Mars' climate on the Mummy"

.. admonition:: Solution
    :class: toggle

    Answer 1 is not descriptive enough, and the purpose of the commit is unclear;
    and answer 2 is redundant to using "git diff" to see what changed in this commit;
    but answer 3 is good: short, descriptive, and imperative.

.. admonition:: Thought exercise

   **Committing changes to Git**
    
   Which command(s) below would save the changes of `myfile.txt`
   to my local Git repository?

   1. ``$ git commit -m "my recent changes"``
   2. ``git init myfile.txt``
      ``git commit -m "my recent changes"``
   3. ``git add myfile.txt``
      ``git commit -m "my recent changes"``
   4. ``git commit -m myfile.txt "my recent changes"``

.. admonition:: Solution
    :class: toggle

    1. Would only create a commit if files have already been staged.
    2. Would try to create a new repository.
    3. Is correct: first add the file to the staging area, then commit.
    4. Would try to commit a file "my recent changes" with the message myfile.txt.


.. admonition:: Practical exercise

   **Committing multiple files**
    
   The staging area can hold changes from any number of files
   that you want to commit as a single snapshot.
   
   1. Add some text to `mars.txt` noting your decision
      to consider Venus as a base
   2. Create a new file `venus.txt` with your initial thoughts
      about Venus as a base for you and your friends
   3. Add changes from both files to the staging area,
      and commit those changes.

.. admonition:: Solution
    :class: toggle

    The output below from `cat mars.txt` reflects only content added during 
    this exercise. Your output may vary.
    
    First we make our changes to the `mars.txt` and `venus.txt` files:

    .. code-block:: bash

        nano mars.txt
        cat mars.txt

    | Maybe I should start with a base on Venus.

    .. code-block:: bash
    
        nano venus.txt
        cat venus.txt

    | Venus is a nice planet and I definitely should consider it as a base.

    Now you can add both files to the staging area. We can do that in one line:
    
    .. code-block:: bash
        
        git add mars.txt venus.txt

    Or with multiple commands:

    .. code-block:: bash

        git add mars.txt
        git add venus.txt

    Now the files are ready to commit. You can check that using `git status`. If you are ready to commit use:
    
    .. code-block:: bash
    
        git commit -m "Write plans to start a base on Venus"

    | [main cc127c2]
    | Write plans to start a base on Venus
    | 2 files changed, 2 insertions(+)
    | create mode 100644 venus.txt

.. admonition:: Practical exercise

    **Creating a biography**

    * Create a new Git repository on your computer called `bio`.
    * Write a three-line biography for yourself in a file called `me.txt`,
      commit your changes
    * Modify one line, add a fourth line
    * Display the differences between its updated state and its original state.


.. admonition:: Solution
    :class: toggle

    If needed, move out of the `planets` folder:

    .. code-block:: bash

        cd ..

    Create a new folder called `bio` and 'move' into it:

    .. code-block:: bash

        mkdir bio
        cd bio

    Initialise git:

    .. code-block:: bash

        git init

    Create your biography file `me.txt` using `nano` or another text editor.
    Once in place, add and commit it to the repository:

    .. code-block:: bash

        git add me.txt
        git commit -m "Add biography file" 

    Modify the file as described (modify one line, add a fourth line).
    To display the differences between its updated state and its original state, use `git diff`:

    .. code-block:: bash
    
        git diff me.txt


Git history
-----------

No, not the story of how Git came to be, but how do we get at the history of our commits.
In the previous section we see we can refer to commits by the unique identifiers. 
You can refer to the *most recent commit* of the working
directory by using the identifier ``HEAD``.

We've been adding one line at a time to :file:`mars.txt`, so it's easy to track our
progress by looking, so let's do that using our ``HEAD``.  Before we start,
let's make a change to :file:`mars.txt`, adding yet another line. 

| Cold and dry, but everything is my favorite color
| The two moons may be a problem for werewolves
| But the Mummy will appreciate the lack of humidity
| An ill-considered change


Now, let's see what we get.

.. code-block:: bash

    git diff HEAD mars.txt

| diff --git a/mars.txt b/mars.txt
| index b36abfd..0848c8d 100644
| --- a/mars.txt
| +++ b/mars.txt
| @@ -1,3 +1,4 @@
|  Cold and dry, but everything is my favorite color
|  The two moons may be a problem for werewolves
|  But the Mummy will appreciate the lack of humidity
| +An ill-considered change.

which is the same as what you would get if you leave out ``HEAD`` (try it).  The
real goodness in all this is when you can refer to previous commits.  We do
that by adding ``~1`` 
(where "~" is "tilde", pronounced [**til**-d*uh*]) 
to refer to the commit one before ``HEAD``.

.. code-block:: bash

    git diff HEAD~1 mars.txt

If we want to see the differences between older commits we can use ``git diff``
again, but with the notation ``HEAD~1``, ``HEAD~2``, and so on, to refer to them:

.. code-block:: bash

    git diff HEAD~3 mars.txt

| diff --git a/mars.txt b/mars.txt
| index df0654a..b36abfd 100644
| --- a/mars.txt
| +++ b/mars.txt
| @@ -1 +1,4 @@
|  Cold and dry, but everything is my favorite color
| +The two moons may be a problem for werewolves
| +But the Mummy will appreciate the lack of humidity
| +An ill-considered change


We could also use ``git show`` which shows us what changes we made at an older commit as 
well as the commit message, rather than the _differences_ between a commit and our 
working directory that we see by using ``git diff``.

.. code-block:: bash

    git show HEAD~3 mars.txt

| commit f22b25e3233b4645dabd0d81e651fe074bd8e73b
| Author: Vlad Dracula <vlad@tran.sylvan.ia>
| Date:   Thu Aug 22 09:51:46 2013 -0400
| 
|    Start notes on Mars as a base
| 
| diff --git a/mars.txt b/mars.txt
| new file mode 100644
| index 0000000..df0654a
| --- /dev/null
| +++ b/mars.txt
| @@ -0,0 +1 @@
| +Cold and dry, but everything is my favorite color

We can also refer to commits using those long strings of digits and letters
that ``git log`` displays. These are unique IDs for the changes,
and "unique" really does mean unique: every change to any set of files on any computer
has a unique 40-character identifier. Our first commit was given the ID
``f22b25e3233b4645dabd0d81e651fe074bd8e73b``, so let's try this:

.. code-block:: bash

    git diff f22b25e3233b4645dabd0d81e651fe074bd8e73b mars.txt

| diff --git a/mars.txt b/mars.txt
| index df0654a..93a3e13 100644
| --- a/mars.txt
| +++ b/mars.txt
| @@ -1 +1,4 @@
|  Cold and dry, but everything is my favorite color
| +The two moons may be a problem for werewolves
| +But the Mummy will appreciate the lack of humidity
| +An ill-considered change

That's the right answer, but typing out random 40-character strings is annoying,
so Git lets us use just the first few characters (typically seven for normal size projects):

.. code-block:: bash

    git diff f22b25e mars.txt

| diff --git a/mars.txt b/mars.txt
| index df0654a..93a3e13 100644
| --- a/mars.txt
| +++ b/mars.txt
| @@ -1 +1,4 @@
|  Cold and dry, but everything is my favorite color
| +The two moons may be a problem for werewolves
| +But the Mummy will appreciate the lack of humidity
| +An ill-considered change


So we can save changes to files and see what we've changed. Now, how can we restore older versions of things?
Let's suppose we change our mind about the last update to ``mars.txt`` (the "ill-considered change").

``git status`` now tells us that the file has been changed, but those changes haven't been staged:

.. code-block:: bash

    git status

| On branch main
| Changes not staged for commit:
|  (use "git add <file>..." to update what will be committed)
|  (use "git checkout -- <file>..." to discard changes in working directory)
|
|    modified:   mars.txt
|
| no changes added to commit (use "git add" and/or "git commit -a")

We can put things back the way they were by using ``git checkout``:

.. code-block:: bash

    git checkout HEAD mars.txt
    cat mars.txt

| Cold and dry, but everything is my favorite color
| The two moons may be a problem for werewolves
| But the Mummy will appreciate the lack of humidity

As you might guess from its name, ``git checkout`` checks out (i.e. restores) an old version of a file.
In this case, we're telling Git that we want to recover the version of the file recorded in ``HEAD``,
which is the last saved commit. If we want to go back even further,
we can use a commit identifier instead:

.. code-block:: bash
    
    git checkout f22b25e mars.txt
    cat mars.txt

| Cold and dry, but everything is my favorite color

.. code-block:: bash

    git status

| On branch main
| Changes to be committed:
| (use "git reset HEAD <file>..." to unstage)
| 
|   modified:   mars.txt

Notice that the changes are currently in the staging area.
Again, we can put things back the way they were
by using ``git checkout``:

.. code-block:: bash

    git checkout HEAD mars.txt

.. caution::

    **Don't Lose Your HEAD**
    
    Above we used
    
    .. code-block:: bash

        git checkout f22b25e mars.txt
    
    to revert ``mars.txt`` to its state after the commit ``f22b25e``. But be careful! 
    The command ``checkout`` has other important functionalities and Git will misunderstand
    your intentions if you are not accurate with the typing. For example, 
    if you forget `mars.txt` in the previous command.
    
    .. code-block:: bash

        git checkout f22b25e
    
    | Note: checking out 'f22b25e'.
    
    You are in `'detached HEAD`' state. You can look around, make experimental
    changes and commit them, and you can discard any commits you make in this
    state without impacting any branches by performing another checkout.
    
    If you want to create a new branch to retain commits you create, you may
    do so (now or later) by using ``-b`` with the checkout command again. Example:
    
    .. code-block:: bash

        git checkout -b <new-branch-name
    
        HEAD is now at f22b25e Start notes on Mars as a base
    
    The "detached HEAD" is like "look, but don't touch" here,
    so you shouldn't make any changes in this state.
    After investigating your repo's past state, reattach your ``HEAD`` with ``git checkout main``.


It's important to remember that we must use the commit number that identifies the state of the repository
*before* the change we're trying to undo. A common mistake is to use the number of
the commit in which we made the change we're trying to discard. In the example below, we want to 
retrieve the state from before the most recent commit (``HEAD~1``), which is commit ``f22b25e``:


.. image:: ../images/git-checkout.png
   :alt: The git commit process

.. admonition:: Learn more
    :class: toggle
    
    **Simplifying the Common Case**
    
    If you read the output of ``git status`` carefully,
    you'll see that it includes this hint:
    
    | (use "git checkout -- <file>..." to discard changes in working directory)
    
    As it says, ``git checkout`` without a version identifier restores files to the state saved in ``HEAD``.
    The double dash `--` is needed to separate the names of the files being recovered
    from the command itself: without it,
    Git would try to use the name of the file as the commit identifier.

The fact that files can be reverted one by one tends to change the way people organize their work.
If everything is in one large document, it's hard (but not impossible) to undo changes to the introduction
without also undoing changes made later to the conclusion. If the introduction and conclusion are stored in separate files,
on the other hand, moving backward and forward in time becomes much easier.


.. admonition:: Thought exercise

    **Recovering Older Versions of a File**
    
    Jennifer has made changes to the Python script that she has been working on for weeks, and the
    modifications she made this morning "broke" the script and it no longer runs. She has spent
    ~ 1hr trying to fix it, with no luck...
    
    Luckily, she has been keeping track of her project's versions using Git! Which commands below will
    let her recover the last committed version of her Python script called
    ``data_cruncher.py``?
    
    1. ``$ git checkout HEAD``
    
    2. ``$ git checkout HEAD data_cruncher.py``
    
    3. ``$ git checkout HEAD~1 data_cruncher.py``
    
    4. ``$ git checkout <unique ID of last commit> data_cruncher.py``
    
    5. Both 2 and 4
    
.. admonition:: Solution
    :class: toggle
    
    The answer is (5)-Both 2 and 4. 
     
    The ``checkout`` command restores files from the repository, overwriting the files in your working 
    directory. Answers 2 and 4 both restore the *latest* version *in the repository* of the file 
    ``data_cruncher.py``. Answer 2 uses ``HEAD`` to indicate the *latest*, whereas answer 4 uses the 
    unique ID of the last commit, which is what ``HEAD`` means. 
     
    Answer 3 gets the version of ``data_cruncher.py`` from the commit *before* ``HEAD``, which is NOT 
    what we wanted.
     
    Answer 1 can be dangerous! Without a filename, ``git checkout`` will restore **all files** 
    in the current directory (and all directories below it) to their state at the commit specified. 
    This command will restore ``data_cruncher.py`` to the latest commit version, but it will also 
    restore *any other files that are changed* to that version, erasing any changes you may 
    have made to those files!
    
    As discussed above, you are left in a *detached* `HEAD` state, and you don't want to be there.


.. admonition:: Thought exercise

    **Reverting a Commit**
    
    Jennifer is collaborating with colleagues on her Python script.  She
    realizes her last commit to the project's repository contained an error, and 
    wants to undo it.  Jennifer wants to undo correctly so everyone in the project's
    repository gets the correct change. The command ``git revert [erroneous commit ID]`` will create a 
    new commit that reverses the erroneous commit.
        
    The command ``git revert`` is different from ``git checkout [commit ID]`` 
    because `git checkout` returns the files not yet committed within the local repository 
    to a previous state, whereas ``git revert``
    reverses changes committed to the local and project repositories.   
      
    Below are the right steps and explanations for Jennifer to use ``git revert``,
    what is the missing command?  

    1. `________ # Look at the git history of the project to find the commit ID`
    
    2. Copy the ID (the first few characters of the ID, e.g. 0b1d055).
    
    3. ``git revert [commit ID]``
    
    4. Type in the new commit message.
    
    5. Save and close


.. admonition:: Solution
    :class: toggle
 
    The command ``git log`` lists project history with commit IDs.  

    The command ``git show HEAD`` shows changes made at the latest commit, and lists
    the commit ID; however, Jennifer should double-check it is the correct commit, and no one
    else has committed changes to the repository.

.. admonition:: Thought exercise

    **Understanding Workflow and History**

    .. code-block:: bash

        cd planets
        echo "Venus is beautiful and full of love" > venus.txt
        git add venus.txt
        echo "Venus is too hot to be suitable as a base" >> venus.txt
        git commit -m "Comment on Venus as an unsuitable base"
        git checkout HEAD venus.txt
        cat venus.txt #this will print the contents of venus.txt to the screen

    1. ``Venus is too hot to be suitable as a base``
    2. ``Venus is beautiful and full of love``
    3. ``Venus is beautiful and full of love``
       ``Venus is too hot to be suitable as a base``
    4. ``Error because you have changed venus.txt without committing the changes``

.. admonition:: Solution
    :class: toggle

    The answer is 2. 
     
    The command ``git add venus.txt`` places the current version of ``venus.txt`` into the staging area. 
    The changes to the file from the second ``echo`` command are only applied to the working copy, 
    not the version in the staging area.

    So, when ``git commit -m "Comment on Venus as an unsuitable base"`` is executed, 
    the version of ``venus.txt`` committed to the repository is the one from the staging area and
    has only one line.
     
    At this time, the working copy still has the second line (and 
    ``git status`` will show that the file is modified). However, ``git checkout HEAD venus.txt`` 
    replaces the working copy with the most recently committed version of ``venus.txt``.
     
    So, ``cat venus.txt`` will output 
    ``Venus is beautiful and full of love.``


.. admonition:: Practical exercise

   **Checking Understanding of ``git diff``**

   Consider this command: ``git diff HEAD~9 mars.txt``. What do you predict this command
   will do if you execute it? What happens when you do execute it? Why?

   Try another command, ``git diff [ID] mars.txt``, where [ID] is replaced with
   the unique identifier for your most recent commit. What do you think will happen,
   and what does happen?


.. admonition:: Practical exercise

   **Getting Rid of Staged Changes**

   ``git checkout`` can be used to restore a previous commit when unstaged changes have
   been made, but will it also work for changes that have been staged but not committed?
   Make a change to ``mars.txt``, add that change, and use ``git checkout`` to see if
   you can remove your change.


.. admonition:: Practical exercise

   **Explore and Summarize Histories**

Exploring history is an important part of Git, and often it is a challenge to find
the right commit ID, especially if the commit is from several months ago.

Imagine the ``planets`` project has more than 50 files.
You would like to find a commit that modifies some specific text in ``mars.txt``.
When you type ``git log``, a very long list appeared.
How can you narrow down the search?

Recall that the ``git diff`` command allows us to explore one specific file,
e.g., ``git diff mars.txt``. We can apply a similar idea here.

.. code-block:: bash

    git log mars.txt

Unfortunately some of these commit messages are very ambiguous, e.g., ``update files``.
How can you search through these files?

Both ``git diff`` and ``git log`` are very useful and they summarize a different part of the history 
for you. Is it possible to combine both? Let's try the following:

.. code-block:: bash

    git log --patch mars.txt

You should get a long list of output, and you should be able to see both commit messages and 
the difference between each commit.

Question: What does the following command do?

.. code-block:: bash

    git log --patch HEAD~9 *.txt


Ignoring files
--------------

What if we have files that we do not want Git to track for us,
like backup files created by our editor or intermediate files created during data analysis?
Let's create a few dummy files:

.. code-block:: bash

    mkdir results
    touch a.dat b.dat c.dat results/a.out results/b.out

and see what Git says:

.. code-block:: bash

    git status

| On branch main
| Untracked files:
|  (use "git add <file>..." to include in what will be committed)
|
|	a.dat
|	b.dat
|	c.dat
|	results/
|
| nothing added to commit but untracked files present (use "git add" to track)

Putting these files under version control would be a waste of disk space.
What's worse, having them all listed could distract us from changes that actually matter,
so let's tell Git to ignore them.

We do this by creating a file in the root directory of our project called ``.gitignore``:

.. code-block:: bash

    nano .gitignore
    cat .gitignore


.. code-block:: output

    *.dat
    results/

These patterns tell Git to ignore any file whose name ends in ``.dat``
and everything in the ``results`` directory. (If any of these files were already being tracked,
Git would continue to track them.)

Once we have created this file, the output of ``git status`` is much cleaner:

.. code-block:: bash

    git status

.. code-block:: output
    
    On branch main
    Untracked files:
      (use "git add <file>..." to include in what will be committed)

        .gitignore

    nothing added to commit but untracked files present (use "git add" to track)

The only thing Git notices now is the newly-created ``.gitignore`` file.
You might think we wouldn't want to track it, but everyone we're sharing our repository with will probably want to ignore
the same things that we're ignoring. Let's add and commit ``.gitignore``:

.. code-block:: bash

    git add .gitignore
    git commit -m "Ignore data files and the results folder."
    git status

.. code-block:: output

    On branch main
    nothing to commit, working tree clean


As a bonus, using ``.gitignore`` helps us avoid accidentally adding files to the repository that we don't want to track:

.. code-block:: bash

    git add a.dat

.. code-block:: output
    
    The following paths are ignored by one of your .gitignore files:
    a.dat
    Use -f if you really want to add them.

If we really want to override our ignore settings, we can use ``git add -f`` to force Git to add something. For example,
``git add -f a.dat``. We can also always see the status of ignored files if we want:

.. code-block:: bash

    git status --ignored

.. code-block:: output

    On branch main
    Ignored files:
     (use "git add -f <file>..." to include in what will be committed)

            a.dat
            b.dat
            c.dat
            results/

    nothing to commit, working tree clean

.. admonition:: Thought exercise

    **Ignoring Nested Files**

    Given a directory structure that looks like:

    .. code-block:: output
        
        results/data
        results/plots

    How would you ignore only ``results/plots`` and not ``results/data``?


.. admonition:: Solution
    :class: toggle

    **Solution**

    If you only want to ignore the contents of
    ``results/plots``, you can change your ``.gitignore`` to ignore
    only the ``/plots/`` subfolder by adding the following line to
    your .gitignore:

    .. code-block:: output
        
        results/plots/

    This line will ensure only the contents of ``results/plots`` is ignored, and
    not the contents of ``results/data``.
    As with most programming issues, there are a few alternative ways that one may ensure this ignore rule is followed.
    The "Ignoring Nested Files: Variation" exercise has a slightly
    different directory structure that presents an alternative solution.
    Further, the discussion page has more detail on ignore rules.


.. admonition:: Thought exercise

    **Including Specific Files**
    
    How would you ignore all ``.dat`` files in your root directory except for
    ``final.dat``?
    Hint: Find out what `!` (the exclamation point operator) does


.. admonition:: Solution
    :class: toggle

    **Solution**

    You would add the following two lines to your .gitignore:

    .. code-block:: output

        \*.dat           # ignore all data files
        !final.dat      # except final.data

    The exclamation point operator will include a previously excluded entry.

    Note also that because you've previously committed ``.dat`` files in this
    lesson they will not be ignored with this new rule. Only future additions
    of ``.dat`` files added to the root directory will be ignored.


.. admonition:: Thought exercise

    **Ignoring Nested Files: Variation**

    Given a directory structure that looks similar to the earlier Nested Files
    exercise, but with a slightly different directory structure:

    .. code-block:: output
    
        results/data
        results/images
        results/plots
        results/analysis

    How would you ignore all of the contents in the results folder, but not ``results/data``?

    Hint: think a bit about how you created an exception with the ``!`` operator
    before.


.. admonition:: Solution
    :class: toggle

    **Solution**

    If you want to ignore the contents of
    ``results/`` but not those of ``results/data/``, you can change your ``.gitignore`` to ignore
    the contents of results folder, but create an exception for the contents of the
    ``results/data`` subfolder. Your .gitignore would look like this:

    .. code-block:: output

        results/*               # ignore everything in results folder
        !results/data/          # do not ignore results/data/ contents


.. admonition:: Thought exercise

    **The Order of Rules**

    Given a `.gitignore` file with the following contents:
    
    .. code-block:: output
    
        *.dat
        !*.dat
    
    What will be the result?


.. admonition:: Solution
    :class: toggle

    **Solution**

    The ``!`` modifier will negate an entry from a previously defined ignore pattern.
    Because the ``!*.dat`` entry negates all of the previous ``.dat`` files in the ``.gitignore``,
    none of them will be ignored, and all ``.dat`` files will be tracked.


.. admonition:: Practical exercise

    **Log Files**

    You wrote a script that creates many intermediate log-files of the form ``log_01``, ``log_02``, ``log_03``, etc.
    You want to keep them but you do not want to track them through ``git``.

    1. Write **one** ``.gitignore`` entry that excludes files of the form ``log_01``, ``log_02``, etc.

    2. Test your "ignore pattern" by creating some dummy files of the form ``log_01``, etc.

    3. You find that the file ``log_01`` is very important after all, add it to the tracked files without changing the ``.gitignore`` again.

    4. Discuss with your neighbor what other types of files could reside in your directory that you do not want to track and thus would exclude via ``.gitignore``.


.. admonition:: Solution
    :class: toggle

    1. append either `log_*`  or  `log*`  as a new entry in your .gitignore
    
    3. track `log_01` using   `git add -f log_01`



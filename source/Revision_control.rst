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

   As with other keys, when you hit :kbd:`Enter` or :kbd:`↵` or on Macs, :kbd:`Return` on your keyboard,
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
   your changes, press :kbd:`Esc` then type ``:q!`` and hit :kbd:`Enter` or :kbd:`↵` or on Macs, :kbd:`Return`.
   If you want to save your changes and quit, press :kbd:`Esc` then type ``:wq`` and hit :kbd:`Enter` or :kbd:`↵` or on Macs, :kbd:`Return`.


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

..  admonition:: Learn more
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

![The Git Staging Area](../fig/git-staging-area.svg)

Let's watch as our changes to a file move from our editor
to the staging area
and into long-term storage.
First,
we'll add another line to the file:

~~~
$ nano mars.txt
$ cat mars.txt
~~~
{: .language-bash}

~~~
Cold and dry, but everything is my favorite color
The two moons may be a problem for Wolfman
But the Mummy will appreciate the lack of humidity
~~~
{: .output}

~~~
$ git diff
~~~
{: .language-bash}

~~~
diff --git a/mars.txt b/mars.txt
index 315bf3a..b36abfd 100644
--- a/mars.txt
+++ b/mars.txt
@@ -1,2 +1,3 @@
 Cold and dry, but everything is my favorite color
 The two moons may be a problem for Wolfman
+But the Mummy will appreciate the lack of humidity
~~~
{: .output}

So far, so good:
we've added one line to the end of the file
(shown with a `+` in the first column).
Now let's put that change in the staging area
and see what `git diff` reports:

~~~
$ git add mars.txt
$ git diff
~~~
{: .language-bash}

There is no output:
as far as Git can tell,
there's no difference between what it's been asked to save permanently
and what's currently in the directory.
However,
if we do this:

~~~
$ git diff --staged
~~~
{: .language-bash}

~~~
diff --git a/mars.txt b/mars.txt
index 315bf3a..b36abfd 100644
--- a/mars.txt
+++ b/mars.txt
@@ -1,2 +1,3 @@
 Cold and dry, but everything is my favorite color
 The two moons may be a problem for Wolfman
+But the Mummy will appreciate the lack of humidity
~~~
{: .output}

it shows us the difference between
the last committed change
and what's in the staging area.
Let's save our changes:

~~~
$ git commit -m "Discuss concerns about Mars' climate for Mummy"
~~~
{: .language-bash}

~~~
[main 005937f] Discuss concerns about Mars' climate for Mummy
 1 file changed, 1 insertion(+)
~~~
{: .output}

check our status:

~~~
$ git status
~~~
{: .language-bash}

~~~
On branch main
nothing to commit, working tree clean
~~~
{: .output}

and look at the history of what we've done so far:

~~~
$ git log
~~~
{: .language-bash}

~~~
commit 005937fbe2a98fb83f0ade869025dc2636b4dad5 (HEAD -> main)
Author: Vlad Dracula <vlad@tran.sylvan.ia>
Date:   Thu Aug 22 10:14:07 2013 -0400

    Discuss concerns about Mars' climate for Mummy

commit 34961b159c27df3b475cfe4415d94a6d1fcd064d
Author: Vlad Dracula <vlad@tran.sylvan.ia>
Date:   Thu Aug 22 10:07:21 2013 -0400

    Add concerns about effects of Mars' moons on Wolfman

commit f22b25e3233b4645dabd0d81e651fe074bd8e73b
Author: Vlad Dracula <vlad@tran.sylvan.ia>
Date:   Thu Aug 22 09:51:46 2013 -0400

    Start notes on Mars as a base
~~~
{: .output}

> ## Word-based diffing
>
> Sometimes, e.g. in the case of the text documents a line-wise
> diff is too coarse. That is where the `--color-words` option of
> `git diff` comes in very useful as it highlights the changed
> words using colors.
{: .callout}

> ## Paging the Log
>
> When the output of `git log` is too long to fit in your screen,
> `git` uses a program to split it into pages of the size of your screen.
> When this "pager" is called, you will notice that the last line in your
> screen is a `:`, instead of your usual prompt.
>
> *   To get out of the pager, press <kbd>Q</kbd>.
> *   To move to the next page, press <kbd>Spacebar</kbd>.
> *   To search for `some_word` in all pages,
>     press <kbd>/</kbd>
>     and type `some_word`.
>     Navigate through matches pressing <kbd>N</kbd>.
{: .callout}

> ## Limit Log Size
>
> To avoid having `git log` cover your entire terminal screen, you can limit the
> number of commits that Git lists by using `-N`, where `N` is the number of
> commits that you want to view. For example, if you only want information from
> the last commit you can use:
>
> ~~~
> $ git log -1
> ~~~
> {: .language-bash}
>
> ~~~
> commit 005937fbe2a98fb83f0ade869025dc2636b4dad5 (HEAD -> main)
> Author: Vlad Dracula <vlad@tran.sylvan.ia>
> Date:   Thu Aug 22 10:14:07 2013 -0400
>
>    Discuss concerns about Mars' climate for Mummy
> ~~~
> {: .output}
>
> You can also reduce the quantity of information using the
> `--oneline` option:
>
> ~~~
> $ git log --oneline
> ~~~
> {: .language-bash}
> ~~~
> 005937f (HEAD -> main) Discuss concerns about Mars' climate for Mummy
> 34961b1 Add concerns about effects of Mars' moons on Wolfman
> f22b25e Start notes on Mars as a base
> ~~~
> {: .output}
>
> You can also combine the `--oneline` option with others. One useful
> combination adds `--graph` to display the commit history as a text-based
> graph and to indicate which commits are associated with the
> current `HEAD`, the current branch `main`, or
> [other Git references][git-references]:
>
> ~~~
> $ git log --oneline --graph
> ~~~
> {: .language-bash}
> ~~~
> * 005937f (HEAD -> main) Discuss concerns about Mars' climate for Mummy
> * 34961b1 Add concerns about effects of Mars' moons on Wolfman
> * f22b25e Start notes on Mars as a base
> ~~~
> {: .output}
{: .callout}

> ## Directories
>
> Two important facts you should know about directories in Git.
>
> 1. Git does not track directories on their own, only files within them.
>    Try it for yourself:
>
>    ~~~
>    $ mkdir spaceships
>    $ git status
>    $ git add spaceships
>    $ git status
>    ~~~
>    {: .language-bash}
>
>    Note, our newly created empty directory `spaceships` does not appear in
>    the list of untracked files even if we explicitly add it (_via_ `git add`) to our
>    repository. This is the reason why you will sometimes see `.gitkeep` files
>    in otherwise empty directories. Unlike `.gitignore`, these files are not special
>    and their sole purpose is to populate a directory so that Git adds it to
>    the repository. In fact, you can name such files anything you like.
>
> 2. If you create a directory in your Git repository and populate it with files,
>    you can add all files in the directory at once by:
>
>    ~~~
>    git add <directory-with-files>
>    ~~~
>    {: .language-bash}
>
>    Try it for yourself:
>
>    ~~~
>    $ touch spaceships/apollo-11 spaceships/sputnik-1
>    $ git status
>    $ git add spaceships
>    $ git status
>    ~~~
>    {: .language-bash}
>
>    Before moving on, we will commit these changes.
>
>    ~~~
>    $ git commit -m "Add some initial thoughts on spaceships"
>    ~~~
>    {: .language-bash}
>
{: .callout}

To recap, when we want to add changes to our repository,
we first need to add the changed files to the staging area
(`git add`) and then commit the staged changes to the
repository (`git commit`):

![The Git Commit Workflow](../fig/git-committing.svg)

> ## Choosing a Commit Message
>
> Which of the following commit messages would be most appropriate for the
> last commit made to `mars.txt`?
>
> 1. "Changes"
> 2. "Added line 'But the Mummy will appreciate the lack of humidity' to mars.txt"
> 3. "Discuss effects of Mars' climate on the Mummy"
>
> > ## Solution
> > Answer 1 is not descriptive enough, and the purpose of the commit is unclear;
> > and answer 2 is redundant to using "git diff" to see what changed in this commit;
> > but answer 3 is good: short, descriptive, and imperative.
> {: .solution}
{: .challenge}

> ## Committing Changes to Git
>
> Which command(s) below would save the changes of `myfile.txt`
> to my local Git repository?
>
> 1. ~~~
>    $ git commit -m "my recent changes"
>    ~~~
>    {: .language-bash}
> 2. ~~~
>    $ git init myfile.txt
>    $ git commit -m "my recent changes"
>    ~~~
>    {: .language-bash}
> 3. ~~~
>    $ git add myfile.txt
>    $ git commit -m "my recent changes"
>    ~~~
>    {: .language-bash}
> 4. ~~~
>    $ git commit -m myfile.txt "my recent changes"
>    ~~~
>    {: .language-bash}
>
> > ## Solution
> >
> > 1. Would only create a commit if files have already been staged.
> > 2. Would try to create a new repository.
> > 3. Is correct: first add the file to the staging area, then commit.
> > 4. Would try to commit a file "my recent changes" with the message myfile.txt.
> {: .solution}
{: .challenge}

> ## Committing Multiple Files
>
> The staging area can hold changes from any number of files
> that you want to commit as a single snapshot.
>
> 1. Add some text to `mars.txt` noting your decision
> to consider Venus as a base
> 2. Create a new file `venus.txt` with your initial thoughts
> about Venus as a base for you and your friends
> 3. Add changes from both files to the staging area,
> and commit those changes.
>
> > ## Solution
> >
> > The output below from `cat mars.txt` reflects only content added during 
> > this exercise. Your output may vary.
> > 
> > First we make our changes to the `mars.txt` and `venus.txt` files:
> > ~~~
> > $ nano mars.txt
> > $ cat mars.txt
> > ~~~
> > {: .language-bash}
> > ~~~
> > Maybe I should start with a base on Venus.
> > ~~~
> > {: .output}
> > ~~~
> > $ nano venus.txt
> > $ cat venus.txt
> > ~~~
> > {: .language-bash}
> > ~~~
> > Venus is a nice planet and I definitely should consider it as a base.
> > ~~~
> > {: .output}
> > Now you can add both files to the staging area. We can do that in one line:
> >
> > ~~~
> > $ git add mars.txt venus.txt
> > ~~~
> > {: .language-bash}
> > Or with multiple commands:
> > ~~~
> > $ git add mars.txt
> > $ git add venus.txt
> > ~~~
> > {: .language-bash}
> > Now the files are ready to commit. You can check that using `git status`. If you are ready to commit use:
> > ~~~
> > $ git commit -m "Write plans to start a base on Venus"
> > ~~~
> > {: .language-bash}
> > ~~~
> > [main cc127c2]
> >  Write plans to start a base on Venus
> >  2 files changed, 2 insertions(+)
> >  create mode 100644 venus.txt
> > ~~~
> > {: .output}
> {: .solution}
{: .challenge}

> ## `bio` Repository
>
> * Create a new Git repository on your computer called `bio`.
> * Write a three-line biography for yourself in a file called `me.txt`,
> commit your changes
> * Modify one line, add a fourth line
> * Display the differences
> between its updated state and its original state.
>
> > ## Solution
> >
> > If needed, move out of the `planets` folder:
> >
> > ~~~
> > $ cd ..
> > ~~~
> > {: .language-bash}
> >
> > Create a new folder called `bio` and 'move' into it:
> >
> > ~~~
> > $ mkdir bio
> > $ cd bio
> > ~~~
> > {: .language-bash}
> >
> > Initialise git:
> >
> > ~~~
> > $ git init
> > ~~~
> > {: .language-bash}
> >
> > Create your biography file `me.txt` using `nano` or another text editor.
> > Once in place, add and commit it to the repository:
> >
> > ~~~
> > $ git add me.txt
> > $ git commit -m "Add biography file" 
> > ~~~
> > {: .language-bash}
> >
> > Modify the file as described (modify one line, add a fourth line).
> > To display the differences
> > between its updated state and its original state, use `git diff`:
> >
> > ~~~
> > $ git diff me.txt
> > ~~~
> > {: .language-bash}
> >
> {: .solution}
{: .challenge}

[commit-messages]: https://chris.beams.io/posts/git-commit/
[git-references]: https://git-scm.com/book/en/v2/Git-Internals-Git-References

{% include links.md %}

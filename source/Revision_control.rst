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

   .	..	.git

Git uses this special subdirectory to store all the information about the project, 
including the tracked files and sub-directories located within the project's directory.
If we ever delete the ``.git`` subdirectory, we will lose the project's history.

Next, we will change the default branch to be called ``main``.
This might be the default branch depending on your settings and version
of git. See the :ref:`Setting up git` section above for more information on this change.

.. code-block:: bash
   
   git checkout -b main

   Switched to a new branch 'main'


We can check that everything is set up correctly
by asking Git to tell us the status of our project:

.. code-block:: bash

   git status

   On branch main

   No commits yet

   nothing to commit (create/copy files and use "git add" to track)

If you are using a different version of `git`, the exact
wording of the output might be slightly different.

> ## Places to Create Git Repositories
>
> Along with tracking information about planets (the project we have already created), 
> Dracula would also like to track information about moons.
> Despite Wolfman's concerns, Dracula creates a `moons` project inside his `planets` 
> project with the following sequence of commands:
>
> ~~~
> $ cd ~/Desktop   # return to Desktop directory
> $ cd planets     # go into planets directory, which is already a Git repository
> $ ls -a          # ensure the .git subdirectory is still present in the planets directory
> $ mkdir moons    # make a subdirectory planets/moons
> $ cd moons       # go into moons subdirectory
> $ git init       # make the moons subdirectory a Git repository
> $ ls -a          # ensure the .git subdirectory is present indicating we have created a new Git repository
> ~~~
> {: .language-bash}
>
> Is the `git init` command, run inside the `moons` subdirectory, required for 
> tracking files stored in the `moons` subdirectory?
> 
> > ## Solution
> >
> > No. Dracula does not need to make the `moons` subdirectory a Git repository 
> > because the `planets` repository can track any files, sub-directories, and 
> > subdirectory files under the `planets` directory.  Thus, in order to track 
> > all information about moons, Dracula only needed to add the `moons` subdirectory
> > to the `planets` directory.
> > 
> > Additionally, Git repositories can interfere with each other if they are "nested":
> > the outer repository will try to version-control
> > the inner repository. Therefore, it's best to create each new Git
> > repository in a separate directory. To be sure that there is no conflicting
> > repository in the directory, check the output of `git status`. If it looks
> > like the following, you are good to go to create a new repository as shown
> > above:
> >
> > ~~~
> > $ git status
> > ~~~
> > {: .language-bash}
> > ~~~
> > fatal: Not a git repository (or any of the parent directories): .git
> > ~~~
> > {: .output}
> {: .solution}
{: .challenge}
> ## Correcting `git init` Mistakes
> Wolfman explains to Dracula how a nested repository is redundant and may cause confusion
> down the road. Dracula would like to remove the nested repository. How can Dracula undo 
> his last `git init` in the `moons` subdirectory?
>
> > ## Solution -- USE WITH CAUTION!
> >
> > ### Background
> > Removing files from a Git repository needs to be done with caution. But we have not learned 
> > yet how to tell Git to track a particular file; we will learn this in the next episode. Files 
> > that are not tracked by Git can easily be removed like any other "ordinary" files with
> > ~~~
> > $ rm filename
> > ~~~
> > {: .language-bash}
> >
> > Similarly a directory can be removed using `rm -r dirname` or `rm -rf dirname`.
> > If the files or folder being removed in this fashion are tracked by Git, then their removal 
> > becomes another change that we will need to track, as we will see in the next episode.
> >
> > ### Solution
> > Git keeps all of its files in the `.git` directory.
> > To recover from this little mistake, Dracula can just remove the `.git`
> > folder in the moons subdirectory by running the following command from inside the `planets` directory:
> >
> > ~~~
> > $ rm -rf moons/.git
> > ~~~
> > {: .language-bash}
> >
> > But be careful! Running this command in the wrong directory will remove
> > the entire Git history of a project you might want to keep.
> > Therefore, always check your current directory using the command `pwd`.
> {: .solution}
{: .challenge}

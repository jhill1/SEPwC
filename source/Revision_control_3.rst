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

.. code-block:: output

    .	..	.git

Git uses this special subdirectory to store all the information about the project, 
including the tracked files and sub-directories located within the project's directory.
If we ever delete the ``.git`` subdirectory, we will lose the project's history.

Next, we will change the default branch to be called ``main``.
This might be the default branch depending on your settings and version
of git. See the :ref:`Setting up git` section above for more information on this change.

.. code-block:: bash
   
   git checkout -b main

.. code-block:: output
   
    Switched to a new branch 'main'


We can check that everything is set up correctly
by asking Git to tell us the status of our project:

.. code-block:: bash

   git status

.. code-block:: output

    On branch main
    
    No commits yet
    
    nothing to commit (create/copy files and use "git add" to track)

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

    .. code-block:: output

        fatal: Not a git repository (or any of the parent directories): .git

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


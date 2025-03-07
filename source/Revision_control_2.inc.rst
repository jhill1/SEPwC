Setting up git
---------------
.. index:: 
   single: git; setup 
   single: git; config


For all the command-line examples below using either the ``git bash`` application (|win|) or the terminal (|maclin|). 
On linux you can access the terminal via the Start Menu equivalent on most systems. On Macs, the terminal may be 
hidden in the Utilities folder under Applications. 

When we use Git on a new computer for the first time, we need to configure a few things. Below are a few examples
of configurations we will set as we get started with Git:

*   our name and email address,
*   what our preferred text editor is,
*   and that we want to use these settings globally (i.e. for every project).

On a command line, Git commands are written as ``git verb options``,
where ``verb`` is what we actually want to do and ``options`` is additional optional information which may be 
needed for the ``verb``. So here is how I might setup my new laptop:

.. code-block:: bash
   :caption: |cli|

   git config --global user.name "Jon Hill"
   git config --global user.email "jon.hill@york.ac.uk"


Please use your own name and email address instead of mine. This user name and email will be associated with your subsequent Git activity,
which means that any changes pushed to
`GitHub <https://github.com/>`__,
`BitBucket <https://bitbucket.org/>`__,
`GitLab <https://gitlab.com/>`__ or
another Git host server after this lesson will include this information.

For this lesson, we will be interacting with `GitHub <https://github.com/>`__ and so the email address used should be the 
same as the one used when setting up your GitHub account. If you are concerned about privacy, 
please review `GitHub's instructions for keeping your email address private <https://docs.github.com/en/account-and-profile/setting-up-and-managing-your-personal-account-on-github/managing-email-preferences/blocking-command-line-pushes-that-expose-your-personal-email-address>`_. 


.. caution::
   
   *Line Endings*

   As with other keys, when you hit :kbd:`Enter` or :kbd:`Return` on your keyboard,
   your computer encodes this input as a character.
   Different operating systems use different character(s) to represent the end of a line.
   (You may also hear these referred to as newlines or line breaks.)
   Because Git uses these characters to compare files,
   it may cause unexpected issues when editing a file on different machines. 
   Though it is beyond the scope of this lesson, you can read more about this issue 
   `in the Pro Git book <https://www.git-scm.com/book/en/v2/Customizing-Git-Git-Configuration#_core_autocrlf>`__.
   
   You can change the way Git recognizes and encodes line endings
   using the `core.autocrlf` command to `git config`.
   The following settings are recommended:
   On macOS and Linux:
    
   .. code-block:: bash
      :caption: |cli|
   
      git config --global core.autocrlf input

   And on Windows:

   .. code-block:: bash
      :caption: |cli|

      git config --global core.autocrlf false

We also need to set our favorite text editor, following this table:

.. list-table:: Editors and config
    :header-rows: 1

    * - Editor
      - Configuration command
    * - nano 
      - ``$ git config --global core.editor "nano -w"``    
    * - BBEdit (Mac, with command line tools)  
      - ``$ git config --global core.editor "bbedit -w"``    
    * - Notepad (Win)     
      - ``$ git config --global core.editor "c:/Windows/System32/notepad.exe"``
    * - Notepad++ (Win, 64-bit install)     
      - ``$ git config --global core.editor "'c:/program files/Notepad++/notepad++.exe' -multiInst -notabbar -nosession -noPlugin"``     
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

It is possible to reconfigure the text editor for Git whenever you want to change it. ``nano`` is probably the best bet as it's usually on every system.


.. caution::

   **Exiting Vim**
  
   Note that Vim is the default editor for many programs. If you haven't used Vim before and wish to exit a session without saving
   your changes, press :kbd:`Esc` then type ``:q!`` and hit :kbd:`Enter` or  :kbd:`Return`.
   If you want to save your changes and quit, press :kbd:`Esc` then type ``:wq`` and hit :kbd:`Enter` or :kbd:`Return`.


Git (2.28+) allows configuration of the name of the branch created when you
initialize any new repository.  We should use that feature to set it to `main` so 
it matches Gihub

.. code-block:: bash
   :caption: |cli|

   git config --global init.defaultBranch main

The five commands we just ran above only need to be run once: the flag `--global` tells Git
to use the settings for every project, in your user account, on this computer.

You can check your settings at any time:

.. code-block:: bash
   :caption: |cli|

   git config --list

You can change your configuration as many times as you want: use the
same commands to choose another editor or update your email address.

.. hint::

   **Git Help and Manual**

   Always remember that if you forget the subcommands or options of a ``git`` command, you can access the
   relevant list of options typing ``git <command> -h`` or access the corresponding Git manual by typing
   ``git <command> --help``, e.g.:

   .. code-block:: bash
      :caption: |cli|
   
      git config -h
      git config --help

   While viewing the manual, remember the ``:`` is a prompt waiting for commands and you can press :kbd:`Q` to exit the manual.
   More generally, you can get the list of available ``git`` commands and further resources of the Git manual typing:
 
   .. code-block:: bash
      :caption: |cli|

      git help

..  youtube:: k_js-zjVXk4
   :align: center


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

.. code-block:: output

    On branch main
    Untracked files:
     (use "git add <file>..." to include in what will be committed)

        a.dat
        b.dat
        c.dat
        results/

    nothing added to commit but untracked files present (use "git add" to track)

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



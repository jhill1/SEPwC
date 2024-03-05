R namespace
----------------------------

Namespace and scope are the section of code where your variables are valid. A namespace
is a collection of currently defined symbolic names; basically a dictionary of variable
names pointing to the object in memory.

In R, the namespace and scope are referred to as the ``environment``. You can create environments
yourself, but they are also created in certain circumstances. There is always at least
three ``environment``s: ``empty``, ``global`` and ``current``. 

The two important ``environments`` are the ``current_env()`` and the ``global_env()``. The
global environment is your "workspace" as it's where all activity, outside functions, takes
place. 

Special environments
~~~~~~~~~~~~~~~~~~~~

Most environments are not created by you, but by R. Each package attached
using ``library()`` or ``require()`` becomes on of the parents of the global environment. 
The immediate parent of the global environment is the last package you attached, and
the previous one is the parent to that...

We can use the ``rlang`` packge to explore this.

.. code-block:: R

    library(rlang)

   env_parents(global_env())
     [[1]] $ <env: package:rlang>
     [[2]] $ <env: package:stats>
     [[3]] $ <env: package:graphics>
     [[4]] $ <env: package:grDevices>
     [[5]] $ <env: package:utils>
     [[6]] $ <env: package:datasets>
     [[7]] $ <env: package:methods>
     [[8]] $ <env: Autoloads>
     [[9]] $ <env: package:base>
    [[10]] $ <env: empty>
   

You can see the ultimate parent is the ``empty`` environment, then we have ``base``
, ``Autoloads``, etc until we get to ``rlang`` which is the last one we loaded. If we
then load another package:

.. code-block:: R

    library(ggpubr)

    env_parents(global_env())
    Loading required package: ggplot2
     [[1]] $ <env: package:ggpubr>
     [[2]] $ <env: package:ggplot2>
     [[3]] $ <env: package:rlang>
     [[4]] $ <env: package:stats>
     [[5]] $ <env: package:graphics>
     [[6]] $ <env: package:grDevices>
     [[7]] $ <env: package:utils>
     [[8]] $ <env: package:datasets>
     [[9]] $ <env: package:methods>
    [[10]] $ <env: Autoloads>
    [[11]] $ <env: package:base>
    [[12]] $ <env: empty>

You can see ``ggpubr`` as the top package, but we can also see that ``ggplot2`` has also been loaded (by ``ggpubr``).

This ordering then dictates the search path when a variable or function is asked for. 

Super assignment
~~~~~~~~~~~~~~~~~

Later, we will deal with R objects and you'll see the ``<<-`` operator for 
assigning values. You will have already seen the `<-` assignment operator. Why
the two?

Regular assignment, ``<-`` always creates a variable in the current environment. Super
assignment, ``<<-`` never creates a variable in the current environment, but instead creates it
in a parent environment. 

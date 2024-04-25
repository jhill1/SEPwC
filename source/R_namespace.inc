R namespace
----------------------------
.. index:: 
   single: namespace; R

Namespace and scope are the section of code where your variables are valid. A namespace
is a collection of currently defined symbolic names; basically a dictionary of variable
names pointing to the object in memory.

In R, the namespace and scope are referred to as the ``environment``. You can create environments
yourself, but they are also created in certain circumstances. There is always at least
three ``environments``: ``empty``, ``global`` and ``current``. 

The two important ``environments`` are the ``current_env()`` and the ``global_env()``. The
global environment is your "workspace" as it's where all activity, outside functions, takes
place. 

Special environments
~~~~~~~~~~~~~~~~~~~~
.. index:: 
   single: special environments; R

Most environments are not created by you, but by R. Each package attached
using ``library()`` or ``require()`` becomes on of the parents of the global environment. 
The immediate parent of the global environment is the last package you attached, and
the previous one is the parent to that...

We can use the ``rlang`` packge to explore this.

.. code-block:: R
   :caption: |R|

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
    :caption: |R|

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

This ordering then dictates the search path when a variable or function is asked for. That's leads to an interesting question
as to which function gets called if there are more than one of the same name. In a new R session, run the following:

.. code-block:: R
   :caption: |R|

    library(rlang)

    env_parents = function(temp) {
        print("My env_parents()")
    }

    env_parents(global_env())
    
You should see ``My env_parents()`` printed to the screen. Your function is first in the search path, so it is
called, not the function of the same name in the ``rlang`` package.

.. admonition:: Exercise

   So how can we call the ``rlang`` version?

.. admonition:: Solution
   :class: toggle

   .. code-block:: R
     :caption: |R|

     rlang::env_parents(global_env())
     
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

    
This is fine for our code, but what about within packages? What happens if ``print`` is a function in multiple
packages?

In R this is handled by the *function* environment and the *namespace* environment. The function environment is created
every time you call a function and it is bound to the enviroment from where it's created. Note there is another
environment called the ``caller_env()`` which is where the function is called from. This is getting rather complex, but 
it means two things that are important to you:

 1. When you call a function and it returns nothing is kept. Eveyrthing you use within a function is destroyed.
 2. As a function is bound to the environment it is created, within a package, *that* function will be found first
    in the search

The upshot of this is that it doesn't matter which order you load libraries, the ``print`` function in ``ggpubr`` will always
be called within ``ggpubr`` and the ``print`` function in side ``rlang`` will always be called within ``rlang``. However, what this
does mean is that sometimes your code behaviour *may* change depending on the order in which you load libraries. If you are expting 
a function called ``sd`` to be called from one library, but another library was loaded afterwards and also had that function, you might
get the wrong one. 

Super assignment
~~~~~~~~~~~~~~~~~
.. index:: 
   single: super assignment; R

In the next section, we will deal with R objects and you'll see the ``<<-`` operator for 
assigning values. You will have already seen the `<-` assignment operator. Why
the two?

Regular assignment, ``<-`` always creates a variable in the current environment. Super
assignment, ``<<-`` never creates a variable in the current environment, but instead creates it
in a parent environment. 

An object method creates a ``function_env``; we don't want that variable altered in the function and then
lost, we want the variable altered in the object. Hence, we use the ``<<-`` assignment to alter
the variable in the environment *above* the function (which is the object). 


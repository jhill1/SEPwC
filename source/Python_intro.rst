Intro to Python
---------------

Python is an interpreted language that has become incredibily popular. Due to that 
there are modules that will do just about anything. This makes Python a really
powerful tool for writing code to analyse any number of problems.

Python can be run on the command line, in a Jupyter notebook, in Google Colab, 
as a standalone script, or even as a full GUI program. There are modules
for plotting (matplotlib), scientific algorithms (scipy), numerical algorithms
(numpy) and GIS (gdal).

Let's get a simple python code running!


We want to calculate the height of a ball after time, t, which we can do using this formula

.. math::
   
   y(t) = v_{0}t- \frac{1}{2}gt^2

where:

 * :math:`y(t)` is the height of the ball at time :math:`t`
 * :math:`v_0` is the initial velocity of tha ball (at :math:`t=0`), and
 * :math:`g` is the acceleration due to gravity

Let's work this out by hand for a ball thrown at 5 m/s, with :math:`g=9.81`, at :math:`t=0.5`

We have:

.. math::

   y = 5 \times 0.5 - (\frac{1}{2} \times 9.81 \times 0.5^2)

I get that to be:

.. math::

   y = 2.5 - 1.22625
   
   y = 1.27375

using a calculator. So let's do that in python:

.. code-block:: python

   print(5*0.5 - 0.5*9.81*0.5**2)
   
Great! Our first python code! Let's build this up to use variables. Type the following code and execute:

.. code-block:: python

   time = 0.5
   initial_velocity = 5
   gravity = 9.81

   vert_position = initial_velocity * time - (0.5 * gravity * time**2)
   print(vert_position)

This code is, inessence, identical to the one above, but instead of *hardcoding* the numebrs, we've used 
variables. The formula is now written in good, descriptive variable names, using spaces and parantheses to
separate the terms for readability. Not that exciting yet. What if we want to calculate the height for a
bunch of times? Let's add a loop!

.. code-block:: python

   times = [0, 0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9]
   initial_velocity = 5
   gravity = 9.81

   for time in times:
       vert_position = initial_velocity * time - (0.5 * gravity * time**2)
       print(time, vert_position)

This is not the most elegant way to do this, but it works. You now have the height of the ball
at time 0 to 0.9 in steps of 0.1. Note the indentation. In Python *whitespace* matters. It signifies 
which statements are part of the `for` loop. You must be consistant with indentation or your
code will not run.

.. admonition:: Practical exercise

   **What happens if the code isn't indented correctly?**
    
   Take the code here:

   .. code-block:: python

      times = [0, 0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9]
      initial_velocity = 5
      gravity = 9.81

      for time in times:
          vert_position = initial_velocity * time - (0.5 * gravity * time**2)
          print(time, vert_position)

   Let's edit that to produce some wierd indentation:

   .. code-block:: python

      times = [0, 0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9]
      initial_velocity = 5
      gravity = 9.81

      for time in times:
        vert_position = initial_velocity * time - (0.5 * gravity * time**2)
          print(time, vert_position)

   What error do you see?

   What about this code? What will it print?

   .. code-block:: python

      times = [0, 0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9]
      initial_velocity = 5
      gravity = 9.81

      for time in times:
          vert_position = initial_velocity * time - (0.5 * gravity * time**2)
      print(time, vert_position)

.. admonition:: Solution
   :class: toggle

   The code above will print a single `time`, `vert_position` pair which will
   be the values at the final iteration of the loop.

   .. code-block:: output

      0.9 0.5269499999999994
      

Shall we plot this?

.. code-block:: python

   from matplotlib import pyplot

   # set up the problem
   times = [0, 0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9]
   heights = []
   initial_velocity = 5
   gravity = 9.81

   # loop through the times, calculating the height
   for time in times:
       vert_position = initial_velocity * time - (0.5 * gravity * time**2)
       heights.append(vert_position)
       
   # the times and heights are now stored, so we can plot
   pyplot.plot(times, heights)
   pyplot.show()


.. image:: ../images/Python_ball_graph.png


That's not bad for a few lines of code. You can't publish that graph (no axes labels, etc), but for
your first Python program I think that's pretty good!

In the above we have used the following Python features:

 * printing
 * comments
 * lists
 * importing modules
 * loops and list comprehension
 * very basic matplotlib
 * variable names

We've covered some of these in the pseudo-code chapter, so here we're going to stick to the
Python-specific parts and go through these in more detail.


Python and R: the basics
=========================

We're now going to learn the basics of a language. If you've chosen 
Python, keep reading. If you've choosen R :ref:`go to this section<Intro to R>`.


Computer languages are much simpler than natural langauages, but much
stricter. We have to get the syntax correct or things won't work. However
interpreted languages tell you what is wrong, so it's not as bad as it sounds.

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
at time 0 to 0.9 in steps of 0.1.

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




Intro to R
-----------

R is an interpreted language that has become incredibily popular, but 
was originally designed as a free, open-source version of "S"; a statistical
analysis package. Due to populularity, there are libaries that will do just about anything. 
This makes R a really powerful tool for writing code to analyse any number of problems.

R can be run on the command line, in a popular GUI call R-Studio,
as a standalone script, even on websites. There are libraries
for fancy plotting (ggplot2), scientific algorithms (e.g. deSolve), AI (dnn) and GIS (r-gdal).

Let's get a simple R code running!


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

.. code-block:: R

   print(5*0.5 - 0.5*9.81*0.5**2)
   
Great! Our first R code! Let's build this up to use variables. Type the following code and execute:

.. code-block:: R

   time <- 0.5
   initial_velocity <- 5
   gravity <- 9.81

   vert_position <- initial_velocity * time - (0.5 * gravity * time**2)
   print(vert_position)

This code is, inessence, identical to the one above, but instead of *hardcoding* the numebrs, we've used 
variables. The formula is now written in good, descriptive variable names, using spaces and parantheses to
separate the terms for readability. Not that exciting yet. What if we want to calculate the height for a
bunch of times? Let's add a loop!

.. code-block:: R

   times <- c(0, 0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9)
   initial_velocity <- 5
   gravity <- 9.81

   for (time in times) {
       vert_position <- initial_velocity * time - (0.5 * gravity * time**2)
       print(paste(time, vert_position))
    }

This is not the most elegant way to do this, but it works. You now have the height of the ball
at time 0 to 0.9 in steps of 0.1.

Shall we plot this?

.. code-block:: R

   # set up the problem
   times = c(0, 0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9)
   heights = c()
   initial_velocity = 5
   gravity = 9.81

   # loop through the times, calculating the height
   for (time in times) {
       vert_position = initial_velocity * time - (0.5 * gravity * time**2)
       heights <- c(heights,vert_position)
    }
       
   # the times and heights are now stored, so we can plot
   plot(times, heights)


.. image:: ../images/R_ball_graph.png


That's not bad for a few lines of code. You can't publish that graph (axes labels without units, etc), but for
your first R program I think that's pretty good!

In the above we have used the following R features:

 * printing
 * comments
 * vectors
 * loops and list comprehension
 * very basic plotting
 * variable names

We've covered some of these in the pseudo-code chapter, so here we're going to stick to the
R-specific parts and go through these in more detail.


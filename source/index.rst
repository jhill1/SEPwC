.. SEPwC documentation master file, created by
   sphinx-quickstart on Wed Jan 18 17:17:35 2023.
   You can adapt this file completely to your liking, but it should at least
   contain the root `toctree` directive.

Welcome to Solving Environmental Problems with Code (SEPwC)
===========================================================

.. image:: ../images/favicon-180x180.png
   :alt: SEPwC logo
   :width: 180px
   :align: center


The aim of this module is to teach you the basics of writing simple computer scripts so 
that you can analyse data to help solve problems. These data may be spatial (i.e. like GIS)
or text (e.g. transcripts of interviews) or collected in the field (so you can do some stats).

By the end of this module you should be able to write a relatively simple script from 
scratch which can load in data, processes it and produce some meaningful output.

We will teach both R and Python and you can choose which one to learn (or even both!). 

The table below contains suggestions of which blocks of works to cover in each week
to help guide you. However, you can forge ahead, but equally, don't worry if you
slip behind a little.

.. list-table:: Suggested work
   :header-rows: 1

   * - Week
     - Content
   * - 1
     - :ref:`How a computer works<How a computer works>`, :ref:`Licences<Software licences>`
   * - 2
     - :ref:`Code basics<The fundamentals of code>`, :ref:`Thinking like a computer<Thinking like a computer>`
   * - 3
     - :ref:`Python<Python: the fundamentals>` or :ref:`R<R: the fundamentals>` 1, :ref:`Debugging code<Solving issues and debugging>`,
   * - 4 
     - :ref:`Revision control<Revision control with Git>`,
   * - 5
     - :ref:`Python<Python: part 2>` or :ref:`R<R: part 2>` 2,  :ref:`Testing code<Testing code>`,
   * - 6
     - :ref:`Python<Python: part 3>` or :ref:`R<R: part 3>` 3,  :ref:`Moving from spreadsheets to data<Moving from spreadsheets to data>`, 
   * - 7
     - :ref:`Software development<Software development>`, :ref:`formative exercise<Our first coding exercise>`
   * - 8
     - Mini-courses
   * - 9
     - Mini-courses
   * - 10
     - Assessment
   * - 11
     - Assessment

**Conventions used.**

Any code will be in a block, with an icon showing the language:

.. code-block:: R
   :caption: |R|

    # some R code
    library(tidyverse)

or

.. code-block:: Python
   :caption: |python|

    # some Python code
    import numpy as np

Any output or commands in the command line will be shown using an icon like this:

.. code-block:: bash
   :caption: |cli|

    ls -al

An additional logo will show which operating system the commands are for

     - Mac only: |mac|
     - Linux only: |linux|
     - Windows only: |win|
     - Mac and Linux:  |maclin|
     - All OSes: |all|

So for example:

.. code-block:: bash
   :caption: |cli| |maclin|

    ls -al

for Linux/Mac commands, and 

.. code-block:: bash
   :caption: |cli| |win|

    dir /a:h

for Window CLI commands.

Sometimes, output is shown from Python or R. These will be labelled as Python and R with 
the command line icon:


.. code-block:: Python
   :caption: |python|

    # some Python code
    print("Hello World!")

.. code-block:: bash
   :caption: |cli| |python| 

    Hello World!
    
If a command and the output are shown in the same block, the command will be prefixed
by either a ``$`` (|maclin|), a ``>`` (|win|) or a ``>>>`` (|python|) symbol. 
*Do not copy or type those symbols in*.
For example:

.. code-block:: bash
   :caption: |cli| |maclin|

   $ pwd
   /home/jh1889/work/teaching/SEPwC/source

Type in the ``pwd`` command only into the command line. 

Where I've used an AI prompt, this will be labelled with this symbol:

.. code-block::
   :caption: |ai|

   How do I load a csv file using numpy?

Finally, I also use psuedo-code in the early stages. This is not a real language so can't be run or compiled! 
All psuedo-code is labelled with this symbol:

.. code-block:: 
   :caption: |pc|

    variable = 23.432

.. include:: acknowledgements.inc.rst


.. toctree::
    :maxdepth: 2
    :caption: Contents:

    How_a_computer_works
    Licences
    Code_basics
    Algorithms
    Python
    R
    Issues
    Revision_control   
    Python2
    R2
    Software_development
    a_first_coding_exercise    
    Python3
    R3
    Spreadsheets_data
    Testing_code
    R_ggplot2
    python_plotting
    Sentiment_analysis
    tides_python
    GIS
    genindex




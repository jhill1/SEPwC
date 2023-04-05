Python comments
----------------

All computer languages have some mechaisms to add text that is not part of the code
itself. These are called comments. The idea of these snippets of text are to provide
commentary to help someone (including future you) understand the code
that has been written.

Python has multiple ways of adding comments, which actually provide slightly different
functions. In this section we're going to stick to the PEP (Python Enhacement Protocols)
styles to keep your code consistant. 
https://peps.python.org/

Python has three styles of comments: inline, block and documentation.

Inline comments
~~~~~~~~~~~~~~~

Inline comments occur within the line of code:

.. code-block:: python

    x = x + 1                 # Increment x

This style of comment should be avoided if possible. The above example is distracting
and unecessary. It may sometimtes be useful, for example:

.. code-block:: python

    x = x + 1                 # account for boundary cell

Here, the same style is used, but as the line of code is so short, as is the comment, this 
may be preferable to the second style of comments


Block comments
~~~~~~~~~~~~~~

Block comments occupy one or more lines. In python they look like:

.. code-block:: python

    # incrememnt count to account for boundary cell
    x = x + 1

Or if you want multiple lines:

.. code-block:: python

    # incrememnt count to 
    # account for boundary cell
    x = x + 1


The PEP8 guidance says lines of code should be sorter than 72 characters (this includes comments), hence
why you may "wrap" comments onto multiple lines.


Documentation comments
~~~~~~~~~~~~~~~~~~~~~~

Python also has a second style of comments that also act as a way of documentating code. They should be used
underneath functions, classes and modules where public facing (i.e. where documentation is helpful!).

An example is something like this:

.. code-block:: python

    def complex(real=0.0, imag=0.0):
        """Form a complex number.

        Keyword arguments:
        real -- the real part (default 0.0)
        imag -- the imaginary part (default 0.0)
        """
        if imag == 0.0 and real == 0.0:
            return complex_zero
        ...

The above function, `complex` returns a complex number. The docstring, delimited by the three " marks states
what the function does, what the arguments are. You may also add what is returned (though here, it's obvious!).

What to comment
~~~~~~~~~~~~~~~

The above tell you *how* to write a comment, but *what* should you comment? Comments need to 
be useful for the people that come after you (including you) so they can understand the code better.
They should not simply repeat the code, nor be used to explain code that could have better variable names.
It's often easier to say what *not* to do, so let's head in that direction...

This is poor coding and commenting:

.. code-block:: python

    # A dictionary of families who live in each city
    mydict = {
        "York": ["Powell", "Brantley", "Young"],
        "Stevenage": ["Montgomery"], 
        "Rotherham": ["Hill"]
    }

    def a(dict):
        # For each city
        for p in dict:
            # If there are no families in the city
            if not mydict[p]:
                # Say that there are no families
                print("None.")

The comments relaly help understand the code and the intentions, but there are 
completely superfluous if the code was writen well:

.. code-block:: python

    families_by_city = {
        "York": ["Powell", "Brantley", "Young"],
        "Stevenage": ["Montgomery"],
        "Rotherham": ["Hill"],
    }

    def no_families(cities):
        for city in cities:
            if not families_by_city[city]:
                print(f"No families in {city}.")

This code doesn't need any comments now; the variable names make things a lot clearer. You 
can't compensate for poor style by adding comments...

You should also avoid comments that simply repeat the code:

.. code-block:: python

    return a  # Returns a

That comments adds nothing to the understanding. If `a` was a proper variable name, e.g. `list_of_cells` then even adding a comment becomes somewhat 
redundant. Add a docstring to the top of a function and there is no need at all to comment the return statement.

The best hint for comments is to write them at the top of code blocks:

.. code-block:: python

    # we now extend this mask - we only need to do this, if the
    # no data occurs (i.e. no contiguous data)
    if (nodata in orig_raster):
        mask = np.full((ncols, nrows), False)
        mask[dist == 0] = True
        mask = self.extend_mask(mask, 1)
        dist[mask] = 0

The code itself might not make perfect sense to someone new to the whole code, but the comment above helps orient them
if there some error in that part of the code. It also helps to explain *why* rather than the how in comments. The how
is in the code. The why is how it's written. 



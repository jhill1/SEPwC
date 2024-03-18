R comments
----------
.. index:: 
   single: comments; r

All computer languages have some mechanisms to add text that is not part of the code
itself. These are called comments. The idea of these snippets of text are to provide
commentary to help someone (including future you) understand the code
that has been written.

R has a single way of adding comments, but can be used in two different ways;
inline comments and block comments.

Inline comments (R)
~~~~~~~~~~~~~~~~~~~~
.. index:: 
   single: comments; inline comments (R)

Inline comments occur within the line of code:

.. code-block:: R

    x = x + 1                 # Increment x

This style of comment should be avoided if possible. The above example is distracting
and unnecessary. It may sometimes be useful, for example:

.. code-block:: R

    x = x + 1                 # account for boundary cell

Here, the same style is used, but as the line of code is so short, as is the comment, this 
may be preferable to the second style of comments


Block comments (R)
~~~~~~~~~~~~~~~~~~
.. index:: 
   single: comments; block comments (R)

Block comments occupy one or more lines. In python they look like:

.. code-block:: R

    # increment count to account for boundary cell
    x = x + 1

Or if you want multiple lines:

.. code-block:: R

    # increment count to 
    # account for boundary cell
    x = x + 1


What to comment (R)
~~~~~~~~~~~~~~~~~~~

The above tell you *how* to write a comment, but *what* should you comment? Comments need to 
be useful for the people that come after you (including you) so they can understand the code better.
They should not simply repeat the code, nor be used to explain code that could have better variable names.
It's often easier to say what *not* to do, so let's head in that direction...

This is poor coding and commenting:

.. code-block:: R

    # A dictionary of families who live in each city
    mydict = c(
        "York" = c("Powell", "Brantley", "Young"),
        "Stevenage" = c("Montgomery"), 
        "Rotherham" = c("Hill")
    )

    a <- function(dict) {
        # For each city
        for (p in dict) {
            # If there are no families in the city
            if (length(p) == 0) {
                # Say that there are no families
                print("None.")
            }
         }
    }

The comments really help understand the code and the intentions, but there are 
completely superfluous if the code was written well:

.. code-block:: R

    families_by_city = c(
        "York" = c("Powell", "Brantley", "Young"),
        "Stevenage" = c("Montgomery"), 
        "Rotherham" = c("Hill")
    )

    no_families <- function(cities) {
        for (city in cities) {
            if (length(cities[city]) == 0) {
                print(paste("No families in",city))
            }
        }
    }

This code doesn't need any comments now; the variable names make things a lot clearer. You 
can't compensate for poor style by adding comments...

You should also avoid comments that simply repeat the code:

.. code-block:: R

    return(a)  # Returns a

That comments adds nothing to the understanding. If `a` was a proper variable name, e.g. `list_of_cells` then even adding a comment becomes somewhat 
redundant. Add a block comment to the top of a function with details of the function and there is no need at all to comment the return statement.

The best hint for comments is to write them at the top of code blocks:

.. code-block:: R

    # load in our layers. They have the same extents and resolution
    dem <- raster('test_dem_clipped.tif')
    drainage <-raster('test_rivers_buffer_utm_clipped.tif')
    landuse <- raster('test_landcover_utm.tif')
    roads <- raster('test_roads_buffer_utm_clipped.tif')
    faults <- raster('test_faults_buffer_utm_clipped.tif')

    # following Saha et al 2002
    # we need: slope and roughness (their relative relief) from the DEM.
    slope <- terrain(dem, opt=c('slope'), unit='degrees', neighbours=8)
    roughness <- terrain(dem, opt=c('roughness'), unit='degrees', neighbours=8)

The code itself might not make perfect sense to someone new to the whole code, but the comment above helps orient them
if there some error in that part of the code. It also helps to explain *why* rather than the how in comments. The how
is in the code. The why is how it's written. 



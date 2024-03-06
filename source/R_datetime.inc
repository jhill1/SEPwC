R: Datetimes
----------------------

Dates and time are a common aspect of environmental data. We often need to 
crop date/times to a specific range and compare or take samples from our
data every *N* minutes, for example. R does not handle date and times well
without additional packages. Here, we'll focus on the ``lubridate`` package
which makes life a lot easier.

There are three types of temporal data:

 - date: ``<date>`` a date only
 - time: ``<time>`` which is within a day
 - datetime: ``<dttm>`` or ``POSIXct``, which is a unqiue time and date

For most data you are going to be dealing with datetime objects and occasionaly dates. It's
rare to have only time!

Let's get some times and dates:

.. code-block:: R

    library(lubridate)

    date()
    now()

The first returns a date object, the second returns a datetime object. These are
represented as a string to screen.

In data, the date or time is represented in a number of ways; either as a complete
string, or as columns with day, month, year, hour, minute, etc. What we need for our
code is a datetime object, so we need to parse the string into those objects.

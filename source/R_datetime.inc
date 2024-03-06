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

We can therefore create arbitrary dates, times or datetime, rather than relying
on ``now()``:

.. code-block:: R

    ymd("2017-01-31")
    mdy("January 31st, 2017")
    dmy("31-Jan-2017")
    ymd(20170131)

To create datetimes:

.. code-block:: R

    ymd_hms("2017-01-31 20:11:59")
    mdy_hm("01/31/2017 08:01")


Representing dates and times as these object then allows calculations to be carried
out, for example, creating a duration:

.. code-block:: R

    date1 = ymd(20240228)
    date2 = ymd(20230228)

    print(date1 - date2)
    diff = date1-date2


    # what about leap years?
    date1 = ymd(20240229)
    date2 = ymd(20230228)

    print(date1 - date2)

However, the difftime class which is the outcome of a duration depends on what the duration is, but comes in the 
form of weeks, days, seconds. Not that useful, so ``lubridate`` comes with a function to force it to seconds:

.. code-block:: R

    date1 = ymd(20240228)
    date2 = ymd(20230228)

    diff = date1-date2
    as.duration(diff)

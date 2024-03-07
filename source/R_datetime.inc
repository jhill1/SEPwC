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

The datetime module knows about leap years, etc so can account for those in durations. Try
the above code with 29th Feb 2023, for example

This all assumes that a datetime can be constructed from user input easily. Often we
need to parse a string to create a datetime object. For example out data might be a
CSV with dates listed as:

.. code-block:: bash

    1984-1-0, 4
    1984-1-1, 5
    1984-1-2, 5

Here the date is represented by the year, month, day and then hour seperated by a hyphen.
There is no minute or second data.

We can use the ``make_datetime`` (or ``make_date``) method to parse these
when in different columns

.. code-block:: R

    year = c(2013, 2013, 2013)
    month = c(1, 2, 3)
    day = c(31, 28, 31)
    hour = c(1, 3, 2)

    make_datetime(year, month, day, hour)

We can use string parsing to pull apart the first column to separate columns of year, month, day.

Within ``tidyverse`` we can use the filter operator to do this over a whole dataframe.
We can use the NYC filght data from ``tidyverse`` to try this (you may need to install this).

.. code-block:: R

    library(nycflights13)
    head(flights)
    flights %>% 
        select(year, month, day, hour, minute)
    flights %>% 
        select(year, month, day, hour, minute) %>% 
        mutate(departure = make_datetime(year, month, day, hour, minute))

Note there is now a ``<dttm>`` column that is a datetime object.

You can switch between dates and times using the ``as_date()`` and ``as_datetime()`` functions:

.. code-block:: R

    as_datetime(today())
    [1] "2024-03-07 UTC"
    as_date(now())
    [1] "2024-03-07"

The final bit of the datetime we need to know about are timezones. The UK has two timezones, GMT and BST
which occur in the winter and summer respectively. There is a Universal Time zone (UTC) which is 
effectively GMT (but doesn't shift in the UK summer!). The datetime object can handle
timezones and can convert times for you (and takes care of duration over different timezones!).

Some timezone functions:

.. code-block::

    # the system timezone
    Sys.timezone()
    [1] "Europe/London"

    # gives the top 6 timezone names
    head(OlsonNames())
    [1] "Africa/Abidjan"     "Africa/Accra"       "Africa/Addis_Ababa"
    [4] "Africa/Algiers"     "Africa/Asmara"      "Africa/Asmera" 

    x1 <- ymd_hms("2015-06-01 12:00:00", tz = "America/New_York")
    x2 <- ymd_hms("2015-06-01 18:00:00", tz = "Europe/Copenhagen")
    x1-x2

Unless specified, lubridate will use UTC. 

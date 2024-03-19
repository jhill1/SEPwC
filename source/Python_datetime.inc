Python: Datetimes
----------------------
.. index::
  single: Datetimes; Python

Dates and time are a common aspect of environmental data. We often need to 
crop date/times to a specific range and compare or take samples from our
data every *N* minutes, for example. Python comes with a datetime module
that helps us deal with these issues. It provides a variety of functions
to work out duration, samples and deal with leap years and timezones.

.. code-block:: Python

    import datetime

    now = datetime.datetime.now()

    print(now)

This prints the current date and time based on your computers clock:

.. code-block:: bash

    2024-02-15 09:07:34.636548

However, this has hidden a few things. Instead of placing the ``now()`` output
into a variable, print it directly using the console Python

.. code-block:: python

    In [1]: import datetime

    In [2]: datetime.datetime.now()
    Out[2]: datetime.datetime(2024, 2, 15, 9, 7, 26, 165519)

What ``now()`` gives us is a datetime object, which contains the year, month, day, 
hour, minutes, seconds, and part-seconds. We can access these directly if we need to. 
The ``print`` function actually creates a prettified string for the user.

The datetime class allows us to create an arbitrary date, time or datetime, rather than relying
on ``now()``:

.. code-block:: python

    import datetime

    # year, month, date
    d = datetime.date(2022, 12, 25)
    print(d)
    # hours, minutes, second
    t = datetime.time(11, 34, 56)
    print(t)

    # or more explicitly:
    t = datetime.time(hour=11, minute=34, second=56)

    dt = datetime.datetime(2022,12,25,11,34,56)
    print(dt)

    # note the datetime.datetime as combine is a function on the datetime class
    # not the the datetime module

    dt2 = datetime.datetime.combine(d, t)


Representing dates and times as these object then allows calculations to be carried
out, for example, creating a duration:

.. code-block:: python

    import datetime

    date1 = datetime.date(2024, 2, 28)
    date2 = datetime.date(2023, 2, 28)

    print(date1 - date2)
    diff = date1-date2
    print(diff.total_second())


    # what about leap years?
    date1 = datetime.date(2024, 2, 29)
    date2 = datetime.date(2023, 2, 28)

    print(date1 - date2)

The datetime module knows about leap years, etc so can account for those in durations. Try
the above code with 29th Feb 2023, for example

This all assumes that the datetime can be constructed from user input easily. Often we
need to parse a string to create a datetime object. For example out data might be a
CSV with dates listed as:

.. code-block:: bash

    1984-1-1, 4
    1984-1-1, 5
    1984-1-1, 5

Here the date is represented by the year, month, day and then hour seperated by a hyphen.
There is no minute or second data.
We can use datetime's ``strptime()`` method to parse these strings:

.. code-block:: python

    import datetime

    date_string = "1984-1-1-0"
    date_object = datetime.datetime.strptime(date_string, "%Y-%m-%d-%H")
    print(date_object)

There is also a function to print a datetime object into a specific format:

.. code-block:: python

    import datetime

    now = datetime.now()

    t = now.strftime("%H:%M:%S")
    print("Time:", t)

You can see the various formatting options `here <https://docs.python.org/3/library/datetime.html#strftime-strptime-behavior>`_. 

The final bit of the datetime we need to know about are timezones. The UK has two timezones, GMT and BST
which occur in the winter and summer respectively. There is a Universal Time zone (UTC) which is 
effectively GMT (but doesn't shift in the UK summer!). The datetime object can handle
timezones and can convert times for you (and takes care of duration over different timezones!).
However, we need another python module ``pytz`` to handle the actual timezones.

.. code-block:: python

    # note I've only import the datetime object, not the whole datetime module
    from datetime import datetime
    import pytz

    local = datetime.now()
    print("Local:", local.strftime("%m/%d/%Y, %H:%M:%S"))


    tz_NY = pytz.timezone('America/New_York') 
    datetime_NY = datetime.now(tz_NY)
    print("NY:", datetime_NY.strftime("%m/%d/%Y, %H:%M:%S"))

    tz_London = pytz.timezone('Europe/London')
    datetime_London = datetime.now(tz_London)
    print("London:", datetime_London.strftime("%m/%d/%Y, %H:%M:%S"))


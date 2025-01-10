Python: Pandas module
----------------------
.. index::
  pair: pandas; python

pandas is a Python package providing fast, flexible, and expressive data structures 
designed to make working with “relational” or “labelled” data both easy and intuitive.
It aims to be the fundamental high-level building block for doing practical, 
real-world data analysis in Python.

pandas is well suited for many different kinds of data:

 - Tabular data with heterogeneously-typed columns, as in an SQL table or Excel spreadsheet
 - Ordered and unordered (not necessarily fixed-frequency) time series data.
 - Arbitrary matrix data (homogeneously typed or heterogeneous) with row and column labels
 - Any other form of observational / statistical data sets. The data need not be labeled at all to be placed into a pandas data structure.

Basically, if you are handling data, pandas is useful!

We normally import as follows:

.. code-block:: python
   :caption: |python|

   import numpy as np
   import pandas as pd

Basic data structures in pandas
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
.. index::
  pair: pandas; structures

pandas provides two types of classes for handling data:

1. :class:`Series`: a one-dimensional labeled array holding data of any type
    such as integers, strings, Python objects etc.
2. :class:`DataFrame`: a two-dimensional data structure that holds data like
   a two-dimension array or a table with rows and columns.

Object creation
~~~~~~~~~~~~~~~~
.. index::
  pair: Pandas; Object Creation

Creating a :class:`Series` by passing a list of values, letting pandas create
a default :class:`RangeIndex`.

.. code-block:: python
   :caption: |python|

   s = pd.Series([1, 3, 5, np.nan, 6, 8])
   s

Creating a :class:`DataFrame` by passing a NumPy array with a datetime index using :func:`date_range`
and labelled columns:

.. code-block:: python
   :caption: |python|

   dates = pd.date_range("20130101", periods=6)
   dates
   df = pd.DataFrame(np.random.randn(6, 4), index=dates, columns=list("ABCD"))
   df

Creating a :class:`DataFrame` by passing a dictionary of objects where the keys are the column
labels and the values are the column values.

.. code-block:: python
   :caption: |python|

   df2 = pd.DataFrame(
       {
           "A": 1.0,
           "B": pd.Timestamp("20130102"),
           "C": pd.Series(1, index=list(range(4)), dtype="float32"),
           "D": np.array([3] * 4, dtype="int32"),
           "E": pd.Categorical(["test", "train", "test", "train"]),
           "F": "foo",
       }
   )
   df2

The columns of the resulting :class:`DataFrame` have different
datatypes:

.. code-block:: python
   :caption: |python|

   df2.dtypes

If you're using IPython, tab completion for column names (as well as public
attributes) is automatically enabled. Here's a subset of the attributes that
will be completed:

.. code-block:: ipython
   :caption: |cli| |python|

   In [1]: df2.<TAB>  # noqa: E225, E999
   df2.A                  df2.bool
   df2.abs                df2.boxplot
   df2.add                df2.C
   df2.add_prefix         df2.clip
   df2.add_suffix         df2.columns
   df2.align              df2.copy
   df2.all                df2.count
   df2.any                df2.combine
   df2.append             df2.D
   df2.apply              df2.describe
   df2.B                  df2.duplicated
   df2.diff

As you can see, the columns ``A``, ``B``, ``C``, and ``D`` are automatically
tab completed. ``E`` and ``F`` are there as well; the rest of the attributes have been
truncated for brevity.

Viewing data
~~~~~~~~~~~~~~
.. index::
  pair: pandas; viewing

Use :meth:`DataFrame.head` and :meth:`DataFrame.tail` to view the top and bottom rows of the frame
respectively:

.. code-block:: python
   :caption: |python|

   df.head()
   df.tail(3)

Display the :attr:`DataFrame.index` or :attr:`DataFrame.columns`:

.. code-block:: python
   :caption: |python|

   df.index
   df.columns

Return a NumPy representation of the underlying data with :meth:`DataFrame.to_numpy`
without the index or column labels:

.. code-block:: python
   :caption: |python|

   df.to_numpy()

.. note::

   **NumPy arrays have one dtype for the entire array while pandas DataFrames
   have one dtype per column**. When you call :meth:`DataFrame.to_numpy`, pandas will
   find the NumPy dtype that can hold *all* of the dtypes in the DataFrame.
   If the common data type is ``object``, :meth:`DataFrame.to_numpy` will require
   copying data.

   .. code-block:: python
      :caption: |python|

      df2.dtypes
      df2.to_numpy()

:func:`~DataFrame.describe` shows a quick statistic summary of your data:

.. code-block:: python
   :caption: |python|

   df.describe()

Transposing your data:

.. index::
  pair: pandas; transpose

.. code-block:: python
   :caption: |python|

   df.T

:meth:`DataFrame.sort_index` sorts by an axis:

.. code-block:: python
   :caption: |python|

   df.sort_index(axis=1, ascending=False)

:meth:`DataFrame.sort_values` sorts by values:

.. code-block:: python
   :caption: |python|

   df.sort_values(by="B")

Selection
~~~~~~~~~~
.. index::
  pair: pandas; selection

.. note::

   While standard Python / NumPy expressions for selecting and setting are
   intuitive and come in handy for interactive work, for production code, we
   recommend the optimised pandas data access methods, :meth:`DataFrame.at`, :meth:`DataFrame.iat`,
   :meth:`DataFrame.loc` and :meth:`DataFrame.iloc`.


Getitem (``[]``)
...................

For a :class:`DataFrame`, passing a single label selects a columns and
yields a :class:`Series` equivalent to ``df.A``:

.. code-block:: python
   :caption: |python|

   df["A"]

For a :class:`DataFrame`, passing a slice ``:`` selects matching rows:

.. code-block:: python
   :caption: |python|

   df[0:3]
   df["20130102":"20130104"]

Selection by label
...................

Selecting a row matching a label:

.. code-block:: python
   :caption: |python|

   df.loc[dates[0]]

Selecting all rows (``:``) with a select column labels:

.. code-block:: python
   :caption: |python|

   df.loc[:, ["A", "B"]]

For label slicing, both endpoints are *included*:

.. code-block:: python
   :caption: |python|

   df.loc["20130102":"20130104", ["A", "B"]]

Selecting a single row and column label returns a scalar:

.. code-block:: python
   :caption: |python|

   df.loc[dates[0], "A"]

For getting fast access to a scalar (equivalent to the prior method):

.. code-block:: python
   :caption: |python|

   df.at[dates[0], "A"]

Selection by position
.......................

Select via the position of the passed integers:

.. code-block:: python
   :caption: |python|

   df.iloc[3]

Integer slices acts similar to NumPy/Python:

.. code-block:: python
   :caption: |python|

   df.iloc[3:5, 0:2]

Lists of integer position locations:

.. code-block:: python
   :caption: |python|

   df.iloc[[1, 2, 4], [0, 2]]

For slicing rows explicitly:

.. code-block:: python
   :caption: |python|

   df.iloc[1:3, :]

For slicing columns explicitly:

.. code-block:: python
   :caption: |python|

   df.iloc[:, 1:3]

For getting a value explicitly:

.. code-block:: python
   :caption: |python|

   df.iloc[1, 1]

For getting fast access to a scalar (equivalent to the prior method):

.. code-block:: python
   :caption: |python|

   df.iat[1, 1]

Boolean indexing
.................
.. index::
  pair: pandas; index

Select rows where ``df.A`` is greater than ``0``.

.. code-block:: python
   :caption: |python|

   df[df["A"] > 0]

Selecting values from a :class:`DataFrame` where a boolean condition is met:

.. code-block:: python
   :caption: |python|

   df[df > 0]

Using :func:`~Series.isin` method for filtering:

.. code-block:: python
   :caption: |python|

   df2 = df.copy()
   df2["E"] = ["one", "one", "two", "three", "four", "three"]
   df2
   df2[df2["E"].isin(["two", "four"])]

Setting
...........

Setting a new column automatically aligns the data by the indexes:

.. code-block:: python
   :caption: |python|

   s1 = pd.Series([1, 2, 3, 4, 5, 6], index=pd.date_range("20130102", periods=6))
   s1
   df["F"] = s1

Setting values by label:

.. code-block:: python
   :caption: |python|

   df.at[dates[0], "A"] = 0

Setting values by position:

.. code-block:: python
   :caption: |python|

   df.iat[0, 1] = 0

Setting by assigning with a NumPy array:

.. code-block:: python
   :caption: |python|

   df.loc[:, "D"] = np.array([5] * len(df))

The result of the prior setting operations:

.. code-block:: python
   :caption: |python|

   df

A ``where`` operation with setting:

.. code-block:: python
   :caption: |python|

   df2 = df.copy()
   df2[df2 > 0] = -df2
   df2


Missing data
.............

For NumPy data types, ``np.nan`` represents missing data. It is by
default not included in computations. 

Reindexing allows you to change/add/delete the index on a specified axis. This
returns a copy of the data:

.. code-block:: python
   :caption: |python|

   df1 = df.reindex(index=dates[0:4], columns=list(df.columns) + ["E"])
   df1.loc[dates[0] : dates[1], "E"] = 1
   df1

:meth:`DataFrame.dropna` drops any rows that have missing data:

.. code-block:: python
   :caption: |python|

   df1.dropna(how="any")

:meth:`DataFrame.fillna` fills missing data:

.. code-block:: python
   :caption: |python|

   df1.fillna(value=5)

:func:`isna` gets the boolean mask where values are ``nan``:

.. code-block:: python
   :caption: |python|

   pd.isna(df1)


panda Operations
~~~~~~~~~~~~~~~~~
.. index::
  pair: pandas; operations

Stats
.......

Operations in general *exclude* missing data.

Calculate the mean value for each column:

.. code-block:: python
   :caption: |python|

   df.mean()

Calculate the mean value for each row:

.. code-block:: python
   :caption: |python|

   df.mean(axis=1)

Operating with another :class:`Series` or :class:`DataFrame` with a different index or column
will align the result with the union of the index or column labels. In addition, pandas
automatically broadcasts along the specified dimension and will fill unaligned labels with ``np.nan``.

.. code-block:: python
   :caption: |python|

   s = pd.Series([1, 3, 5, np.nan, 6, 8], index=dates).shift(2)
   s
   df.sub(s, axis="index")


User defined functions
.......................
.. index::
  pair: pandas; functions

:meth:`DataFrame.agg` and :meth:`DataFrame.transform` applies a user defined function
that reduces or broadcasts its result respectively.

.. code-block:: python
   :caption: |python|

   df.agg(lambda x: np.mean(x) * 5.6)
   df.transform(lambda x: x * 101.2)

Value Counts
.............

.. code-block:: python
   :caption: |python|

   s = pd.Series(np.random.randint(0, 7, size=10))
   s
   s.value_counts()

String Methods
...............

:class:`Series` is equipped with a set of string processing methods in the ``str``
attribute that make it easy to operate on each element of the array, as in the
code snippet below. 

.. code-block:: python
   :caption: |python|

   s = pd.Series(["A", "B", "C", "Aaba", "Baca", np.nan, "CABA", "dog", "cat"])
   s.str.lower()

Merge
~~~~~~~~
.. index::
  pair: pandas; merge

Concat
.........
.. index::
  pair: pandas; concatenation

pandas provides various facilities for easily combining together :class:`Series` and
:class:`DataFrame` objects with various kinds of set logic for the indexes
and relational algebra functionality in the case of join / merge-type
operations.

Concatenating pandas objects together row-wise with :func:`concat`:

.. code-block:: python
   :caption: |python|

   df = pd.DataFrame(np.random.randn(10, 4))
   df

   # break it into pieces
   pieces = [df[:3], df[3:7], df[7:]]

   pd.concat(pieces)

.. note::

   Adding a column to a :class:`DataFrame` is relatively fast. However, adding
   a row requires a copy, and may be expensive. We recommend passing a
   pre-built list of records to the :class:`DataFrame` constructor instead
   of building a :class:`DataFrame` by iteratively appending records to it.

Join
......
.. index::
  pair: pandas; join

:func:`merge` enables SQL style join types along specific columns.

.. code-block:: python
   :caption: |python|

   left = pd.DataFrame({"key": ["foo", "foo"], "lval": [1, 2]})
   right = pd.DataFrame({"key": ["foo", "foo"], "rval": [4, 5]})
   left
   right
   pd.merge(left, right, on="key")

:func:`merge` on unique keys:

.. code-block:: python
   :caption: |python|

   left = pd.DataFrame({"key": ["foo", "bar"], "lval": [1, 2]})
   right = pd.DataFrame({"key": ["foo", "bar"], "rval": [4, 5]})
   left
   right
   pd.merge(left, right, on="key")

Grouping
...........
.. index::
  pair: pandas; grouping

By "group by" we are referring to a process involving one or more of the
following steps:

* **Splitting** the data into groups based on some criteria
* **Applying** a function to each group independently
* **Combining** the results into a data structure

.. code-block:: python
   :caption: |python|

   df = pd.DataFrame(
       {
           "A": ["foo", "bar", "foo", "bar", "foo", "bar", "foo", "foo"],
           "B": ["one", "one", "two", "three", "two", "two", "one", "three"],
           "C": np.random.randn(8),
           "D": np.random.randn(8),
       }
   )
   df

Grouping by a column label, selecting column labels, and then applying the
:meth:`.DataFrameGroupBy.sum` function to the resulting
groups:

.. code-block:: python
   :caption: |python|

   df.groupby("A")[["C", "D"]].sum()

Grouping by multiple columns label forms :class:`MultiIndex`.

.. code-block:: python
   :caption: |python|

   df.groupby(["A", "B"]).sum()

Reshaping
~~~~~~~~~~~
.. index::
  pair: pandas; reshape

Stack
.........
.. index::
  pair: pandas; stack

.. code-block:: python
   :caption: |python|

   arrays = [
      ["bar", "bar", "baz", "baz", "foo", "foo", "qux", "qux"],
      ["one", "two", "one", "two", "one", "two", "one", "two"],
   ]
   index = pd.MultiIndex.from_arrays(arrays, names=["first", "second"])
   df = pd.DataFrame(np.random.randn(8, 2), index=index, columns=["A", "B"])
   df2 = df[:4]
   df2

The :meth:`~DataFrame.stack` method "compresses" a level in the DataFrame's
columns:

.. code-block:: python
   :caption: |python|

   stacked = df2.stack()
   stacked

With a "stacked" DataFrame or Series (having a :class:`MultiIndex` as the
``index``), the inverse operation of :meth:`~DataFrame.stack` is
:meth:`~DataFrame.unstack`, which by default unstacks the **last level**:

.. code-block:: python
   :caption: |python|

   stacked.unstack()
   stacked.unstack(1)
   stacked.unstack(0)

Pivot tables
.............
.. index::
  pair: pandas; pivot

.. code-block:: python
   :caption: |python|

   df = pd.DataFrame(
       {
           "A": ["one", "one", "two", "three"] * 3,
           "B": ["A", "B", "C"] * 4,
           "C": ["foo", "foo", "foo", "bar", "bar", "bar"] * 2,
           "D": np.random.randn(12),
           "E": np.random.randn(12),
       }
   )
   df

:func:`pivot_table` pivots a :class:`DataFrame` specifying the ``values``, ``index`` and ``columns``

.. code-block:: python
   :caption: |python|

   pd.pivot_table(df, values="D", index=["A", "B"], columns=["C"])


Time series
~~~~~~~~~~~~
.. index::
  pair: pandas; time

pandas has simple, powerful, and efficient functionality for performing
resampling operations during frequency conversion (e.g., converting secondly
data into 5-minute splices of data). This is extremely common in, but not limited to,
financial applications.

.. code-block:: python
   :caption: |python|

   rng = pd.date_range("1/1/2012", periods=100, freq="s")
   ts = pd.Series(np.random.randint(0, 500, len(rng)), index=rng)
   ts.resample("5Min").sum()

:meth:`Series.tz_localize` localizes a time series to a time zone:

.. code-block:: python
   :caption: |python|

   rng = pd.date_range("3/6/2012 00:00", periods=5, freq="D")
   ts = pd.Series(np.random.randn(len(rng)), rng)
   ts
   ts_utc = ts.tz_localize("UTC")
   ts_utc

:meth:`Series.tz_convert` converts a timezones aware time series to another time zone:

.. code-block:: python
   :caption: |python|

   ts_utc.tz_convert("US/Eastern")

Adding a non-fixed duration (:class:`~pandas.tseries.offsets.BusinessDay`) to a time series:

.. code-block:: python
   :caption: |python|

   rng
   rng + pd.offsets.BusinessDay(5)

Categoricals
~~~~~~~~~~~~~~

pandas can include categorical data in a :class:`DataFrame`.


.. code-block:: python
    :caption: |python|

    df = pd.DataFrame(
        {"id": [1, 2, 3, 4, 5, 6], "raw_grade": ["a", "b", "b", "a", "a", "e"]}
    )

Converting the raw grades to a categorical data type:

.. code-block:: python
   :caption: |python|

   df["grade"] = df["raw_grade"].astype("category")
   df["grade"]

Rename the categories to more meaningful names:

.. code-block:: python
    :caption: |python|

    new_categories = ["very good", "good", "very bad"]
    df["grade"] = df["grade"].cat.rename_categories(new_categories)

Reorder the categories and simultaneously add the missing categories (methods under :meth:`Series.cat` return a new :class:`Series` by default):

.. code-block:: python
    :caption: |python|

    df["grade"] = df["grade"].cat.set_categories(
        ["very bad", "bad", "medium", "good", "very good"]
    )
    df["grade"]

Sorting is per order in the categories, not lexical order:

.. code-block:: python
    :caption: |python|

    df.sort_values(by="grade")

Grouping by a categorical column with ``observed=False`` also shows empty categories:

.. code-block:: python
    :caption: |python|

    df.groupby("grade", observed=False).size()




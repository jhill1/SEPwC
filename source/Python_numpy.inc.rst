Python: Numpy
----------------------
.. index::
   single: Numpy; Python

NumPy (**Num**\ erical **Py**\ thon) is an open source Python library that is
widely used in science and engineering. The NumPy library contains
multidimensional array data structures, such as the homogeneous, N-dimensional
``ndarray``, and a large library of functions that operate efficiently on these
data structures. 

Python lists are general purpose containers. They can be
"heterogeneous", meaning that they can contain elements of a variety of datatypes.

However, scientific data is often numerical and hence `homogeneous`. 
NumPy is designed to work on such data, rather than be more general.

Most NumPy arrays have some restrictions. For instance:

- All elements of the array must be of the same type of data.
- Once created, the total size of the the array can't change.
- The shape must be "rectangular", not "jagged"; e.g., each row of
  a two-dimensional array must have the same number of columns.

When these conditions are met, NumPy exploits these characteristics to
make the array faster, more memory efficient, and more convenient to use than
less restrictive data structures.

For the remainder of this document, we will use the word "array" to refer to
an instance of ``ndarray``.

How to import NumPy
~~~~~~~~~~~~~~~~~~~

Numpy is generally imported into Python code like this:

.. code-block:: python

    import numpy as np

This widespread convention allows access to NumPy features with a short,
recognisable prefix (``np.``) while distinguishing NumPy features from others
that have the same name (e.g. ``max()``)


NumPy array fundamentals
~~~~~~~~~~~~~~~~~~~~~~~~~

One way to initialize an array is using a Python sequence, such as a list.
For example:

.. code-block:: python

    >>> a = np.array([1, 2, 3, 4, 5, 6])
    >>> a
    array([1, 2, 3, 4, 5, 6])

Elements of an array can be accessed in various ways. We can access an
individual element of this array as we would access an element in the original
list: using the integer index of the element within square brackets.

.. code-block:: python
    
    >>> a[0]
    1

Like the original list, the array is mutable.

.. code-block:: python

    >>> a[0] = 10
    >>> a
    array([10,  2,  3,  4,  5,  6])

Also like the original list, Python slice notation can be used for indexing.

.. code-block:: python

    >>> a[:3]
    array([10, 2, 3])

One major difference is that slice indexing of a list copies the elements into
a new list, but slicing a NumPy array returns a *view*: an object that refers to the
data in the original array. The original array can be mutated using the view.

.. code-block:: python

    >>> b = a[3:]
    >>> b
    array([4, 5, 6])
    >>> b[0] = 40
    >>> a
    array([ 10,  2,  3, 40,  5,  6])
    >>> c = [1,2,3,4,5,6]
    >>> d = c[3:]
    >>> d[0] = 50
    >>> c
    >>> d

Two- and higher-dimensional arrays can be initialised from nested Python
sequences::

.. code-block:: python

    >>> a = np.array([[1, 2, 3, 4], [5, 6, 7, 8], [9, 10, 11, 12]])
    >>> a
    array([[ 1,  2,  3,  4],
           [ 5,  6,  7,  8],
           [ 9, 10, 11, 12]])

In NumPy, a dimension of an array is sometimes referred to as an "axis". This
terminology may be useful to disambiguate between the dimensionality of an
array and the dimensionality of the data represented by the array. For
instance, the array ``a`` could represent three points, each lying within a
four-dimensional space, but ``a`` has only two "axes".

Another difference between an array and a list of lists is that an
element of the array can be accessed by specifying the index along each
axis within a *single* set of square brackets, separated by commas.
For instance, the element ``8`` is in row ``1`` and column ``3``:

.. code-block:: python

    >>> a[1, 3]
    8

If we used Python lists we would use ``a[1][3]``

.. note::

    It is familiar practice in maths to refer to elements of a matrix
    by the row index first and the column index second. This happens to be true
    for two-dimensional arrays, but a better mental model is to think of
    the column index as coming *last* and the row index as *second to last*.
    This generalizes to arrays with *any* number of dimensions.

.. note::

    In maths you might hear of a 0-D (zero-dimensional) array referred to as a "scalar",
    a 1-D (one-dimensional) array as a "vector", a 2-D (two-dimensional) array
    as a "matrix", or an N-D (N-dimensional, where "N" is typically an integer
    greater than 2) array as a "tensor". For clarity, it is best to avoid the
    mathematical terms when referring to an array because the mathematical
    objects with these names behave differently than arrays (e.g. "matrix"
    multiplication is fundamentally different from "array" multiplication), and
    there are other objects in the scientific Python ecosystem that have these
    names (e.g. the fundamental data structure of PyTorch is the "tensor").
    However, you will find these terms in codes that are mathematical in 
    nature and use NumPy!


Numpy array attributes
~~~~~~~~~~~~~~~~~~~~~~~
.. index::
   pair: Array; Attributes; Python

The number of dimensions of an array is contained in the ``ndim`` attribute.

.. code-block:: python

    >>> a.ndim
    2

The shape of an array is a tuple of non-negative integers that specify the
number of elements along each dimension.

.. code-block:: python

    >>> a.shape
    (3, 4)
    >>> len(a.shape) == a.ndim
    True

The fixed, total number of elements in array is contained in the ``size``
attribute.

.. code-block:: python

    >>> a.size
    12
    >>> import math
    >>> a.size == math.prod(a.shape)
    True

Arrays are typically "homogeneous", meaning that they contain elements of
only one "data type". The data type is recorded in the ``dtype`` attribute.

.. code-block:: python

    >>> a.dtype
    dtype('int64')  # "int" for integer, "64" for 64-bit


How to create a basic array
~~~~~~~~~~~~~~~~~~~~~~~~~~~
.. index::
  single: Arrays; Python

Besides creating an array from a sequence of elements, you can easily create an
array filled with ``0``'s::

.. code-block:: python

  >>> np.zeros(2)
  array([0., 0.])

Or an array filled with ``1``'s::

.. code-block:: python

  >>> np.ones(2)
  array([1., 1.])

Or even an empty array! The function ``empty`` creates an array whose initial
content is random and depends on the state of the memory. The reason to use
``empty`` over ``zeros`` (or something similar) is speed - just make sure to
fill every element afterwards! ::

.. code-block:: python

  >>> # Create an empty array with 2 elements
  >>> np.empty(2) #doctest: +SKIP
  array([3.14, 42.  ])  # may vary

You can create an array with a range of elements::

.. code-block:: python

  >>> np.arange(4)
  array([0, 1, 2, 3])

And even an array that contains a range of evenly spaced intervals. To do this,
you will specify the **first number**, **last number**, and the **step size**.

.. code-block:: python

  >>> np.arange(2, 9, 2)
  array([2, 4, 6, 8])

You can also use ``np.linspace()`` to create an array with values that are
spaced linearly in a specified interval:

.. code-block:: python

  >>> np.linspace(0, 10, num=5)
  array([ 0. ,  2.5,  5. ,  7.5, 10. ])

**Specifying your data type**

While the default data type is floating point (``np.float64``), you can explicitly
specify which data type you want using the ``dtype`` keyword.

.. code-block:: python

  >>> x = np.ones(2, dtype=np.int64)
  >>> x
  array([1, 1])


Adding, removing, and sorting elements
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
.. index::
  pair: Array; Elements; Python

Sorting an element is simple with ``np.sort()``. You can specify the axis, kind,
and order when you call the function.

If you start with this array:

.. code-block:: python

  >>> arr = np.array([2, 1, 5, 3, 7, 4, 6, 8])

You can quickly sort the numbers in ascending order with:

.. code-block:: python

  >>> np.sort(arr)
  array([1, 2, 3, 4, 5, 6, 7, 8])

In addition to sort, which returns a sorted copy of an array, you can use:

- `argsort`, which is an indirect sort along a specified axis,
- `lexsort`, which is an indirect stable sort on multiple keys,
- `searchsorted`, which will find elements in a sorted array, and
- `partition`, which is a partial sort.

To read more about sorting an array, see: `sort`.

If you start with these arrays:

.. code-block:: python

  >>> a = np.array([1, 2, 3, 4])
  >>> b = np.array([5, 6, 7, 8])

You can concatenate them with ``np.concatenate()``.

.. code-block:: python

  >>> np.concatenate((a, b))
  array([1, 2, 3, 4, 5, 6, 7, 8])

Or, if you start with these arrays:

.. code-block:: python

  >>> x = np.array([[1, 2], [3, 4]])
  >>> y = np.array([[5, 6]])

You can concatenate them with:

.. code-block:: python

  >>> np.concatenate((x, y), axis=0)
  array([[1, 2],
         [3, 4],
         [5, 6]])

In order to remove elements from an array, it's simple to use indexing to select
the elements that you want to keep.

To read more about concatenate, see: `concatenate`.


How do you know the shape and size of an array?
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
.. index::
  pair: Array; Shape; Python
.. index::
  pair: Array; Size; Python

``ndarray.ndim`` will tell you the number of axes, or dimensions, of the array.

``ndarray.size`` will tell you the total number of elements of the array. This
is the *product* of the elements of the array's shape.

``ndarray.shape`` will display a tuple of integers that indicate the number of
elements stored along each dimension of the array. If, for example, you have a
2-D array with 2 rows and 3 columns, the shape of your array is ``(2, 3)``.

For example, if you create this array:

.. code-block:: python

  >>> array_example = np.array([[[0, 1, 2, 3],
  ...                            [4, 5, 6, 7]],
  ...
  ...                           [[0, 1, 2, 3],
  ...                            [4, 5, 6, 7]],
  ...
  ...                           [[0 ,1 ,2, 3],
  ...                            [4, 5, 6, 7]]])

To find the number of dimensions of the array, run:

.. code-block:: python

  >>> array_example.ndim
  3

To find the total number of elements in the array, run:

.. code-block:: python

  >>> array_example.size
  24

And to find the shape of your array, run:

.. code-block:: python

  >>> array_example.shape
  (3, 2, 4)


Can you reshape an array?
~~~~~~~~~~~~~~~~~~~~~~~~~
.. index::
   pair: Array; Reshape; Python

**Yes!**

Using ``arr.reshape()`` will give a new shape to an array without changing the
data. Just remember that when you use the reshape method, the array you want to
produce needs to have the same number of elements as the original array. If you
start with an array with 12 elements, you'll need to make sure that your new
array also has a total of 12 elements.

If you start with this array:

.. code-block:: python

  >>> a = np.arange(6)
  >>> print(a)
  [0 1 2 3 4 5]

You can use ``reshape()`` to reshape your array. For example, you can reshape
this array to an array with three rows and two columns:

.. code-block:: python

  >>> b = a.reshape(3, 2)
  >>> print(b)
  [[0 1]
   [2 3]
   [4 5]]

With ``np.reshape``, you can specify a few optional parameters:

.. code-block:: python

  >>> np.reshape(a, newshape=(1, 6), order='C')
  array([[0, 1, 2, 3, 4, 5]])

``a`` is the array to be reshaped.

``newshape`` is the new shape you want. You can specify an integer or a tuple of
integers. If you specify an integer, the result will be an array of that length.
The shape should be compatible with the original shape.

``order:`` ``C`` means to read/write the elements using C-like index order,
``F`` means to read/write the elements using Fortran-like index order, ``A``
means to read/write the elements in Fortran-like index order if a is Fortran
contiguous in memory, C-like order otherwise. (This is an optional parameter and
doesn't need to be specified.)

C and Fortran orders have to do with how indices correspond
to the order the array is stored in memory. In Fortran, when moving through
the elements of a two-dimensional array as it is stored in memory, the **first**
index is the most rapidly varying index. As the first index moves to the next
row as it changes, the matrix is stored one column at a time.
This is why Fortran is thought of as a **Column-major language**.
In C on the other hand, the **last** index changes
the most rapidly. The matrix is stored by rows, making it a **Row-major
language**. What you do for C or Fortran depends on whether it's more important
to preserve the indexing convention or not reorder the data.


How to convert a 1D array into a 2D array (how to add a new axis to an array)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
.. index::
  pair: Array; Axis; Python

You can use ``np.newaxis`` and ``np.expand_dims`` to increase the dimensions of
your existing array.

Using ``np.newaxis`` will increase the dimensions of your array by one dimension
when used once. This means that a **1D** array will become a **2D** array, a
**2D** array will become a **3D** array, and so on.

For example, if you start with this array:

.. code-block:: python

  >>> a = np.array([1, 2, 3, 4, 5, 6])
  >>> a.shape
  (6,)

You can use ``np.newaxis`` to add a new axis:

.. code-block:: python

  >>> a2 = a[np.newaxis, :]
  >>> a2.shape
  (1, 6)

You can explicitly convert a 1D array to either a row vector or a column
vector using ``np.newaxis``. For example, you can convert a 1D array to a row
vector by inserting an axis along the first dimension:

.. code-block:: python

  >>> row_vector = a[np.newaxis, :]
  >>> row_vector.shape
  (1, 6)

Or, for a column vector, you can insert an axis along the second dimension:

.. code-block:: python

  >>> col_vector = a[:, np.newaxis]
  >>> col_vector.shape
  (6, 1)

You can also expand an array by inserting a new axis at a specified position
with ``np.expand_dims``.

For example, if you start with this array:

.. code-block:: python

  >>> a = np.array([1, 2, 3, 4, 5, 6])
  >>> a.shape
  (6,)

You can use ``np.expand_dims`` to add an axis at index position 1 with:

.. code-block:: python

  >>> b = np.expand_dims(a, axis=1)
  >>> b.shape
  (6, 1)

You can add an axis at index position 0 with:

.. code-block:: python

  >>> c = np.expand_dims(a, axis=0)
  >>> c.shape
  (1, 6)


Indexing and slicing
~~~~~~~~~~~~~~~~~~~~~
.. index::
  pair: Array; Indexing; Python

You can index and slice NumPy arrays in the same ways you can slice Python
lists.

.. code-block:: python

  >>> data = np.array([1, 2, 3])

  >>> data[1]
  2
  >>> data[0:2]
  array([1, 2])
  >>> data[1:]
  array([2, 3])
  >>> data[-2:]
  array([2, 3])

You can visualize it this way:

.. image:: ../images/np_indexing.png

.. index::
  pair: Array; Slice; Python

You may want to take a section of your array or specific array elements to use
in further analysis or additional operations. To do that, you'll need to subset,
slice, and/or index your arrays.

If you want to select values from your array that fulfill certain conditions,
it's straightforward with NumPy.

For example, if you start with this array

.. code-block:: python

  >>> a = np.array([[1 , 2, 3, 4], [5, 6, 7, 8], [9, 10, 11, 12]])

You can easily print all of the values in the array that are less than 5.

.. code-block:: python

  >>> print(a[a < 5])
  [1 2 3 4]

You can also select, for example, numbers that are equal to or greater than 5,
and use that condition to index an array.

.. code-block:: python

  >>> five_up = (a >= 5)
  >>> print(a[five_up])
  [ 5  6  7  8  9 10 11 12]

You can select elements that are divisible by 2:

.. code-block:: python

  >>> divisible_by_2 = a[a%2==0]
  >>> print(divisible_by_2)
  [ 2  4  6  8 10 12]

Or you can select elements that satisfy two conditions using the ``&`` and ``|``
operators:

.. code-block:: python

  >>> c = a[(a > 2) & (a < 11)]
  >>> print(c)
  [ 3  4  5  6  7  8  9 10]

You can also make use of the logical operators **&** and **|** in order to
return boolean values that specify whether or not the values in an array fulfill
a certain condition. This can be useful with arrays that contain names or other
categorical values.

.. code-block:: python

  >>> five_up = (a > 5) | (a == 5)
  >>> print(five_up)
  [[False False False False]
   [ True  True  True  True]
   [ True  True  True True]]

You can also use ``np.nonzero()`` to select elements or indices from an array.

Starting with this array:

.. code-block:: python

  >>> a = np.array([[1, 2, 3, 4], [5, 6, 7, 8], [9, 10, 11, 12]])

You can use ``np.nonzero()`` to print the indices of elements that are, for
example, less than 5:

.. code-block:: python

  >>> b = np.nonzero(a < 5)
  >>> print(b)
  (array([0, 0, 0, 0]), array([0, 1, 2, 3]))

In this example, a tuple of arrays was returned: one for each dimension. The
first array represents the row indices where these values are found, and the
second array represents the column indices where the values are found.

If you want to generate a list of coordinates where the elements exist, you can
zip the arrays, iterate over the list of coordinates, and print them. For
example:

.. code-block:: python

  >>> list_of_coordinates= list(zip(b[0], b[1]))

  >>> for coord in list_of_coordinates:
  ...     print(coord)
  (np.int64(0), np.int64(0))
  (np.int64(0), np.int64(1))
  (np.int64(0), np.int64(2))
  (np.int64(0), np.int64(3))


You can also use ``np.nonzero()`` to print the elements in an array that are less
than 5 with:

.. code-block:: python

  >>> print(a[b])
  [1 2 3 4]

If the element you're looking for doesn't exist in the array, then the returned
array of indices will be empty. For example:

.. code-block:: python

  >>> not_there = np.nonzero(a == 42)
  >>> print(not_there)
  (array([], dtype=int64), array([], dtype=int64))


How to create an array from existing data
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
.. index::
  single: Array; Python

You can easily create a new array from a section of an existing array.

Let's say you have this array:

.. code-block:: python

  >>> a = np.array([1,  2,  3,  4,  5,  6,  7,  8,  9, 10])

You can create a new array from a section of your array any time by specifying
where you want to slice your array.

.. code-block:: python

  >>> arr1 = a[3:8]
  >>> arr1
  array([4, 5, 6, 7, 8])

Here, you grabbed a section of your array from index position 3 through index
position 8.

You can also stack two existing arrays, both vertically and horizontally. Let's
say you have two arrays, ``a1`` and ``a2``

.. code-block:: python

  >>> a1 = np.array([[1, 1],
  ...                [2, 2]])

  >>> a2 = np.array([[3, 3],
  ...                [4, 4]])

You can stack them vertically with ``vstack``

.. code-block:: python

  >>> np.vstack((a1, a2))
  array([[1, 1],
         [2, 2],
         [3, 3],
         [4, 4]])

Or stack them horizontally with ``hstack``

.. code-block:: python

  >>> np.hstack((a1, a2))
  array([[1, 1, 3, 3],
         [2, 2, 4, 4]])

You can split an array into several smaller arrays using ``hsplit``. You can
specify either the number of equally shaped arrays to return or the columns
*after* which the division should occur.

Let's say you have this array

.. code-block:: python

  >>> x = np.arange(1, 25).reshape(2, 12)
  >>> x
  array([[ 1,  2,  3,  4,  5,  6,  7,  8,  9, 10, 11, 12],
         [13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24]])

If you wanted to split this array into three equally shaped arrays, you would
run

.. code-block:: python

  >>> np.hsplit(x, 3)
    [array([[ 1,  2,  3,  4],
           [13, 14, 15, 16]]), array([[ 5,  6,  7,  8],
           [17, 18, 19, 20]]), array([[ 9, 10, 11, 12],
           [21, 22, 23, 24]])]

If you wanted to split your array after the third and fourth column, you'd run

.. code-block:: python

  >>> np.hsplit(x, (3, 4))
    [array([[ 1,  2,  3],
           [13, 14, 15]]), array([[ 4],
           [16]]), array([[ 5,  6,  7,  8,  9, 10, 11, 12],
           [17, 18, 19, 20, 21, 22, 23, 24]])]


You can use the ``view`` method to create a new array object that looks at the
same data as the original array (a *shallow copy*).

Views are an important NumPy concept! NumPy functions, as well as operations
like indexing and slicing, will return views whenever possible. This saves
memory and is faster (no copy of the data has to be made). However it's
important to be aware of this - modifying data in a view also modifies the
original array!

Let's say you create this array

.. code-block:: python

  >>> a = np.array([[1, 2, 3, 4], [5, 6, 7, 8], [9, 10, 11, 12]])

Now we create an array ``b1`` by slicing ``a`` and modify the first element of
``b1``. This will modify the corresponding element in ``a`` as well!

.. code-block:: python

  >>> b1 = a[0, :]
  >>> b1
  array([1, 2, 3, 4])
  >>> b1[0] = 99
  >>> b1
  array([99,  2,  3,  4])
  >>> a
  array([[99,  2,  3,  4],
         [ 5,  6,  7,  8],
         [ 9, 10, 11, 12]])

Using the ``copy`` method will make a complete copy of the array and its data (a
*deep copy*). To use this on your array, you could run::

  >>> b2 = a.copy()


Basic array operations
~~~~~~~~~~~~~~~~~~~~~~~
.. index::
  single: iArray Operations; Python

Once you've created your arrays, you can start to work with them.  Let's say,
for example, that you've created two arrays, one called "data" and one called
"ones"

.. image:: ../images/np_array_data_ones.png

You can add the arrays together with the plus sign.

.. code-block:: python

  >>> data = np.array([1, 2])
  >>> ones = np.ones(2, dtype=int)
  >>> data + ones
  array([2, 3])

.. image:: ../images/np_data_plus_ones.png

You can, of course, do more than just addition!

.. code-block:: python

 >>> data - ones
  array([0, 1])
  >>> data * data
  array([1, 4])
  >>> data / data
  array([1., 1.])

.. image:: ../images/np_sub_mult_divide.png

Basic operations are simple with NumPy. If you want to find the sum of the
elements in an array, you'd use ``sum()``. This works for 1D arrays, 2D arrays,
and arrays in higher dimensions.

.. code-block:: python

 >>> a = np.array([1, 2, 3, 4])

  >>> a.sum()
  10

To add the rows or the columns in a 2D array, you would specify the axis.

If you start with this array:

.. code-block:: python

  >>> b = np.array([[1, 1], [2, 2]])

You can sum over the axis of rows with:

.. code-block:: python

  >>> b.sum(axis=0)
  array([3, 3])

You can sum over the axis of columns with:

.. code-block:: python

  >>> b.sum(axis=1)
  array([2, 4])



Transposing and reshaping a matrix
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
.. index::
  pair: Transposing; Matrix; Python

It's common to need to transpose your matrices. NumPy arrays have the property
``T`` that allows you to transpose a matrix.

.. image:: ../images/np_transposing_reshaping.png

You may also need to switch the dimensions of a matrix. This can happen when,
for example, you have a model that expects a certain input shape that is
different from your dataset. This is where the ``reshape`` method can be useful.
You simply need to pass in the new dimensions that you want for the matrix.

.. code-block:: python

  >>> data.reshape(2, 3)
  array([[1, 2, 3],
         [4, 5, 6]])
  >>> data.reshape(3, 2)
  array([[1, 2],
         [3, 4],
         [5, 6]])

.. image:: ../images/np_reshape.png

You can also use ``.transpose()`` to reverse or change the axes of an array
according to the values you specify.

If you start with this array:

.. code-block:: python

  >>> arr = np.arange(6).reshape((2, 3))
  >>> arr
  array([[0, 1, 2],
         [3, 4, 5]])

You can transpose your array with ``arr.transpose()``.

.. code-block:: python

  >>> arr.transpose()
  array([[0, 3],
         [1, 4],
         [2, 5]])

.. index::
   pair: Reshaping; Matrix; Python

You can also use ``arr.T``

.. code-block:: python

    >>> arr.T
    array([[0, 3],
           [1, 4],
           [2, 5]])

To learn more about transposing and reshaping arrays, see `transpose` and
`reshape`.

NumPy's ``np.flip()`` function allows you to flip, or reverse, the contents of
an array along an axis. When using ``np.flip()``, specify the array you would like
to reverse and the axis. If you don't specify the axis, NumPy will reverse the
contents along all of the axes of your input array.

**Reversing a 1D array**

If you begin with a 1D array like this one

.. code-block:: python

  >>> arr = np.array([1, 2, 3, 4, 5, 6, 7, 8])

You can reverse it with

.. code-block:: python

  >>> reversed_arr = np.flip(arr)

If you want to print your reversed array, you can run:

.. code-block:: python

  >>> print('Reversed Array: ', reversed_arr)
  Reversed Array:  [8 7 6 5 4 3 2 1]

**Reversing a 2D array**

A 2D array works much the same way.

If you start with this array:

.. code-block:: python

  >>> arr_2d = np.array([[1, 2, 3, 4], [5, 6, 7, 8], [9, 10, 11, 12]])

You can reverse the content in all of the rows and all of the columns with:

.. code-block:: python

  >>> reversed_arr = np.flip(arr_2d)
  >>> print(reversed_arr)
  [[12 11 10  9]
   [ 8  7  6  5]
   [ 4  3  2  1]]

You can easily reverse only the *rows* with:

.. code-block:: python

  >>> reversed_arr_rows = np.flip(arr_2d, axis=0)
  >>> print(reversed_arr_rows)
  [[ 9 10 11 12]
   [ 5  6  7  8]
   [ 1  2  3  4]]

Or reverse only the *columns* with:

.. code-block:: python

  >>> reversed_arr_columns = np.flip(arr_2d, axis=1)
  >>> print(reversed_arr_columns)
  [[ 4  3  2  1]
   [ 8  7  6  5]
   [12 11 10  9]]

You can also reverse the contents of only one column or row. For example, you
can reverse the contents of the row at index position 1 (the second row):

.. code-block:: python

  >>> arr_2d[1] = np.flip(arr_2d[1])
  >>> print(arr_2d)
  [[ 1  2  3  4]
   [ 8  7  6  5]
   [ 9 10 11 12]]

You can also reverse the column at index position 1 (the second column):

.. code-block:: python

  >>> arr_2d[:,1] = np.flip(arr_2d[:,1])
  >>> print(arr_2d)
  [[ 1 10  3  4]
   [ 8  7  6  5]
   [ 9  2 11 12]]


*Image credits: `Jay Alammar <https://jalammar.github.io/>`_*.

Material is based on `Numpy's starter guide <https://numpy.org/doc/stable/user/absolute_beginners.html>'_.
See original `licence <https://numpy.org/doc/stable/license.html>`_

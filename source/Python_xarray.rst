.. _python_xarray_module:

Python Xarray Module
====================

The **xarray** module is an open-source project and Python package that makes working with 
labelled multi-dimensional arrays simple, efficient, and fun. Xarray introduces labels in 
the form of dimensions, coordinates, and attributes on top of raw NumPy-like arrays, 
allowing for a more intuitive and concise developer experience.

It is particularly powerful for physical sciences (meteorology, oceanography, etc.) where 
data often has spatial and temporal dimensions.

Installation
------------

To install the xarray module, use the following command in your terminal:

.. code-block:: bash

   pip install xarray

Alternatively, if you are using Conda:

.. code-block:: bash

   conda install -c conda-forge xarray

Data Structures
---------------

Xarray provides two primary data structures: **DataArray** and **Dataset**.

1. DataArray
~~~~~~~~~~~~

A **DataArray** is xarray’s implementation of a labeled, multi-dimensional array. It 
combines the underlying data (a NumPy or Dask array) with metadata.

* **data**: A multi-dimensional array of values (e.g., NumPy array).
* **coords**: A container of arrays (coordinates) that label each point.
* **dims**: Names for each axis (e.g., ``("x", "y")`` or ``("time", "lat", "lon")``).
* **attrs**: A dictionary holding arbitrary metadata (units, descriptions).

**Example:**

.. code-block:: python

   import xarray as xr
   import numpy as np

   # Create data
   data = np.random.rand(4, 3)
   times = ["2023-01-01", "2023-01-02", "2023-01-03", "2023-01-04"]
   locs = ["IA", "IL", "IN"]

   # Create DataArray
   da = xr.DataArray(
       data,
       coords=[times, locs],
       dims=["time", "space"]
   )
   print(da)

2. Dataset
~~~~~~~~~~

A **Dataset** is a dict-like container of aligned **DataArray** objects. It can be 
thought of as a multi-dimensional equivalent of a Pandas DataFrame.

**Example:**

.. code-block:: python

   # Create a dataset with two variables: temperature and precipitation
   ds = xr.Dataset(
       data_vars={
           "temperature": (["time", "space"], np.random.rand(4, 3)),
           "precipitation": (["time", "space"], np.random.rand(4, 3)),
       },
       coords={
           "time": times,
           "space": locs,
       }
   )
   print(ds)

Core Operations
---------------

Xarray allows for operations using dimension names instead of axis numbers.

1. Indexing and Selecting
~~~~~~~~~~~~~~~~~~~~~~~~~

Xarray supports label-based indexing using ``.sel()`` and integer-based indexing 
using ``.isel()``.

.. code-block:: python

   # Select data by label
   july_data = ds.sel(time="2023-01-01")

   # Select data by integer index
   first_snapshot = ds.isel(time=0)

2. Aggregation
~~~~~~~~~~~~~~

You can perform aggregations across specific dimensions by name.

.. code-block:: python

   # Calculate the mean temperature across the 'time' dimension
   mean_temp = ds["temperature"].mean(dim="time")
   print(mean_temp)

3. Broadcasting and Alignment
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Xarray automatically "aligns" data based on coordinates. If you subtract two 
arrays, xarray ensures the labels match before performing the math.

.. code-block:: python

   # Subtract the mean from the original data
   anomalies = ds["temperature"] - mean_temp

Data I/O
--------

Xarray is the industry standard for handling **NetCDF** files, but also supports 
Zarr, GRIB, and GeoTIFF (via the rioxarray extension).

.. code-block:: python

   # Save to NetCDF
   ds.to_netcdf("weather_data.nc")

   # Read from NetCDF
   new_ds = xr.open_dataset("weather_data.nc")

Summary Table of Properties
---------------------------

+-----------------+-----------------------------------------------------------+
| Property        | Description                                               |
+=================+===========================================================+
| ``.values``     | The underlying array (usually NumPy).                     |
+-----------------+-----------------------------------------------------------+
| ``.dims``       | The names of the dimensions (e.g. 'lat', 'lon').          |
+-----------------+-----------------------------------------------------------+
| ``.coords``     | The labels for the points along the dimensions.           |
+-----------------+-----------------------------------------------------------+
| ``.attrs``      | Metadata dictionary (units, source, etc.).                |
+-----------------+-----------------------------------------------------------+

Important Links
---------------

* `Official Xarray Documentation <https://docs.xarray.dev/>`_
* `Xarray Tutorial Gallery <https://tutorial.xarray.dev/>`_
* `Comparison to Pandas <https://docs.xarray.dev/en/stable/getting-started-guide/why-xarray.html#xarray-and-pandas>`_

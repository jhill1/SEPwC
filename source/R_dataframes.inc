R dataframes 
----------------------------

Data frames (tables) are an object of class ``data.frame``. They are a two dimensional
array-like sructure where columns contains values of a single variable, and each row contains
values for ever column. A spreadsheet in R. 

Creating data frames
~~~~~~~~~~~~~~~~~~~~~

We can use the ``data.frame()`` function to create the data frame:

.. code-block:: R

    name <- c("Tom", "Jerry", "Spike")
    age <- c(10, 20, 11)

    df <- data.frame(name, age)
    print(df)

Here, the data frame has been created using existing vectors. The column names
have been taken from the variable names. You can create a more usable version:

.. code-block:: R

    name <- c("Tom", "Jerry", "Spike")
    age <- c(10, 20, 11)

    df <- data.frame("Name"=name, "Age"=age)
    print(df)

You can then access data using either indexing or using the ``$`` notation:

.. code-block:: R

    # Accessing element at 3rd row and 2nd column
    print(df[3, 2])
    
    # Accessing entire column named "Age"
    print(df$Age)
    
    # Accessing the 2nd row
    print(df[2, ])

You can also add columns easily:

.. code-block:: R

    df$animal <- c("Mouse","Cat","Dog")
    print(df)

You can also use logicals to select data:

.. code-block:: R

    df[df$animal == "Cat",]

Notice the trailing comma; try the same code without and see what is different. This is beacuse we
want to access rows. Without the trailing comma we access a column. The ``df$animal == "Cat"`` returns
``FALSE TRUE FALSE``, which is applied to columns without that trailing comma, rather than the rows
as we wanted. Try this code:

.. code-block:: R

    df[df$animal == "Mouse",]
    df[df$animal == "Mouse"]
   
There are a number of other useful functions, such as ``head()``, ``tail()``, ``rbind()`` and ``cbind()``.
It's worth looking those up and trying them out.



Debuggers
==========
.. index::
  single: debugger; debugging

Before we start, we need to define some terms:

+-------------+----------------------+-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
| Term        | Analogy              | Definition                                                                                                                                                                                |
+=============+======================+===========================================================================================================================================================================================+
| Breakpoint  | A Stop Sign          | A marker you place on a specific line of code. The program will run at full speed until it hits this line, then freeze and wait for your command.                                         |
+-------------+----------------------+-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
| Step (Over) | Walk One Pace        | Executes the current line and moves to the next one. If the line contains a function call, it runs the entire function in the background and stops on the next line of your current file. |
+-------------+----------------------+-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
| Step Into   | Open the Door        | If the current line has a function, this "dives" inside that function so you can see what it's doing line-by-line, rather than just getting the result.                                   |
+-------------+----------------------+-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
| Step Out    | Exit the Room        | If you are inside a function and realize it's working fine, this finishes the rest of that function and jumps back out to the line that called it.                                        |
+-------------+----------------------+-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
| Continue    | Green Light          | Tells the program to stop pausing and resume running at full speed until it hits the next breakpoint or the end of the script.                                                            |
+-------------+----------------------+-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
| Call Stack  | The Breadcrumb Trail | A list that shows which functions are currently active. If main() calls calculate(), the stack shows you exactly how you arrived at the current line.                                     |
+-------------+----------------------+-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+

Most debuggers have the same terminology, so we can use them in Spyder or Rstudio.


Debugging in Spyder
--------------------
.. index::
  single: spyder; debugger; ipdb

Spyder integrates the **ipdb** debugger directly into its console, allowing you to execute code line-by-line and inspect variables in real-time.

Core Debugging Controls
~~~~~~~~~~~~~~~~~~~~~~~~

You can find these tools in the **Debug** menu or the Debug toolbar:

* **Debug (Ctrl+F5):** Starts the debugging session from the beginning.
* **Step (Ctrl+F10):** Executes the current line and stops at the next one.
* **Step Into (Ctrl+F11):** Enters the function on the current line.
* **Step Out (Ctrl+F12):** Finishes the current function and returns to the caller.
* **Continue (Ctrl+F12 / F12):** Runs the code until the next breakpoint is hit.
* **Stop (Ctrl+Shift+F12):** Exits the debugger.

Workflow Steps
~~~~~~~~~~~~~~

1. **Set Breakpoints**
   Click to the left of the line number in the editor. A **red dot** will appear, telling Spyder to pause execution there.

2. **Start Debugging**
   Press ``Ctrl+F5``. Your console prompt will change from ``In [1]:`` to ``ipdb>``, indicating you are in debug mode.

3. **Inspect Variables**
   While paused, look at the **Variable Explorer** pane. You can see the current value of every object in memory. You can even modify them on the fly to test "what if" scenarios.

4. **Navigate the Stack**
   Use the buttons or shortcuts to move through your code. The editor will highlight the line currently being executed with an arrow.


Tips for Efficiency
~~~~~~~~~~~~~~~~~~~~

* **The ipdb Prompt:** You can type any Python command directly into the ``ipdb>`` prompt to evaluate expressions using the current local variables.
* **Conditional Breakpoints:** Right-click a breakpoint to set a condition (e.g., ``x > 10``). The debugger will only stop if that condition is true.
* **Post-Mortem Debugging:** If your code crashes, type ``%debug`` in the console immediately after the error to enter the debugger at the point of failure.

.. warning::
   Always remember to "Stop" the debugger before trying to run a new version of your script to avoid conflicting sessions.

.. admonition:: Practical exercise - Python

   Debug the following (create this as a script and then run) using the Spyder debugger.

   .. code-block:: python 
        :caption: |python|

        def calculate_average(data):
            total = sum(data)
            count = len(data)
            # The bug: If data is empty, count is 0, leading to a crash.
            average = total / count
            return average

        def main():
            datasets = [[10, 20, 30], [], [5, 15]]
            
            for i, d in enumerate(datasets):
                print(f"Processing dataset {i}...")
                result = calculate_average(d)
                print(f"Average: {result}")

        if __name__ == "__main__":
            main()

.. admonition:: Solution
   :class: toggle

   1. Set a Breakpoint: Click next to the line result = calculate_average(d) inside the main() function.
    
   2. Start Debugging: Press Ctrl+F5.
         
   3. Step Into: When the code stops at your breakpoint, press Ctrl+F11 to "Step Into" the calculate_average function.
         
   4. Observe: Use the Variable Explorer to watch the value of d.
         
   5. Identify: Keep pressing Ctrl+F10 (Step) until the loop hits the second item (the empty list []). You will see count become 0 in the Variable Explorer just before the division happens.


Debugging in RStudio
---------------------
.. index::
  single: Rstudio; debugger

RStudio provides a robust visual debugger that integrates with R's native 
debugging tools. It allows you to pause execution, inspect data frames, 
and step through logic line-by-line.

When the debugger is active, the **Console** toolbar provides these controls:

* **Next (F10):** Executes the current line and moves to the next.
* **Step Into (Shift+F7):** Enters the function on the current line.
* **Finish (Shift+F8):** Completes the current function and returns to the caller.
* **Continue (c):** Resumes execution until the next breakpoint or the end of the script.
* **Stop (Shift+F10):** Immediately exits the debugger.

.. admonition:: Practical exercise - R

    This exercise demonstrates how to identify a logical error where a missing 
    value (``NA``) breaks an ``if`` statement.

    Add the following to a script:
    
    .. code-block:: r
       :caption: |R|

       calculate_total_sales <- function(daily_revenue) {
          # Logic: Sum up the revenue
          # Potential Bug: If revenue contains NA, sum() returns NA
          total <- sum(daily_revenue)
          
          if (total > 1000) {
            message <- "Great week!"
          } else {
            message <- "Keep pushing!"
          }
          
          return(message)
       }

       # Test Data
       week_1 <- c(200, 150, 300)
       week_2 <- c(400, NA, 500) # This will cause an issue

       print(calculate_total_sales(week_1))
       print(calculate_total_sales(week_2))


.. admonition:: Solution
    :class: toggle

    1. **Set a Breakpoint:** Click to the left of the line number for ``total <- sum(daily_revenue)``. A red circle will appear.
    2. **Source the Script:** Click the **Source** button. R will pause at your breakpoint, highlighting the line in yellow.
    3. **Inspect the Environment:** Look at the **Environment** pane. When ``week_2`` is processed, you will see ``daily_revenue`` contains an ``NA``.
    4. **Observe the Failure:** Use **Next (F10)**. You will see ``total`` becomes ``NA``. The script will error on the ``if`` statement because it cannot compare ``NA > 1000``.


Advanced Techniques
~~~~~~~~~~~~~~~~~~~~

**The browser() Command**
Insert ``browser()`` directly into your code to trigger the debugger programmatically. This is useful for conditional debugging:

.. code-block:: r
    :caption: |R|

    if (any(is.na(daily_revenue))) {
      browser() # Pause only if data is messy
    }

**Post-Mortem Debugging**
If your code crashes, you can use ``traceback()`` in the console to see the sequence of function calls that led to the error.

.. note::
   In RStudio, you can also enable **"Error: Break on Error"** under the *Debug* menu to automatically jump into the debugger whenever an error occurs.

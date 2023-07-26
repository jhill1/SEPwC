Software development
====================

Software developmen (softdev) or engineering (softeng) are the process by which we write code. There is a subtle difference between these two titles, 
with engineers being resonsible for creating, designing, and testing the whole software applicaiton, whereas developers are responsible for a 
portion of that cycle. When we write code for ourselve, we are software engineers!

There are multiple processes by which software is created. Here, we're not going to become softdevs or softengs in any meaningful way
but we are going to learn some of the basics of the process, which helps us write better code.

Revision control
----------------

We've already learnt one of the key tools (or if you've skipped to this bit, you can go back and learn about it), which is revision control.
Rather than keep seperate versions of code in seperate files (which would be a nightmare for any reasonable sized applicaiton), we keep versions
of files in a revision control system. In this course we've learnt about `git`, but there are other tools, jut not as popular. 

However, revision control is a tool to help development; it does not solve all problems. You can use it in a number of ways depending on the project, the number of people and the aims of the code. There is no single right way to do this and any development tools helps set up a process, but it's humans that actually devise and use (or not!) any processes.

Simple way
~~~~~~~~~~~

Keep all your code in a repository. Develop on the main branch only and commit changes as and when. You can add robustness by running the test suite before committing or adding the test suite to run automatically on commit (requires certain services like GitHub or BitBucket and may require money!).

More robust method
~~~~~~~~~~~~~~~~~~~

Develop on branches. Issue a pull request when a feature is ready, tested and documented to merge it into the main branch. Set GitHub to require code review and passing of tests before a merge can happen. Even with a single person this means the main branch will always pass tests (and hence work to some standard) and gives you as the user and developer a chance to see the ``diff`` between the new and existing code.

The merge can then ``squash`` the smaller commits from the branch into a single, meaningful commit message, making your revision history much cleaner. 

With teams of developers this is the preferred method and only a few individuals are allowed to merge the requests into the main branch. 


Testing
--------

How do you know your code is correct? See this chapter!


Development process
--------------------

Software development goes through a number of stages:

 - requirements capture; what should it do?
 - writing code or refactoring
 - testing
 - bug fixes
 - client testing/approval

When writing code for yourself you are both the developer and the client. If you write code for someone else, then these roles are split. 

We've covered testing, bug fixing and writing code elsewhere, so let's focus on processes that can be used and the other elements that have not bee covered.

Requirements capture
~~~~~~~~~~~~~~~~~~~~~

If you are going to write code it is because you want to do something. You want to be able to analyse data, merge datasets togther, create animations of outputs, etc., etc. Requirements capture is a process by which we lay out what code should be able to do (and perhaps what it won't be able to do). There are a number of ways this can happen including interviews, workshops, user observations, prototyping and use cases/scenarios. For the purposes of this course we're going to assume you are the developer and the user so not all of these methods will be useful (unless you want to interview yourself...).

Prototyping is a useful thing when you are struggling to see what a code can or cannot do. It is often helpful to write short script with hard-coded data to try and work *how* to do something. The aim here is to create a realisitic, but small, dataset or set-up and write code that does a single, particular thing. You can then build on that to abstract it (e.g. take user input or a file) and develop code from there. It's often useful to then use this protype as template for a test. This way you don't get overwhelmed in designing the whole code/software in one go, but build it up bit-by-bit as you go. 

Use cases or scenarios are also really useful for the lone developer. Think about how you want to use your new software. Imagine being yourself in five years' time writing some new code that uses this. How would you like to call functions; do names make sense; does the flow make sense? With experience this kind of thinking becomes more second nature, but writing this down in a document will help clarify your thoughts and help the logical flow of code before you start writing. 

A useful technique it to also write psuedo-code or comments for the outline of various parts of your idea. This again helps point out any parts that could be functions or objects; where possible data issues might be, etc. 

The above takes time but helps you write better, cleaner, more readable code. Remember not to over-engineer or start optimising prematurely. Step one is to get functional code. Then move onto readable code. Then, if the code is too slow, optimise the code. Requirements capture helps the first of those steps.

Refactoring
~~~~~~~~~~~~

Refactoring is re-writing existing code into a new design or structure. Code ultimately goes out of date. Languages eventually die off for example and code will therefore need to be moved to a new language (or version of the same language as in Python 2 to Python 3) or the libraries we depend on may become obsolete. Sometimes, greater experience means we can see how an older code can be rewritten to be clearer or faster or use less memory. Regardless of the reason code will probably need rewritting at some point.

Refactoring can be done in one of two ways: starting from scratch (but with the knowledge of what has gone before) or step-by-step. The means depends on a number of factors, but regardless one should not be afraid to start again. Your code is safe in a revision control repository and refactoring, even in a minor way, can vastly improve code.

Development processes
----------------------

There are number of processes that have been devised to manage software projects. Here, we'll cover two currently popular processes. Again, remember there is no right or wrong way and it depends on the project in question. Processes are human devices to manage a project and not something that should be seen as "the one true way".

Traditional development
~~~~~~~~~~~~~~~~~~~~~~~~~

A traditional software project will create a document to set out the reuirements of the software. Another document will be created for the design, following discussions and prototyping. More documents will outline the tests and the test infrastructure as well as the processes and protocols. Develoeprs can then be sent off to write individuals blocks of code or tests. A project manager overseas this and checks progress of each element and ensures they work together. 

The project may be split into phases with client approval at each phase, but clients generally don't see or interact with the code between these releases. 

This is how traditional software was released; think Windows XP vs Windows 10 with bug fixes and very minor updates in between releases.


Agile development
~~~~~~~~~~~~~~~~~~~

Agile development takes the software development process and creates a tight, rapid loop of development, which is repeated often. Rather than create an overarching requirements capture and then a grand design, you start small. You would aim to create a single feature, design it, code it, test it and get approval within a short timeframe. You then move onto the next. 

Agile development has a huge advantage when a project is ill-defined (which is bascially all research code as we have no idea what is needed in the future!), but comes at potential costs. With no overarching design or plan it is very difficult to give a final cost and development may go "off-piste" with features that aren't actually needed.

However, for a lone developer/user it works well, if you also have an eye on the larger picture of what you need to acheive. The documetns listed above may still be needed!

THis is how apps on phones tend to be managed, with small minor updates and features added relatively frequently. More larger software packages use this method now, with releases more often (ChromeOS for example).


Test-driven development
~~~~~~~~~~~~~~~~~~~~~~~~

Test-driven development turns the development cycle around to put testing up-front:

 - requirements capture; what should it do?
 - testing
 - client testing/approval
 - writing code or refactoring 
 - bug fixes

The tests are written immediately after requirements capture and before any code is written (so the test will all fail!). You get approval from the client that the tests meet the requirements and then write code to pass the tests. Once done, you have met the requirements. 




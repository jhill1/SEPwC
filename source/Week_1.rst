Filesystems, how a computer works and the command line
======================================================

Computers have been around since the 1940's. The first computers were 
mechanical; using valves to store and process information. By the 60's and 70's they
had moved to silicon transistors; tiny gates that store a 1 or 0 (on or off). A modern
computer CPU (Central Processing Unit) will have around 20 billion transistors,
each around 5 nm in size (human hair is 70 microns thick, so around 1000 times
thicker than the CPU transistor!). 

The modern computer has several parts we need to know about in order to use
them well:

 * A CPU: the processing unit of the computer. Carries out the instructns (we are going to give it!)
 * RAM: Random Access Memory, or often memory. Typical computers have 4 - 16 Gb (giga bytes). This 
   is non-permananet storage. Turn your computer off and what is in RAM disappears.
 * Storage. Often a hard (drive) disk (HDD) or a solid state drive (SSD). This is permanant
   storage and where you keep your files.
 * Graphics card or chip: Modern computers can display more colours than the eye can see and at a resolution 
   that is comparable to the human eye. To do that they have a dedicated chip, often called a GPU
   (Graphical Processing Unit). NVidia is a popular brand.
 * Operating System (OS): This is Windows, Linux, MacOS, etc. It lives on the storage.
 * BIOS: Basic Input-Output System. Computers need something to tell them what to do when you
   turn it on. The BIOS does this. It's a very basic OS on a chip.

 A computer works by reading the BIOS, which then starts the OS loading from disk to RAM. Once done, 
 you can then log on and start using it. There is a lot of jargon around compters. We will try and cover this
 as we go, but look up anything you come across that isn't explained.

Filesystems
-----------

Every computer needs to store files so it can be used. A variety of media have been used 
in the past to do this: punch cards, tapes, floppy disks, CDs, DVDs, and of course, hard drives
and solid state drives. How we store the data onto the drive is called the filesystem. You may
have come across things like FAT95, NTFS, ext4, journalling, etc. These are all types of filesystems.
Fortunately, we rarely need to care about this (unless we want to plug storage 
from a Mac into Windows or vice-versa); the OS takes care of this for us. Each OS uses a different filesystem. 
Macs use Apple File System (APFS), Windows uses NTFS, Linux uses
ext4 or similar.

The OS then stores files on its filesystem. Each OS has different characteristics and ways of 
storing your files. This we do care about. We'll go through each OS in turn.

Windows
^^^^^^^

Windows organises files into drives. Drives are usually physical drives, but can be partitions on a single drive too
(i.e. divide your 1 Tb drive into a 250 Gb drive and a 750 Gb drive). Drives are given letters, A:, B:, C:, etc. C: is
the root drive where Windows actually lives, along with your programs (apps) and your data and files.

Exercise: Why C:? What's wrong with A? Google and find out.
.. note::
   :class: dropdown

   A: and B: were reserved for floppy disks, which is what MSDOS computers generally had.

From the drive, folders are seperated with a '\' symbol. Software is generally installed
in ``C:\Program Files`` (or ``C:\Program Files (x86)`` for older software). Your documents are
in a *magic* folder called ``Documents``. It's possible to get this to point to network drives or 
to your local hard drive. However, a *standard* Windows 11 machine will have this pointing to 
``C:\Users\*Username*\``. Likwise for, ``Downloads``, ``Music``, ``Desktop``, ``Pictures``, etc.

Why do we care? When writing code, we often need to know exactly where a file is; it's not enough to know
it's in ``Documents``; we need a full path (see later).

Linux
^^^^^

Linux organises things around the root drive, which is access via ``/`` (note the direction of the slash compared 
to Windows - yes, they use the opposite direction). In root you then find a bunch of standard directories, ``\etc``, ``\bin``
``\var``, etc. This contain the system files. One directory is called ``\home``. This is where user files live. Within 
``\home`` there is a directory with your username. Within there are your images, music, etc.

Unlike Windows, drives can be mounted anywhere in the file structure and this is generally transparent to the user. So for example
``\home`` can be mounted onto a completely seperate physical hard drive to the rest of the folders. The same applies to *any*
folder. Temporary drives will be mounted into ``\media`` or ``\mnt``. Note that Linux filenames are case-senstive, so ``Bob.txt`` is
a different file to ``bob.txt``

MacOS
^^^^^

Mac is very similar to Linux (it is in fact based on Unix, which Linux is too). Unlike Linux Apple added some
standard folder names and moved a few things around compared to Linux. I'll note the differences only here.

User directories live in ``\Users`` rather than ``\home``. Applications are stored ``\Applications``, but there
are some binaries (i.e. programmes) in ``\bin``, etc.

Like Linux, MacOS is case sensitive.

Exercises
^^^^^^^^^


As we have to deal with multiple OSes, from here we will designate sections with 
symbols.

Mac only: |mac|

Linux only: |linux|

Windows only: |win|

Mac and Linux:  |maclin|

All OSes: |all|

.. |mac| image:: ../images/Apple_logo.png
   :align: middle
   :height: 12

.. |linux| image:: ../images/Linux_logo.png
   :align: middle
   :height: 12

.. |win| image:: ../images/Windows_logo.png
   :align: middle
   :height: 12

.. |maclin| image:: ../images/linux_mac_logo.png
   :align: middle
   :height: 12

.. |all| image:: ../images/win_linux_mac_logo.png
   :align: middle
   :height: 12


Navigating a filesystem
-----------------------

There are two ways to navigate your files; some form of graphic interface (all three common OSes have a similar tool) or the
command line. We're going to explore using both. Before we do this, we need a few basic command line tools to move around the files.



cd
ls/dir

need examples and video of this

GUI way. Need screenshots of this and video

Absolute vs Relative paths
---------------------------

Most of the filepaths above are absolute paths. You start at the root of the drive (C: or /) and give the 
all the directories until you get to the file you're after. I did however sneak in a few *relative*
paths. These are paths that start from where you curently are (be that in the command line or running
a programme). 

Let's do an example. Here's an absolute path:

/home/jon/my_exicting_project/data/very_important_data.csv

This is in a directory structure like:

[add image]

Now let's cd into the scripts folder

cd /home/jon/my_exciting_project/scripts

The data (*very_important_data.csv*) is one directory up (now in my_exciting_project) and then into data.
So relative to scripts, that's ../data/very_important_data.csv

This is a really useful thing. Rather than give a full/absolute path, we can give relative paths
to file. Imagine I had written a script that used absolute paths to data on my computer and gave that to
you. It would not work as you're not on my computer and you are not logged in as me. You would then
have to edit every path in the script. However, if I give relative paths, as long as the directory 
structure is the same, the script will work. 

The downside of relative paths is that you must have the same directory structure, relative to 
the script. If you move the script elsewhere, things might break. You can, of course,
mix and match; so pull data from an absolut path in one place and from a relative path
in another. Finally, you can ask the user where to get data from too (or pull data
from the internet) saving all this hassle.

However, when starting to write your own script you will `hardcode` the filenames and hence
you need to know the difference between relative and absolute paths.

From source code to programme
------------------------------



More basic command line functions
----------------------------------


Connecting to other computers
-----------------------------

Software licences
=================

Software needs a licence which tells your users or other developers what they are allowed
to do with it. Most software you've heard of is commercial (Word, Windows, MacOs, 
Adobe Reader, Corel Draw, Photoshop, etc). You pay a fee and have access to the
executable code for a year or forever, for example. Some software is free (i.e. you
don't pay to use it) but not open (you can't see the source code, nor give it 
to someone else). All of the conditions are laid out in the "Terms and Conditions" 
which are displayed when you install the software (and that no-one ever reads despite
ticking the little box to say you read them...)

A lot of research software is free in all senses of the word. You don't pay and 
you can see the source code, take it for yourself, edit it and re-release it. This
type of software is called *open source*. Not only can you use it for free, you can also
modify it. 

There are two things in law we have to worry about: copyright and licence. Copyright
is granted to the writer of the software (or book, or photograph, etc). If you
create something you own the copyright. You don't have to do anything to get copyright, 
except be the author or creator of the content. Authors generally place a copyright
notice on the work though, so something like:

Copyright lasts for 50 years and protects the author from someone stealing their work.
This page has a simple explination of UK copyright law. [https://www.gov.uk/copyright#:~:text=You%20get%20copyright%20protection%20automatically,work%2C%20including%20illustration%20and%20photography]

Separately, licences tell you what you can do with some code (or image, or text). For 
commerical software, the lincence will tell you you cannot resell, give away, etc
the software you have bought. Similarly, for open-source software the licence tells 
you what you can do with the source code, including modifying and re-releasing and under
what conditions.

There are two main types of licences: copyleft and permissive. Within those are a whole
bunch of different licences, but let's focus on the two main types first.

Copyleft
--------

Copyleft licences (a pun on copyright, geddit?) mean you can take 
source-code, modify it, but can only re-release on a similar licence. For example,
you could not take copyleft code, create a commercial application, then sell it. 
That would breach the licence terms. Most copyleft licneces specify the 
source code most be available under a similar copyleft licence.

Common copyleft licences are:

 * GNU Public Licence (GPL)
 * Mozilla public licence (MPL)
 * LGPL (Lesser GPL); though this has some permissive terms too
 * Creative Commons, Sahrealike (CC-SA)

Permissive
----------

Permissive licences are much less restrictive. They impose little or no restrictions
on what you can do if you modify code. They can either be completely open (i.e. do whatever you want!)
or impose some restrictions, e.g. citations.

Common permissive licences include:

 * Apache
 * Berkley Source Distribution (BSD)
 * MIT


Exercise: write down basic terms for 2 permissive and 2 copyleft licences. Use wikipedia.



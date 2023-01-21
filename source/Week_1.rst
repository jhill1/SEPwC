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

Navigating a filesystem
-----------------------

There are two ways to navigate your files 





Software licences
=================

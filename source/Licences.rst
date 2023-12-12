.. include:: <isonum.txt>


Software licences
=================

Software needs a licence which tells your users or other developers what they are allowed
to do with it. Most software you've heard of is commercial (Word, Windows, MacOs, 
Adobe Reader, Corel Draw, Photoshop, etc.). You pay a fee and have access to the
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
is granted to the writer of the software (or book, or photograph, etc.). If you
create something you own the copyright. You don't have to do anything to get copyright, 
except be the author or creator of the content. Authors generally place a copyright
notice on the work though, so something like:

*Copyright 2024. Jon Hill*

Copyright lasts for 50 years (or 75 for music) and protects the author from someone stealing their work.
`This page has a simple explanation of UK copyright law. <https://www.gov.uk/copyright>`_

Separately, licences tell you what you can do with some code (or image, or text). For 
commercial software, the licence will tell you you cannot resell, give away, etc.
the software you have bought. Similarly, for open-source software the licence tells 
you what you can do with the source code, including modifying and re-releasing and under
what conditions.

There are two main types of open licences: copyleft and permissive. Within those are a whole
bunch of different licences, but let's focus on the two main types first.

Copyleft
--------

Copyleft licences (a pun on copyright, geddit?) mean you can take 
source-code, modify it, but can only re-release on a similar licence. For example,
you could not take copyleft code, create a commercial application, then sell it. 
That would breach the licence terms. Most copyleft licences specify the 
source code most be available under a similar copyleft licence.

Common copyleft licences are:

 * GNU Public Licence (GPL)
 * Mozilla public licence (MPL)
 * LGPL (Lesser GPL); though this has some permissive terms too
 * Creative Commons, Share-alike (CC-SA)

Permissive
----------

Permissive licences are much less restrictive. They impose little or no restrictions
on what you can do if you modify code. They can either be completely open (i.e. do whatever you want!)
or impose some restrictions, e.g. citations.

Common permissive licences include:

 * Apache
 * Berkley Source Distribution (BSD)
 * MIT

.. admonition:: Practical exercise

    **Licences**
    
    Write down some restrictions for 2 permissive and 2 copyleft licences. Use Wikipedia.


..  admonition:: Solution
    :class: toggle

    * Apache: Permissive licence. Restriction is to preserve copyright, trademark and attribution
      notices.
    * BSD: Permissive. Restriction is to preserve copyright and the notice. Also had to show this
      with advertising. Spawned a number of similar licences without that clause.
    * MIT: Same as Apache in most respects!
    * GPL: Copyleft. All software using your must be released under similar terms. 
      You can modify, share, run without restrictions.
    * LGPL: As above, but if you use a LGPL code in proprietry software and modify it you 
      must release that modification. You don't have to release your proproetry software
      as copyleft though.
    * CC: A number of different licences that can allow share-alike, acknowledgement only or non-commercial use.
    * MPL: Somewhere between GPL and Apache, so similar to LGPL. You can use the software in proprietry
      software, but you need to make it available.


.. admonition:: Practical exercise

    **Licences**
    
    Find the licence for the following software:
    
    * Ubuntu
    * MacOs
    * Google Chrome
    * R
    * Python


..  admonition:: Solution
    :class: toggle

    * Ubuntu: `A mix <https://ubuntu.com/legal/intellectual-property-policy>`_. 
      Ubuntu itself is a bespoke licence. The various bits of software in Ubuntu have their own licences.
    * MacOs: `Bespoke <https://www.apple.com/uk/legal/sla/>`_, with some terms to prevent 
      reverse engineering, and running on non-Apple branded hardware!
    * Google Chrome: Freeware. It is based on the open source Chromium which is under BSD.
    * R: GPL3/GPL2. 
    * Python: `PSF <https://docs.python.org/3/license.html>`_, which is GPL compatible. 


Adding a licence to your code
-----------------------------

If you write any code that is to be used by others you should always add a 
copyright notice and a licence. This protects you and the person using it.
Try and get in the habit of writing both of these in your code, so something like:

*Copyright 2023 by Jon Hill. CC-BY-SA.*

You then include the full licence in your distribution.



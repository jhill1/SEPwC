Thinking like a computer
========================

To write code, we have to think in terms of algorithms and logic flow. We have covered the basics of code structures above, so now
we can arrange those to form algorithms and then into programs. We can think about this in terms of pseudo-code (like I wrote above).
Remember, pseudo-code is not a formal language but is code written to be read by a human with no concerns about syntax. We can also 
depict code as a flow diagram; this is more useful as we build more complex algorithms. 

Let's build software to do some simple tasks.

Create a word cloud
-------------------

We want to create a word cloud of a text file only including
words that occur more than 2 times *and* does not include
the words "and", "the", "or".

Let's start by writing the pseudo-code.

.. code-block::

   text = load_textfile("our text_file.txt")
   words = split_into_words(text)
   
   for word in words
      if word == "or" or word == "and" or word == "the":
         remove(word, words)

   unique_words = get_unique(words)
   counts = zeros(length(unique_words))
   for word in words:
      index = get_index(word, unique_words)
      counts[index] = count[index] + 1

    index = 0
    for count in counts
       if count < 2
          remove_item(words,index)
       index = index + 1
      
    make_word_cloud(words)

The above code is quite complex and makes a lot of assumption on what functions are there. We might
need to write some of these ourselves. The gist of the above code is:

 1. load in the text
 2. separate into words (removing punctuation, spaces, etc.)
 3. loop through the list of words and remove and, the, or
 4. get a list of unique words
 5. make an empty list of counts which is the same length as the unique words
 6. loop through the list of words and find out where this is in the unique word list, incrementing the correct count value
 7. loop through the words a third time, removing those where the count is less than 2
 8. make out word cloud

Let's run through an example of that. Here's our text:

 | Need some sample, random, text and noise, 
 | I need some words that occur three times, so
 | random, random, noise, need, times, times, need and and and

The text above should generate word cloud containing the words:
 * random (3 occurrences)
 * need (4 occurrences)
 * times (3 occurrences)

Check you agree with the above.

Let's now go through the steps. So we load in the above and split into words (steps 1 and 2):

 * need
 * some
 * sample
 * random
 * text
 * and
 * noise
 * I
 * need
 * some
 * words
 * that
 * occur
 * three
 * times
 * so
 * random
 * random
 * noise
 * need
 * times
 * times
 * need
 * and
 * and
 * and

Our next step (3) is to remove the words "and", "the", and "or", so we end up with:

 * need
 * some
 * sample
 * random
 * text
 * noise
 * I
 * need
 * some
 * words
 * that
 * occur
 * three
 * times
 * so
 * random
 * random
 * noise
 * need
 * times
 * times
 * need

We then create a list of unique words (we'll do that code later), which would give us:

 * need
 * some
 * sample
 * random
 * text
 * noise
 * I
 * words
 * that
 * occur
 * three
 * times
 * so

We then count the number of times those words occur, by looping over the original word list and counting them. 
We know there are 13 unique words. We set up a list where the count is sorted in the same location as the unique
word, so our lists are like this:

.. list-table:: Unique word count
   :header-rows: 1

   * - Index
     - Word
     - Count
   * - 1
     - need
     - 4
   * - 2
     - some
     - 2
   * - 3
     - sample
     - 1
   * - 4
     - random
     - 3
   * - 5
     - text
     - 1
   * - 6
     - noise
     - 1
   * - 7
     - I
     - 1
   * - 8
     - words
     - 1
   * - 9
     - that
     - 1
   * - 10
     - occur
     - 1
   * - 11
     - three
     - 1
   * - 12
     - times
     - 3
   * - 13
     - so
     - 1

We now have a count of each word and we loop through a final time (step 7) to remove those with 
fewer than 3 occurrences (or in other words with more than 2 occurrences). 

Step 8 is then make the word cloud from the remaining words ("times", "random" and "need")


Making a jam sandwich
---------------------

Write down the steps to make a jam sandwich. Create a flow diagram of the list. You can then reveal the answer


.. hint::
 
   Make sure you are very precise in your description




Plotting a graph with options
-----------------------------

Write down the pseudo-code needed to read in the data below
and plot a graph of time (x axis) vs wave height (y axis).
Allow the user to flip the graph (so wave height vs time).


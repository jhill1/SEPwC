Mini course: Sentiment Analysis
==================================
.. index:: 
   single: sentiment analysis

Sentiment analysis or opinion mining is a way of extracting feelings from large amounts of text. When 
we read text we can use our understanding of the words to derive an emotion from the text the
author is trying to convey. This can be characterised as *positive* or *negative* or even in
more nuanced emotions like *joy* or *anger*.

This section is heavily based on `"Text Mining with R" <https://www.tidytextmining.com/sentiment.html>`_

The pipeline in R
--------------------
.. index:: 
   pair: tidytext; R

We can use R's ``tidyverse``, along with ``tidytext``, data structures to perform these kinds of analyses quite easily, 
building a pipeline, something like this:


The Sentiment lexicon is the key to this. The simplest way to analyse text is to break it into tokens: words.
Obviously, this is a bit simplistic, we could have a positive word "great", preceded by a negative one "not",
which flips the entire meaning. However, the idea behind sentiment analysis is to analyse vast amounts of text, 
so these issues get lost as noise. It's something you need to be aware of though if you want to do
this on real data.

There are three sentiment databases, packaged into a R library, we can use for general-purpose analysis:

 - `AFINN` from `Finn Årup Nielsen <http://www2.imm.dtu.dk/pubdb/views/publication_details.php?id=6010>`_
 - `bing` from `Bing Liu and collaborators <https://www.cs.uic.edu/~liub/FBS/sentiment-analysis.html>`_
 - `nrc` from `Saif Mohammad and Peter Turney <http://saifmohammad.com/WebPages/NRC-Emotion-Lexicon.htm>`_

All of these are based on unigrams; single words, and are in English only. The ``nrc`` classifies
words in a binary fashion (i.e. yes/no) into categories of positive, negative, anger, joy, sadness, etc.
The ``bing`` lexicon categorises words into positive or negative. The ``AFINN`` lexicon creates a score between
-5 and 5 to show the sentiment (on a negative to positive scale). 

.. index:: 
   pair: sentiment analysis; lexicon

.. note::

  Each lexicon has a licence. You'll need to agree to the licence before using it. You will
  need to check if that licence is OK with your project. See :ref:`Software licences`.

Let's get these lexicons and see what they contain.

.. code-block:: R
    :caption: |R|

    library(tidytext)

    get_sentiments("afinn")

    get_sentiments("bing")

    get_sentiments("nrc")

Each one is a table of words (the unigram) and the sentiment, either as an emotion, positive/negative, or a score. 

Using the ``inner join`` to get the sentiments from your data
--------------------------------------------------------------

We can use the Jane Austen book database as our text. Let's first see which words are used to convey "joy" in 
*Emma*. We first need to separate the words into rows in a dataframe, for which we can use
``unnest_tokens()``. When we do this, we can also set up some other columns to help keep track of chapters, etc.

.. code-block:: R
    :caption: |R|

    library(janeaustenr)
    library(dplyr)
    library(stringr)

    tidy_books <- austen_books() %>%
      group_by(book) %>% # so we have each book as a group
      mutate(            # add some new columns
        linenumber = row_number(),  # like a line number
        chapter = cumsum(str_detect(text, # a chapter
                                    regex("^chapter [\\divxlc]", 
                                          ignore_case = TRUE)))) %>%
      ungroup() %>% # now we've done that, ungroup
      unnest_tokens(word, text) # and finally seperate out the words!

For ``unnest_tokens`` we chose the column ``word`` ; this is very helpful - look at the output
from the sentiment lexicons before; note they also have a column ``word``. This means we can easy
to an ``inner_join`` on our data and the lexicon to get the sentiment.

Let's do that, but first we need to filter for the book *Emma*, then we can do the join and look
at the output:

.. code-block:: R
    :caption: |R|

    nrc_joy <- get_sentiments("nrc") %>%
               filter(sentiment == "joy")

    tidy_books %>%
       filter(book == "Emma") %>%
       inner_join(nrc_joy) %>%
       count(word, sort = TRUE)

You should see the output of the most "joyfull" words in *Emma*, listed in number of
occurrences order. My output gave "good", "friend", "hope" as the top three.

We can use the same idea, but analyse the text in "blocks" to see how sentiment
changes throughout the book. It's a matter of keep track with an index. Here, we'll use 80
lines of text to form a section. This will depend what text you are analysing. 


.. code-block:: R
    :caption: |R|

    library(tidyr)

    jane_austen_sentiment <- tidy_books %>%
      inner_join(get_sentiments("bing")) %>%
      count(book, index = linenumber %/% 80, sentiment) %>%
      pivot_wider(names_from = sentiment, values_from = n, values_fill = 0) %>% 
      mutate(sentiment = positive - negative)


Here, we've done the ``inner_join`` with the ``bing`` database and then counted that over
80 lines of text (``%/%`` does integer division). The ``pivot_wider`` pulls the negative and positive sentiments
into separate columns (the ``n`` is introduced from the ``count``), then finally, the ``mutate`` creates a 
total score. You'll get a warning about "many-to-many" relationships. This is because of the multiple
matches to words (i.e. words occur multiple times in *Emma*). Have a look at the ``jane_austen_sentiment``
dataframe. Also look at the original ``tidy_books`` frame. Note that columns ``linenumber`` and ``chapter`` have been 
dropped during the processing. We can quickly plot these data:

.. code-block:: R
    :caption: |R|

    library(ggplot2)

    ggplot(jane_austen_sentiment, aes(index, sentiment, fill = book)) +
        geom_col(show.legend = FALSE) +
        facet_wrap(~book, ncol = 2, scales = "free_x")

.. image:: ../images/jane_austen_sentiment.png
       :alt: A graphs of overall sentiment for each of Austen's novels.

.. admonition:: Practical Exercise

    **Use the NRC and AFINN databases**
    
    Repeat the analysis of all Jane Austen's book, but using the AFFIN and NRC
    lexicon databases. Remember for AFINN, it's a score. Remember for NRC there
    are positive and negative labels (not just "joy", etc). 

..  admonition:: Solution
    :class: toggle

    .. code-block:: R
        :caption: |R|

        jane_austen_sentiment_afinn <- tidy_books %>%
            inner_join(get_sentiments("afinn")) %>%
            group_by(index = linenumber %/% 80) %>%
            summarise(sentiment = sum(value))
    
    After ``inner_join`` with the database, we need to ``group_by`` the linenumbers
    to create the index; we can then summarise by summing the ``value`` from ``afinn``
    over the index (i.e. every 80 lines).

    .. code-block:: R
        :caption: |R|

        jane_austen_sentiment_nrc <- tidy_books %>%
            inner_join(get_sentiments("nrc") %>%
                       filter(sentiment %in% c("positive", "negative"))
                      ) %>%
            count(book, index = linenumber %/% 80, sentiment) %>%
            pivot_wider(names_from = sentiment, values_from = n, values_fill = 0) %>% 
            mutate(sentiment = positive - negative)

    Similar to the ``bing`` data, you do an ``inner_join``, but here, we ``filter`` the 
    ``nrc`` data to only include positive and negative sentiments (not joy, anger, etc). 
    The rest of the functions are then identical to the ``bing`` example.


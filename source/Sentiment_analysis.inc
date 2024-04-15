Sentiment Analysis
===================

Sentiment analysis or opinion mining is a way of extracting feelings from large amounts of text. When 
we read text we can use our understanding of the words to derive an emotion from the text the
author is trying to convey. This can be characterised as *positive* or *negative* or even in
more nuanced emotions like *joy* or *anger*.

The pipeline in R
------------------

We can use R's `tidyverse`, along with `tidytext`, data structures to perform these kinds of analyses quite easily, 
building a pipeline, something like this:


The Sentiment lexicon is the key to this. The simpliest way to analyse text is to break it into tokens: words.
Obviously, this is a bit simplisitc, we could have a positive word "great", preceeded by a negative one "not",
which flips the entire meaning. However, the idea behind sentiment analysis is to analyse vast amounts of text, 
so these issues get lost as noise. It's something you need to be aware of though if you want to do
this on real data.

There are three `sentiment` databases, packaged into a R library, we can use for general-purpose analysis:

 - `AFINN` from `Finn Årup Nielsen <http://www2.imm.dtu.dk/pubdb/views/publication_details.php?id=6010>`_
 - `bing` from `Bing Liu and collaborators <https://www.cs.uic.edu/~liub/FBS/sentiment-analysis.html>`_
 - `nrc` from `Saif Mohammad and Peter Turney <http://saifmohammad.com/WebPages/NRC-Emotion-Lexicon.htm>`_

All of these are based on unigrams; single words, and are in English only. The `nrc` classifies
words in a binary fashion (i.e. yes/no) into categorieis of poisitve, negative, anger, joy, sadness, etc.
The `bing` lexicon categorises words into positive or negative. The `AFINN` lexicon creates a score between
-5 and 5 to show the sentiment (on a negative to positive scale). 

.. note::

  Each lexicon has a licence. You'll need to agree to the licence before using it. You will
  need to check if that licence is OK with your project. See :ref:`Software licences`.

Let's get these lexicons and see what they contain.

.. code-block:: R

    library(tidytext)

    get_sentiments("afinn")

    get_sentiments("bing")

    get_sentiments("nrc")

Each one is a table of words (the unigram) and the sentiment, either as an emotion, positive/negative, or a score. 

Using the `inner join` to get the sentiments from your data
-------------------------------------------------------------

We can use the Jane Austen book database as our text. Let's first see which words are used to convey "joy" in 
*Emma*. We firs tneed to seperate the words into seperate rows in a dataframe, for which we can use
`unnest_tokens()`. When we do this, we can also set up some other columns to help keep track of chapters, etc.

.. code-block:: R

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

For `unnest_tokens` we chose the oclumn `word`; this is very helpful - look at the output
from the sentiment lexiconcs before; note they also have a column`word`. 


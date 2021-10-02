# Simple python program to demonstrate NLTK basics by Azim Pathan

import nltk
from nltk.book import text1

# find no. of words in text
n_words = len(text1)
print(n_words)

# find no. of unique words in text
n_unique_words = len(set(text1))
print(n_unique_words)

# find no. of unique words considering different cases in text
text = [word.lower() for word in set(text1)]
n_unique_words_lc = len(set(text))
print(n_unique_words_lc)

# print word coverage i.e avg no. of words
coverage = n_words / n_unique_words
print(coverage)
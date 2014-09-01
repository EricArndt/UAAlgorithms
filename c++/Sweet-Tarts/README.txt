<h3>Sweet Tarts</h3>

Sweet Tarts are a hard candy similar to Life Savers. They come in a roll with n Sweet Tarts per roll and there are four flavors (A, B, C, and D). The package is clear so you can see the order of the flavors
in the roll. You can only get a Sweet Tart from either end of the roll; no breaking open the package in the middle. Furthermore, you immediately eat a Sweet Tart once you remove it from the package.
Now you have a definite preference for the flavors and like to save your favorites until the end. Being the computer science type, you’ve come up with a score for the order in which you eat the candies. You
give each of the flavors a number from 1 through 4, depending on your preference (4 is most favored, 1 is least). The score for eating a Sweet Tart is the product of its preference number with the position
you ate it. For example if you ate a flavor B as the 5th Sweet Tart, and B had preference number 3, then it’s score would be 15.

After you’ve eaten the entire roll, the score is the sum of all the individual Sweet Tarts eaten. Of course,
you’d like to maximize the score. Given a particular roll of Sweet Tarts and the preference order of the
four flavors, you’ll compute the maximum score of the roll. (Note there may be more than one way of
realizing the score.)


<h5>Input</h5>

There will be multiple input sets. Each input set will have 3 lines. The first line will contain n (n ≤ 100),
the number of Sweet Tarts in the roll. A value of n = 0 indicates there are no more input sets for this
problem. The second line will contain a permutation of {A,B,C,D} indicating preference for the flavors
(most favored to least). The third line will contain the n flavors as they appear in the roll, from left to
right. Note that it may be that not all flavors will be used.


<h5>Output</h5>

Each input set should produce one line of output of the form:
Case i has a maximum score of s where i is the number of the input set (starting at 1) and s is the maximum score you determine.

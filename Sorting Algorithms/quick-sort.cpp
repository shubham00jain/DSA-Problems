/*
Quick sort is an in-place algorithm and its default representation is unstable.

Inplace Algorithms:
It doesn't have any concrete defination but informally it can be defined as an algorithm which takes no extra memory or memory less than O(input) to sort the given elements.

Stable Algorithms:
This categorization is mainly done for sorting algorithms. The algorithms in which elements or keys having same values are given same priority (or are next to each other)
are called Stable Algorithms.

Quick Sort can be done in two ways:
1. Chosing the same position for the pivot everytime  (start, end or median).
2. Choosing random pivot.

https://www.geeksforgeeks.org/quick-sort/
https://www.geeksforgeeks.org/in-place-algorithm/
https://www.geeksforgeeks.org/stability-in-sorting-algorithms/


Time:
Best - O(nlog(n))
Worst - O(n^2) But this can always be avoided using randomised pivots
Average - O(nlog(n))

Space : constant
*/



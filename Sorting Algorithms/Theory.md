## In-Place Algo:
The algorithms which takes constant space to sort. This is debatable beacause to have an index to an length 'n' array we require at least log(n)bits. 
So, More broadly, in-place means that the algorithm does not use extra space for manipulating the input but may require a small though nonconstant extra space for its operation.
i.e the space should be less than O(n).

## Stable Algo:
A sorting algo is caled stable when the relative order of same elements is maintained. It is only useful when the indexes or keys have a significant value. for eg. in a map
when two elements A:1 and B:1 have same value, then the relative position of A and B should be preserved.

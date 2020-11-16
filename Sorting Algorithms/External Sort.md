## Question:
Suppose you have 5 GB of data and you have a RAM of size 1 GB. Give an efficient way to sort the 5 GB of data.

## Answer:
We will use something called a _k-way merge sort_. Merge sort was actually invented in the 1940s for this sole purpose. At that time, big companies like IBM used to store data
on magnetic tapes, and they often required to sort that data, hence this was invented.

## Process:
1. We will first load the first 1 GB of data in RAM and sort it using some algorithm like quick sort or insertion sort. We will then store the data in a file e.g. Sorted_1.
We will repeat the process for all of the 5 GBs of data and make Sorted_2,Sorted_3...

2. Now that all 5 GBs are seprately sorted we can merge them using a k-way merge sort. To do that, we will load the first 150 MB of every file into the RAM. Now our RAM has 
150x5 MB of every Sorted_ith file and 250 MB of free space. We will put 5 pointers (or k- pointers) at the start of every 150MB array and perform the merge step of the merge sort
only difference being this time we will be comparing between 5 numbers (or k numbers) and we will simulatenously write the output in the 250MB free file. AFter the free space is
filled we will store the data in the external DISK say OUTPUT_1 and empty the free space. After some time we will sort the whole 150x5MB of data. We will then take the next 150x5
MB of data from Sorted_ith files and keep sorting them in OUTPUT_ith files. And in the end we can combine all the outputs to get the final 5 GB sorted data.

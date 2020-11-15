/*
Quick sort is an in-place algorithm and its default representation is unstable.

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

Space : O(1)
*/

int Partition(int A[], int start, int end){
    int pivot = A[end];
    int pIndex = start;
  
    for(int i = start; i<end-1;i++){
      if(A[i]<=pivot ){
        swap(A[i], A[pIndex])
        pIndex++;
      }
    }
    swap(A[pIndex], pivot);
    return pIndex;
}

void Quicksort(int A[], int start, int end){
  if(start<end ){
    int pIndex = Partition(A,start,end);
    QuickSort(A,start,p);
    QuickSort(A,p+1,end);
  }
}

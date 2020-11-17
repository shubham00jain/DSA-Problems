/*
Quick sort is an in-place algorithm and its default representation is unstable.

Quick Sort can be done in two ways:
1. Chosing the same position for the pivot everytime  (start, end or median).
2. Choosing random pivot.

In Randomized quicksort we can either randomize the input array or choose a random pivot. The latter is easier and more logical to implement.
To make the chances even better, we can choose 3 random pivots and then pick the median of them!

Time:
Best - O(nlog(n))
Worst - O(n^2) But this can always be avoided using randomised pivots
Average - O(nlog(n))

Space : O(1)

Stable: No.
In-place: It is debatable. It uses O(log(n)) space to store the recursive calls but it does not use extra memory to sort. So, acc. to me the ans should be Yes.
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
    QuickSort(A,start,p-1);
    QuickSort(A,p+1,end);
  }
}

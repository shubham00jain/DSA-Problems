/*
1. It is of the easiest sorting algo.
2. It is in-place algo.
3. In this algo, we check every element with the current element and if it is smaller than the current element, we will swap them.
4. It is guranteed that at least one element will get to its correct position after each iteration.

Time:
Best: O(n^2)
Worst: O(n^2)
Average: O(n^2)

Space: O(1)
*/


void selectionSort(){
  int arr[] = {1,7,2,18,3,4};
  int n = 6;
  
  for(int i=0;i<n;i++){
    for(int j = i; j<n; j++){
      if(a[j]<a[i])
         swap(a[j],a[i]);
    }
  }
}

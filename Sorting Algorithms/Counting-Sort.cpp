/*
In this algorithm we assume that the input is smaller than a given k.
We first "count" the number of occurances of each element and then we make a cumulative array so that we know that all the elements at the position are less than or equal to that 
element and then we replace the elements.

ONLY WORKS IF WE ALREADY KNOW THE THE VALUE OF MAX(ARRAY).

k = Max(Array)
n = number of elements

Time:
Best: O(n+k)
Worst: O(n+k)
Average: O(n+k)

Space:
O(n+k)
*/

void countingsort(int arr[], int n){
  int res[n], aux[n];
  
  for(int i=0;i<n;i++){
    aux[a[i]]++;
  }
  
  for(int i=1; i<n;i++){
    aux[i] = aux[i-1];
  }
  for(int i=0;i<n;i++){
    res[aux[a[i]]] = a[i];
    res[aux[a[i]]]--;
  }
  return res;
}

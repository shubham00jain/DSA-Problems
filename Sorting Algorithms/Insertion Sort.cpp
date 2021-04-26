/*
1. In insertion sort, we assume that the left side of the array is already sorted.
2. This sort is very similar to sorting a hand of cards. We assume that the first card is at its correct place. Then we choose a card check, start checking the card with the sorted
cards and *insert* the card at its correct position inside the sorted hand.
3. This algorithm works best when the input is small and almost sorted.

Time:
Best: O(n)
Worst: O(n^2)
Average: O(n^2)

Space: O(1)

Stable: Yes
In-place: Yes
*/


void insertionSort(){
    int arr[] = {1,7,2,18,3,4};
    int n = 6;
    
    for(int i=1;i<n;i++){
      //v = current element
      int v = arr[i];
      int j = i;
      while(arr[j-1]>v && j>-1){
        A[j] = A[j-1];
        j--;
      }
      A[j] = v;
    }
    
}

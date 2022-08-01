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

    void quickSort(int arr[], int low, int high)
    {
        
        if (low < high) {
            int pivot = partition(arr, low, high);
            quickSort(arr, low, pivot-1);
            quickSort(arr, pivot + 1, high);
                
        }
    }
    
    public:
    int partition (int arr[], int low, int high)
    {
        
        int pIndex = low;
        int pivot = arr[high];
        
        for(int i=low; i<high;i++){
            
            if(arr[i] <=  pivot ){
                swap(arr[i], arr[pIndex]);
                pIndex++;
            }
        }
        
        swap(arr[pIndex], arr[high]);
        
        return pIndex;
        
        
        
    }

/*
1. It is the simplest of all the sorts.
2. In this algo, we check every element with its next element and if they statisfy our condition we swap them.

Time:
Best: O(n^2)
Worst: O(n^2)
Space: O(1)

Best case can be improved by checking if there was swap in the previous pass.
Best: O(n)
*/

void bubblesort(){
    int arr[] = {1,7,2,18,3,4};
    int n = 6;
    
    
    for(int i=0;i<n-1;i++){
        for(int j=i;j<n-1;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
            }
                
        }
    }
    
    //print
    for(int i=0;i<6;i++){
        cout<<arr[i]<<" ";
    }
    
}

void modifiedbubblesort(){
    int arr[] = {1,7,2,18,3,4};
    int n = 6;
    
    int swapped = 1;
    for(int i=0;i<n-1 && swap;i++){
      swapped = 0;
        for(int j=i;j<n-1;j++){
            if(arr[j]>arr[j+1]){
                swapped(arr[j],arr[j+1]);
                swapped = 1;
            }
                
        }
    }
    
    //print
    for(int i=0;i<6;i++){
        cout<<arr[i]<<" ";
    }
    
}

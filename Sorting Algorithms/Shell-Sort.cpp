/*
1. It is a genralized version of insertion sort.
2. In insertion sort we compare two adjacent elements i.e. an element 'j' with 'j-1' element but in shell sort we compare an element 'j' with an elment 'j-gap'.
This 'gap' is n/2 in the starting and we keep reducing it until we reach the end.
3. The final iteration of shell sort when gap==1 is an insertion sort.
4. The idea behind insertion sort is that we want almost all the smaller elements to the left side of the array before we perform the final insertion sort so that the 
insertion sort can have O(n) time complexity.

Time:
The time of insertion sort depends on the gap choosen and it very hard to predict its time compexity. Some time complexities are:
Best known : O(nlog^2n)
Another: O(n^4/3)
*/

void shellSort(){
    int arr[] = {1,7,2,18,3,4};
    int n = 6;
    
    for(int gap = n/2 ; gap>0;gap/=2){
        
       for(int i=gap;i<n;i++){
           int temp = arr[i];
           int j;
           
           for(j = i; arr[j-gap]>temp && j>-temp ; j-= gap){
               arr[j] = arr[j-gap];
           }
           arr[j] = temp;
           
       } 
    }
    
    //print
    for(int i=0;i<6;i++){
        cout<<arr[i]<<" ";
    }
}

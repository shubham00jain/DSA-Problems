/*
1.This is a genralization of counting sort.
2. It is generally used when we cannot use counting sort due to some restrictions.
3. In this algorithm, we first put every element in some "buckets". We then sort each and every bucket using insertion sort. And finally we cocatenate all of the buckets.

Time:
O(n)

Space:
O(n)

https://www.geeksforgeeks.org/bucket-sort-2/
*/

void bucketSort(float arr[], int n) 
{ 
    // 1) Create n empty buckets 
    vector<float> b[n]; 
  
    // 2) Put array elements in different buckets 
    for (int i = 0; i < n; i++) { 
        int bi = n * arr[i]; // Index in bucket 
        b[bi].push_back(arr[i]); 
    } 
  
    // 3) Sort individual buckets 
    for (int i = 0; i < n; i++) 
        sort(b[i].begin(), b[i].end()); 
  
    // 4) Concatenate all buckets into arr[] 
    int index = 0; 
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < b[i].size(); j++) 
            arr[index++] = b[i][j]; 
}

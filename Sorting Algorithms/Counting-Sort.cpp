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

Stable: Yes
In-place: No
*/

void countSort(){
    vector<int> v = { 1, 7, 3, 15, 2,0, 0, 1,15 };
    int n = v.size();
    int m = *max_element(v.begin(),v.end());
    vector<int> aux(m+1,0);
    vector<int> res(n,0);
    
    for(int i=0;i<v.size();i++){
        aux[v[i]]++;
    }
    for(int i=1;i<m+1;i++){
        aux[i]+= aux[i-1];
    }
    
    for(int i=0;i<n;i++){
        res[aux[v[i]]-1] = v[i];
        --aux[v[i]];
    }

    //print
    // for(int i=0;i<res.size();i++){
    //     cout<<res[i]<<" ";
    // }
}




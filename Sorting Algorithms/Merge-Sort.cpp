// https://www.geeksforgeeks.org/merge-sort/
/*
Time:
best - O(nlog(n))
avg  -  O(nlog(n))
worst - o(nlog(n))

Space : O(n)
It makes 2 extra auxillary containers in the merge function.
This extra space is one of the major reason why language libraries don't use merge sort and use quick sort instead. 
*/

void merge(vector<int> vec, int l, int m, int r){
    vector<int> le, ri;
    int n1 = m - l + 1;
    int n2 = r - m;

    for(int i = 0; i<n1;i++){
      le.push_back(vec[l + i]);
    }

    for(int i = 0; i<n2;i++){
      ri.push_back(vec[m + 1 + i]);
    }

    int k = l;
    int i = 0;
    int j = 0;

    while(i<n1 && j<n2){
      if(le[i]<=ri[j]){
        vec[k] = le[i];
        i++;
      }else{
        vec[k] = ri[j];
        j++;
      }
       k++;
    }

    while(i<n1){
      vec[k] = le[i];
      i++;
      k++;
    }
    while(j<n2){
      vec[k] = ri[j];
      j++;
      k++;
    }
}


void mergesort(vector<int> vec, int l, int r){
    if(r>l){
        int m = ( l + (r-1) )/2;
        mergesort(vec,l,m);
        mergesort(vec,m+1,r);
        merge(vec,l,m,r);
    }
}



int main(){

  vector<int> a{9,2,16,3,4,80,32};
  mergesort(a,0,6);
  
  for(int i=0;i<a.size();i++){
    cout<<a[i]<<" ";
  }

  return 0;
}

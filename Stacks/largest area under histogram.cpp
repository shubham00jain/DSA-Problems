/*
We use both previous smaller element and next smaller element in this problem. The only change is that we store the size of the array in next smaller element if the 
element dosen't have any next smaller element. Watch gfg video.
*/

vector<long long int> PreviousSmallerElement(long long arr[], int n){
    stack<long long int> s;
    vector<long long int> vec;
    for(int i = 0;i<n;i++){
        while(!s.empty() && arr[s.top()] >= arr[i] ){
            s.pop();
        }
        long long int sm = s.empty() ? -1 : s.top();
        vec.push_back(sm);
        s.push(i);
    }
    return vec;
}

vector<long long int > NextSmallerElement(long long arr[], int n){
    stack<long long int> s;
    vector<long long int> vec;
    for(int i = n-1;i>=0;i--){
        while(!s.empty() && arr[s.top()] >= arr[i] ){
            s.pop();
        }
        long long int sm = s.empty() ? n : s.top();
        vec.push_back(sm);
        s.push(i);
    }
    for(int i=0;i<n/2;i++){
        swap(vec[i],vec[n-i-1]);
    }
    return vec;
}

long getMaxArea(long long arr[], int n){
    long res = 0;
    vector<long long int> ns = NextSmallerElement(arr,n);
    vector<long long int> ps = PreviousSmallerElement(arr,n);

    for(int i=0;i<n;i++){
        long int ans = arr[i];
        ans += (i - ps[i] - 1)*arr[i] ; 
        ans += ( ns[i]-i-1 )*arr[i];
        ans = abs(ans);
        res = max(res,ans);
    }
    return res;
}

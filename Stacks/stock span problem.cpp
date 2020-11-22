//https://practice.geeksforgeeks.org/problems/stock-span-problem/0

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            arr.push_back(x);
        }
        stack<int> s;
        for(int i=0;i<n;i++){
            while(!s.empty() && arr[i] >= arr[s.top()] ){
                s.pop();
            }
            int ans = (s.empty() ? (i+1) : (i-s.top()) );
            cout<<ans<<" ";
            s.push(i);
        }
        cout<<endl;
    }

}

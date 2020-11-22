//https://practice.geeksforgeeks.org/problems/next-larger-element-1587115620/1

#include <bits/stdc++.h>
using namespace std;

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
            while(!s.empty() && arr[i] >= s.top() ){
                s.pop();
            }
            cout << ( s.empty() ? -1 : s.top() )<<" ";
            s.push(arr[i]);
        }
        cout<<endl;
    }

}

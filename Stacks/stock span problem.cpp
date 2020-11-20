//https://practice.geeksforgeeks.org/problems/stock-span-problem/0

#include <bits/stdc++.h>
using namespace std;



int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        stack<int> s,temp;
        vector<int>res;
        for(int i=0;i<n;i++){
            int num = 0;
            int x;
            cin>>x;
            temp = s;
            while(!temp.empty() && temp.top()<=x){
                temp.pop();
                num+=1;
            }
            num+=1;
            s.push(x);
            res.push_back(num);
        }
        for(int i=0;i<n;i++){
            cout<<res[i]<<" ";
        }
        cout<<endl;
    }
	return 0;
}

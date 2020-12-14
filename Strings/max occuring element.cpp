// use hashmap
//https://www.geeksforgeeks.org/return-maximum-occurring-character-in-the-input-string/

#include <bits/stdc++.h>
using namespace std;
#define long long int ll

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int t;
    cin>>t;
    while(t--){
        int arr[26] = {0};
        string s;
        cin>>s;
        for(int i=0;i<s.length();i++){
            arr[s[i]-'a']++ ;
        }
        int ma = INT_MIN;
        int mai = INT_MIN;
        for(int i=0;i<26;i++){
            if( arr[i]> ma ){
                ma = arr[i];
                mai = i;
            }
                
        }
        cout<<char(mai+'a')<<endl;
    }
    
	return 0;
}

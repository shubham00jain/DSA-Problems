//https://www.geeksforgeeks.org/write-a-c-program-to-print-all-permutations-of-a-given-string/

void solve(string s, int l, int r, map<string,int>& mp){
    if(l==r){
	//map is used to sort the result
        mp[s] = 1;   
    }
        
    for(int i = l; i<=r; i++){
        swap( s[i],s[l]);
        solve(s,l+1,r,mp );
        swap(s[i],s[l]);
    }
    
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin>>t;
	while(t--){
	    string s;
	    cin>>s;
	    map<string,int> mp;
	    solve(s,0,s.size()-1,mp);
	    for(auto i : mp){
	        cout<<i.first<<" ";
	    }
	    
	    cout<<endl;
	}
	
	return 0;
}

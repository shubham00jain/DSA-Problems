	// use hashmap
  //https://www.geeksforgeeks.org/remove-duplicates-from-a-given-string/
  
  string removeDuplicates(string str) {
	    unordered_map<char,int> mp;
	    string res;
	    for(int i=0;i<str.length();i++){
	        if( mp[str[i]]==0 ){
	            res+=str[i];
	            mp[str[i]]++;
	        }
	    }
	    return res;
	}

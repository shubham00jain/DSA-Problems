// Read this article for constant space solution.
//https://www.geeksforgeeks.org/check-whether-two-strings-are-anagram-of-each-other/ 


bool isAnagram(string a, string b){
    
    if(a.length()!=b.length())
        return 0;
    
    int h1[26] = {0};
    int h2[26] = {0};
    
    for(int i=0;i<a.length();i++){
        h1[ a[i] -'a' ] +=1;    
    }
    
    for(int i=0;i<b.length();i++){
        h2[ b[i] -'a' ]+=1;        
    }
    int flag = 0;
    
    for(int i=0;i<26;i++){
        if(h1[i]!=h2[i]){
            flag = 1;
            break;
        }
    }
    
    if(!flag)
        return 1;
    return 0;
    
}

//https://www.geeksforgeeks.org/program-to-validate-an-ip-address/

string diff(string s, int& i){
    string res;
    if(i<s.size() && s[i]=='.')
        i++;
    while(i<s.size()&&s[i]!='.'){
        res+=s[i];
        i++;
    }
    if(res.empty())
        return "#";
    return res;
}

int valid(string s){
        
    if(s.length()>3)
        return 0;
    
    int n = s.length();
    if( s[0]=='0' && n>1 )
        return 0;
    
    int x = stoi(s) ;
    return (x>=0 && x<=255);
}

int isValid(string s) {
    
    int count = 0;
    
    for(int i=0;i<s.length();i++){
        if(s[i]!='.' && s[i]<'0' || s[i]>'9')
            return 0;
    }
    
    for(int j=0;j<s.length();j++){
        if( s[j]=='.')
            count++;
    }
    if(count!=3)
        return 0;

    int  i =0;
    string a = diff(s,i);
    string b = diff(s,i);
    string c = diff(s,i);
    string d = diff(s,i);
    
    if(a[0]=='#' || b[0]=='#' || c[0]=='#' || d[0]=='#')
        return 0;
        
    if( valid(a) && valid(b) && valid(c) && valid(d)){
        return true;
    }
    else{
        return false;
    }
    
    
}

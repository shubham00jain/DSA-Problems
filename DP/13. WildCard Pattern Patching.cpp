// https://practice.geeksforgeeks.org/problems/wildcard-pattern-matching/1

int solve(string s1, string s2, int x, int y, vector<vector<int>>&dp ){
    
    if(dp[x][y]!=-1)
        return dp[x][y];
    
    if(x == 0 && y == 0)
        return dp[x][y] =  1;
    
    if(x == 1 && s1[x-1] == '*')
        return dp[x][y] = 1;
    
    if(x == 0 && y == 0)
        return dp[x][y] = 0;
    
    if( s1[x-1] == s2[y-1] )
        return dp[x][y] = solve(s1,s2,x-1,y-1,dp);
    
    if( s1[x-1] == '?' )
        return dp[x][y] = solve(s1,s2,x-1,y-1,dp);
        
    else if (s1[x-1] == '*' ){
        int a = solve( s1,s2,x-1,y,dp);
        int b = solve(s1,s2,x,y-1,dp);
        int c = solve(s1,s2,x-1,y-1,dp);
        
        return dp[x][y] = (a || b || c);
        
    }
    
    return dp[x][y] = 0;
    
}


int wildCard(string s1,string s2)
{
    int x = s1.size();
    int y = s2.size();
    
    vector<vector<int>> dp(x+1, vector<int>(y+1, -1) );
    
    
    return solve(s1,s2,x,y,dp);
}

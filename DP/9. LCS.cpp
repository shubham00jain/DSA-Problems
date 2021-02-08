// https://www.youtube.com/watch?v=4Urd0a0BNng&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=19&ab_channel=AdityaVerma
// https://practice.geeksforgeeks.org/problems/longest-common-subsequence-1587115620/1

/*
Approach:
This is a fundamental DP problem. In this we have 3 (1 + 2) choices:
1. Either both the characters of the strings match in which case we should call the function will 1 + s1.length()-1, s2.length()-1.
2. Else they dont match, in which case we will have 2 choices: Either call the function with s1.length()-1 or call the function with s2().length()-1. and we will take max() of 
both of the choices.

Problems similar to this:
1. Longest common substring
2. Print LCS
3. Shortest common supersquence
4. Print SCS
5. Min num of insertion or deletion to make a -> b
6. Largest repeating subsquence
7. length of longest subsqunce of a which is a substring of b.
8. subsequnce pattern matching.
9. count how many a appears as subsqunece in b.
10. longest palindormic subsequnce.
11. longest palindromic substring.
12. count of palindromic substring.
13. min no. of deletion in a string to make it a palindrome.
14. min no. of addition in a string to make it a palindrome.
*/




// Naive recursive solution----------------------------------------
// ----------------------------------------------------------------

int solve(string s1, string s2, int x, int y){
    
    //base
    if(x==0 || y==0)
        return 0;
        
    //equal value    
    if( s1[x-1]==s2[y-1] )
        return 1 + solve(s1,s2,x-1,y-1);
    //not equal
    else{
        // reduce s1    
        int a = solve(s1,s2,x-1,y);
        //reduce s2
        int b = solve(s1,s2,x,y-1);
        return max(a,b);
    }
    
    return 0;
}


int lcs(int x, int y, string s1, string s2){
    return solve(s1,s2,x,y);
}

//-----------------------------------------------------Top Down with DP with memoization-------------
//---------------------------------------------------------------------------------------------------

int solve(string s1, string s2, int x, int y, vector<vector<int>>&dp){
    
    //base
    if(dp[x][y]!=-1)
        return dp[x][y];
        
    if(x==0 || y==0)
        return dp[x][y]=  0;
    
        
    //equal value    
    if( s1[x-1]==s2[y-1] )
        return dp[x][y]= 1 + solve(s1,s2,x-1,y-1,dp);
    //not equal
    else{
        // reduce s1    
        int a = solve(s1,s2,x-1,y,dp);
        //reduce s2
        int b = solve(s1,s2,x,y-1,dp);
        return dp[x][y]= max(a,b);
    }
    
    return dp[x][y]= 0;
}


int lcs(int x, int y, string s1, string s2){
    vector<vector<int>> dp(x+1, vector<int>(y+1, -1) );
    return solve(s1,s2,x,y,dp);
}

// --------------------Bottom up with memoization--------------------------------------

int lcs(int x, int y, string text1, string text2){
        vector<vector<int>> dp(x+1, vector<int>(y+1) );
        
        for(int i=0;i<x+1;i++){
            for(int j=0;j<y+1;j++){
                if(i==0 || j==0)
                    dp[i][j]  = 0;
            }
        }
        
        for(int i=1;i<x+1;i++){
            for(int j=1;j<y+1;j++){
                
                if(text1[i-1]==text2[y-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];                  
                }
                
                else{
                    int a = dp[i-1][j];
                    int b = dp[i][j-1];
                    dp[i][j] = max( a,b );
                }
            }
        }
        return dp[x][y];
}

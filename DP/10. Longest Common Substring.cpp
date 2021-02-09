// https://www.geeksforgeeks.org/longest-common-substring-dp-29/
// https://www.youtube.com/watch?v=HrybPYpOvz0&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=22&ab_channel=AdityaVerma

/*
The bottom up code is somewhat similar to LCS. In this we will make a DP table each of which cell will contain the "the longest common substring including this character".
So, to get the actual result we will have to return the max value in the DP table.
*/

class Solution{
    public:
    
    int longestCommonSubstr (string S1, string S2, int n, int m)
    {
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0) );
        
        for(int i=0;i<n+1;i++){
            for(int j=0;j<m+1;j++){
                if(i==0 || j==0)
                    dp[i][j] = 0;
            }
        }
        
        int res = 0;
        
        for(int i=1;i<n+1;i++){
            for(int j=1;j<m+1;j++){
                
                if( S1[i-1]==S2[j-1] ){
                    dp[i][j] = 1 + dp[i-1][j-1];
                    res = max(res, dp[i][j]);
                }
                
                else dp[i][j] = 0;
            }
        }
        
        for(int i=0;i<n+1;i++){
            for(int j=0;j<m+1;j++){
                cout<<dp[i][j]<<" ";
            }
            cout<<endl;
        }
        
        return dp[n][m];

    }
};

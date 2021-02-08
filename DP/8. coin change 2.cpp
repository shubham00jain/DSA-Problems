// https://leetcode.com/problems/coin-change/submissions/
// https://www.youtube.com/watch?v=I-l6PBeERuc&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=16&ab_channel=AdityaVerma

/*
This is a bit different than other problems. Here we will have to initialize 2 rows.
First row with INT_MAX.
Seecond row with INT_MAX or if the amount is divisible by arr[0] then current_amount/coins[0].
Now this problem becomes a normal unbounded knapsack problem with some minor code diff.
*/


// Bottom up tabulation method--------------------------------------------
//------------------------------------------------------------------------

class Solution {
public:
    
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        if(n==0)
            return -1;
        
        vector<vector<int>> dp(n+1, vector<int>(amount+1, (INT_MAX-1) ) );
        
        for(int i=0;i<n+1;i++){
            for(int j=0;j<amount+1;j++){
                if(i==0)
                    dp[i][j] = INT_MAX;
                if(j==0)
                    dp[i][j] = 0;
            }
        }
          
        for(int j=1;j<amount+1;j++){
            if(j%coins[0]==0)
                dp[1][j] = j/coins[0];
        }
        
        for(int i=2;i<n+1;i++){
            for(int j=1;j<amount+1;j++){
                
                if( coins[i-1]>j )
                    dp[i][j] = dp[i-1][j];
                
                else{
                    int x = 1 + dp[i][j-coins[i-1]];
                    int y = dp[i-1][j];
                    dp[i][j] = min(x,y);
                }
            }
        }
        if(dp[n][amount]== (INT_MAX-1) )
            return -1;
        return dp[n][amount];
    }
};

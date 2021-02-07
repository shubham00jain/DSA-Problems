// https://practice.geeksforgeeks.org/problems/coin-change2448/1
// https://www.youtube.com/watch?v=I4UR2T6Ro3w&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=15&ab_channel=AdityaVerma

/*
Approach:
1. This is same as subset sum. The total sum is the sum and the denominations of the coin are the values inside the subset.
2. The only difference is that any element(or coin) can be taken more than once.
3. So, this is basically count no. of subsets with given sum ( unbounded kanpsack ).

*/

class Solution
{
  public:
  
    long long int solve(int arr[], long long int n, long long int sum, 
    vector<vector<long long int>>&dp ){
        
        //base
        if(sum==0)
            return  dp[n][sum] = 1;
        
        if(n==0)
            return dp[n][sum] =0;
        
        
        if(dp[n][sum]!=-1)
            return dp[n][sum];
    
        //ignore
        if( arr[n-1]>sum ){
            return solve(arr,n-1,sum,dp);
        }
        
        //else
        else{
            long long int a = solve(arr,n,sum-arr[n-1],dp);
            long long int b = solve(arr,n-1,sum,dp);
            return dp[n][sum] =a+b;
        }
        return dp[n][sum] = 0;
    }
    
    long long int count( int S[], int m, int n )
    {
        vector<vector<long long int>> dp(m+1, vector<long long int>(n+1,-1) );
       return solve(S,m,n,dp);
    }
};

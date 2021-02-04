// https://practice.geeksforgeeks.org/problems/subset-sum-problem2014/1#
// https://www.youtube.com/watch?v=UmMh7xp07kY&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=8&ab_channel=AdityaVerma

// Top down recursive memoized version---------------------------------------------------
// --------------------------------------------------------------------------------------

class Solution{
public:
    int solve(int n, int arr[], int sum, vector<vector<int>>& dp)
    {
        if(n<0)
            return 0;       
        if(sum==0){
            dp[n][sum] = 1;
            return dp[n][sum];
        }
        if(dp[n][sum] !=-1)
            return dp[n][sum];
        if( arr[n]>sum ){
            dp[n][sum] = solve(n-1, arr,sum,dp);
            return dp[n][sum];  
        } 
        else{
            if( solve(n-1,arr,sum-arr[n],dp) || solve(n-1,arr,sum,dp) ){
                dp[n][sum] = 1;
                return dp[n][sum]; 
            }
        }
        return dp[n][sum] = 0;
    }
    int equalPartition(int N, int arr[])
    {
        int sum = accumulate(arr,arr+N,0);
        if(sum%2!=0)
            return 0;
        else sum = sum/2;
        vector<vector<int>> dp(N+2, vector<int>(sum+2, -1) );
        return solve(N-1,arr,sum, dp);
    }
};

//Bottom up iterative-------------------------------------------------------------


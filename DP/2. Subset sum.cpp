// Given a get of numbers check if any combination of numbers can sum up to the given number 'B'.
// https://www.interviewbit.com/problems/subset-sum-problem/
// https://www.youtube.com/watch?v=_gPcYovP7wc&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=7&ab_channel=AdityaVerma

/*
Approach:
Almost an identical question to kanpsack. We need to choose some integers and fill up a "knapsack" (which is in this case, a sum). Figure the rest yourself.

*/


// Recurvise appraoch

//helper fxn
int subset(int* arr, int n, int sum, vector<vector<int>> &dp ){
    
    
    if(sum==0)
        return dp[n][sum] =  1;
    
    if(n<0)
        return dp[n][sum] = 0;

    if(arr[n]>sum)
        return dp[n][sum] = subset(arr,n-1,sum);
    
    if( subset(arr,n-1,sum-arr[n] ) || subset(arr,n-1,sum) )
        return dp[n][sum] = 1;
        
    return dp[n][sum] = 0;
}
 
//fxn called by the main fxn 
int solve(int* A, int n1, int B) {
    return subset(A,n1-1,B);
}

//top down recursive apprach with memoization --------------------------------------------------
//-----------------------------------------------------------------------------------


int subset(int* arr, int n, int sum){
    
    
    if(sum==0)
        return 1;
    
    if(n<0)
        return 0;

    if(arr[n]>sum)
        return subset(arr,n-1,sum);
    
    if( subset(arr,n-1,sum-arr[n] ) || subset(arr,n-1,sum) )
        return 1;
        
    return 0;
}
 
int solve(int* A, int n1, int B) {
    vector<vector<int>> dp(n1+1, vector<int>(B+1,-1)  );
    return subset(A,n1-1,B, dp);
}

//


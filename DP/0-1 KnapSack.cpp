//https://www.geeksforgeeks.org/0-1-knapsack-problem-dp-10/

int dp[1002][1002];
int solve(int W, int wt[], int val[], int n){
    
    if(n<0 || W==0)
        return 0;
    
    if(dp[n][W]!=-1)
        return dp[n][W];

    if(wt[n] > W){
        dp[n][W] = solve(W,wt,val,n-1);
        return dp[n][W];
    }
    else{
        dp[n][W] = max( val[n]+solve(W-wt[n],wt,val,n-1), solve(W,wt,val,n-1) );
        return dp[n][W];
    }
    
}

int knapSack(int W, int wt[], int val[], int n) 
{ 
    memset(dp,-1,sizeof(dp));
    int res = 0;
    res = solve(W,wt,val,n-1);
    return res;
}


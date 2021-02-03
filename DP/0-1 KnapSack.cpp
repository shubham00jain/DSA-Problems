//https://www.geeksforgeeks.org/0-1-knapsack-problem-dp-10/

int dp[1002][1002];
int solve(int i, int W, int wt[], int val[], int n, int ans){
    
    int a = 0;
    int b = 0;
    int lmax = 0;
    
    if(dp[i][W]!=-1)
        return dp[i][W];
    
    if(W>0 && i<= n-1 ){
        if(W>=wt[i])
            a = solve(i+1,W-wt[i],wt,val,n,ans+val[i]);
        b = solve(i+1,W,wt,val,n,ans);
        lmax = max(a,b);
    }
    
    return dp[i][W] = max(ans,lmax);
}

int knapSack(int W, int wt[], int val[], int n) 
{ 
    memset(dp,-1,sizeof(dp));
    int res = 0;
    res = solve(0,W,wt,val,n,res);
    return res;
}

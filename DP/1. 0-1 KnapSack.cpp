// https://www.geeksforgeeks.org/0-1-knapsack-problem-dp-10/

// https://www.youtube.com/watch?v=kvyShbFVaY8&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=3&ab_channel=AdityaVerma
// https://www.youtube.com/watch?v=fJbIuhs24zQ&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=4&ab_channel=AdityaVerma
// https://www.youtube.com/watch?v=ntCGbPMeqgg&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=5&ab_channel=AdityaVerma

/*
To solve every DP approach a general approach can be follwed:
1. Write its recursive solution.
2. Memoize that recursive solution.
3. (Optional: for bottom up approach)Make a bottom-up approach from the recursive approach.

To know if any question is of DP(or recursion in that matter), try to find these things:
1. Choices
2. Optimal result
3. (In case of DP) Overlapping subproblem. This can ONLY happen if we have more than 1 recursive fxn calls.

Watch the videos again, for further reference.
*/



// using top down recursive approach with memoization

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

//-----------------using bottom-up iterative method or Real DP---------------------

int knapSack(int W, int wt[], int val[], int n) 
{ 
    int dp[n+1][W+1];
    
    for(int i=0;i<n+1;i++){
        for(int j=0;j<W+1;j++){
            if(i==0 || j==0)
                dp[i][j] = 0;
        }
    }
    
    for(int i=1;i<n+1;i++){
        for(int j=1;j<W+1;j++){
            if( wt[i-1] <= j){
                int a = val[i-1] + dp[i-1][j-wt[i-1]];
                int b = dp[i-1][j];
                dp[i][j] =  max( a, b );
            }
            
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[n][W];
}


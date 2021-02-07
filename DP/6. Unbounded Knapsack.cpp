// https://practice.geeksforgeeks.org/problems/knapsack-with-duplicate-items4201/1
// https://www.youtube.com/watch?v=aycn9KO8_Ls&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=13&ab_channel=AdityaVerma


/*
This problem is same as the 0-1 Knapsack problem with the only difference that any item can be taken more than once to maximize the profit.
So, to maximize the profit the only thing which needs to be changed is that an item is only proceessed when it is no longer added in the array i.e. if
the item is added in the array we call the function again on the same time. This is done to take this item as long as its possible to maximize profit.

Problems similar to this:
1. Rod cutting 
2. Coin change 2
3. Coin change 3
4. max ribbon cut

*/

//--------------------Naive recursive approach-----------------------------
//-------------------------------------------------------------------------
class Solution{
public:
    
    int solve(int val[], int wt[], int w, int n){
        
        if(n==0 || w==0)
            return 0;
        
        if( wt[n-1] > w ){
            return solve(val,wt,w,n-1);
        }
        else{
            return max( ( val[n-1]+solve(val,wt,w-wt[n-1],n) ), solve(val,wt,w,n-1) );
        }
        return 0;
    }
    
    
    int knapSack(int N, int W, int val[], int wt[])
    {
       return solve(val,wt,W,N);
    }
};

//-------------------Recursive solution with memoization----------------
//----------------------------------------------------------------------


class Solution{
public:
    
    int solve(int val[], int wt[], int w, int n, vector<vector<int>>&dp){
        
        if(n==0 || w==0)
            return dp[n][w] = 0;
        
        if(dp[n][w]!=-1)
            return dp[n][w];
            
        if( wt[n-1] > w ){
            return dp[n][w] = solve(val,wt,w,n-1,dp);
        }
        else{
            return dp[n][w] = max( ( val[n-1]+solve(val,wt,w-wt[n-1],n,dp) ), 
            solve(val,wt,w,n-1,dp) );
        }
        return dp[n][w] = 0;
    }
    
    
    int knapSack(int N, int W, int val[], int wt[])
    {
        vector<vector<int>> dp(N+1, vector<int>(W+1, -1));
       return solve(val,wt,W,N, dp);
       
    }
};


//---------------------Bottom up tabulation-------------------------
//------------------------------------------------------------------

class Solution{
public:
    

    int knapSack(int N, int W, int val[], int wt[])
    {
        
        vector<vector<int>> dp(N+1, vector<int>(W+1, -1));
       
       for(int i=0;i<N+1;i++){
           
           for(int j=0;j<W+1;j++){
               if(i==0 || j==0)
                    dp[i][j] = 0;
           }
       }
       
       for(int i=1;i<N+1;i++){
           
           for(int j=1;j<W+1;j++){
               
               if(wt[i-1]>j)
                    dp[i][j] = dp[i-1][j];
                    
                else{
                    int a = val[i-1] + dp[i][j-wt[i-1]];
                    int b = dp[i-1][j];
                    dp[i][j] = max(a,b);
                }
           }
       }
       
       return dp[N][W];
       
    }
};


// https://practice.geeksforgeeks.org/problems/minimum-sum-partition3317/1#
// https://www.youtube.com/watch?v=-GtpxG6l_Mc&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=10&ab_channel=AdityaVerma

/*
Approach:

Similar to Subset sum. We have to minimize two subsets sum diffrence i.e. min(S2 - S1). Also S2 = total_sum - s1.
So, now the eq becomes min(total_sum - 2*s1). Now we just have to find a value of S1 so that the eq becomes minimum.
To do that, we can check all the possible subset sums one by one and use the one which is minimum. 
Now, we don't have to check "all" the subset sums because as the value of S1 increases the value of S2 decrases. So, 
we have to find the greatest subset sum upto half of the total_sum of given array so that the other half will be S2
and the diff will be minimum. To do this, when we construct a dp table in subset sum problem the last row gives us
all the subset sum which are possible using all the elements in the array.

In other words, find subset sum of total_sum -> extract last row -> find the max number which is less than total_sum/2 ->
put that number equal to s1 -> return (total_sum - 2*s1)
*/


// bottom up DP solution ---------------------------------------------------------------
// -------------------------------------------------------------------------------------
class Solution{

	public:
	int minDiffernce(int arr[], int n) 
	{ 
        double sum = accumulate(arr,arr+n,0);
        double n2 = n;
        
        vector<vector<int>> dp(n2+1 , vector<int>(sum+1,-1) );
        
        for(int i=0;i<=n2;i++){
            for(int j=0;j<=sum;j++){
                if(i==0)
                    dp[i][j] = 0;
                if(j==0)
                    dp[i][j] = 1;
            }
        }
        
        
        for(int i=1;i<=n2;i++){
            for(int j=1;j<=sum;j++){
                
                if( arr[i-1] >j )
                    dp[i][j] = dp[i-1][j];
                    
                else{
                    if( dp[i-1][j-arr[i-1]] || dp[i-1][j] )
                        dp[i][j] = 1;
                    else dp[i][j] = 0;
                }
            }
        }
        
        
        int a = 0;
        sum/=2;
        for(int i=1;i<=sum;i++){
            if(dp[n2][i]==1)
                a = i;
        }
        
        int sum2 = accumulate(arr,arr+n,0);
        return (sum2 - a*2);
	} 
};

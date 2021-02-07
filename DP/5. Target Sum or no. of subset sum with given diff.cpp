// https://leetcode.com/problems/target-sum/submissions/
// https://www.youtube.com/watch?v=ot_XBHyqpFc&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=11&ab_channel=AdityaVerma
// https://www.youtube.com/watch?v=Hw6Ygp3JBYw&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=12&ab_channel=AdityaVerma




// naive recursive solution------------------------------------------------------------
// (This is not DP, but it works on leetcode)------------------------
// This can be optimized with memoization

class Solution {
public:
    
    int solve(vector<int>& vec, int t, int n, int sum){
        
        if( n==0 && sum==t)
            return 1;
        
        else if( n==0 && sum!=t)
            return 0;
        //+
        int x = solve(vec,t,n-1,sum+vec[n-1]);
        
        //-
        int y = solve(vec,t,n-1,sum-vec[n-1]);
        
        return x+y;
    }
    
    int findTargetSumWays(vector<int>& nums, int S) {
        int n = nums.size();
        return solve(nums,S,n,0);
    }
};


// recusion with memoization
// We use 1000 because it is given as the uppermost contraint on leetcode
// This is not very efficient and one other way of doing this can be
// to make our "sum" equal to the array sum. Now, for + case do nothing to the "sum"
// and for the - case subtract the value from the sum. This will ensure that the sum
// is always greater than equal to 0 and then it can be used inside the DP table.

public class Solution {
    int count = 0;
    public int findTargetSumWays(int[] nums, int S) {
        int[][] memo = new int[nums.length][2001];
        for (int[] row: memo)
            Arrays.fill(row, Integer.MIN_VALUE);
        return calculate(nums, 0, 0, S, memo);
    }
    public int calculate(int[] nums, int i, int sum, int S, int[][] memo) {
        if (i == nums.length) {
            if (sum == S)
                return 1;
            else
                return 0;
        } else {
            if (memo[i][sum + 1000] != Integer.MIN_VALUE) {
                return memo[i][sum + 1000];
            }
            int add = calculate(nums, i + 1, sum + nums[i], S, memo);
            int subtract = calculate(nums, i + 1, sum - nums[i], S, memo);
            memo[i][sum + 1000] = add + subtract;
            return memo[i][sum + 1000];
        }
    }
}


// This doesn't work but the logic behind this is very important. 
// We can see this in way that we have to divide the array in two subsets S1 and S2 such that their diff is equal to a given difference S.
// Now Target sum problem is broken down into count no of subset with given difference. This can be done easily by observing:
// S1 - S2 = diff  ----- eq.1
// S1 + S2 = total_sum -----------eq.2
// solve 1 and 2 we get
// S1 = ( diff + t ) / 2
// Now the problem further breaks down into find subset with given sum (S1) int the array which is essentially the subset sum problem!

class Solution {
public:
    
    int solve(vector<int>vec, int sum, int n, vector<vector<int>>&dp){
        
        //base
        if (sum==0)
            return dp[n][sum] = 1;
        if(n==0)
            return dp[n][sum] = 0;

        if(dp[n][sum]!=-1)
            return dp[n][sum];
        
        if(vec[n-1]>sum){
            return dp[n][sum] = solve(vec,sum,n-1,dp);
        }
        
        else{
            int a = solve(vec, sum - vec[n-1], n-1,dp);
            int b = solve(vec, sum, n-1,dp);
            return dp[n][sum] = a + b;
        }
        dp[n][sum] = 0;
    }
    
    int findTargetSumWays(vector<int>& nums, int S) {
        int n = nums.size();
        int total = accumulate(nums.begin(),nums.end(),0 );
        double sum = (total+S)/2.0;
        sort(nums.begin(),nums.end());
        
        vector<vector<int>> dp(n+1, vector<int>(sum+1,-1));

        if(ceil(sum)!=sum )
            return 0;
        
        int count = 0;
        for(int i : nums){
            if(i==0)
                count++;
        }
        
        if(count) return solve(nums,sum,n,dp)* pow(2,count); 
        
        else return solve(nums,sum,n,dp);
        
    }
};

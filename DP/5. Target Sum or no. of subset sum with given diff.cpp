// https://leetcode.com/problems/target-sum/submissions/
// https://www.youtube.com/watch?v=ot_XBHyqpFc&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=11&ab_channel=AdityaVerma
// https://www.youtube.com/watch?v=Hw6Ygp3JBYw&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=12&ab_channel=AdityaVerma




// naive recursive solution------------------------------------------------------------
// (This is not DP, but it works on leetcode : Don't use this!)------------------------


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


// bottom up approach using DP


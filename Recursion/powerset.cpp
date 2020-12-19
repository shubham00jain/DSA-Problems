/*
The idea is to first make a recursive tree. From that it is evident that We have 2 choices either to include an element or don't include an element.
This tells us that we will have 2 fxn calls. One in which we have included the element and other in which we haven't included the element. Finally return after we have 
the length of input becomes 0.
*/

class Solution {
public:
    
    void solve(vector<vector<int>>&res, vector<int>nums, vector<int>op){
        if(nums.size()==0){
            res.push_back(op);
            return;
        }
        
        vector<int> op1 = op;
        vector<int> op2 = op;
        
        op2.push_back(nums[0]);
        nums.erase(nums.begin());
        
        solve(res,nums,op1);
        solve(res,nums,op2);
        return;
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        
        vector<vector<int>> res;
        vector<int> op;
        solve(res, nums, op);
        return res;
    }
};

//--------------------------------------------Same approach but we don't have to erase anything from Input and instead we use a pointer to assume that we have erased that
//part of the input-------------------------------------------------------------------------------------------------------------------------------------------------------

    void solve(vector<vector<int>>&res, vector<int>nums, vector<int>op, int i){
        if(nums.size()==i){
            res.push_back(op);
            return;
        }
        solve(res,nums,op,i+1);
        op.push_back(nums[i]);
        solve(res,nums,op,i+1);
        return;
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        
        vector<vector<int>> res;
        vector<int> op;
        int i = 0;
        solve(res, nums, op, i);
        return res;
    }
};

Time : O(2^n)

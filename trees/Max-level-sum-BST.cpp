//https://leetcode.com/problems/maximum-level-sum-of-a-binary-tree/

class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> q;
        if(!root)
            return 0;
        q.push(root);
        q.push(NULL);
        int sum=0;
        int global = INT_MIN;
        int lv=0;
        int maxlv=0;
        
        while(!q.empty()){
            TreeNode * curr = q.front();
            q.pop();
            if(curr){
                sum+=curr->val;
                if(curr->left)
                    q.push(curr->left);
                if(curr->right)
                    q.push(curr->right); 
            }
               
            if(!curr){
                lv+=1;
                if(!q.empty())
                    q.push(NULL);
                if(sum>global){
                    global = sum;
                    maxlv = lv;
                }
                sum=0;
            }
        }
        
        return maxlv;
        
    }
};

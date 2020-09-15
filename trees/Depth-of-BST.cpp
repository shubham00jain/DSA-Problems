//https://leetcode.com/problems/diameter-of-binary-tree/submissions/

class Solution {
public:
    int maxs;
    int dbt(TreeNode *root)
    {
        if(!root)return 0;
        int left=dbt(root->left);
        int right=dbt(root->right);
        maxs=max(maxs,left+right);
        return max(left,right)+1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        maxs=0;
        dbt(root);
        return maxs;
    }
};

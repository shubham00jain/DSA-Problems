// given a binary Tree swap left and right nodes of every node.
// https://leetcode.com/problems/invert-binary-tree/

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(!root)
            return root;
        
        TreeNode * temp = NULL;
        temp = root->left;
        root->left = root->right;
        root->right = temp;
        if(root->left)
            invertTree(root->left);
        if(root->right)
            invertTree(root->right);
        
        return root;
        
        
    }
};

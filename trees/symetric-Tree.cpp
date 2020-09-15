//  https://leetcode.com/problems/symmetric-tree/submissions/

bool find(TreeNode* root1, TreeNode* root2){
        if(!root1 && !root2)
            return 1;
        if(!root1 || !root2)
            return 0;
        if(root1->val != root2->val)
            return 0;
        else return find(root1->left, root2->right) && find(root1->right, root2->left);
    }
    
    bool isSymmetric(TreeNode* root){
        if(!root)
            return 1;
        return find(root->left, root->right);
    }

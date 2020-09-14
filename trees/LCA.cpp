//A imp question
//https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/submissions/

class Solution {
public:
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==p || root==q)
            return root;
        
        if(root==NULL)
            return NULL;
        
        TreeNode* x1 =  lowestCommonAncestor(root->left,p,q);
        TreeNode* x2 = lowestCommonAncestor(root->right,p,q);
        
        if(!x1)
            return x2;
        if(!x2)
            return x1;
        
        return root;      
    }
};

//--another harder way
//create a container(stack prefreably) and then store the path from root to the given node in both cases
//now reverse the container and then pop out top the elements one by one until one of the stack becomes empty or the top elements become unequal.

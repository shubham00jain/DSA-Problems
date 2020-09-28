// https://leetcode.com/problems/flatten-binary-tree-to-linked-list/submissions/
// https://www.geeksforgeeks.org/flatten-a-binary-tree-into-linked-list/


void flatten(TreeNode* root){
        if(root==NULL || root->left == NULL && root->right == NULL)
            return;
        if(root->left!=NULL){
            flatten(root->left);
            TreeNode *temp = new TreeNode;
            temp = root->right;
            root->right = root->left;
            root->left = NULL;
            TreeNode *t = root;
            while(t->right){
                t = t->right;
            }
            t->right = temp;
        }
        flatten(root->right);
    }

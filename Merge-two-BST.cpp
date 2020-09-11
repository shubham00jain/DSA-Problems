// add and return root node value of 2 BSTs if they exists else return the node which exists.
// https://leetcode.com/problems/merge-two-binary-trees/
class Solution {
public:
    void solve(TreeNode *t1, TreeNode *t2, TreeNode *p1, TreeNode *p2){
        if(t1&&t2){
            t1->val += t2->val;
            solve(t1->left, t2->left, t1,t2);
            solve(t1->right, t2->right, t1, t2);
            return;
        }
        if( !t1 && t2){
            if(p1->left == NULL && p2->left){
                p1->left = t2;
            }
            else{
                p1->right = t2;
            }
            return;
        }
        return;
    }
    
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if(t1 && t2){
            t1->val +=t2->val;
            solve(t1->left, t2->left, t1,t2);
            solve(t1->right, t2->right, t1,t2);
            return t1;
        }
        else if(!t1 && t2){
            return t2;
        }
        return t1;
    }
};

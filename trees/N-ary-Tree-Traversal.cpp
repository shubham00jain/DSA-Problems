// traverse a N-ary Tree
// https://leetcode.com/problems/n-ary-tree-postorder-traversal/
// it is defined as --->>>
/*
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/


class Solution {
public:
    vector<int> ans;
    vector<int> postorder(Node* root) {
        // if(root->children.empty())
        //     ans.push_back(root->val);
        if(root){
            for(int i=0;i<root->children.size();i++){
            postorder(root->children[i]);
                }
            ans.push_back(root->val);
    
        }
        return ans;
            
    }
};








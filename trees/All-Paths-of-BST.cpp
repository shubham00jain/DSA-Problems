// https://leetcode.com/problems/binary-tree-paths/
class Solution {
public:
    
    void addtostr(vector<string>& res, stack<int> s){
        vector<int> x;
        while(!s.empty()){
            x.push_back(s.top());
            s.pop();
        }
        reverse(x.begin(),x.end());
        string str = "";
        
        for(int i=0;i<x.size();){
            str+=to_string(x[i]);
            i+=1;
            if(i<x.size())
                str+="->";
        }
        res.push_back(str);
    }
    
    void solve(TreeNode* root, stack<int>&s, vector<string>& res){
        if(!root)
            return;
        
        s.push(root->val);
        if(!root->left && !root->right){
            addtostr(res,s);
            s.pop();
            return;
        }
        
        solve(root->left,s,res);
        solve(root->right,s,res);
        s.pop();
        return;
        
    }
    
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        stack<int> s;
        if(!root)
            return res;
        solve(root,s,res);
        return res;
    }
    
};

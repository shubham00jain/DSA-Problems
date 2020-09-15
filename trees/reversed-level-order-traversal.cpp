//https://www.geeksforgeeks.org/reverse-level-order-traversal/
//https://practice.geeksforgeeks.org/problems/reverse-level-order-traversal/1

vector<int> reverseLevelOrder(Node *root)
{
    vector<int> res;
    stack<int> s;
    queue<Node*> q;
    
    if(!root)
        return res;
        
    q.push(root);
    
    while(!q.empty()){
        Node * curr = q.front();
        q.pop();
        s.push(curr->data);
        if(curr->left)
            q.push(curr->left);
        if(curr->right)
            q.push(curr->right);
    }
    
    while(!s.empty()){
        res.push_back(s.top());
        s.pop();
    }
    return res;
}

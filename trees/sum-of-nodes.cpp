// https://practice.geeksforgeeks.org/problems/sum-of-binary-tree/1
//
long int sumBT(Node* root)
{
    if(!root)
        return 0;
    
    return sumBT(root->left) + sumBT(root->right) + root->key;
}

//--------------------------------------------------------------------
//------------------------USING QUEUE (WITHOUT RECURSION)-------------
//--------------------------------------------------------------------

long int sumBT(Node* root)
{
    if(!root)
        return 0;
    
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    long int sum = 0;
    
    while(!q.empty()){
        Node * curr = q.front();
        q.pop();
        if(curr){
            sum += curr->key;
            if(curr->left)
                q.push(curr->left);
                
            if(curr->right)
                q.push(curr->right);
        }
            
        if(!curr){
            if(!q.empty()){
                q.push(NULL);
            }
        }
    }
    return sum;
}

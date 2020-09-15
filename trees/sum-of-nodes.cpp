// https://practice.geeksforgeeks.org/problems/sum-of-binary-tree/1
//
long int sumBT(Node* root)
{
    if(!root)
        return 0;
    
    return sumBT(root->left) + sumBT(root->right) + root->key;
}

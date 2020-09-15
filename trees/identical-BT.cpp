// https://practice.geeksforgeeks.org/problems/determine-if-two-trees-are-identical/1
// https://www.geeksforgeeks.org/write-c-code-to-determine-if-two-trees-are-identical/
void inorder(Node* root, vector<int> & vec){
    if(root){
        inorder(root->left, vec);
        vec.push_back(root->data);
        inorder(root->right,vec);
        return;
    }
    return;
}

bool isIdentical(Node *r1, Node *r2)
{
    vector<int> vec1,vec2;
    inorder(r1, vec1);
    inorder(r2, vec2);
    return vec1==vec2;
}

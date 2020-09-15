/*
A tree is a special type of graph, so it typically has 2 types of traversal:
1. DFS - access the nodes while going through depth of the tree.
2. BFS - access the nodes while going thorough breadth of the tree. 

In trees DFS has three types:
1. Inorder
2. Preorder
3. Postorder

*/

//--------------------DFS using recursion---------------------------

void inorder( node * root){
 if(node!=NULL){
   inorder(root->left);
   cout<<root->data;
   inorder(root->right);
 }
}


void preorder( node * root){
 if(node!=NULL){
   cout<<root->data;
   preorder(root->left);
   preorder(root->right);
 }
}


void postorder( node * root){
 if(node!=NULL){
   preorder(root->left);
   preorder(root->right);
   cout<<root->data;
 }
}




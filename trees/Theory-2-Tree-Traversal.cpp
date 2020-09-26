/*
A tree is a special type of graph, so it typically has 2 types of traversal:
1. DFS - access the nodes while going through depth of the tree.
2. BFS - access the nodes while going thorough breadth of the tree. 

In DFS we recursively call for the children the the root and then take decision for the last node.
In other words we build our solution from the very bottom to the very top of the tree, return all the worked values the from nodes to their respective roots and fianlly to the
very first root.



In trees DFS has three types:
1. Inorder
2. Preorder
3. Postorder

In Level order Traversal we take a queue of node* elements and push the root value in the queue and then iteratively check if the queue empty and if its not then we pop the 
first element of the queue and prcoess it and then push its left and right child value(if they exist) into the queue.
To get an output where each level is separted, push a NULL value after pushing the root value and when root pops out of the queue check if the queue is empty or not, 
if its not empty push a NULL inside a queue again. We are doing this beacuse if the queue is not empty this means that we still have to explore some nodes and we are pushing
NULL inside it because after a NULL is reached we can certainly say that the next level is complety pushed into the queue.(see code)

*/

//--------------------DFS using recursion---------------------------

void inorder( node * root){
 if(node!=NULL){
   inorder(root->left); // call left child
   cout<<root->data; // work on data when the leaf node is reached for left call
   inorder(root->right); // call right child 
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


//----------------------BFS using Queue-------------------------


vector<int> levelOrderTraversal{node * root}{

 queue<node *> q;
 q.push(root);
 vector<int> res;
 
 while(!q.empty()){
    node * curr = q.front();
    res.push(curr->val);
  q.pop();
  if(curr->left)
     q.push(curr->left);
  if(curr->right)
     q.push(curr->right);
 }
 
 return res;
}


//get the levels seprated by -1 in the result
// or levels seprated by NULL
// another way to do this is to use 2 queues Qp and Qc and push all the children in the Qc and check for while(Qp isnotempty and Qc isnotempty)
vector<int> levelOrderTraversal{node * root}{

 queue<node *> q;
 q.push(root);
 queue<int> lor;
 q.push(NULL);
 
 while(!q.empty()){
   
  node * curr = q.front();
  q.pop();
  res.push(curr);
  
  if(curr){
   if(curr->left)
     q.push(curr->left);
  if(curr->right)
     q.push(curr->right);
  }
  
  if(!curr){
     if (!q.empty()){
          q.push(NULL);
      }  
  }
  
 }
 
 return res;
}




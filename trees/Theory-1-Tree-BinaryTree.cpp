/*
A tree is a non-linear data structure. It is often termed as a "hierarchical or recursive data structure".
In graph thoery, A tree is a directed acyclic graph (DAG).
It is made up of a user-defined class/ structure.
Most common tree is binary tree in which each node can have max 2 children.
The data members of a typical BT are:
1. data value
2. left child pointer 
3. right child pointer
Strict Binary tree - each node has exactly 0 or 2 children.
Complete Binary tree- When making the level wise array(queue) of BT, there is no empty space in between.
Full Binary tree- A tree in which each node has 2 children, except the leaf nodes.

There are mainly 2 types of tree traversal.
1. DFS - going along the depth of the tree while following some common rule. Its general sub-types are: Pre-order(Root,L,R), In-order(L,Root,Right), Post-order(Left,Right,Root).
2. BFS - going along the breath of the tree while following some common rule.
*/

//------------------Tree using structure----------------------------------
//                             1
//                          /    \
//                         2      3
//                       /   \   /  
//                       4   5  6

#include<bits/stdc++.h>
using namespace std;

struct Node{
  int data;
  Node * left = NULL;
  Node * right = NULL;
}

Node * newNode(int val){
  Node * temp = new Node;
  temp->data = val;
}

int main(){
    Node * root = newNode(1);
     root->left = newNode(2);
     root->right = newNode(3);
     root->left->left = newNode(4);
     root->left->right = newNode(5);
     root->right->left = newNode(6);
    return 0;
}


//---------- "Binary" Tree using Class------------------------------
//------------------------------------------------------------------
//                            10
//                          /    \
//                         3      20
//                       /       /   \
//                       4     16     30

#include<bits/stdc++.h>
using namespace std;

struct node{
  int data;
  node* left = NULL;
  node* right = NULL;
};

class bTree{
  
  public:
  node * root;
  bTree(){
    root = NULL;
  };
  void insert(int key);
  int isEmpty(){ return root== NULL; };
  void printbTreein(node * temp);
  void printbTreepre(node * temp);
  void printbTreepost(node * temp);
  
};

void bTree::insert(int key){
  node *p;
  p = new node;
  p->data = key;

  if(root==NULL)
    root = p;

  else{

    node * temp = root;
    node * parent = root;

    while(temp!=NULL){
        parent = temp;
        if(key > temp->data)
          temp = temp->right;
        else
          temp = temp->left;
    }
    if(temp == parent->left)
      parent->left = p;
    else
      parent->right = p;

  }
}

void bTree::printbTreein(node * temp){
  if(temp == NULL)
    return;
  printbTreein(temp->left);
  cout<<temp->data<<" ";
  printbTreein(temp->right);

}


void bTree::printbTreepre(node * temp){
  if(temp == NULL)
    return;
  cout<<temp->data<<" ";
  printbTreepre(temp->left);
  printbTreepre(temp->right);

}

void bTree::printbTreepost(node * temp){
  if(temp == NULL)
    return;
  printbTreepost(temp->left);
  printbTreepost(temp->right);
  cout<<temp->data<<" ";

}

int main(){

  bTree t1;
  t1.insert(10);
  t1.insert(3);
  t1.insert(20);
  t1.insert(16);
  t1.insert(4);
  t1.printbTreein(t1.root);
  cout<<endl;
  t1.printbTreepre(t1.root);
  cout<<endl;
  t1.printbTreepost(t1.root);
  cout<<endl;

  return 0;
}
    
  


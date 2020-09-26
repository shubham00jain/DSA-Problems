/*
Algorithm:
1. traverse the tree in in-order and store in a array.
2. sort the final array.
2. Now traverse the tree again in postorder and replace root value with respective array values.
This works beacause the array is sorted!
https://www.geeksforgeeks.org/initialize-a-vector-in-cpp-different-ways/
*/

void inorder(TreeNode* root, vector<int> &vec){
   if(root){
    inorder(root->left, vec);
    vec.push_back(root->val, vec);
    inorder(root->right, vec);
   }
}

void solve(TreeNode* root, vector<int> vec, int i){
      if(root){
        solve(root->left, vec, i);
        solve(root->right, vec, i);
        root->data = vec[i];
        i++;
      }
}


TreeNode* BSTtoMAXH(TreeNode* root){
  vector<int> sorted;
  inorder(root,sorted);
  solve(root,sorted,0);
  return root;
}

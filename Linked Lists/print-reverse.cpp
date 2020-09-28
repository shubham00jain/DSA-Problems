/*
Algorithm:
Recursive move to the end of the Lineked List and then start printing from the end.
This will also take a O(n) System stack space so other way is to store it in a container and then print from the end.
*/

void solve(ListNode *root){
  if(root)
    return;
  solve(root->next);
  cout<<root->val;
}

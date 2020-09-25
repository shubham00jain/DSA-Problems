void solve(Node* head){
  if(!head)
    return;
  solve(head->next);
  cout<<(head->data);
  return;
}

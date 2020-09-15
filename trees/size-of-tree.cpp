int getSize(Node* node)
{
    if(!node)
        return 0;
        
    int l = getSize(node->left);
    int r = getSize(node->right);
   
   return l+r+1;
  
   
}

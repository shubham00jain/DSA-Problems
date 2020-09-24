//

// iterative solution

ListNode* reverseList(ListNode* head) {
        ListNode *p1,*p2;
        p1 = NULL;
        p2 = head;
        
        while(p2!=NULL){
            ListNode *p3 = p2->next;
            p2->next = p1;
            p1 = p2;
            p2 = p3;
        }

        return p1;
        
    }
    
 // recursive solution
 
 ListNode* solve(ListNode* head){
  if(head==NULL || head->next == NULL) 
      return head;
  ListNode *p = solve(head->next);
  p->next = head;
  return p;
 }

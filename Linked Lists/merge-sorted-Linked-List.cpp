

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *p1 = l1, *p2 = l2, *k = new ListNode(-1);
        ListNode *h3 = k;
        
        while(p1&&p2){
            if(p1->val<=p2->val){
                k->next = p1;
                p1 = p1->next;
            }
            else{
                k->next = p2;
                p2 = p2->next;
            }
            k = k->next;
        }
        
        if(p1){
            k->next = p1;
        }
        if(p2){
            k->next = p2;
        }
        
        return h3->next;
        
    }

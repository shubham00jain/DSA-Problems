//https://leetcode.com/problems/odd-even-linked-list/submissions/
 ListNode* oddEvenList(ListNode* head) {
        if(!head)
            return head;
        
        ListNode *p = head;
        ListNode *q = head->next;
        ListNode *head2 = q;
        
        while(p && p->next && q && q->next){
            ListNode *t1 = p->next->next, *t2 = q->next->next;
            p->next = t1;
            q->next = t2;
            p = t1;
            q = t2;
        }
        
        p->next = head2;
        return head;
        
    }

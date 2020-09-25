  //https://leetcode.com/problems/middle-of-the-linked-list/
  
  ListNode* middleNode(ListNode* head) {
        ListNode *slow = head, *fast=head;
        if(!head)
            return head;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
        
    }

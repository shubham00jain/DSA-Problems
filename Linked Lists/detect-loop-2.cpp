// https://leetcode.com/problems/linked-list-cycle-ii/submissions/

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *fast = head, *slow = head;
        
        if(!head)
            return NULL;
        
        if(!fast->next)
            return NULL;
        
        while(fast && slow && fast->next){
            fast = fast->next->next;
            slow = slow->next;

            if(fast==slow){
                break;
            }
        }
        
        if(slow!=fast)
            return NULL;

        slow = head;
        
        while(fast!=slow){
                fast = fast->next;
                slow = slow->next;
        }
        return slow;

    }
};

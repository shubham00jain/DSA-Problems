/* Two ways :
1. Use a map and store the results while traversing the list and check if curr element is present in the list or not.
2. Use fast pointer and slow pointer. Increment fast pointer by 2 addresses and slow by one address.
https://leetcode.com/problems/linked-list-cycle/solution/
*/


//FAST pointer & Slow pointer
class Solution {
public:
    bool hasCycle(ListNode *head){
        
        if(!head)
            return false;
        
        ListNode* fast = head->next, *slow = head;
        if(fast==slow)
            return true;
        
        while(fast){
            if(fast==slow)
                return true;
            else if(fast->next){
                fast = fast->next->next;
                slow = slow->next;
            }
            else{
                return 0;
            }
        }
        
        return 0;

    }
};

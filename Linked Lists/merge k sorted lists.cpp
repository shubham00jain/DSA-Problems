// We merge 2 lists at a time and then take the output and merge it with the next list.

class Solution {
public:
    ListNode* merge(ListNode*l1, ListNode*l2){
        ListNode* p1 = l1, *p2 = l2;
        ListNode *k = new ListNode(-1);
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
        while(p1){
            k->next = p1;
            p1 = p1->next;
            k = k->next;
        }
        while(p2){
            k->next = p2;
            p2 = p2->next;
            k = k->next;
        }
        
        return h3->next; 
    }
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(!lists.size())
            return NULL;
        
        ListNode *t = lists[0];
        for(int i=1;i<lists.size();i++){
            t = merge(t,lists[i]);
        }
        return t;
    }
};

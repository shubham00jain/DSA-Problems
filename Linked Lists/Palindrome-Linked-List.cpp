//https://leetcode.com/problems/palindrome-linked-list/
/*
For constant space do this:
1. get the middle of linked list using two pointers.
2. reverse the second half using 3 pointers.
3. check the for the first half and the second half.
4. Now reverse the second half again and connect it to the first half.

*/

bool isPalindrome(ListNode* head) {
        if(!head || !head->next){
            return 1;
        }
        ListNode *t = head;     
        vector<int> v;
        while(t){
            v.push_back(t->val);;
            t = t->next;
        }
        for(int i = 0;i<v.size();i++){
            if(v[i] != v[v.size()-1-i])
                return 0;
        }
        return 1;
    }

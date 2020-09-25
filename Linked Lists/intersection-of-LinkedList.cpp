/*
The best way to do this to use 2 pointers, the algo is as follows:
Maintain two pointers pApA and pBpB initialized at the head of A and B, respectively. Then let them both traverse through the lists, one node at a time.
When pApA reaches the end of a list, then redirect it to the head of B (yes, B, that's right.); similarly when pBpB reaches the end of a list, redirect it the head of A.
If at any point pApA meets pBpB, then pApA/pBpB is the intersection node.
To see why the above trick would work, consider the following two lists: A = {1,3,5,7,9,11} and B = {2,4,9,11}, which are intersected at node '9'. Since B.length (=4) < A.length (=6), pBpB would reach the end of the merged list first, because pBpB traverses exactly 2 nodes less than pApA does. By redirecting pBpB to head A, and pApA to head B, we now ask pBpB to travel exactly 2 more nodes than pApA would. So in the second iteration, they are guaranteed to reach the intersection node at the same time.
If two lists have intersection, then their last nodes must be the same one. So when pApA/pBpB reaches the end of a list, record the last element of A/B respectively. If the two last elements are not the same one, then the two lists have no intersections.

https://leetcode.com/problems/intersection-of-two-linked-lists/solution/
*/
 
 

//using maps
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_map<ListNode*,int> umap;
        
        while(headA){
            umap[headA] +=1;
            headA = headA->next;
        }
        while(headB){
            if(umap.find(headB)!=umap.end()){
                return headB;
            }
            headB = headB->next;
        }
        return NULL;
    }
    
    
 //using 2 pointers (better way)
 
 
 ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* p1 = headA, *p2=headB;
        ListNode* e1=NULL,*e2=NULL;
        int i1=0,i2=0;
        if(headA==NULL || headB==NULL){
            return NULL;
        }
        if(headA == headB)
            return headA;
        
        while(true){
            if(p1->next==NULL){
                e1 = p1;
                p1 = headB;
                i1 = 1;
            }
            else{
                p1 = p1->next;    
            }
            
            
            if(p2->next == NULL){
                e2 = p2;
                p2 = headA;
                i2 = 1;
            }
            else{
                p2 = p2->next;    
            }
            
            
            if(i1==1 && i2 == 1 && e1!=e2){
                return NULL;
            }
            
            if(p1==p2)
                return p1;
        }
    }

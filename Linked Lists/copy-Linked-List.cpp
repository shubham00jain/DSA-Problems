//https://leetcode.com/problems/copy-list-with-random-pointer/submissions/

//Time O(n) and space O(n)

Node* copyRandomList(Node* head) {
        unordered_map<Node*,Node*> umap;
        Node* t = head;
        while(t){
            Node* temp = new Node(t->val);
            pair<Node *, Node*> p;
            p = make_pair(t,temp);
            umap.insert(p);
            t = t->next;
        }
        
        t = head;
        Node* head2 = umap[t];
        Node* p = head2;
        
        while(t){
            p->next = umap[t->next];
            p->random = umap[t->random];
            t = t->next;
            p = p->next;
        }
        return head2;
   }
    

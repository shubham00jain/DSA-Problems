//https://practice.geeksforgeeks.org/problems/insert-in-a-sorted-list/1

Node *sortedInsert(struct Node* head, int data) {
    Node * temp = new Node(data);
    Node *p1=head,*p2=head;
    if(!head)
        return temp;
        
    if(data<head->data){
        temp->next = head;
        head = temp;
        return head;
    }
    
    while( (p1->data<data) && p1){
        p2 = p1;
        p1 = p1->next;
    }
    
    temp->next = p1;
    p2->next = temp;
    
    return head;
}

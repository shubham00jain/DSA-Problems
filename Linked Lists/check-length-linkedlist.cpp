//https://www.geeksforgeeks.org/check-whether-the-length-of-given-linked-list-is-even-or-odd/#:~:text=1.,length%20is%20Even%2C%20else%20Odd.

string isLengthEvenOrOdd(struct Node* head)
{
     Node* fast = head;
     while(fast && fast->next){
         if(fast == NULL)
            return "odd";
        if(fast->next == NULL)
            return "even";
        fast = fast->next->next;
     }
     
}

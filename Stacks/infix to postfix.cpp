//https://practice.geeksforgeeks.org/problems/infix-to-postfix-1587115620/1
/*
To evaluate a postfix expression:
1. Start reading the string from left to right.
2. Push if to stack if any number or operand is encountered.
3. If any operator is encountered, pop 2 elements out of the stack, perform the operation and push the resultant into the stack again.

To evaluate a prefix expression, do the same thing as postfix but read the string from right to left instead.

To convert infix to prefix, its almost the same as this code having these diffenrences:
1. Read the infix string from right to left.
2. As we reading the infix string from right to left, every ) bracket becomes our "opening" bracket and every ( bracket becomes our "closing" bracket.
3. Use the above the exceptions and do the same as infix to postfix to a get a string as a resullt. Now reverse the answer to the final result.
*/


bool checkop(char c){
    if(c=='+' || c=='-' || c=='*' || c=='^' || c=='/' )
        return true;
    return false;
}

bool checkbra(char c){
    if(c=='(' || c==')')
        return true;
    return false;
}

bool priority(string s, char c, stack<char> op){
    if( c == '(' )
        return false;

    map<char,int> m = { {'+',0}, {'-',0}, {'*',1}, {'/',1}, {'^',2} };
    int p1 = m.find(c)->second;
    int p2 = m.find(op.top())->second;
    if(p2>=p1)
        return true;
    return false;
}


string infixToPostfix(string s)
{
   stack <char> op;
   string res;
   
   for(auto i : s){
       if( !checkop(i) && !checkbra(i) )
            res.push_back(i);
        else{
            if(i==')'){
                    while(!op.empty() && op.top()!='(' ){
                        res.push_back(op.top());
                        op.pop();
                    }
                    op.pop();
                }
                
            else{
                while(!op.empty() && priority(s,i,op) && op.top()!='(' ){
                    res.push_back(op.top());
                    op.pop();
                }
                op.push(i);
            }
        }
            
    }
    while(!op.empty()){
        if(!checkbra(op.top()) ){
            res.push_back(op.top());
            op.pop();
        }
        else
            op.pop();
    }
    return res;
}

//https://practice.geeksforgeeks.org/problems/infix-to-postfix-1587115620/1


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

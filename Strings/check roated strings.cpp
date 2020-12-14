// https://www.geeksforgeeks.org/a-program-to-check-if-strings-are-rotations-of-each-other/

class Solution {
public:
    bool rotateString(string A, string B) {
        if(A.length()!=B.length())
            return 0;
        if(A.length()==0 && B.length()==0)
            return 1;
       A = A + A;
       return A.find(B) != string::npos; 
    }
};

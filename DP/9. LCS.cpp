// https://www.youtube.com/watch?v=4Urd0a0BNng&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=19&ab_channel=AdityaVerma
// https://practice.geeksforgeeks.org/problems/longest-common-subsequence-1587115620/1

/*
Approach:
This is a fundamental DP problem. In this we have 3 (1 + 2) choices:
1. Either both the characters of the strings match in which case we should call the function will 1 + s1.length()-1, s2.length()-1.
2. Else they dont match, in which case we will have 2 choices: Either call the function with s1.length()-1 or call the function with s2().length()-1. and we will take max() of 
both of the choices.

Problems similar to this:
1. Longest common substring
2. Print LCS
3. Shortest common supersquence
4. Print SCS
5. Min num of insertion or deletion to make a -> b
6. Largest repeating subsquence
7. length of longest subsqunce of a which is a substring of b.
8. subsequnce pattern matching.
9. count how many a appears as subsqunece in b.
10. longest palindormic subsequnce.
11. longest palindromic substring.
12. count of palindromic substring.
13. min no. of deletion in a string to make it a palindrome.
14. min no. of addition in a string to make it a palindrome.
*/




// Naive recursive solution----------------------------------------
// ----------------------------------------------------------------

int solve(string s1, string s2, int x, int y){
    
    //base
    if(x==0 || y==0)
        return 0;
        
    //equal value    
    if( s1[x-1]==s2[y-1] )
        return 1 + solve(s1,s2,x-1,y-1);
    //not equal
    else{
        // reduce s1    
        int a = solve(s1,s2,x-1,y);
        //reduce s2
        int b = solve(s1,s2,x,y-1);
        return max(a,b);
    }
    
    return 0;
}


int lcs(int x, int y, string s1, string s2){
    return solve(s1,s2,x,y);
}

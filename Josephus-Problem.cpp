/*
N people are standing in a circle and we have to kill kth person everytime(skipping k-1 people). 
The last one remaining survives. Our task is to find the last person(or the safest position where Josephus should stand).
eg... if n = 5 and k = 2 the last person will be the person no. 3 (1 based indexing)

We will use recursion for this:
1. See wikipedia for the best explanation.[Its hard to explain]
https://en.wikipedia.org/wiki/Josephus_problem
https://www.geeksforgeeks.org/josephus-problem-set-1-a-on-solution/#:~:text=In%20computer%20science%20and%20mathematics,circle%20in%20a%20fixed%20direction.

*/

// Function snippet

int josephus(int n, int k) 
{ 
    if (n == 1) 
        return 1; 
    else
        /* The position returned by josephus(n - 1, k) 
        is adjusted because the recursive call  
        josephus(n - 1, k) considers the  
        original position k % n + 1 as position 1 */
        return (josephus(n - 1, k) + k-1) % n + 1; 
} 


Time : O(n)

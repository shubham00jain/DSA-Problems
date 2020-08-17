/*
  non-decreasing subsequence is the longest subsquence which has only elements equal to each other or in increasing order.
  (This problem can have many different flavours like longest increasing subsequece(LIS), longest decreasing subsquence(LDS),
  longest non-decreasing subsequence etc.)
  for eg..
   array [1,-2,3,2,2,2] will have the longesst subsequence equal to:
   [1,2,2,2]
   some other non-decreasing subsquence can be:
   [1,3], [-2,3]etc. 
   
   
   For this we will use DP.
   1. initialise all elements in dp = 1.
   2. compare the next element in the array with all of the previous elements starting from 1.
      If the element is greater than the previous element, check its corresponding value in the DP table
      If the DP[previous element]+1 is greater than DP[current element], update DP Value of the current element with DP[previous element] + 1.
   */



#include <bits/stdc++.h>
using namespace std;


int main() {
  int a[] = {-1,3,5,2,2,2};
  int dp[6] = {1,1,1,1,1,1};

  for(int i=0;i<6;i++){
    for(int j=0;j<i;j++){
      if(a[i]>=a[j]){
        if(dp[j]+1 > dp[i])
          dp[i] = dp[j]+1;
      }
    }
  }
  cout<<endl<<dp[5];

  
  return 0;
}
/*
Time : O(n^2)
Space : O(n)
*/


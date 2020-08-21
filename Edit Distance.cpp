/*
In this problem we have to convert a string str1 to string str2 using one of the following operations:
1. Insert
2. Replace
3. Delete

The naive way is to recursive check for every last character of the string and:
1. if it is same then call the fxn again for len1-1 and len2-1.
2. if not then perform all 3 operations and return the minimum of all three of them + 1 ( +1 because 1 operation will have to be done for this mismatched charcter).

Dp sol:
same as recursive but rather than calling the function everytime, we will use bottom up approach and bulid a 2d DP table from 0.

See these:
https://www.geeksforgeeks.org/edit-distance-dp-5/
https://www.youtube.com/watch?v=MiqoA-yF-0M&t=4s
*/

//----------------------------recursive----------------

#include<bits/stdc++.h>
using namespace std;

int min(int x, int y, int z) 
{ 
    return min(min(x, y), z); 
} 


int editDistance(string s1, string s2, int len1, int len2){
  if(len1==0)
    return len2;
  
  else if(len2 ==0)
    return len1;

  else if(s1[len1-1]==s2[len2-1])
      return editDistance(s1, s2, len1-1, len2-1);

  else{
    return 1 + min(editDistance(s1, s2, len1, len2-1), editDistance(s1, s2, len1-1, len2),editDistance(s1, s2, len1-1, len2-1));
  }
}

int main(){
  string s1 = "sunday";
  string s2 = "saturday";
    cout<<editDistance(s1, s2, s1.length(), s2.length());
}

// Time: O(3^len1)[you have three choices everytime]
// Space: system stack space

//------------------------DP-----------------------------

int editDistance(string s1, string s2, int len1, int len2){
  int dp[len1+1][len2+1];

  for(int i=0;i<=len1;i++){
      cout<<i<<" ";
    for(int j=0;i<=len2;j++){
      cout<<i<<" "<<j;
      if(i==0)
        dp[i][j] = j;

      else if(j==0)
        dp[1][j] = i;

      else if(s1[i-1] == s2[j-1])
        dp[i][j] = dp[i-1][j-1];

      else{
        dp[i][j] = 1 + min(dp[i-1][j-1], dp[i-1][j], dp[i][j-1]);
      }
  }

  }
  return dp[len1][len2];
}

//Time : O(len1*len2)
//space : O(len1*len2)

/*
Longest common subsequence is the longest subsequence common in 2 strings.
We have to find length of the LCS (in some other flavour the actual LCS can also be asked)

eg.. string1 = "COMPUTER"
     string2= "HOUSE"
     will have LCS  = 3 => "OUE"  
     some other common subseq. are = "OU", "E", "UE" etc.
     
     The naive approach is to make a recursive function and call lcs everytime. (approch will be same as below except 
     rather than storing values in a dp table we will make a recursive call at that point).
     Time complexity = O(n*2^n)
     
     
     Optimised way is to use DP. (see gfg https://www.geeksforgeeks.org/longest-common-subsequence-dp-4/ )
     1. make a dp table.
     2. initialize all elemnets of row = 0 and cloumn = 0 equal to 0.
     3. now interate over the strings and if: string 1 [i] == string 2 [j] then check the diagonally left element and add 1 to it.
     i.e. dp [i][j] = dp[i-1][j-1] + 1.
     4. else dp of current element wiil be the max of dp of i-1,j  and dp i,j-1.
     [make a recursion tree to understand this!].
*/


//------------------------------------------------------Naive recusrive solution------------------------------------------
//------------------------------------------------------Naive recursive solution------------------------------------------

#include <bits/stdc++.h>
using namespace std;

vector<vector<string>> dp;
int lcs(string &s1, string &s2, int n, int m){

  if(m==0||n==0){
    return 0;
  }
  if(s1[n]==s2[m]){
    return (lcs(s1,s2,n-1,m-1) + 1);

  }
  
  else{
    return max(lcs(s1,s2,n-1,m),lcs(s1,s2,n,m-1));
  }
}


int main() {
  string s1 = "COMPUTER";
  string s2 = "HOUSE";

  int n = s1.length();
  int m = s2.length();

  
  cout<<lcs(s1,s2,n,m);
  
  
  return 0;
}
Time = O(n*2^n)
Space = size of system stack

//-------------------------------------------Optimized DP sol--------------------------------------------
//-------------------------------------------Optimized DP sol--------------------------------------------

#include <bits/stdc++.h>
using namespace std;

int main() {

  string s1 = "COMPUTER";
  string s2 = "HOUSE";
  int len1 = s2.length() ;
  int len2 = s1.length() ;

  //vector<vector<int> > dp(len1, vector<int> (len2));
  
  int dp[len1+1][len2+1];
  // for(int i=0;i<len1;i++){
  //   for(int j=0;j<len2;j++){
  //     cout<<dp[i][j];
  //   }
  //   cout<<endl;
  // }

  for(int i=0;i<=len1;i++){

    for(int j=0;j<=len2;j++){
      //cout<<i<<" "<<j<<endl;
      if(i==0 || j==0){
        dp[i][j] = 0;
      }
      else if(s1[j-1]==s2[i-1]){
        //cout<<i-1<<' '<<j-1<<endl;
        dp[i][j] = dp[i-1][j-1]+1;
      }else{
        dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
      }     
    }
  }

  for(int i=0;i<=len1;i++){
    for(int j=0;j<=len2;j++){
      cout<<dp[i][j];
    }
    cout<<endl;
  }

  cout<<dp[len1][len2];
  return 0;
}

Time = O(mn)
Space = O(mn)
  

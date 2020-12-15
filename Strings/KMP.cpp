#include <bits/stdc++.h>
using namespace std;

void computelps(string pat, vector<int>& lps){
  int len = 0;
  int i = 1;
  lps[0] = 0;

  while(i<pat.length()){
      if(pat[len] == pat[i]){
        len++;
        lps[i] = len;
        i++;
      }
      else{
        if(len !=0)
          len = lps[len-1];

        else{
          lps[i] = 0;
          i++;
        }
      }
  }


}


void KMP(string txt, string pat){
  int i = 0;
  int j = 0;
  int n = txt.length();
  int m = pat.length();

  vector<int> lps(m,0);
  computelps(pat,lps);

  while(i<n){
    if( txt[i] == pat[j] ){
      i++;j++;
    }
    if(j==m){
      cout<<"Pattern Found at "<<i-j<<" to "<<i-1<<endl;
      j = lps[j-1];
    }

    else if(i<n && txt[i]!=pat[j]  ){
      if(j!=0){
        j = lps[j-1];
      }
      else{
        i++;
      }
    }
  }
}



int main(){
  KMP("adsgwadsxdsgwadsgz","dsgwadsgz");
}

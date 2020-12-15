#include <bits/stdc++.h>
using namespace std;

void rabinkarp(string txt, string pat){
  int n = txt.length();
  int m = pat.length();
  int d = 256;
  int q = 101;
  int i,j;
  int p =0;
  int t = 0;
  int h = 1;

  for (i = 0; i < m - 1; i++){
    h = (h * d) % q;
  }
    

  for(i=0;i<m;i++){
    t = ( d * t + txt[i] ) % q;
    p = ( d * p + pat[i] ) % q;
  }

  for(i=0;i<n-m;i++){
    if(p==t){
      
      for(j=0;j<m;j++){
        if(txt[i+j]!=pat[j] )
          break;
      }
      if(j==m)
        cout<<"Pattern found at"<<i<<endl;
    }
    

    if(i<n-m){
      t = (d* (t - txt[i]*h) + txt[i+m] )%q;

      if(t<0)
        t = (t+q);
    }
  }
}


int main(){
  rabinkarp("adsgwadsxdsgwadsgz","dsgwadsgz");
}

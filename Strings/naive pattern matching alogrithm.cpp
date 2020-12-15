void naivematch(string txt, string pat){
  int n = txt.length();
  int m = pat.length();
  int  i =0;
  while(i<n){
      if(txt[i]==pat[0]){
        int p = i;
        int q = 0;
        while(p<n && q<m && txt[p]==pat[q]){
          p++;
          q++;
        }
        if(q==m){
          cout<<"Pattern Found at "<<i<<endl;
          break;
        }
      }
      i++;
  }
}



int main(){
  naivematch("adsgwadsxdsgwadsgz","dsgwadsgz");
}

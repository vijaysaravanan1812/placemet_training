string encode(string src)
{     
  int count=1;
  string ans="";
  int n=src.size();

  for(int i=1;i<n;i++)
  {
      if(src[i]!=src[i-1]){
          ans+=src[i-1] + to_string(count);
          count=1;
      }
      else count++;
  }
    ans = ans + src[n-1] + to_string(count); 
  return ans;
}


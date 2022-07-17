int stringComparsion(string s1,string s2)
{
   int i=0, j=0;
   
   while(i<s1.size() && j<s2.size())
    {
        if( (s1[i]=='n' && (i+1<s1.size()) &&s1[i+1]=='g'))
         {
             if(s2[j]=='n' && (j+1<s2.size()) && s2[j+1]=='g')
               i++, j++;
             else if(s2[j] >='o') return -1;
             else return 1;
         }
         else if( (s2[j]=='n' && (j+1<s2.size()) &&  s2[j+1]=='g'))
         {
             if(s1[i]=='n' && (i+1<s1.size()) && s1[i+1]=='g')
               i++, j++;
             else if(s1[i] >='o') return 1;
             else return -1;
         }
        
        else if(s1[i]>s2[j]) return 1;
        else if (s1[i]<s2[j]) return -1;
        
          i++, j++;

    }
    if(i==s1.size() && j<s2.size() ) return -1;
    else if(j==s2.size() && i<s1.size()) return 1;
    else
    return 0;
   
   
}
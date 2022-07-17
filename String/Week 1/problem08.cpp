string merge (string s1, string s2)
{
    string s3;
    int M = s1.length();
    int N = s2.length();
    
    int i = 0 ;
    int j = 0 ;
    while( i < M || j < N)
    {
        s3 += s1[i++];
        s3 += s2[j++];
    }
    if(i < M){
        s3 += s1[i++];
    }
    if(j < N)
    {
        s3 += s2[j++];
    }
    
    return s3;
    
}
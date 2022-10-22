#include<string.h>
    void main()
    { 
      char s[100],c;
      int i,x,l;
      scanf("%s",s);
      l=strlen(s);
      for(i=0;i<=l-1;i++)
      {
         x=s[i];
         if(x<=90)
           x=x+32;
         else
           x=x-32;
 
         c=x;
         s[i]=c;
      }
      printf("%s",s);
    }

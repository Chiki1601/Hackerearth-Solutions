#include<stdio.h>
int main()
{
      char s[9];
      int i,x;
      scanf("%s",s);
      int flag1=0,flag2=0;
      for(int i=0;i<9;i++)
      {
            if((s[0]+s[1])%2==0 && (s[3]+s[4])%2==0 && (s[4]+s[5])%2==0 && (s[7]+s[8])%2==0)
      flag1=1;
       if(s[2]=='A'|| s[2]=='E'|| s[2]=='I'|| s[2]=='O'|| s[2]=='U'|| s[2]=='Y')
        flag2=1;
      }
      if(flag1==1 && flag2==0)
       printf("valid");
      else
       printf("invalid");
      return 0;
      
}

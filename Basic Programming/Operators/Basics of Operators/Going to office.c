#include<stdio.h>
int main()
{
     long long int d,oc,of,od,cs,cb,cm,cd;
     long long int cost1,cost2;
     scanf("%lld",&d);
     scanf("%lld %lld %lld",&oc,&of,&od);
     scanf("%lld %lld %lld %lld",&cs,&cb,&cm,&cd);
     cost1=oc+((d-of)*od);
     cost2=cb+((d/cs)*cm)+(d*cd);
     if(cost1<cost2||cost1==cost2)
      printf("Online Taxi");
     else
      printf("Classic Taxi");
     return 0;
}

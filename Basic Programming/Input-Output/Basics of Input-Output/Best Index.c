#include<stdio.h>
#include<math.h>
main()
{
    long n,i,k,j,left,p=0,max=-10000000;
    scanf("%ld",&n);
    long a[n],sum;
    for(i=0;i<n;i++)
    {
        scanf("%ld",&a[i]);
        if(i>0)
        a[i]+=a[i-1];
    }
    for(i=0;i<n;i++)
    {
        left=n-i;
        sum=0;
        k=(-1+(int)sqrt((double)(8*left+1)))/2;
        sum=a[(k*(k+1))/2+i-1];
        if(i!=0)
        sum-=a[i-1];
        if(max<sum)
        max=sum;
    }
    printf("%ld",max);
}

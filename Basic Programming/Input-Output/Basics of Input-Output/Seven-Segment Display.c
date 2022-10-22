#include<string.h> 
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int a[10]={6,2,5,5,4,5,6,3,7,6,},i,sum=0;
        char n[100];
        scanf("%s",n);
        for(i=0;i<strlen(n);i++)
            sum+= a[(n[i]-48)];
        if(sum%2==1)
            printf("7");
        else
            printf("1");
        for(i=1;i<sum/2;i++)
            printf("1");
        printf("\n"); 
    }
    return 0;
}

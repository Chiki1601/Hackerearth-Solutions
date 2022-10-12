#include<bits/stdc++.h>
using namespace std;
char str[3005];
 
bool comp(int i,int j)
{
    return (str[i] != str[j]) ? str[i] > str[j]: i < j;
}
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int t, n, i, in[3001];
    cin >> t;
 	while(t--)
	{
       	cin >> str >> n;
       	n--;
       	for(i = 0; str[i] != '\0'; i++)   
		   	in[i] = i;
       	sort(in, in + i, comp);
       	for(i = 0; str[i] != '\0'; i++, n = in[n]) 
		   	putchar(str[n]);
       	puts("");
    }
    return 0;
}

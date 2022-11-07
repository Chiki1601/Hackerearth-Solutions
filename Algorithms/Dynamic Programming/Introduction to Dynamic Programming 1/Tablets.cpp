#include<bits/stdc++.h>
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n;
    cin >> n;
    int a[n], t[n]={0};
    for(int i = 0; i < n; i++)
    	cin >> a[i];
    t[0] = 1;
    for(int i = 1; i < n; i++)
    {
        if(a[i] > a[i - 1])
        	t[i] = t[i - 1] + 1;
        else
        	t[i] = 1;
    }
    for(int i = n - 2; i >= 0; i--)
    {
        if(a[i] > a[i + 1] && t[i] <= t[i + 1])
        	t[i] = t[i + 1] + 1;
    }
    int sum = 0;
    for(int i = 0; i < n; i++)
    	sum += t[i];
    cout << sum;
}

#include<bits/stdc++.h>
using namespace std;
long long int f[1000001];
int a[100001], divi[1000001];
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int n;
    for(int i = 1; i <= 1000000; i++)
	{
        for(int j = i; j <= 1000000; j += i)
            divi[j]++;
    }
    cin >> n;
    for(int i = 1; i <= n; i++)
	{
        cin >> a[i];
        f[divi[a[i]]]++;
    }
    long long int ans = 0;  
    for(int i = 1; i <= 1000000; i++)
        ans = ans + (f[i] * (f[i] - 1)) / 2;
    cout << ans << endl;
}

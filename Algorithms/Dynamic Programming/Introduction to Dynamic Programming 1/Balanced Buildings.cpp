#include<bits/stdc++.h>
using namespace std;
 
int main()
{
    long long int n, m, s, p;
    cin >> n >> s >> m >> p;
    long long int a[n];
    for(long int i = 0; i < n; i++)
        cin >> a[i];
    long long int dp1[n] = {0}, pp[n] = {0}, dp2[n] = {0};
    for(long int i = 0; i < n; i++)
    {
        for(long int j = 0; j < i; j++)
        {
            if(a[i] > a[j])
            	pp[j] += m * (a[i] - a[j]);
            else
            	pp[j] += p * (a[j] - a[i]);
        }
        long long int temp = 0;
        for(long int j = i; j >= 0; j--)
        {
            if(a[j] > a[i])
                temp += (a[j] - a[i]) * m;
            else
            	temp += (a[i] - a[j]) * p;
            dp1[i] = max({dp1[i], s * (i - j) - temp + (j - 1 >= 0 ? max(dp1[j - 1], dp2[j - 1]) : 0)});
            dp2[i] = max({dp2[i], s * (i - j) - pp[j] + dp1[j]});
        }
    }
    dp1[n - 1] = max(dp1[n - 1], dp2[n - 1]);
    cout << dp1[n - 1];
}

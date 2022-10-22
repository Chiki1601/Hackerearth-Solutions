#include <bits/stdc++.h>
using namespace std;
 
int main() 
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t;
    cin >> t;
    while(t--) 
	{
        long long a, b, c, d, m, ar[100005];
        cin >> a >> b >> c >> d >> m;
        int n;
        cin >> n;
        map<long long, int> mp;
        for(int i = 0; i < n; i ++) 
		{
            cin >> ar[i];
            mp[(((ar[i] * ar[i]) % m) + m) % m]++;
        }
        long long ans = 0;
        for(int i = 0; i < n; i ++) 
		{
            long long x = (((((((a * ar[i]) % m) * ((ar[i] * ar[i]) % m)) % m) + (b * ((ar[i] * ar[i]) % m) % m) + ((c * ar[i]) % m) + d) % m) + m) % m;
            if(mp.find(x) != mp.end())
                ans += mp[x];
        }
        cout << (ans % 1000000007) << endl;
        mp.clear();
    } 
    return 0;
}

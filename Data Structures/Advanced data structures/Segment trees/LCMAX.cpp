#include <bits/stdc++.h>           
using namespace std;
 
struct best_hash 
{
	static uint64_t splitmix64(uint64_t x) 
    {
		x += 0x9e3779b97f4a7c15;
		x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
		x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
		return x ^ (x >> 31);
	}
	size_t operator()(uint64_t x) const 
    {
		static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
		return splitmix64(x + FIXED_RANDOM);
	}
};
 
int main() 
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	long long t;
	t = 1;
	cin >> t;
	for(long long i = 0; i <= t - 1; i++) 
	{
        long long n, ans = 0;
        cin >> n;
        vector<long long> v(n), L(n, -1), R(n, n);
        for(long long i = 0; i <= n - 1; i++) 
            cin >> v[i];
        stack<array<long long, 2>> s;
        for(long long i = 0; i <= n - 1; i++) 
        {
            if(!((long long)(s.size())) or s.top()[0] % v[i] == 0) 
                s.push({v[i], i});
            else 
            {
                while((long long)(s.size()) and s.top()[0] % v[i]) 
                {
                    R[s.top()[1]] = i;
                    s.pop();
                }
                s.push({v[i], i});
            }
        }
        while((long long)(s.size())) 
            s.pop();
        for(long long i = n - 1; i >= 0; i--) 
        {
            if(!((long long)(s.size())) or s.top()[0] % v[i] == 0) 
                s.push({v[i], i});
            else 
            {
                while((long long)(s.size()) and s.top()[0] % v[i]) 
                {
                    L[s.top()[1]] = i;
                    s.pop();
                }
                s.push({v[i], i});
            }
        }
        unordered_map<long long, long long, best_hash> kithe;
        for(long long i = 0; i <= n - 1; i++)
        {
            long long x = L[i] + 1, y = R[i] - 1;
            if(kithe.count(v[i])) 
                x = max(x, kithe[v[i]] + 1);
            x = i - x;
            y = y - i;
            ans += (x + y + x * y + 1);
            kithe[v[i]] = i;
        }
        cout << ans << "\n";
    }
	return 0;
}

#include <bits/stdc++.h>
using namespace std;
vector <int> v[100005];
int n;
long long dp[100005];
bool vis[100005];
 
long long f(int idx)
{
	if(idx == n) 
        return 1;
	if(vis[idx]) 
        return dp[idx];
	vis[idx] = true;
	long long ans = 0;
	for(int i = 0; i < v[idx].size(); i++) 
        ans += f(v[idx][i]);
	dp[idx] = ans;
	return ans;
}
 
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int x, y;
	cin >> n;
	for( ;; ) 
    {
		cin >> x >> y;
		if(x == 0 && y == 0) 
            break;
		v[x].push_back(y);
	}
	long long ans = f(1);
	cout << ans << endl;
    return 0;
}

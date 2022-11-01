#include <bits/stdc++.h>
using namespace std;
long long level[200005], parent[200005], a[200005], val[200005], maxlevel = 0;
vector<int> edge[200005];
int n, k, q;
 
long long poww(long long a, long long b)
{
	long long res = 1;
	while(b)
    {
		if(b % 2)
        {
			res *= a;
			res %= k;
		}
		a *= a;
		a %= k;
		b /= 2;
	}
	return res;
}
 
void BFS(long long s)
{
	queue <long long> q;
	q.push(s);
	level[s] = 0;
	val[s] = a[s];
	while(q.size())
    {
		long long p = q.front();
		q.pop();
		for(auto it : edge[p])
        {
			level[it] = level[p] + 1;
			maxlevel = max(maxlevel, level[it]);
			q.push(it);
			val[it] = (val[p] * 10 + a[it]) % k;
		}
	}
}
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> k >> q;
	for(long long i = 1; i <= n; ++i) 
        cin >> a[i];
	for(long long i = 1; i < n; ++i) 
    {
		int x;
		cin >> x;
		parent[i + 1] = x;
		edge[x].push_back(i + 1);
	}
	parent[1] = 0;
	BFS(1);
	for(int i = 1; i <= n; ++i) 
		level[i] = maxlevel - level[i];
	while(q--)
    {
		int x, y;
		cin >> x >> y;
		if(x == 1) 
        {
			if(val[y] % k == 0) 
                cout << "YES\n";
			else 
                cout << "NO\n";
		}
		else
        {
			long long temp = parent[x];
			if((val[y] - val[temp] * (poww(10, level[temp] - level[y]))) % k == 0) 
                cout << "YES\n";
			else 
                cout << "NO\n";
		}
	}
}

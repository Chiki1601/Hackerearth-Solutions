#include <bits/stdc++.h>
using namespace std;
char ispr[1 << 17];

bool isPrime(int x) 
{
	for(int i = 2; i * i <= x; i++) 
		if(x % i == 0) 
			return 0;
	return 1;
}

int Sqrt(long long x) 
{
	int y = sqrt(x);
	while(1LL * y * y < x) 
		y++;
	while(1LL * y * y > x) 
		y--;
	if(1LL * y * y == x) 
		return y;
	return -1;
}

int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	vector<int> pr;
	map<long long, int> oo;
	for(int i = 2; i <= 2155; i++) 
		if(isPrime(i)) 
			pr.push_back(i);
	for(int i = 2; i < 1 << 17; i++) 
	{
		if(isPrime(i)) 
		{
			ispr[i] = 1;
			oo[1LL * i * i] = 1;
		}
	}
	int n;
	while(cin >> n) 
	{
		vector<long long> a(n);
		for(int i = 0; i < n; i++) 
			cin >> a[i];
		int ans = 0;
		vector<vector<pair<int, int>>> mem(n);
		map<vector<pair<int, int>>, int> mp;
		set<vector<pair<int, int>>> used;
		for(int i = 0; i < n; i++) 
		{
			int y = (int)pow(a[i], 1.0 / 3.0);
			while(1LL * y * y * y < a[i]) 
				y++;
			while(1LL * y * y * y > a[i]) 
				y--;
			if(1LL * y * y * y == a[i]) 
			{
				if(ans == 0) 
					ans++;
				continue;
			}
			long long x = a[i];
			vector<pair<int, int> > cur;
			for(int j = 0; j < (int)pr.size(); j++) 
			{
				if(x % pr[j] == 0) 
				{
					int cnt = 0;
					while(x % pr[j] == 0) 
					{
						x /= pr[j];
						cnt++;
					}
					if(cnt % 3 != 0) 
						cur.push_back(make_pair(pr[j], cnt % 3));
				}
			}
			if(x < 100000 && ispr[x]) 
			{
				cur.push_back(make_pair(x, 1)); 
				x = 1;
			}
			y = Sqrt(x);
			if(y != -1 && ispr[y]) 
			{
				cur.push_back(make_pair(y, 2)); 
				x = 1;
			}
			if(x != 1) 
				cur.push_back(make_pair(200000 + i, 1));
			assert(!cur.empty());
			mem[i] = cur;
			mp[cur]++;
		}
		for(int i = 0; i < n; i++) 
		{
			if(mem[i].empty()) 
				continue;
			vector<pair<int, int>> cur = mem[i];
			if(used.find(cur) != used.end()) 
				continue;
			vector<pair<int, int>> oth = cur;
			for(int j = 0; j < (int)oth.size(); j++) 
				oth[j].second = 3 - oth[j].second;
			ans += max(mp[cur], mp[oth]);
			used.insert(cur);
			used.insert(oth);
		}
		cout << ans << "\n";
	}
	return 0;
}

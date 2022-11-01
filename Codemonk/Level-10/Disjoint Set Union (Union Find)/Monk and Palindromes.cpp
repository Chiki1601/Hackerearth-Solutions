#include <bits/stdc++.h>
using namespace std;
int par[1002];

long long int power(long long int a, long long int b) 
{
	long long int x = 1, y = a;
    while(b > 0) 
	{
        if(b % 2 == 1) 
		{
            x = (x * y);
            if(x > 1000000007) 
				x %= 1000000007;
        }
        y = (y * y);
        if(y > 1000000007) 
			y %= 1000000007;
        b /= 2;
    }
    return x;
}

int func(int x)
{
  	if(x != par[x]) 
    	par[x] = func(par[x]);
  	return par[x];
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  	int n, q, a, b, x, y;
  	cin >> n >> q;
  	for(int i = 1; i <= n; i++) 
    	par[i] = i;
  	while(q--) 
	{
    	cin >> a >> b;
    	int i, j;
    	for(i = a, j = b; i < j; i++,j--) 
		{
      		x = func(i);
      		y = func(j);
      		if(x != y) 
        		par[y] = x;
    	}
  	}
  	map<int, int>mp;
  	for(int i = 1; i <= n; i++) 
    	mp[func(i)]++;
  	long long int l = mp.size(), ans;
  	ans = power(10, l);
  	cout << ans << "\n";
  	return 0;
}

//Solution-2
#include<bits/stdc++.h>
using namespace std;

int find(vector<int> v, int i)
{
	while(v[i] != -1)
		i = v[i];
	return i;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, m, i, a, b;
	cin >> n >> m;
	vector<int> v(n, -1);
	for(i = 0; i < m; i++)
	{
		cin >> a >> b;
		if(a == b)
			continue;
		int s = a - 1, e = b - 1;
		while(s < e)
		{
			int t1 = find(v, s), t2 = find(v, e);
			if(t1 != t2)
				v[t1] = t2;
			s++; 
			e--;
		}
	}
	long long int total = 1;
	for(i = 0; i < n; i++)
	{
		if(v[i] == -1)
			total = ((total % 1000000007) * 10) % 1000000007;
	}
	cout << total % 1000000007 << "\n";
}

#include <bits/stdc++.h>
using namespace std;
bool flag;
set<int> g[1000010];
set<pair<int, int>> seen;
int t, n, x, d[1000010], e[1000010], p[1000010], ans = 0x3f3f3f3f;
 
int main() 
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    for(int i = 1; i < 1000010; i++) 
        p[i] = i;
	for(int i = 2; i * i < 1000010; i++) 
        if(p[i] == i) 
            for(int j = i * i; j < 1000010; j += i)
		if(p[j] == j) 
            p[j] = i;
	cin >> n;
	for(int i = 0; i < n; i++) 
    {
		cin >> x;
		set<int> s;
		for(int y = x; y != 1; y /= p[y])
			if(s.count(p[y])) 
                s.erase(p[y]);
			else 
                s.insert(p[y]);
		if(!s.size()) 
            return puts("1"), 0;
		if(s.size() == 1) 
            s.insert(1);
		for(int i : s) 
            for(int j : s) 
                if(i != j) 
                {
			        if(seen.count({i, j})) 
                        flag = true;
			        seen.emplace(i, j);
			        g[i].insert(j), g[j].insert(i);
		        }
	}
	if(flag) 
        return puts("2"), 0;
	for(int i = 1; i * i < 1000010; i++) 
    {
		for(int j = 0; j < 1000010; j++) 
            d[j] = 0;
		queue<int> q; 
        q.push(i); 
        d[i] = 1;
		while(q.size()) 
        {
			int v = q.front(); 
            q.pop();
			for(int u : g[v])
				if(d[u] && e[v] != u) 
                    ans = min(ans, d[u] + d[v] - 1);
				else if(!d[u])
                { 
                    d[u] = d[v] + 1; 
                    e[u] = v; 
                    q.push(u);
                }
		}
	}
	printf("%d", ans==0x3f3f3f3f?-1:ans);
}

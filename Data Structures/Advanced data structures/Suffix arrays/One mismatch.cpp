#include <bits/stdc++.h>
using namespace std;
vector<int> g[500010], V[500010];
char s[500010], t[500010];
int ans[500010], ch[500010][96], x[500010], y[500010], sz = 1, fa[500010], f[2][500010], st[500010], ed[500010], cnt;
vector<pair<int, int>>Q[500010];
 
int pow(int a, int b)
{
    int ans = 1;
    while(b)
	{
        if(b & 1)
			ans = ans * (long long)a % 1000000007;
        a = (long long)a * a % 1000000007;
		b>>=1;
    }
    return ans;
}
 
int add(int p, char c)
{
    int i = c - 33;
    if(!ch[p][i])
		ch[p][i] = ++sz;
    return ch[p][i];
}
 
void build()
{
    queue<int>q;
	fa[1] = 0;
    for(int i = 0; i < 96; i++)
		if(ch[1][i])
		{
            q.push(ch[1][i]);
		    fa[ch[1][i]] = 1;
        }
    while(!q.empty())
	{
        int u = q.front();
		q.pop();
        g[fa[u]].push_back(u);
        for(int i = 0; i < 96; i++)
		{
            int &j=ch[u][i];
            if(j)
			{
                int x = fa[u];
                while(x && !ch[x][i])
				    x = fa[x];
                if(x <= 0)
					x = 1;
				else 
					x = ch[x][i];
                fa[j] = x;
                q.push(j);
            }
            else{}
        }
    }
}
 
void add(int i, int x)
{
    if(x <= 0)
		cerr << (x) << "=" << x << "\n";
    while(x < 500010)
	{
		f[i][x]++;
		x += x & -x;
	}
}
 
int query(int i, int x)
{
    if(x < 0)
        cerr << (x) << "=" << x << "\n";
    int ans = 0;
    while(x > 0)
	{	
		ans += f[i][x];
		x -= x & -x;
	}
    return ans;
}
 
void dfs(int u)
{
    st[u] = ++cnt;
    for(auto v : g[u])
		dfs(v);
    ed[u] = cnt;
}
 
void solve(int u)
{
    for(auto o : Q[u])
	{
        if(o.second < 0)
            ans[o.first] += query(1, ed[-o.second]) - query(1, st[-o.second] - 1);
        else
            ans[o.first] -= query(0, ed[o.second]) - query(0, st[o.second] - 1);
    }
    for(auto v : V[u])
	{
        if(v > 0)
			add(0, st[v]);
		else 
			add(1, st[-v]);
    }
    for(auto v : g[u])
		solve(v);
    for(auto o : Q[u])
	{
        if(o.second < 0)
            ans[o.first] -= query(1, ed[-o.second]) - query(1, st[-o.second] - 1);
        else
            ans[o.first] += query(0, ed[o.second]) - query(0, st[o.second] - 1);
    }
}
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T, i, j, k, ca = 0, K, n, m, L, p;
    cin >> K >> s;
    L = strlen(s);
    cin >> m;
    for(int r = 0; r < m; r++)
	{
        cin >> t;
        n = strlen(t);
		p = 1;
        if(n <= K)
		{
            ans[r] = max(L - n + 1, 0);
			continue;
        }
        for(int i = 0; i < n; i++)
            p = x[i] = add(p, t[i]);
        p = 1;
        for(int i = n - 1; i >= 0; i--)
            p = y[i] = add(p, t[i]);
        int u, v;
        for(int i = K; i < n + 1; i++)
		{
            u = i == K ? 1 : x[i - K - 1];
            v = i == n ? 1 : y[i];
            Q[u].push_back({r, v});
        }
        for(int i = K; i < n; i++)
		{
            u = x[i - K];
            v = y[i];
            Q[u].push_back({r, -v});
        }
    }
    build();
    p = 1;
    for(int i = 0; i < L; i++)
	{
        j = s[i] - 33;
        while(p && !ch[p][j])
			p = fa[p];
        if(p <= 0)
			p = 1;
		else 
			p = ch[p][j];
        x[i] = p;
    }
    p = 1;
    for(int i = L - 1; i >= 0; i--)
	{
        j = s[i] - 33;
        while(p && !ch[p][j])
			p = fa[p];
        if(p <= 0)
			p = 1;
		else 
			p = ch[p][j];
        y[i] = p;
    }
    int u, v;
    for(int i = K; i < L + 1; i++)
	{
        u = i == K ? 1 : x[i - K - 1];
        v = i == L ? 1 : y[i];
        V[u].push_back(v);
    }
    for(int i = K; i < L; i++)
	{
        u = x[i - K];
		v = y[i];
        V[u].push_back(-v);
    }
    dfs(1);
    solve(1);
    for(int i = 0; i < m; i++)
		cout << ans[i] << "\n";
    return 0;
}

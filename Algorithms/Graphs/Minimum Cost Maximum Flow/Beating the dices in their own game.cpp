#include <bits/stdc++.h>
using namespace std;
vector<pair<long long, long long>> inp[220];
long long setB[220], g[220][220], linky[220], lx[220], ly[220], slack[220], visy[220], visx[220], flag = 0, N;
 
bool check(int now)
{
    visx[now] = flag;
    for(int i = 0; i < N; i++)
    {
        if(lx[now] + ly[i] == g[now][i] && visy[i] != flag)
        {
            visy[i] = flag;
            if(linky[i] == -1 || check(linky[i]))
            {
                linky[i] = now;
                return true;
            }
        }
        slack[i] = min(slack[i], g[now][i] - lx[now] - ly[i]);
    }
    return false;
}
 
long long hungarian(int n)
{
    N = n;
    for(int i = 0; i < n; i++) 
    {
        lx[i] = 20000000000000LL; 
        ly[i] = 0; 
        linky[i] = -1;
    }
    for(int i = 0; i < n; i++) 
        for(int j = 0; j < n; j++)
            lx[i] = min(lx[i], g[i][j]);
    for(int vec = 0; vec < n; vec++)
    {
        for(int j = 0; j < n; j++) 
            slack[j] = 20000000000000LL;
        for(flag++; !check(vec); flag++)
        {
            long long dt = 20000000000000LL;
            for(int j = 0; j < n; j++) 
                if(visy[j] != flag)
                    dt = min(slack[j], dt);
            for(int i = 0; i <= vec; i++) 
                if(visx[i] == flag) 
                    lx[i] += dt;
            for(int j = 0; j < n; j++) 
                if(visy[j] == flag)
                    ly[j] -= dt;
            for(int j = 0; j < n; j++) 
                slack[j] = 20000000000000LL;
            if(lx[vec] >= 20000000000000LL) 
                return 20000000000000LL + 1;
        }
    }
    long long ans = 0;
    for(int i = 0; i < n; i++) 
        ans += lx[i] + ly[i];
    return ans;
}
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int q, n, m;
    long long u, v, c;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> m;
        for(int j = 0; j < m; j++)
        {
            cin >> u >> c;
            inp[i].push_back(make_pair(u, c));
        }
    }
    cin >> q;
    while(q--)
    {
        for(int i = 0; i < n; i++)
            cin >> setB[i];
        for(int i = 0; i < n; i++) 
            for(int j = 0; j < n; j++) 
                g[i][j] = 20000000000000LL;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < inp[i].size(); j++)
                for(int k = 0; k < n; k++)
                    if(inp[i][j].first == setB[k])
                        g[i][k] = inp[i][j].second;
        }
        long long res = hungarian(n);
        if(res >= 20000000000000LL) 
            cout << "-1" << endl;
        else 
            cout << res << endl;
    }
    return 0;
}

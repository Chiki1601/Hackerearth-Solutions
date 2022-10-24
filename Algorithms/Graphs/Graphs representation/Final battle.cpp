#include<bits/stdc++.h>
using namespace std;
int n, Q, w[105000], a[105000], b[105000], c[105000], cur_comps, mapp[105000], used[105000], taken[105000];
vector<int> by_weight[105000], G[105000], visited;
 
int get(int x)
{
    if(x == w[x])
        return x;
    return w[x] = get(w[x]);
}
 
void merge(int a, int b)
{
    a = get(a);
    b = get(b);
    if(a == b)
        return;
    --cur_comps;
    w[a] = b;
}
 
vector<vector<long long>> normalize(vector<vector<long long>> v)
{
    for(int i = 0; i < v.size(); i++)
    {
        for(int j = 0; j < v[i].size(); j++)
        {
            v[i][j] %= 1000000007;
            if(v[i][j] < 0)
                v[i][j] += 1000000007;
        }
    }
    return v;
}
 
int mult(int a, int b)
{
    long long res = 1ll * a * b;
    res %= 1000000007;
    if(res < 0)
        res += 1000000007;
    return res;
}
 
long long pw(long long a, long long b)
{
    if(b == 0)
        return 1;
    if(b % 2)
        return a * pw(a, b - 1) % 1000000007;
    return pw(a * a % 1000000007, b / 2);
}
 
int inv(long long x)
{
    return pw(x, 1000000005);
}
 
int sub(int a, int b)
{
    a -= b;
    a %= 1000000007;
    if(a < 0)
        a += 1000000007;
    return a;
}
 
long long get_det(vector<vector<long long>> v)
{
    long long res = 1;
    int n = v.size(), det = 1;
    for(int i = 0; i < n; i++)
    {
        int k = i;
        for(int j = i + 1; j < n; j++)
        {
            if(v[j][i] > v[k][i])
                k = j;
        }
        if(v[k][i] == 0)
            return 0;
        swap(v[i], v[k]);
        if(i != k)
            det = mult(det, -1);
        det = mult(det, v[i][i]);
        for(int j = i + 1; j < n; j++)
            v[i][j] = mult(v[i][j], inv(v[i][i]));
        for(int j = 0; j < n; j++)
        {
            if(j != i && v[j][i] > 0)
            {
                for(int k = i + 1; k < n; k++)
                    v[j][k] = sub(v[j][k], mult(v[i][k], v[j][i]));
            }
        }
    }
    return det;
}
 
void dfs(int v)
{
    used[v] = 1;
    visited.push_back(v);
    for(int i = 0; i < G[v].size(); i++)
    {
        int to = G[v][i];
        if(used[to])
            continue;
        dfs(to);
    }
}
 
vector<vector<long long>> update(vector<vector<long long>> v)
{
    v.erase(v.begin());
    for(int i = 0; i < v.size(); i++)
        v[i].erase(v[i].begin());
    return v;
}
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> Q;
    for(int i = 1; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
    }
    for(int i = 1; i <= Q; i++)
    {
        cin >> a[i] >> b[i] >> c[i];
        --a[i];
        --b[i];
        by_weight[c[i]].push_back(i);
    }
    for(int i = 0; i <= n; i++)
        w[i] = i;
    cur_comps = n;
    long long ans = 1;
    for(int i = 1; i <= 100000; i++)
    {
        if(by_weight[i].size() == 0)
            continue;
        for(int j = 0; j < n; j++)
        {
            used[j] = 0;
            G[j].clear();
        }
        for(int j = 0; j < by_weight[i].size(); j++)
        {
            int id = by_weight[i][j];
            G[get(a[id])].push_back(get(b[id]));
            G[get(b[id])].push_back(get(a[id]));
        }
        for(int j = 0; j < n; j++)
        {
            if(used[j])
                continue;
            if(G[j].size() == 0)
                continue;
            visited.clear();
            dfs(j);
            for(int q = 0; q < n; q++)
                taken[q] = 0;
            int cnt = 0;
            vector<int> v2;
            for(int q = 0; q < visited.size(); q++)
                v2.push_back(get(visited[q]));
            sort(v2.begin(), v2.end());
            for(int q = 0; q < v2.size(); q++)
            {
                if(q == 0 || v2[q] != v2[q - 1])
                {
                    taken[v2[q]] = cnt;
                    ++cnt;
                }
            }
            vector<vector<long long> > V;
            V.resize(cnt);
            for(int i = 0; i < V.size(); i++)
            {
                V[i].resize(cnt);
                for(int j = 0; j < V[i].size(); j++)
                    V[i][j] = 0;
			}
            for(int j = 0; j < visited.size(); j++)
            {
                int v = visited[j];
                int id1 = get(v);
                for(int q = 0; q < G[v].size(); q++)
                {
                    int to = G[v][q];
                    int id2 = get(to);
                    id1 = taken[get(v)];
                    id2 = taken[id2];
                    V[id1][id2]--;
                    V[id1][id1]++;
                }
            }
            V = normalize(V);
            V = update(V);
            ans = mult(ans, get_det(V));
        }
        for(int j = 0; j < by_weight[i].size(); j++)
        {
            int id = by_weight[i][j];
            int id1 = a[id], id2 = b[id];
            id1 = get(id1);
            id2 = get(id2);
            merge(id1, id2);
        }
 
	}
    if(cur_comps > 1)
        cout << 0 << endl;
    else
        cout << ans << endl;
    cin.get(); 
    cin.get();
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
vector<int>par, siz;
 
struct edge
{
    int a, b, cst;
};
 
void init(int n)
{
    par.resize(n + 1);
    siz.resize(n + 1);
    for(int i = 1; i <= n; ++i)
	  {
        par[i] = i;
        siz[i] = 1;
    }
}
 
int root(int a)
{
    while(par[a] != a)
	  {
        par[a] = par[par[a]];
        a = par[a];
    }
    return a;
}
 
void unify(int a, int b)
{
    int roota = root(a), rootb = root(b);
    if(roota == rootb)
        return;
    if(siz[roota] > siz[rootb])
        swap(roota, rootb);
    par[roota] = rootb;
}
 
bool cmp(edge a, edge b)
{
    return a.cst <= b.cst;
}
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<edge>edges(m);
    for(int i = 0; i < m; ++i)
        cin >> edges[i].a >> edges[i].b;
    int costt[n + 1];
    for(int i = 1; i <= n; ++i)
        cin >> costt[i];
    for(int i = 0; i < m; ++i)
		edges[i].cst = abs(costt[edges[i].a] - costt[edges[i].b]);
    int starting, ending;
    cin >> starting >> ending;
    init(n);
    sort(edges.begin(), edges.end(), cmp);
    int ans = 0;
    for(edge e : edges)
	  {
        if(root(starting) == root(ending))
            break;
        unify(e.a, e.b);
        ans = e.cst;
    }
    cout << ans;
    return 0;
}

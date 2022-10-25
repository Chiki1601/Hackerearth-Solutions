#include<bits/stdc++.h>
using namespace std;
const int nax = 1 << 19; 
vector<int> w[nax], query[nax];
int par[nax][19], val[nax], h[nax], lca[nax];
 
int find_lca(int a, int b) 
{
    if(h[a] < h[b]) 
        swap(a, b);
    for(int i = 18; i >= 0; --i)
        if(h[par[a][i]] >= h[b])
            a = par[a][i];
    if(a == b) 
        return a;
    for(int i = 18; i >= 0; --i)
        if(par[a][i] != par[b][i]) 
        {
            a = par[a][i];
            b = par[b][i];
        }
    assert(a != b);
    assert(par[a][0] == par[b][0]);
    return par[a][0];
}
 
void one(int a) 
{
    for(int b : w[a]) 
        if(b != par[a][0]) 
        {
            h[b] = h[a] + 1;
            par[b][0] = a;
            one(b);
        }
}
 
struct interval 
{
    long long left, right, inside, total;
    interval(long long x = -1000000005) 
    {
        total = left = right = inside = x;
    }
    interval operator * (interval b) 
    {
        interval ans;
        ans.left = max(left, total + b.left);
        ans.right = max(b.right, right + b.total);
        ans.inside = max(max(inside, b.inside), right + b.left);
        ans.total = total + b.total;
        return ans;
    }
} tr[2 * nax];
 
interval merge(int from) 
{
    interval ans = tr[nax + from];
    for(int i = nax + from; i > 1; i /= 2)
        if(i % 2 == 0)
            ans = ans * tr[i+1];
    return ans;
}
 
vector<interval> ANSWER[nax];
void two(int a) 
{
    static int sz = 1;
    assert(sz == h[a]);
    tr[nax + sz] = interval(val[a]);
    for(int i = (nax + sz) / 2; i > 0; i /= 2)
        tr[i] = tr[2 * i] * tr[2 * i + 1];
    ++sz;
    for(int id : query[a]) 
        ANSWER[id].push_back(merge(h[lca[id]]));
    for(int b : w[a]) 
        if(b != par[a][0]) 
            two(b);
    tr[nax + sz] = interval();
    for(int i = (nax + sz) / 2; i > 0; i /= 2)
        tr[i] = tr[2 * i] * tr[2 * i + 1];
    --sz;
}
 
int main() 
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, q;
    cin >> n;
    for(int i = 0; i <= n - 2; ++i) 
    {
        int a, b;
        cin >> a >> b;
        w[a].push_back(b);
        w[b].push_back(a);
    }
    h[1] = 1;
    one(1);
    for(int j = 1; j <= 18; ++j) 
        for(int a = 1; a <= n; ++a) 
            par[a][j] = par[par[a][j - 1]][j - 1];
    for(int i = 1; i <= n; ++i) 
        cin >> val[i];
    cin >> q;
    for(int i = 1; i <= q; ++i) 
    {
        int a, b;
        cin >> a >> b;
        lca[i] = find_lca(a, b);
        query[a].push_back(i);
        query[b].push_back(i);
    }
    two(1);
    for(int a = 1; a <= q; ++a) 
    {
        long long r = max(ANSWER[a][0].inside, ANSWER[a][1].inside);
        r = max(r, ANSWER[a][0].left + ANSWER[a][1].left - val[lca[a]]);
        cout << r << endl;
    }
    return 0;
}

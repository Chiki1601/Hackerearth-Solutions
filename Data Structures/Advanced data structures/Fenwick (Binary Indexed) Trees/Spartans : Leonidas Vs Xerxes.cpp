#include <bits/stdc++.h>
using namespace std;            
long long int  x, y, n, i, z, j, k, w, u, q, m, t, tree[800048], v[100002];
vector<pair<long long int, long long int>> ele;
 
void update(long long int  node, long long int  start, long long int  end, long long int idx, long long int  val)
{
    if(start == end)
        tree[node] = 1;
    else if(idx > end or idx < start) 
        return;
    else
    {
        long long int mid = (end + start) / 2;
        update(2 * node + 1, start, mid, idx, val);
        update(2 * node + 2, mid + 1, end, idx, val);
        tree[node] = max({((v[mid] < v[mid + 1]) ? (ele[2 * node + 1].second + ele[2 * node + 2].first):0), tree[2 * node + 1], tree[2 * node + 2]});
        if(ele[2 * node + 1].first == mid - start + 1 and v[mid] < v[mid + 1]) 
            ele[node].first = ele[2 * node + 1].first + ele[2 * node + 2].first;
        else 
            ele[node].first = ele[2 * node + 1].first;
        if(ele[2 * node + 2].second == end - mid and v[mid] < v[mid + 1]) 
            ele[node].second = ele[2 * node + 2].first + ele[2 * node + 1].second;
        else 
            ele[node].second = ele[2 * node + 2].second;
    }
}
 
void build(long long int node, long long int start, long long int end)
{
    if(start == end)
    {
        tree[node] = 1;
        ele[node] = {1, 1};
    }
    else
    {
        long long int mid = (end + start) / 2;
        build(2 * node + 1, start, mid);
        build(2 * node + 2, mid + 1, end);
        tree[node] = max({((v[mid] < v[mid + 1]) ? (ele[2 * node + 1].second + ele[2 * node + 2].first):0), tree[2 * node + 1], tree[2 * node + 2]});
        if(ele[2 * node + 1].first == mid - start + 1 and v[mid] < v[mid + 1]) 
            ele[node].first = ele[2 * node + 1].first + ele[2 * node + 2].first;
        else 
            ele[node].first = ele[2 * node + 1].first;
        if(ele[2 * node + 2].second == end - mid and v[mid] < v[mid + 1]) 
            ele[node].second = ele[2 * node + 2].second + ele[2 * node + 1].second;
        else 
            ele[node].second = ele[2 * node + 2].second;
    }
}
 
long long int query(long long int  node, long long int start, long long int end, long long int l, long long int r)
{
    if(l <= start and r >= end)
        return tree[node];
    else if(start > r or end < l)
        return 0;
    else 
    {
        long long int mid = (end + start) / 2, p1 = query(2 * node + 1, start, mid, l, r), p2 = query(2 * node + 2, mid + 1, end, l, r);
        if(p1 and p2 and v[mid] < v[mid + 1])
        {      
            x = min(mid - l + 1, ele[2 * node + 1].second);
            y = min(r - mid, ele[2 * node + 2].first);
            return max({x + y, p1, p2});
        } 
        return max(p1, p2);
    }
}
 
int main() 
{ 
    ios_base::sync_with_stdio(false); cout.tie(0); cin.tie(0);
    int TESTS = 1;
    cin >> TESTS;
    while(TESTS--)
    {
        cin >> n >> q;
        for(i = 1; i < n + 1; i++)
            cin >> v[i];
        memset(tree, 0, sizeof tree);
        ele.assign(8 * n + 4, {0, 0});
        build(0, 1, n);
        for(i = 1; i < q + 1; i++)
        {
            cin >> w >> x >> y;
            if(w)
            {
                v[x] += y;
                update(0, 1, n, x, y);
            }
            else 
                cout << query(0, 1, n, x, y) << endl;
        }
    }
}

#include <bits/stdc++.h>
using namespace std; 
 
struct dsu
{
    int parent, size;
    long long int  min_val, max_val;
};vector <dsu> v(200010);
 
int find(int u)
{
    if(v[u].parent==u)
        return u;
    return v[u].parent = find(v[u].parent);
}
 
void Union(int a,int b)
{
    a = find(a);
    b = find(b);
    if(a == b)
        return;
    if(v[a].size < v[b].size){swap(a,b);}
        v[b].parent = a;
    v[a].size += v[b].size;
    v[a].min_val = min(v[a].min_val,v[b].min_val);
    v[a].max_val = max(v[a].max_val,v[b].max_val);
}
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, q; 
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        long long int x; 
        cin >> x;
        v[i].parent = i;
        v[i].size = 1;
        v[i].max_val = x;
        v[i].min_val = x;
    }
    cin >> q;
    while(q--)
    {
        int x, y; 
        cin >> x >> y;
        Union(x, y);
        x = find(x);
        cout << v[x].min_val << " " << v[x].max_val << endl;
    }
    return 0;
}

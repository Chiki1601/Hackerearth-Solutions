#include<bits/stdc++.h>
using namespace std;
 
struct dsu 
{
    int parent, max_val, min_val, rank;
} s[1000001];
 
int find_parent(int x) 
{
    if(s[x].parent != x)
        return s[x].parent = find_parent(s[x].parent);
    return x;
}
 
void join(int x,int y) 
{
    int px = find_parent(x), py = find_parent(y);
    if(px == py)
        return;
    if(s[px].rank < s[py].rank) 
	{
        swap(px, py);
        swap(x, y);
    }
    s[py].parent = px;
    s[px].min_val = min(s[px].min_val, s[py].min_val);
    s[px].max_val = max(s[px].max_val, s[py].max_val);
    if(s[px].rank == s[py].rank)
        ++s[px].rank;
}
 
int main()  
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, q;
    cin >> n;
    for(int i = 1; i <= n; i++) 
	{
        int val;
        cin >> val;
        s[i].parent = i;
        s[i].min_val = val;
        s[i].max_val = val;
    }
    cin >> q;
    while(q--) 
	{
        int query_type;
        cin >> query_type;
        if(query_type == 1) 
		{
            int x, y;
            cin >> x >> y;
            join(x, y);
        }
        else 
		{
            int x;
            cin >> x;
            int p = find_parent(x);
            cout << s[p].max_val - s[p].min_val << endl;
        }
    }
}

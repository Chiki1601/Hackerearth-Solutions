#include <bits/stdc++.h>
using namespace std;
vector<int> node[1 << 18];
int n;
 
struct Gauss 
{
    int a[30];
    Gauss() 
	{
        memset(a, 0, sizeof a);
    }
    void add(int x) 
	{
        for(int i = 29; i >= 0; i--)
            if(x >> i & 1)
                if(a[i])
                    x ^= a[i];
                else 
				{
                    a[i] = x;
                    break;
                }
    }
    void operator+=(vector<int> &o) 
	{
        for(int i : o)
            if(i)
                add(i);
    }
    int cnt() 
	{
        return 1 << 30 - count(a, a + 30, 0);
    }
};
 
void add(int s, int e, int x, int l = 0, int r = n, int id = 1) 
{
    if(s <= l && r <= e) 
	{
        node[id].push_back(x);
        return;
    }
    if(e <= l || r <= s)
        return;
    int mid = (l + r) / 2;
    add(s, e, x, l, mid, id * 2);
    add(s, e, x, mid, r, id * 2 + 1);
}
 
int get_ans(int l = 0, int r = n, int id = 1, Gauss carry = Gauss()) 
{
    carry += node[id];
    if(l + 1 == r)
        return carry.cnt();
    int mid = (l + r) / 2;
    return (long long) get_ans(l, mid, id * 2, carry) * get_ans(mid, r, id * 2 + 1, carry) % 1000000007;
}
 
int main() 
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int m;
    cin >> n >> m;
    for(int i = 0; i < m; ++i) 
	{
        int l, r, x;
        cin >> l >> r >> x;
        add(l - 1, r, x);
    }
    cout << get_ans() << endl;
}

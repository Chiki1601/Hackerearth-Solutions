#include <bits/stdc++.h>
using namespace std;
int filter[30], n, tests, ar[100100], tp[100100], l[100100], r[100100], val[100100], x[100100], T[30][200200];
vector<pair<int, int>> V[30];
 
void add(int id, int i, int delta)
{
    for(; i < 200200; i = (i | (i + 1)))
        T[id][i] += delta;
}
 
int sum(int id, int r)
{
    int res = 0;
    for(; r >= 0; r = (r&(r + 1)) - 1)
        res += T[id][r];
    return res;
}
 
void add_number(int val, int ps)
{
    for(int bits = 1; bits <= 23; bits++)
    {
        int v2 = (val&filter[bits]);
        V[bits].push_back(make_pair(v2, ps));
    }
}
 
void turn_on(int val, int ps)
{
    for(int bits = 1; bits <= 23; bits++)
    {
        int v2 = (val & filter[bits]), id = lower_bound(V[bits].begin(), V[bits].end(), make_pair(v2, ps)) - V[bits].begin();
        add(bits, id, 1);
    }
}
 
void turn_off(int val, int ps)
{
    for(int bits = 1; bits <= 23; bits++)
    {
        int v2 = (val&filter[bits]), id = lower_bound(V[bits].begin(), V[bits].end(), make_pair(v2, ps)) - V[bits].begin();
        add(bits, id, -1);
    }
}
 
int solve(int ps, int val)
{
    int res = 0;
    for (int bits = 1; bits <= 23; bits++)
    {
        int v2 = (val&filter[bits]), id = upper_bound(V[bits].begin(), V[bits].end(), make_pair(v2, ps)) - V[bits].begin();
        res += sum(bits, id - 1);
    }
    return res;
}
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    for(int i = 1; i <= 23; i++)
        filter[i] = (1 << i) - 1;
    cin >> n >> tests;
    for(int i = 1; i <= n; i++)
    {
        cin >> ar[i];
        add_number(ar[i], i);
	}
    for(int i = 1; i <= tests; i++)
    {
        cin >> tp[i];
        if(tp[i] == 1)
        {
            cin >> l[i] >> val[i];
            add_number(val[i], l[i]);
        }
        else
            cin >> l[i] >> r[i] >> x[i];
    }
    for(int i = 1; i <= 23; i++)
        sort(V[i].begin(), V[i].end());
    for(int i = 1; i <= n; i++)
        turn_on(ar[i], i);
    for(int i = 1; i <= tests; i++)
    {
        if(tp[i] == 2)
            cout << solve(r[i], x[i]) - solve(l[i] - 1, x[i]) << endl;
        else
        {
            turn_off(ar[l[i]], l[i]);
            ar[l[i]] = val[i];
            turn_on(ar[l[i]], l[i]);
        }
	}
    return 0;
}

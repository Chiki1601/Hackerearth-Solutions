#include <bits/stdc++.h>
using namespace std;
int n, q = 0;
vector<int> val, op, comp, bit(500005);
vector<pair<int, int>> pos(500005), v[500005];
 
int query(int idx) 
{
    int res = 0;
    for(; idx; idx -= (idx & -idx))
        res += bit[idx];
    return res;
}
 
void update(int idx, int val) 
{
    for(; idx <= n; idx += (idx & -idx))
        bit[idx] += val;
}
 
int main() 
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    stack<int> st;
    cin >> n;
    for(int i = 1, ty, a, b; i <= n; i++) 
    {
        cin >> ty;
        if(ty == 0) 
            pos[i] = {ty, -1};
        else if(ty == 1) 
        {
            cin >> a;
            pos[i] = {ty, a};
            comp.emplace_back(a);
        } 
        else 
        {
            cin >> a >> b;
            pos[i] = {-1, -1};
            op.emplace_back(a);
            val.emplace_back(b);
            comp.emplace_back(b);
            q++;
        }
    }
    sort(comp.begin(), comp.end());
    for(int i = 1; i <= n; i++)
        if(pos[i].second != -1)
            pos[i].second = lower_bound(comp.begin(), comp.end(), pos[i].second) - comp.begin() + 1;
    for(int i = 0; i < q; i++)
        val[i] = lower_bound(comp.begin(), comp.end(), val[i]) - comp.begin() + 1;
    for(int i = 0; i < q; i++)
        v[op[i]].emplace_back(val[i], i);
    vector<int> ans(q);
    for(int i = 1; i <= n; i++) 
    {
        if(pos[i].first == 0) 
        {
            update(pos[st.top()].second, -1);
            st.pop();
        }
        else if(pos[i].first == 1) 
        {
            update(pos[i].second, 1);
            st.push(i);
        }
        for(int j = 0; j < v[i].size(); j++)
            ans[v[i][j].second] = query(v[i][j].first - 1);
    }
    for(int i : ans)
        cout << i << endl;
}

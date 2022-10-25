#include <bits/stdc++.h> 
using namespace std; 
int N, bit[200010];
 
bool cmp(const pair<pair<int, int>, int>& a, const pair<pair<int, int>, int>& b)
{
    if(a.first.first / 300 != b.first.first / 300)
        return a.first.first / 300 < b.first.first / 300;
    return a.first.second < b.first.second;
}
 
inline void add(int x, int v)
{
    for(; x <= N; x += x & -x)
        bit[x] += v;
}
 
inline int sum(int x)
{
    int ret = 0;
    for(; x > 0; x -= x & -x)
        ret += bit[x];
    return ret;
}
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int Q, A[200010], X[200010], l = 1, r = 1, pre = -1;
    long long ans[200000], inv = 0;
    pair<pair<int, int>, int> queries[200000];
    cin >> N >> Q;
    for(int i = 1; i <= N; i++)
    {
        cin >> A[i]; 
        X[i] = A[i];
    }
    sort(X + 1, X + 1 + N);
    for(int i = 1; i <= N; i++)
        A[i] = lower_bound(X + 1, X + 1 + N, A[i]) - X;
    for(int i = 0; i < Q; i++)
    {    
        cin >> queries[i].first.first >> queries[i].first.second; 
        queries[i].second = i;
    }
    sort(queries, queries + Q, cmp);
    for(int i = 0; i < Q; i++)
    {
        if(queries[i].first.first / 300 != pre)
        {
            memset(bit, 0, sizeof bit);
            l = r = queries[i].first.first;
            add(A[queries[i].first.first], 1);
            inv = 0;
            pre = queries[i].first.first / 300;
        }
        while(l < queries[i].first.first)
        {
            inv -= sum(A[l] - 1);
            add(A[l], -1);
            l++;
        }
        while(l > queries[i].first.first)
        {
            l--;
            add(A[l], 1);
            inv += sum(A[l] - 1);
        }
        while(r < queries[i].first.second)
        {
            r++;
            add(A[r], 1);
            inv += (r - l + 1) - sum(A[r]);
        }
        ans[queries[i].second] = inv;
    }
    for(int i = 0; i < Q; i++)
        cout << ans[i] << endl;
    return 0;
}

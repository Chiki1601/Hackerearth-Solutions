#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
template <class T>
using ordered_set = __gnu_pbds::tree<T, __gnu_pbds::null_type, less<T>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;
template <class T>
using ordered_multiset = __gnu_pbds::tree<T, __gnu_pbds::null_type, less_equal<T>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>; 
int N, Q, table [200010][18];
long long trees [2][200010], ret [200010];
 
pair<int, int> getNext(int st, int val)
{
    for(int j = 17; j > -1; j--)
        if(st + (1<<j) <= N + 1 && table[st][j] % val == 0)
            st += (1<<j);
    if(st == N + 1) 
        return {st, -1};
    return {st, __gcd(val, table[st][0])};
}
 
void add(int pos, long long x, long long y)
{
    while(pos <= N)
    {
        trees[0][pos] += x;
        trees[1][pos] += y;
        pos += (pos&-pos);
    }
}
 
long long query(int pos)
{
    long long sum = 0, ori = pos;
    while(pos > 0)
    {
        sum += ori * trees[0][pos] + trees[1][pos];
        pos -= (pos & -pos);
    }
    return sum;
}
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(10);
    cin >> N >> Q;
    for(int i = 1; i <= N; i++) 
        cin >> table[i][0];
    for(int j = 1; j < 18; j++)
        for(int i = 1; i + (1<<j) <= N + 1; i++)
            table[i][j] = __gcd(table[i][j - 1], table[i + (1<<(j - 1))][j - 1]);
    vector<pair<int, int>> queries [200010];
    for(int i = 0; i < Q; i++)
    {
        int L, R; 
        cin >> L >> R;
        queries[L].push_back({R, i});
    }
    for(int i = N; i > 0; i--)
    {
        int st = i, val = table[i][0];
        while(st <= N)
        {
            pair<int, int> trans = getNext(st, val);
            add(st, val, -(long long)(st - 1) * (long long)val);
            add(trans.first, -val, (long long)(trans.first - 1) * (long long)val);
            st = trans.first, val = trans.second;
        }
        for(pair<int, int> q : queries[i]) 
            ret[q.second] = query(q.first);
    }
    for(int i = 0; i < Q; i++) 
        cout << ret[i] << endl;
    return 0;
}

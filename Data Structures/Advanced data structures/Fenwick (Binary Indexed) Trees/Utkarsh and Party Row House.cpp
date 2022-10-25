#include<bits/stdc++.h>
using namespace std;
vector<int> G[200005];
signed long long int t1[100005], t2[100005];
 
signed long long int read(signed long long int *bit, int idx)
{
    signed long long int sum = 0;
    if(idx == 0)
        return 0;
    while (idx > 0)
    {
        sum += bit[idx];
        idx -= (idx & -idx);
    }
    return sum;
}
 
void update(signed long long int *bit, int idx, signed long long int val)
{
    while(idx <= 100000)
    {
        bit[idx] += val;
        idx += (idx & -idx);
    }
}
 
signed long long int rangeQuery(signed long long int *bit, int i, int j)
{
    return read(bit, j) - read(bit, i - 1);
}
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N, Q, L, R, K;
    signed long long int S, x;
    cin >> N >> Q;
    for(int i = 1; i <= N; ++i)
    {
        cin >> x;
        update(t1, i, x);
        update(t2, i, i * x);
    }
    while(Q--)
    {
        int C;
        cin >> C;
        if(C == 1)
        {
            cin >> K >> L >> R;
            signed long long int ans = 0;
            if(K <= L)
                ans = rangeQuery(t2, L, R) - rangeQuery(t1, L, R) * K;
            else if(K <= R)
                ans = rangeQuery(t2, K, R) - rangeQuery(t1, K, R) * K + rangeQuery(t1, L, K) * K - rangeQuery(t2, L, K);
            else
                ans = rangeQuery(t1, L, R) * K - rangeQuery(t2, L, R);
            cout << ans << endl;
        }
        else
        {
            cin >> K >> S;
            update(t1, K, S);
            update(t2, K, K * S);
        }
    }
}

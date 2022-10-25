#include<bits/stdc++.h>
using namespace std;
int bit[20][100009], N;
 
void upd(int at, int by, int c)
{
    for(; at <= N; at += at & -at)
        bit[c][at]+=by;
    return;
}
 
int query(int at,int c)
{
    int sum = 0;
    for(; at >= 1; at -= at & -at)
        sum += bit[c][at];
    return sum;
}
 
int distinct_dig(long long int num)
{
    int cnt[10], c = 0;
    memset(cnt, 0, sizeof cnt);
    long long int temp = num;
    while(temp > 0)
    {
        cnt[temp % 10] = 1;
        temp /= 10;
    }
    for(int i = 0; i < 10; ++i)
    {
        if(cnt[i])
            c++;
    }
    return c;
}
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    long long int temp, arr[100009];
    for(int i = 1; i <= N; ++i)
    {
        cin >> temp;
        arr[i] = temp;
        upd(i, 1, distinct_dig(temp));
    }
    int Q;
    cin >> Q;
    while(Q--)
    {
        int typ;
        cin >> typ;
        if(typ == 0)
        {
            long long int u, v;
            cin >> u >> v;
            upd(u, -1, distinct_dig(arr[u]));
            upd(u, 1, distinct_dig(arr[u] + v));
            arr[u] += v;
        }
        else if(typ == 1)
        {
            long long int u, v;
            cin >> u >> v;
            upd(u, -1, distinct_dig(arr[u]));
            upd(u, 1, distinct_dig(v));
            arr[u] = v;
        }
        else if(typ == 2)
        {
            int l, r, c;
            cin >> l >> r >> c;
            cout << query(r, c) - query(l - 1, c) << endl;
        }
    }
    return 0;
}

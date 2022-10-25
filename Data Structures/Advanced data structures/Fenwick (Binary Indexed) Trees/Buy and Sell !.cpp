#include<bits/stdc++.h>
using namespace std;
int BIT[100005];
 
int query(int x)
{
    int res = 0;
    for(; x; x -= (x & -(x))) 
        res += BIT[x];
    return res;
}
 
void update(int x, int idx)
{
    for(; x <= 100000; x += (x & (-x))) 
        BIT[x] += idx;
}
 
int main()  
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, i, idx, val[100004], cnt[100004], k, q;
    string s;
    char chr;
    map<string, int>mp;
    cin >> n;
    for(i = 1; i <= n; i++)
    {
        cin >> s;
        mp[s] = i;
        cin >> k;
        cnt[i] = 0;
        val[i] = k;
    }
    cin >> q;
    while(q--)
    {
        cin >> chr;
        if(chr == '+')
        {
            cin >> s;
            idx = mp[s];
            update(val[idx], 1);
            cnt[idx]++;
        }
        else if(chr == '-')
        {
            cin >> s;
            idx = mp[s];
            if(cnt[idx])
            {
                cnt[idx]--;
                update(val[idx], -1);
            }
        }
        else 
        {
            cin >> idx;
            cout << query(100000) - query(idx) << endl;
        }
    }
}

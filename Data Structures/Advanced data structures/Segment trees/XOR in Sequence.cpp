#include <bits/stdc++.h>
using namespace std;
long long int ctr, arr[100005], que[20][2], ans[20];
 
struct trie
{
    int ch[2], cnt;
    trie() 
    {
        ch[0] = ch[1] = cnt = 0;
    }
}tree[3100155];
 
void insert(long long int val) 
{
    long long int cur = 1, i;
    for(i = 30; i >= 0; i--)
    {
        tree[cur].cnt++;
        int h = (val >> i) & 1;
        if(!tree[cur].ch[h]) 
            tree[cur].ch[h] = ++ctr;
        cur = tree[cur].ch[h];
    }
    tree[cur].cnt++;
}
 
long long int query(long long int pre, long long int lm) 
{
    long long int ans = 0, i, cur = 1;
    for(i = 30; i >= 0; i--) 
    {
        int req = (lm >> i) & 1, h = (pre >> i) & 1;
        if(req) 
        {
            ans += tree[tree[cur].ch[h]].cnt;
            cur = tree[cur].ch[1 ^ h];
        }
        else 
            cur = tree[cur].ch[h];
    }
    ans += tree[cur].cnt;
    return ans;
}
 
int main() 
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t;
    cin >> t;
    while(t--) 
    {
        long long int n, i, j, q, pre = 0;
        cin >> n;
        for(i = 1; i <= n; i++) 
            cin >> arr[i];
        cin >> q;
        for(i = 1; i <= q; i++)
        {
            cin >> que[i][0] >> que[i][1];
            ans[i] = 0;
        }
        ctr = 1;
        insert(0);
        for(i = 1; i <= n; i++)
        {
            pre ^= arr[i];
            for(j = 1; j <= q; j++) 
            {
                long long int val1 = query(pre, que[j][1]), val2 = 0;
                if(que[j][0]) 
                    val2 = query(pre, que[j][0] - 1);
                ans[j] += val1 - val2;
            }
            insert(pre);
        }
        for(i = 1; i <= q; i++)
        {
            cout << ans[i] << endl;
            cout << endl;
        }
        for(i = 0; i <= ctr; i++)
            tree[i].ch[0] = tree[i].ch[1] = tree[i].cnt = 0;
    }
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
int BIT[1500020], N = 1500015;
 
void update(int x, int val)
{
    for(; x <= N; x += x & (-x))
        BIT[x] += val;
}
 
int query(int x)
{
    int sum = 0;
    for(; x > 0; x -= x & (-x))
        sum += BIT[x];
    return sum;
}
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, q, lft = 500005, rgt, pos[500005];
    long long sum = 0;
    cin >> n >> q;
    for(int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        pos[x] = lft + i - 1;
        update(pos[x], 1);
    }
    rgt = lft + n - 1;
    while(q--)
    {
        char ch;
        int x, a, b;
        cin >> x >> ch;
        b = query(rgt) - query(pos[x]);
        a = query(pos[x] - 1);
        sum += min(a, b);
        update(pos[x], -1);
        if(ch == 'r')
        {
            rgt++;
            pos[x] = rgt;
            update(pos[x], 1);
        }
        else
        {
            lft--;
            pos[x] = lft;
            update(pos[x], 1);
        }
    }
    cout << sum << endl;
    return 0;
}

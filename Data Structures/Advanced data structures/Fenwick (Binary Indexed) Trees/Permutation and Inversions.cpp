#include<bits/stdc++.h>
using namespace std;
int n, bit[100005];
 
void update(int i, int val)
{
    for(; i <= n; i += (i & -i))
        bit[i] += val;
}
 
int query(int i)
{
    int ans = 0;
    for(; i > 0; i -= (i & -i))
        ans += bit[i];
    return ans;
}
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t, m, l, r;
    cin >> t;
    while(t--)
    {
        memset(bit, 0, sizeof bit);
        cin >> n;
        int a[100005];
        for(int i = 1; i <= n; i++)
            cin >> a[i];
        long long sum = 0;
        for(int i = n; i >= 1; i--)
        {
            sum += query(a[i] - 1);
            update(a[i], 1);
        }
        long long final = sum;
        for(int i = 1; i <= n - 1; i++)
        {
            sum -= (a[i] - 1);
            sum += n - a[i]; 
            final ^= sum;
        }
        cout << final << endl;
    }
    return 0;
}

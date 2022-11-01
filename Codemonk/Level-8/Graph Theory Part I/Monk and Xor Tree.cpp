#include <bits/stdc++.h>
using namespace std;
long long ans = 0, ha[10000000], a[100005], k;
vector <int> v[100005];

void dfs(int r, long long xo)
{
    xo ^= a[r];
    ans += ha[xo ^ k];
    ha[xo]++;
    for(int i = 0; i < v[r].size(); i++)
        dfs(v[r][i], xo);
    ha[xo]--;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, x;
    cin >> n >> k;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    ha[0] = 1;
    for(int i = 1; i <= n - 1; i++)
    {
        cin >> x;
        v[x].push_back(i + 1);
    }
    dfs(1, 0);
    cout << ans << "\n";
    return 0;
}

#include<bits/stdc++.h>>
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m, a[10005][22], arr[22], tg, res;
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++) 
            cin >> a[i][j];
    for(int x = 1; x <= 18; x++)
    {
        for(int j = 1; j <= m; j++) 
            arr[j] = 0;
        for(int i = x; i <= n; i++)
        {
            tg = 0;
            for(int j = 1; j <= m; j++)
            {
                arr[j] = arr[j] ^ a[i][j];
                tg = max(tg, max(arr[j], arr[j] ^ tg));
            }
            res = max(res, tg);
        }
    }
    cout << res;
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
int pri[10001];
 
void soe()
{
    for(int i = 2; i <= 5000; i++)
        if(pri[i] == 1)
            for(int j = 2 * i; j <= 10000; j += i)
                pri[j] = 0;
}
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);    
    int n, k, val, ans1, ans2, ans3, i, j;
    pri[0] = 0;
    pri[1] - 0;
    for(i = 2; i <= 10000; i++)
        pri[i] = 1;
    soe();
    pri[10000] = 20000;
    for(i = 9999; i >= 0; i--)
    {
        if(pri[i] == 1)
            pri[i] = 0;
        else
            pri[i] = pri[i + 1] + 1;
    }
    ans1 = n + 1;
    ans2 = n + 1;
    ans3 = 50000;
    cin >> n >> k;
    int a[n][n];
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
            cin >> a[i][j];
    }
    for(i = 0; i < n - 2; i++)
    {
        for(j = 0; j < n - 2; j++)
        {
            if(pri[a[i][j]] < 10000 && pri[a[i][j + 2]] < 10000 && pri[a[i + 1][j + 1]] < 10000 && pri[a[i + 2][j]] < 10000 && pri[a[i + 2][j + 2]] < 10000)
            {
                if(pri[a[i][j]] % k == 0 && pri[a[i][j + 2]] % k == 0 && pri[a[i + 1][j + 1]] % k == 0 && pri[a[i + 2][j]] % k == 0 && pri[a[i + 2][j + 2]] % k == 0)
                {
                    val = pri[a[i][j]] / k + pri[a[i][j + 2]] / k + pri[a[i + 1][j + 1]] / k + pri[a[i + 2][j]] / k + pri[a[i + 2][j + 2]] / k;
                    if(val < ans3)
                    {
                        ans1 = i + 2;
                        ans2 = j + 2;
                        ans3 = val;
                    }
                }
            }
        }
    }
    if(ans1 < n + 1 && ans2 < n + 1)
    {
        cout << "yes" << endl;
        cout << ans3 << endl;
        cout << ans1 << " " << ans2 << endl;
    }
    else
        cout << "no" << endl;
    return 0;
}

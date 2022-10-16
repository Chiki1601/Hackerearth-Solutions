#include <bits/stdc++.h>
using namespace std;
int table[9][505][9][505], lg[505];
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    lg[2] = 1;
    for(int i = 3; i < 505; i++)
        lg[i] = lg[i / 2] + 1;
    int t = 1;
    cin >> t;
    while(t--)
    {
        int n, q;
        cin >> n;
        int a[n][n], val[n][n], down[n][n], right[n][n];
        for(int i = 0; i < n; i++) 
            for(int j = 0; j < n; j++) 
                cin >> a[i][j];
        for(int i = n - 1; i >= 0; i--)
        {
            for(int j = n - 1; j >= 0; j--)
            {
                down[i][j] = 1;
                if(i < n - 1 && (a[i][j] ^ a[i + 1][j] == 1))
                    down[i][j] = 1 + down[i + 1][j];
                right[i][j] = 1;
                if(j < n - 1 && (a[i][j] ^ a[i][j + 1] == 1))
                    right[i][j] = 1 + right[i][j + 1];
            }
        }
        for(int i = n - 1; i >= 0; i--)
        {
            for(int j = n - 1; j >= 0; j--)
            {
                val[i][j] = 1;
                if(i < n - 1 && j < n - 1 && a[i][j] == a[i + 1][j + 1])
                    val[i][j] = min(val[i + 1][j + 1] + 1, min(down[i][j], right[i][j]));
            }
        }
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++) 
                table[0][i][0][j] = val[i][j];
            for(int j = 1; j < 9; j++)
                for(int k = 0; k + (1 << (j - 1)) < n; k++)
                    table[0][i][j][k] = max(table[0][i][j - 1][k], table[0][i][j - 1][k + (1 << (j - 1))]);
        }
        for(int l = 1; l < 9; l++)
        {
            for(int i = 0; i + (1 << (l - 1)) < n; i++)
            {
                for(int j = 0; j < 9; j++)
                {
                    for(int k = 0; k < n; k++)
                        table[l][i][j][k] = max(table[l - 1][i][j][k], table[l - 1][i + (1 << (l - 1))][j][k]);
                }
            }
        }
        cin >> q;
        while(q--)
        {
            int l1, r1, l2, r2, l = 0, r = n;
            cin >> l1 >> r1 >> l2 >> r2;
            l1--, r1--, l2--, r2--;
            int res = l;
            while(l <= r)
            {
                int mid = (l + r) / 2;
                bool check = false;
                int len_l = l2 - mid + 1 - l1 + 1, len_r = r2 - mid + 1 - r1 + 1;
                if(len_l >= 1 && len_r >= 1)
                {
                    int lg_l = lg[len_l], lg_r = lg[len_r];
                    check |= table[lg_l][l1][lg_r][r1] >= mid;
                    check |= table[lg_l][l1][lg_r][(r2 - mid + 1) + 1 - (1 << lg_r)] >= mid;
                    check |= table[lg_l][l2 - mid + 1 + 1 - (1 << lg_l)][lg_r][r1] >= mid;
                    check |= table[lg_l][l2 - mid + 1 + 1 - (1 << lg_l)][lg_r][(r2 - mid + 1) + 1 - (1 << lg_r)] >= mid;
                }
                if(check)
                {
                    res = mid;
                    l = mid + 1;
                }
                else
                    r = mid - 1;
            }
            cout << res << "\n";
        }
    }
}

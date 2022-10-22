#include<bits/stdc++.h>
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	long long int n, q, i, j, k, m, r, c, s, d;
    cin >> n >> m >> q;
    long long int a[n][m];
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < m; j++)
            cin >> a[i][j];
    }
    for(i = 0; i < q; i++)
    {
        cin >> r >> c >> s >> d;
        for(j = r - 1; j < r + s - 1 ; j++)
        {
            for(k = c - 1; k < c + s - 1; k++)
                a[j][k] += d;
        }
    }
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < m; j++)
            cout << a[i][j] << " ";
        cout << endl;
    }
}

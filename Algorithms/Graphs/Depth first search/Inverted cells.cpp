#include <bits/stdc++.h>
using namespace std;
int n, m;
bool ok[1004][1004], a[1004][1004], b[1004][1004], ff[1004][1004];
char c[1004][1004];
 
int main()
{
    ios::sync_with_stdio(0), cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        cin >> c[i];
    for(int i = n - 1; i >= 0; i--)
        for(int j = m - 1; j >= 0; j--)
            ok[i][j] = c[i][j] == '.' && (i == n - 1 && j == m - 1 || ok[i + 1][j] || ok[i][j + 1]);
    if(!ok[0][0])
	{
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                ff[i][j] = c[i][j] == '.' && (i == 0 && j == 0 || i && ff[i - 1][j] || j && ff[i][j - 1]);
        for(int i = 0; i < n; i++)
		{
            for(int j = 0; j < m; j++)
                cout << ((j && ff[i][j - 1] || i && ff[i - 1][j]) && (ok[i + 1][j] || ok[i][j + 1])) << ' ';
            cout << endl;
        }
        return 0;
    }
    int x = 0, y = 0;
    bool allz = false;
    while(x != n - 1 || y != m - 1)
	{
        a[x][y] = true;
        if(ok[x + 1][y])
            x++;
        else if(ok[x][y + 1])
            y++;
        else
		{
            allz = true;
            break;
        }
    }
    a[x][y] = true;
    x = y = 0;
    while(x != n - 1 || y != m - 1)
	{
        b[x][y] = true;
        if(ok[x][y + 1])
            y++;
        else if(ok[x + 1][y])
            x++;
        else
		{
            allz = true;
            break;
        }
    }
    b[x][y] = true;
    for(int i = 0; i < n; i++)
	{
        for(int j = 0; j < m; j++)
            cout << !(allz || a[i][j] && b[i][j]) << ' ';
        cout << endl;
    }
}

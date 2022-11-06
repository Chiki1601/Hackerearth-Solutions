#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, r, c, a[1003][1003], t[1003], row[1003], col[1003];
    cin >> n >> r >> c;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> a[i][j];
    for(int i = 0; i < r; i++)
    {
    	int x;
    	cin >> x;
    	x--;
    	row[x]++;
    }
    for(int i = 0; i < c; i++)
    {
    	int x;
    	cin >> x;
    	x--;
    	col[x]++;
    }
    for(int i = 0; i < n; i++)
    {
    	int cnt = row[i];
    	for(int j = 0; j < n; j++)
            t[(j + cnt) % n] = a[i][j];
    	for(int j = 0; j < n; j++)
            a[i][j] = t[j];
    }
    for(int i = 0; i < n; i++)
    {
    	int cnt = col[i];
    	for(int j = 0; j < n; j++)
            t[(j + cnt) % n] = a[j][i];
    	for(int j = 0; j < n; j++)
            a[j][i] = t[j];
    }
    for(int i = 0; i < n; i++)
    {
    	for(int j = 0; j < n; j++)
            cout << a[i][j] << " ";
    	cout << endl;
    }
    return 0;
}

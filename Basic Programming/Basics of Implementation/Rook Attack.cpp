#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, m, maxi = 0, x = 0, y = 0;
	cin >> n >> m;
	long long a[n][m], row[n] = {0}, col[m] = {0};
	for(int i = 0; i < n; i++)
    {
		for(int j = 0; j < m; j++)
		    cin >> a[i][j];
	}
	for(int i = 0; i < n; i++)
    {
		for(int j = 0; j < m; j++)
		{    
            row[i] += a[i][j]; 
            col[j] += a[i][j];
        }
	}
	for(int i = 0; i < n; i++)
    {
		for(int j = 0; j < m; j++)
        {
			if(row[i] + col[j] - 2 * a[i][j] > maxi)
            {
				x = i; 
                y = j;
				maxi = row[i] + col[j] - 2 * a[i][j];
            }
		}
	}
	cout << x + 1 << " " << y + 1 << endl;
}

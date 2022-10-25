#include <bits/stdc++.h>
using namespace std;
int go[7014][7014];
 
int main() 
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int inv = 0, n, p[7014];
    cin >> n;
    for(int i = 0; i < n; ++i) 
	{
        cin >> p[i];
        for(int j = 0; j < i; ++j) 
            inv += p[j] > p[i];
    }
    for(int i = 0; i < n; ++i) 
	{
        for(int j = i + 1, greater = 0; j < n; ++j) 
		{
            go[i][j] = greater;
            greater += p[j] > p[i];
        }
        for(int j = i - 1, greater = 0; j >= 0; --j) 
		{
            go[i][j] = greater;
            greater += p[j] > p[i];
        }
    }
    int ans = inv;
    for(int i = 0; i < n; ++i) 
	{
        for(int j = i + 1; j < n; ++j)
            if(p[i] > p[j])
                ans = min(ans, inv - go[j][i] + (j - i - 1 - go[j][i]) + go[i][j] - (j - i - 1 - go[i][j]) - 1);
    }
    cout << ans << endl;
}

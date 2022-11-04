#include <bits/stdc++.h>
using namespace std;
 
int main() 
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    char a[1003][1003];
	int t, n, m, TEST_NO, ryt[1003][1003], dwn[1003][1003], buf[1003];
	cin >> t;
	for(TEST_NO = 1; TEST_NO <= t; TEST_NO ++) 
    {
		cin >> n >> m;
	    for(int i = 0; i < n; ++i) 
		    cin >> a[i];
		memset(ryt, 0, sizeof ryt);
        for(int j = m - 1; j >= 0; --j) 
        {
            for(int i = 0; i < n; ++i) 
            {
                if(a[i][j] == '0') 
                    ryt[i][j] = 0;
                else 
                    ryt[i][j] = 1 + ryt[i][j + 1];
            }
        }
        memset(dwn, 0, sizeof dwn);
        for(int i = n - 1; i >= 0; --i) 
        {
            for(int j = 0; j < m; ++j) 
            {
                if(a[i][j] == '0') 
                    dwn[i][j] = 0;
                else 
                    dwn[i][j] = 1 + dwn[i + 1][j];	
            }
        }
		int ans1 = 0, ans2 = 0;
        for(int j = 0; j < m; ++j) 
        {		
            for(int i = 0; i < n; ++i)
                buf[i] = ryt[i][j];		
            sort(buf, buf + n);		
            for(int i = 0; i < n; ++i)
                ans1 = max(ans1, buf[i] * (n - i));
        }
        for(int i = 0; i < n; ++i) 
        {		
            for(int j = 0; j < m; ++j)
                buf[j] = dwn[i][j];		
            sort(buf, buf + m);		
            for(int i = 0; i < m; ++i) 
                ans2 = max(ans2, buf[i] * (m - i));
        }
        cout << ans1 << " " << ans2 << endl;
	}
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
 
bool check(vector<int> a, vector<int> b) 
{
	int n = a.size(), m = b.size();
	sort((a).begin(), (a).end(), greater<int>());
	sort((b).begin(), (b).end(), greater<int>());
	int sum1 = 0, sum2t = 0, j = m - 1;
	for(int k = 1; k <= n; ++k)
    {
		sum1 += a[k - 1];
		while(j >= 0 && b[j] <= k * 4) 
        {
			sum2t += b[j];
			-- j;
		}
		int sum2 = sum2t + (j + 1) * (k * 4);
		if(sum1 > sum2) 
            return false;
	}
	return true;
}
 
int main() 
{
	int T;
	cin >> T;
	for(int ii = 0; ii < T; ++ii) 
    {
		int n, m;
		cin >> n >> m;
		vector<int> a(n), b(m);
		for(int i = 0; i < n; ++i) 
            cin >> a[i];
		for(int i = 0; i < m; ++i) 
            cin >> b[i];
		vector<vector<int>> ans(n, vector<int>(m));
		for(int i = 0; i < n; ++i) 
            a[i] -= m;
		for(int j = 0; j < m; ++j) 
            b[j] -= n;
		for(int i = 0; i < n; ++i) 
            for(int j = m - 1; j >= 0; -- j) 
            {
			    a[i] -= 4; 
                b[j] -= 4;
			    for(int d = 4; d >= 0; -- d) 
                {
				    if(a[i] >= 0 && b[j] >= 0 && check(a, b)) 
                    {
					    ans[i][j] = d + 1;
					    break;
				    }
				    ++a[i]; 
                    ++b[j];
			    }
		    }
		for(int i = 0; i < n; ++i)
        {
			for(int j = 0; j < m; ++j)
            {
				if(j != 0) 
                    putchar(' ');
				cout << ans[i][j];
			}
			puts("");
		}
	}
	return 0;
}

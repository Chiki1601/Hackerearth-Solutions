#include <bits/stdc++.h>
using namespace std;
     
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  	int t, n, m, a[105][105], ans[105];
   	cin >> t;
   	while(t--)
    {
   		cin >> n;
   		m = n;
   		for(int i = 1; i <= n; i++) 
            for(int j = 1; j <= n; j++) 
            {
                cin >> a[i][j]; 
                a[i][j] = -a[i][j];
            }
   		vector<int> u(n + 1), v(m + 1), p(m + 1), way(m + 1);
        for(int i = 1; i <= n; ++i) 
        {
            p[0] = i;
            int j0 = 0;
            vector<int> minv (m + 1, 1000000000);
            vector<char> used (m + 1, false);
            do 
            {
                used[j0] = true;
                int i0 = p[j0], delta = 1000000000, j1;
                for(int j = 1; j <= m; ++j)
                    if(!used[j]) 
                    {
                        int cur = a[i0][j] - u[i0] - v[j];
                        if(cur < minv[j])
                        {
                            minv[j] = cur; 
                            way[j] = j0;
                        }
                        if(minv[j] < delta)
                        {	
                            delta = minv[j];  
                            j1 = j;
                        }
                    }
                    for(int j = 0; j <= m; ++j)
                        if(used[j])
                        {
                            u[p[j]] += delta;  
                            v[j] -= delta;
                        }
                    else
                        minv[j] -= delta;
                j0 = j1;
            } while (p[j0] != 0);
            do 
            {
                int j1 = way[j0];
                p[j0] = p[j1];
                j0 = j1;
            } while (j0);
        }
        for(int i = 1; i <= m; i++)
            ans[p[i]] = i;
   		int sum = 0;
   		for(int i = 1; i <= n; i++) 
            sum += -a[i][ans[i]];
   		cout << sum << endl;
   	}
}

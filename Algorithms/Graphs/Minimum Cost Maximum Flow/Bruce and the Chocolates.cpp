#include <bits/stdc++.h>
using namespace std;
 
int main() 
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t, A[222], n, m, a[222][222], edge[222][222];
    cin >> t;
    while(t--) 
    {
        int e;
        cin >> n >> e;
        for(int i = 1; i < n; i++)
            cin >> A[i];
        n /= 2;
        m = n;
        memset(a, 0, sizeof(a));
        memset(edge, 0, sizeof(edge));
        while(e--) 
	    {
            int x, y;
            cin >> x >> y;
            if(y & 1) 
	  	        swap(x, y);
            a[(x + 1) / 2][y / 2] = -1 * __gcd(A[x], A[y]);
            edge[(x + 1) / 2][y / 2] = 1;
        }
        vector <int> u(n + 1), v(m + 1), p(m + 1), way(m + 1);
        for(int i = 1 ; i <= n ; ++i) 
        {
            p[0] = i;
            int j0 = 0;
            vector <int> minv (m + 1, 1000000000);
            vector <char> used (m + 1, false);
            do 
            {
                used[j0] = true;
                int i0 = p[j0], delta = 1000000000, j1;
                for(int j = 1 ; j <= m ; ++j)
                    if(!used [j]) 
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
            } while(p[j0] != 0);
            do 
            {
                int j1 = way[j0];
                p[j0] = p[j1];
                j0 = j1;
            } while(j0);
        }
        vector<int>ans (n + 1);
        for(int j = 1; j <= m; ++j)
            ans[p[j]] = j;
        int res = 0;
        for(int i = 1; i < n + 1; i++)
        {
            if(edge[i][ans[i]]) 
                res += __gcd(A[2 * i - 1], A[2 * ans[i]]);
        }
        cout << res << endl;
    }
    return 0;
}

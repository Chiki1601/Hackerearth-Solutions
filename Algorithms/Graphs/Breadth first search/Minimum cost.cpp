#include<bits/stdc++.h>
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    long long int tc, n, x, y;
    cin >> tc;
    while(tc--)
	{
        cin >> n;
        vector<int>a(n + 1), ans(n + 1, INT_MAX);
        for(int i = 1; i <= n; i++)
            cin >> a[i];
        ans[1] = 0;
        queue<int>q;
        q.push(1);
        while(!q.empty() && ans[n] == INT_MAX)
		{
            x = q.front();
            q.pop();
            y = x;
            while(ans[a[y]] > ans[y])
			{
                ans[a[y]] = ans[y];
                q.push(a[y]);
                y = a[y];
            }
            if(x - 1 >=1 && ans[x - 1] > ans[x] + 1)
			{
                ans[x - 1] = ans[x] + 1;
                q.push(x - 1);
            }
            if(x + 1 <= n && ans[x + 1] > ans[x] + 1)
			{
                ans[x + 1] = ans[x] + 1;
                q.push(x + 1);
            }
        }
        cout << ans[n] << endl;
    }
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
int p[100100];

int f(int x)
{
	return (x == p[x]) ? x : (p[x] = f(p[x]));
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t = 1, tab;
    tab = t;
    while(t--)
	  { 
        vector<array<int, 3>> ed;
        int n, m, s, e; 
        cin >> n >> m >> s >> e;
        for(int i = 1; i <= n; i++)
            p[i] = i;
        for(int i = 0; i < m; i++)
        {
			int x, y; 
            cin >> x >> y;
            ed.push_back({abs(x - y), x, y});
        }
        vector<int> A(n + 1);
        for(int i = 1; i <= n; i++)
            cin >> A[i];
			 for(auto &x : ed)
            x[0] = abs(A[x[1]] - A[x[2]]);
        sort((ed).begin(), (ed).end());
        for(auto x : ed)
		{
            p[f(x[1])] = f(x[2]);
            if(f(s) == f(e))
            {
                cout << x[0] << endl; 
                return 0;
            }
		}
	}
}

#include <bits/stdc++.h>
using namespace std;
 
void dfs(int i, vector<int> g[], vector<int> &h, int l )
{
	if(g[i].size() == 0)
		h.push_back(l);
     	for(int k : g[i])
         	dfs(k, g, h, l + 1);
	return; 
}
 
int main() 
{
    int t; 
	cin >> t;
    while(t--)
	{
        int n, s;
        cin >> n >> s;
        vector<int> g[n + 10];
        for(int i = 0; i < n - 1; i++)
		{
            int a, b;
            cin >> a >> b;
            g[a].push_back(b);
        }
        int m1 = 0, m2 = 0;
		vector<int> nv;
     	for(int i:g[1])
	 	{
     		vector<int> v;
     		dfs(i, g, v, 1);
     		sort(v.begin(), v.end(), greater<int>());
     		if(v[0] > m1)
			{
				m2 = m1;
				m1 = v[0];
			}
     		else if(v[0] > m2)
			 	m2 = v[0];
     		for(int k : v)
         		nv.push_back(k);
     	}
     	bool p = 0;
     	for(int y : nv)
		{
         	if(y != m1 && y != m2)
			 	p = 1;
     	}
     	if(!p)
		 	cout << (s / (n - 1) + ((s % (n - 1) ? 1 : 0)));
     	else 
		 	cout << 0;
     	cout << endl << endl;
    }
}

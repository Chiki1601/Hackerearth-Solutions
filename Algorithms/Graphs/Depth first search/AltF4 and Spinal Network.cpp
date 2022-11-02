#include<bits/stdc++.h>
using namespace std;
 
int main() 
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, t, u, v, f;
	bool *visit = new bool[10010];
	cin >> t; 
    while(t--) 
    {
		cin >> n; 
        f = 1; 
		for(int i = 0; i < n; i++)
            visit[i]=false;
		int deg[n], edg[n];
		memset(deg, 0, sizeof deg); 
        memset(deg, 0, sizeof deg);
		for(int i = 0; i < n - 1; i++)
        {    
            cin >> u >> v; 
            u -= 1; 
            v -= 1; 
            deg[u] += 1; 
            deg[v] += 1; 
            edg[u] = v; 
            edg[v] = u;
        }
		for(int i = 0; i < n; i++) 
            if(deg[i] == 1) 
                visit[i] = true;
		for(int i = 0; i < n; i++)
            if(visit[i]) 
            {    
                deg[edg[i]] -= 1; 
                deg[i] = -1;
            }
		for(int i = 0; i < n; i++) 
            if(deg[i] > 2) 
            { 
                f = 0; 
                break; 
            }
		if(f) 
            cout << "YES" << endl;
		else 
            cout << "NO" << endl;
	}
	delete visit;
} 

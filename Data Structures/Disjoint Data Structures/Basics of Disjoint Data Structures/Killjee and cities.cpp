#include<bits/stdc++.h>
using namespace std;
int par[1000001];
 
int root(int a)
{
	if(a == par[a])
        return a;
	return par[a] = root(par[a]);
}
 
void merge(int a, int b)
{
	int root_a = root(a), root_b = root(b);
	if(root_a != root_b)
 	    par[root_a] = root_b;
}
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, m, s, cnt = 0, q, s1;
    cin >> n >> m >> s;
    for(long long i = 1; i < n + 1; i++)
        par[i] = i;
    while(m--)
    {
  	    int u, v;
  	    cin >> u >> v;
  	    merge(u, v);
    }
    for(long long i = 1; i < n + 1; i++)
    {
  	    if(par[i] == i)
            cnt++;
    }
    cnt--;
    cin >> q >> s1;
    while(q--)
    {
  	    int u, v;
  	    cin >> u >> v;
  	    if(root(u) != root(v))
  	    {
  		    merge(u, v);
  		    cout << cnt - 1 << " ";
  		    cnt--;
  	    }
  	    else
  	    	cout << cnt << " ";
  	}
    return 0;
}

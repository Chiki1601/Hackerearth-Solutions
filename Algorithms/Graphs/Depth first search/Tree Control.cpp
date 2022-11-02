#include<bits/stdc++.h>
using namespace std;
 
int main() 
{ 
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N;
	cin >> N;
   	const int P = N + 1;
   	vector<long long> c(P);
   	for(int u = 1; u <= N; ++u)
    	cin >> c[u];
   	vector<int> p(P), w(P), ans(P);
   	for(int u = 2; u <= N; ++u)
    	cin >> p[u];
   	for(int u = 2; u <= N; ++u)
    	cin >> w[u];
   	for(int u = 2; u <= N; ++u) 
	{
      	long long m = c[u] + 1, d = w[u];
      	for(int v = p[u]; d < m and v > 0; d += w[v], v = p[v])
         	++ans[v]; 
	}
   	cout << ans[1];
   	for(int i = 2; i <= N; ++i)
      	cout << ' ' << ans[i]; 
   	return 0; 
}

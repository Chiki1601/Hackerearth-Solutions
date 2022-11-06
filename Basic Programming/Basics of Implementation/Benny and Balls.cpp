#include<bits/stdc++.h> 
using namespace std; 
 
int main()
{ 
	  int tests, n, cnt[100031], x, a, b, t, p[100031]; 
	  ios_base::sync_with_stdio(0); cin.tie(0); cin >> tests; 
	  for(; tests; --tests) 
	  {  
		    cin >> n; 
		    for(int i = 0; i < n; i++) 
		    { 
			      cin >> p[i]; 
			      cnt[i] = 0; 
		    } 
		    cin >> x >> a >> b >> t; 
		    int ans = 0; 
		    for(int i = 1; i <= t; i++) 
		    { 
			      cnt[x]++; 
			      if(cnt[x] >= p[x]) 
			      { 
				        ans++; 
				        cnt[x] = 0; 
			      } 
			      x = (1ll * x*a + b) % n; 
		    }
		    cout << ans << endl; 
	  } 
	  return 0; 
}

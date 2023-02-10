#include<bits/stdc++.h>
using namespace std;
vector<int> has[2002];
 
long long search(int l, int r, int x)
{
  	long long k1 = upper_bound(has[x].begin(), has[x].end(), r) - has[x].begin(), k2 = lower_bound(has[x].begin(), has[x].end(), l) - has[x].begin();
  	return (k1 - k2) > 0 ? (k1 - k2) : 0;
}
 
int main()
{
  	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  	int n, q, *a = new int[1000005];
  	cin >> n >> q;
  	for(int i = 0; i < n; ++i)
  	{
     	cin >> a[i];
     	has[a[i]].push_back(i);
  	}
  	while(q--) 
  	{
      	int l, r, x;
      	cin >> l >> r >> x;
      	long long ans = 0;
      	l--;
      	r--;
      	for(int i = 1; i <=x ; ++i)
	  	{
        	long long aa = 0;
        	if(i == (x - i))
			{
            	long long v = search(l, r, i);
            	aa += v * (v - 1);
        	}
			else
            	aa = search(l, r, i) * search(l, r, x - i);
        	ans += aa;
      	}
      	cout << ans / 2 << endl;
  	}
}

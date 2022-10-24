#include <bits/stdc++.h> 
using namespace std;
 
int main()
{   
	  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	  long long int n, q;
	  cin >> n >> q;
	  long long int a[n];
	  for(long long int i = 0; i < n; i++)
		    cin >> a[i];
	  sort(a, a + n);
	  map <int,int> mp;
	  mp.insert({-1, a[0]});
	  mp.insert({a[n - 1] + 1, INT_MAX});
	  for(int i = 1; i < n; i++)
		    if(a[i] - a[i - 1] > 1)
			      mp.insert({a[i - 1] + 1, a[i] - a[i - 1] - 2});
	  for(int i = 0; i < q; i++)
	  {
		    int x, a1 = INT_MAX, a2 = INT_MAX, ans;
		    cin >> x;
		    x++;
		    auto itr = mp.lower_bound(x);
		    if(itr->first == x)
			      ans = x;
		    else if(itr == mp.end())
			      ans = x;
		    else
		    {
			      a1 = itr->first;
			      itr--;
			      if(itr->first <= x && itr->second + itr->first >= x)
				        a2 = x;
			      ans = min(a1, a2);
		    }
		    cout << ans << endl;
	  }
}

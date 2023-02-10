#include <bits/stdc++.h>
using namespace std;
 
int main()
{
	  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	  int t;
	  cin >> t;
	  while(t--)
	  {
		    int n, q;
		    cin >> n >> q;
		    vector<pair<long long int, long long int>> v;
		    for(int i = 0; i < n; i++)
		    {
		  	    long long int a, b;
			      cin >> a >> b;
			      v.push_back({a, b});
		    }
		    sort(v.begin(), v.end());
		    long long int idx = 0;
		    for(long long int i = 1; i < v.size(); i++)
		    {
			      if(v[idx].second >= v[i].first)
				        v[idx].second = max( v[idx].second, v[i].second);
			      else
			      {
				        idx++;
				        v[idx] = v[i];
			      }
		    }
		    while(q--)
		    {
			      long long int k, ans = -1;
			      cin >> k;
			      for(int i = 0; i <= idx; i++)
			      {
				        if((v[i].second - v[i].first + 1) >= k)
				        {
					          ans = v[i].first + k - 1;
					          break;
				        }
				        else
					          k -= (v[i].second - v[i].first + 1);
			      }
			      cout << ans << endl;
		    }
	  }
	  return 0;
}

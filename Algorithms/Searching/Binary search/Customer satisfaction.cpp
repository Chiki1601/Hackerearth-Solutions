#include<bits/stdc++.h>
using namespace std;
int n;
vector<pair<long long, long long>> rz;
 
bool check(long long val)
{
	  long long res = 0;
	  for(int i = 0; i < n; i++)
	  {
		    long long temp = rz[i].first * val;
		    if(temp - res >= rz[i].second) 
            res += rz[i].second;
		    else 
            return false;
	  }
	  return true;
}
 
void test_case()
{
	  rz.clear();
	  cin >> n;
	  for(int i = 0; i < n; i++)
	  {
		    long long a, b, c;
		    cin >> a >> b >> c;
		    rz.push_back({ b, c });
	  }
	  sort(rz.begin(), rz.end());
	  long long l = 0, r = 1e13, ans = -1, mid;
	  while (l <= r)
	  {
		    mid = (l + r) / 2;
		    if (check(mid))
		    {
			      ans = mid;
			      r = mid - 1;
		    }
		    else 
            l = mid + 1;
	  }
	  cout << ans << endl;
}
 
int main()
{
	  ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	  int T;
	  cin >> T;
	  while (T--)
		    test_case();
	  return 0;
}

#include <bits/stdc++.h>
using namespace std;
 
int main() 
{
	  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	  int n, k;
	  cin >> n >> k;
	  vector<pair<int, int>> pts(k);
	  for(int i = 0; i < k; i++)
		    cin >> pts[i].first >> pts[i].second;
	  sort(pts.begin(), pts.end());
	  vector<int> prefMin(k), prefMax(k), suffMin(k), suffMax(k);
	  for(int i = 0; i < k; i++) 
	  {
		    prefMin[i] = min(pts[i].second, i > 0 ? prefMin[i-1] : INT_MAX);
		    prefMax[i] = max(pts[i].second, i > 0 ? prefMax[i-1] : INT_MIN);
	  }
	  for(int i = k - 1; i >= 0; i--) 
	  {
		    suffMin[i] = min(pts[i].second, i + 1 < k ? suffMin[i+1] : INT_MAX);
		    suffMax[i] = max(pts[i].second, i + 1 < k ? suffMax[i+1] : INT_MIN);
	  }
	  auto check = [&] (int x) -> bool 
	  {
		    if((prefMax[k-1] - prefMin[k-1] + 1) / 2 <= x)
			      return true;
		    for(int i=0, j=0; i<k; i++) 
		    {
			      while(j < k && (pts[j].first - pts[i].first + 1) / 2 <= x)
				        j++;
			          int minY = min(i > 0 ? prefMin[i - 1] : INT_MAX, j < k ? suffMin[j] : INT_MAX), maxY = max(i > 0 ? prefMax[i - 1] : INT_MIN, j < k ? suffMax[j] : INT_MIN);
			          if((i == 0 && j == k) || (maxY - minY + 1) / 2 <= x)
				            return true;
		    }
		    return false;
	  };
 	  int l = 0, r = n + 1;
	  while (l < r) 
	  {
		    int m = (l + r) / 2;
		    if(check(m))
			      r = m;
		    else
			      l = m + 1;
	  }
	  cout << l << endl;
	  return 0;
}

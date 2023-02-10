#include <bits/stdc++.h>
using namespace std;
 
int main()
{
	  int n, q;
	  long long x;
	  cin >> n >> q;
	  assert(1 <= n and n <= 100000);
	  assert(1 <= q and q <= 100000);
	  vector <long long > v;
	  for(int i = 0; i < n; ++i)
	  {
		    cin >> x;
		    v.push_back(x);
	  }
	  sort(v.begin(), v.end());
	  string s;
	  for(int i = 0;i < q;++i)
	  {
		    cin >> x;
		    assert(1 <= x and x <= 1000000000LL);
		    if(binary_search(v.begin(), v.end(), x))
			      s = "YES";
		    else
			      s = "NO";
		    cout << s << endl;
	  }
}

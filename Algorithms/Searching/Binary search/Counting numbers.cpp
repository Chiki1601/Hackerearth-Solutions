#include <bits/stdc++.h>
using namespace std;
vector<int> pos[10];
vector<int>::iterator p;
 
int lower_bound(int first, int last, int right, int K, int L) 
{
	  while (last - first > 0) 
    {
		    int m = (first + last) / 2;
		    if(max(m, K + p[m - 1] - right) < L) 
			      first = ++m;
        else
			      last = m;
	  }
	  return first;
}
 
int G(int left, int right, int K, int L) 
{
	  for (int i = 9; i >= 0; --i) 
    {
		    auto min_pos = lower_bound(pos[i].begin(), pos[i].end(), left);
		    auto max_pos = upper_bound(pos[i].begin(), pos[i].end(), right);
		    p = min_pos;
		    int c = max_pos - min_pos;
		    if (c > 0) 
        {
			      int t[c + 1];
			      t[1] = max(1, K + p[0] - right);
			      if(t[1] > L)
				        return G(left, p[0] - 1, t[1] - 1, L);
			      t[c] = max(c, K + p[c - 1] - right);
			      if (t[c] < L)
				        return G(p[c - 1] + 1, right, K - t[c], L - t[c]);
			      int j = lower_bound(1, c + 1, right, K, L);
			      t[j] = max(j, K + p[j - 1] - right);
			      t[j - 1] = max(j - 1, K + p[j - 2] - right);
			      if(t[j] == L) 
				        return i;
            else 
				        return G(p[j - 2] + 1, p[j - 1] - 1, t[j] - t[j - 1] - 1, L - t[j - 1]);
		    }
	  }
}
 
int main() 
{
	  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	  string x;
	  cin >> x;
	  int n = x.size();
	  for(int i = 1; i <= n; ++i)
		    pos[x[i - 1] - '0'].push_back(i);
	  int m;
	  cin >> m;
	  for(int i = 0; i < m; ++i) 
    {
		    int k, l;
		    cin >> k >> l;
		    cout << G(1, n, k, l);
	  }
	  cout << endl;
}

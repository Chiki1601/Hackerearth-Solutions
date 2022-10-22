#include <bits/stdc++.h>
using namespace std;
 
int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
 	int T;
  	cin >> T;
  	for(int n, k; T-- > 0 && cin >> n >> k; ) 
	{
    	unordered_map<int, int> c;
    	for(int i = 0, x; i < n && cin >> x; ++i) 
			++c[x];
    	int ck = c[k];
    	priority_queue<int> q;
    	for(const auto& p : c) 
			if(p.first != k) 
				q.push(p.second);
    	int o = 0;
    	while(!q.empty() && ck <= q.top()) 
		{
      		int x = q.top();
      		q.pop();
      		++ck;
      		--x;
      		q.push(x);
      		++o;
    	}
    	cout << o << endl;
  	}
    return 0;
}

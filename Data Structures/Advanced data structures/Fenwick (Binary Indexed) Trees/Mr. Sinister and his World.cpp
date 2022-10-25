#include <bits/stdc++.h>
using namespace std;
 
int main()
{
	ios_base::sync_with_stdio(false); cout.tie(0); cin.tie(0);
	int t, n, q, i, x, y, a, b, c, A[100001];
	cin >> t;
	for(int xt = 1; xt <= t; ++xt) 
    {
       	set <int> se;
       	multiset <pair<int, pair<int, int>>> pq;
		cout << "Case " << xt << ":" << endl;
		pq.clear();
		se.clear();
		cin >> n;
		for(i = 0; i < n; ++i) 
           	cin >> A[i];
		sort(A, A + n);
       	set <int> :: iterator it;
		for(i = 0; i < n; ++i) 
       	{
			y = A[i];
			se.insert(y);
			it = se.lower_bound(y);
			if(it != se.begin()) 
           	{
				x = *(--it);
				pq.insert(make_pair(y - x, make_pair(x, y)));
			}
		}
		cin >> q;
		while(q--) 
        {
			cin >> c;
			if(c == 1) 
           	{
				cin >> x;
				se.insert(x);		
				it = se.lower_bound(x);
				if(it == se.begin()) 
                   	a = -1;
				else 
                   	a = *(--it);
				it = se.upper_bound(x);
				if(it == se.end()) 
                   	b = -1;
				else 
                   	b = *(it);
				if(a != -1 && b != -1) 
                   	pq.erase(pq.find(make_pair(b - a, make_pair(a, b))));
				if(a != -1) 
                   	pq.insert(make_pair(x - a, make_pair(a, x)));		
				if(b != -1) 
                   	pq.insert(make_pair(b - x, make_pair(x, b)));
			} 
            else if(c == 2) 
            {
               	pair<int, pair<int, int>> p;
				p = *(--pq.end());
				cout << p.first << " " << p.second.first << " " << p.second.second << endl;
			} 
            else if(c == 3) 
            {
				cin >> x;
				it = se.lower_bound(x);
				if(it == se.begin()) 
                   	a = -1;
				else 
                   	a = *(--it);
				it = se.upper_bound(x);
				if(it == se.end()) 
                   	b = -1;
				else 
                   	b = *(it);
				if(a != -1) 
                   	pq.erase(pq.find(make_pair(x - a, make_pair(a, x))));
				if(b != -1) 
                   	pq.erase(make_pair(b - x, make_pair(x, b)));
				if(a != -1 && b != -1) 
                   	pq.insert(make_pair(b - a, make_pair(a, b)));
				se.erase(x);
			}
		}
	}
	return 0;
}

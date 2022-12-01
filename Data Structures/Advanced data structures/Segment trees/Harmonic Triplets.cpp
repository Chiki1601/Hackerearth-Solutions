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
		long long a[n], b[n], c[n];
		for(int i = 0; i < n; i++)
			cin >> a[i];
		set<long long> si1;
		b[0] = 0;
		si1.insert(a[0]);
		for(int i = 1; i < n; i++)
        {
			auto it1 = si1.upper_bound(a[i]);
			if(it1 != si1.begin())
            {
				it1--;
				b[i] = *it1;
			}
            else
				b[i] = 0;
			si1.insert(a[i]);
		}
		si1.clear();
		c[n - 1] = 0;
		si1.insert(a[n - 1]);
		for(int i = n - 2; i >= 0; i--)
        {
			auto it1 = si1.upper_bound(a[i]);
			if(it1 != si1.begin())
            {
				it1--;
				c[i] = *it1;
			}
            else
				c[i] = 0;
			si1.insert(a[i]);
		}
		si1.clear();
		while(q--)
        {
			int n1;
			cin >> n1;
			cout << a[n1 - 1] * b[n1 - 1] * c[n1 - 1] << endl;
		}
	}
}

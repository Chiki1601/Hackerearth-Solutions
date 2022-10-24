#include <bits/stdc++.h>
using namespace std;
 
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);	
	long long int t;
	cin >> t;
	while(t--)
	{
		long long int n, m, q;
		cin >> n >> m >> q;
		long long int a[q + 2], b[q + 2];
		for(long long int i = 0; i < q; i++)
			cin >> a[i] >> b[i];
		a[q] = 1;
		a[q + 1] = n;
		b[q] = 1;
		b[q + 1] = m;
		sort(a, a + q + 2);
		sort(b, b + q + 2);
		vector <long long int> v1, v2;
		for(long long int i = q + 1; i >= 1; i--)
		{
			if(a[i] - a[i - 1] != 0) 
				v1.push_back(a[i] - a[i - 1]);
			if(b[i] - b[i - 1] != 0) 
				v2.push_back(b[i] - b[i - 1]);
		}
		sort(v1.begin(), v1.end());
		sort(v2.begin(), v2.end());
		cout << v1.size() * v2.size() << " " << v1[0] * v2[0] << " " << v1[v1.size() - 1] * v2[v2.size() - 1] << endl;
	}
}

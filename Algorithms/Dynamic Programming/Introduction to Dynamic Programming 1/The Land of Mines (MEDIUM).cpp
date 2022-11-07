#include<bits/stdc++.h>
using namespace std;
 
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	long long t; 
	cin >> t;
	while(t--)
	{
		long long n, k; 
		cin >> n >> k;
		long long a[n], right = 0, count = 0;
		for(int i = 0; i < n; i++)
			cin >> a[i];
		map<long long, long long>mp;
		for(int i = 0; i < n; i++)
		{
			mp[a[i]]++;
			if(mp[a[i]] >= k)
			{
				while(a[right] != a[i])
				{
					mp[a[right]]--;
					count += n - i;
					right++;
				}
				count += n - i;
				mp[a[right]]--;
				right++;
			}
		}
		cout << count << endl;
	}
	return 0;
}

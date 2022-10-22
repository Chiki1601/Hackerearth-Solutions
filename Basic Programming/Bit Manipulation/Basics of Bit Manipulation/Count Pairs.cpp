#include<bits/stdc++.h> 
using namespace std;
 
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    long long int t, n; 
	cin >> t;
    while(t--)
    {   
		cin >> n;
		vector<long long int> bits(32, 0);
		long long int total = (n * (n - 1LL)) / 2LL, x;
		for(int i = 0; i < n; i++)
		{
			cin >> x;
			for(long long int j = 31; j >= 0; j--)
			{
				if(x & (1LL<<j))
				{
					total -= bits[j];
					bits[j]++;
					break;
				}
			}
		}
		cout << total << endl;
	}
    return 0;
}

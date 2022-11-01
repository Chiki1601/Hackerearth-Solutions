#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  	long long t; 
	cin >> t;
  	while(t--)
  	{
    	long long n; 
		cin >> n;
    	map<long long, long long> m;
    	for(int i = 1; i <= n; i++)
		{
      		long long temp;
			cin >> temp;
      		m[temp]++;
    	}
    	long long x = (*m.begin()).second;
        if(x & 1)
			cout << "Lucky" << endl;
    	else 
			cout << "Unlucky" << endl;
  	}
  	return 0;
}

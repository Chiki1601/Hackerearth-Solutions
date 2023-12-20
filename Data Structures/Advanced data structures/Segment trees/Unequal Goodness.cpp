#include <bits/stdc++.h>
using namespace std;

int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int tc;
	cin >> tc;
	while(tc--) 
	{
		int n;
		cin >> n;
		vector<int> A(n);
		for(int& a : A) 
			cin >> a;
		long long minSum = 0, minSum2 = LLONG_MAX, sum = 0, ans = LLONG_MIN;
		int a = A[0];
		for(int i = 0; i < n; ++i) 
		{
			if(a != A[i]) 
				ans = max(ans, sum + A[i] - minSum);
			else if(minSum2 != LLONG_MAX) 
				ans = max(ans, sum + A[i] - minSum2);
			if(sum <= minSum) 
			{
				if(a != A[i]) 
					minSum2 = minSum;
				minSum = sum;
				a = A[i];
			} 
			else if(sum < minSum2) 
			{
				if(a != A[i]) 
					minSum2 = sum;
			}
			sum += A[i];
		}
		if(ans == LLONG_MIN) 
			cout << "Not Possible" << endl;
		else 
			cout << ans << endl;
	}
}

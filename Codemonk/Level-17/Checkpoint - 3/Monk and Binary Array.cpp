#include<bits/stdc++.h>
using namespace std;
int arr[2000], x0[2001], x1[2001];

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  	int n, tot = 0, res = 0; 
	cin >> n;
  	for(int i = 0; i < n; ++i) 
	  	cin >> arr[i];
  	for(int i = 0; i < n; ++i)
	{
    	int test = 0; 
		for(int j = i; j < n; ++j)
		{
      		test ^= arr[j];
      		if(test)
			{ 
				tot++; 
				x1[i]++; 
				x1[j + 1]--; 
			}
      		else 
			{ 
				x0[i]++; 
				x0[j + 1]--; 
			}
    	}
  	}
  	for(int i = 1; i < n; ++i)
	{
    	x1[i] += x1[i - 1];
    	x0[i] += x0[i - 1];
	}
	for(int i = 0; i < n; i++) 
		res = max(res, tot - x1[i] + x0[i]);
	cout << res;
  	return 0;
}

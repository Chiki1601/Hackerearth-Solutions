#include<bits/stdc++.h> 
using namespace std;
 
int main()
{
 	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, freq = 0, sq;
	cin >> n;
	int ar[n], pre[n];
	for(int i = 0; i < n; i++)
		cin >> ar[i];
	pre[0] = ar[0];
	for(int i = 1; i < n; i++)
		pre[i] = pre[i - 1] + ar[i];
	pre[-1] = 0;
	for(int i = 0; i < n; i++)
	{
		for(int j = i; j < n; j++)
		{
			sq = sqrt(pre[j] - pre[i - 1]);
			if((sq * sq) == pre[j] - pre[i - 1])
				freq++;
		}
	}
	cout << freq;
}

#include <bits/stdc++.h>
using namespace std;
 
int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	unsigned long N, i, j, temp, ans;
	bitset<2000> G[2000];
	cin >> N;
	for(i = 0; i < N; i++) 
	{
		for(j = 0; j < N; j++) 
		{
			cin >> temp;
			G[i][j] = (temp == 1);
		}
	}
	for(i = 0; i < N; i++) 
	{
		for(j = i + 1; j < N; j++) 
		{
			temp = (G[i] & G[j]).count();
			ans += temp * (temp - 1) / 2; 
		}
	}
	cout << ans / 2;
	return 0;
}

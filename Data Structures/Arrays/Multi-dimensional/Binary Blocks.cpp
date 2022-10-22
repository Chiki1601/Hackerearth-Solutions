#include <bits/stdc++.h>
using namespace std;
 
int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	vector<string> pixels(n);
	for (int i = 0; i < n; i++) 
		cin >> pixels[i];
	int minCount = INT_MAX;
	for(int k = 2; k < 10; k++) 
	{
		int total = 0;
		for(int i = 0; i < n; i += k) 
		{
			for(int j = 0; j < m; j += k) 
			{
				int one = 0;
				for(int l = i; l < i + k; l++) 
				{
					if(l >= n) 
						break;
					for(int p = j; p < j + k; p++) 
					{
						if(p >= m) 	
							break;
						if(pixels[l][p] == '1')
							one++;
					}
				}
				int zero = k * k - one;
				int toggle = min(zero, one);
				total += toggle;
			}
		}
		if(total < minCount) 
			minCount = total;
	}
	cout << minCount;
	return 0;
}

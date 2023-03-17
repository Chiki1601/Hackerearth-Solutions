#include <bits/stdc++.h>
using namespace std;

int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	long long int i, j, n, k;
	cin >> n >> k;
	vector<long long int> ar(n);
	for(i = 0; i < n; i++)
		cin >> ar[i];
	sort(ar.begin(), ar.end());
	vector<long long int> br(n, 0);
	int c = 0;
	j = n / 2;
	for(i = 0; i <= n / 2 - 1; i++)
    {
		while(j < n && ar[j] < ar[i] + k)
			j++;
		if(j < n && ar[j] >= ar[i] + k)
        {
			c++;
			ar[j] = -1;
		}
	}
    cout << c;
}

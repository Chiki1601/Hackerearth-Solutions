#include <bits/stdc++.h>
using namespace std;
int phi[1000017], divs[1000017];
 
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	for(int i = 1; i < 1000017; i++)
    {
		phi[i] += i;
		for(int j = i * 2; j < 1000017; j += i)
			phi[j] -= phi[i];
		for(int j = i; j < 1000017; j += i)
			divs[j]++;
	}
    int q;
	cin >> q;
	while(q--)
    {
		int n;
		cin >> n;
		cout << n - phi[n] - divs[n] + 1 << endl;
	}
}

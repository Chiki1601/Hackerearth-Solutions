#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;
	for(int i = 1 ; i <= k - 1 ; i++)
		cout << i << " ";
	cout << n << endl;
	for(int i = k ; i >= 1 ; i--)
		cout << i << " ";
	cout << endl;
	for(int i = 1 ; i <= k ; i++)
		cout << i << " ";
	cout << endl;
}

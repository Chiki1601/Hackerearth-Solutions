#include <bits/stdc++.h>
using namespace std;
 
int main() 
{
	int n, i, arr[26] = {0};;
	cin >> n;
	string s;
	cin >> s;
	for(i = 0; i < s.length(); i++)
		arr[s[i] - 'a']++;
	sort(arr, arr + 26);
	cout << n - arr[25];
}

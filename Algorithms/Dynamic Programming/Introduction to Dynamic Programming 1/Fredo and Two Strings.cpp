#include<bits/stdc++.h>
using namespace std;
 
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	string s1, s2;
	cin >> s1 >> s2;
	int n1 = s1.length(), n2 = s2.length();
	int af[n1 + 2] = {0}, ab[n1 + 2] = {0}, j = 0;
	for(int i = 0; i < n1; i++)
	{
		if(s1[i] == s2[j] && j < n2)
		j++;
		af[i + 1] = j;
	}
	j = n2 - 1;
	for(int i = n1 - 1; i >= 0; i--)
	{
		if(s1[i] == s2[j] && j >= 0)
		j--;
		ab[i + 1] = n2 - j - 1;
	}
	int q, l, r, x;
	cin >> q >> x;
	while(q--)
	{
		cin >> l >> r;
        l--,r++;
		if(af[l] + ab[r] >= n2)
		    cout << "Yes" << endl;
		else
		    cout << "No" << endl;
	}
}

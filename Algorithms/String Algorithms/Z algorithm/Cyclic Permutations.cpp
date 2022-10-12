include<bits/stdc++.h>
using namespace std;
 
vector<int> get_lps(string s)
{
	int n = s.size(), l = 0, i = 1;
	vector<int> lps(n, 0);
	while(i < n) 
	{
		if(s[i] == s[l])
		{
			l++;
			lps[i] = l;
			i++;
		}
		else
		{
			if(l == 0) 
				i++;
			else 
				l = lps[l - 1];
		}
	}
	return lps;
}
 
void solve()
{
	string A, B;
	cin >> A >> B;
	vector<int> lps = get_lps(A);
	int cnt = 0, i = 0, j = 0;
	B = B + B;
	while(j < B.size() - 1)
	{
		if(A[i] == B[j])
		{
			i++;
			j++;
		}
		if(i == A.size())
		{
			cnt++;
			i = lps[i - 1];
		}
		else if(A[i] != B[j])
		{
			if(i == 0) 
				j++;
			else 
				i = lps[i-1];
		}
	}
	cout << cnt << endl;
}
 
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int t;
	cin >> t;
	for(int i = 0; i < t; i++) 
		solve();
}

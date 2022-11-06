#include<bits/stdc++.h>
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    long long int t; 
    cin >> t; 
    while(t--)
    {
        string s;
	cin >> s;
	long long int A[s.size()], index = s.size();
	for(long long int i = s.size() - 1; i >= 0; i--)
	{
	    if(s[i] == 'a' || s[i] == 'z')
	        index = i;
	    A[i] = index;
	}
	long long int ans = 0;
	for(long long int i = 0; i < s.size(); i++)
	    ans += s.size() - A[i];
	cout << ans << endl;
    }
}

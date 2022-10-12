#include<bits/stdc++.h>
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	long long t = 1;
	while(t--)
	{
        string s;
        cin >> s;
        long long n = s.length();
        vector<long long> pi(n, 0);
        for(long long i = 1; i < n; i++)
        {
            long long j = pi[i - 1];
            while(j && s[i] != s[j])
                j = pi[j - 1];
            if(s[i] == s[j])
                j++;
            pi[i] = j;
        }
        long long cnt = 0, j = 1;
        for(long long i = 1; i < n; i += 2, j++)
        {
            if(pi[i] == j)
                cnt++;
            if(pi[i] > j && s[j] == s[j - 1])
                cnt++;
        }
        cout << cnt;
    }
}

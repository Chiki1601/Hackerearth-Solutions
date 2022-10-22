#include<bits/stdc++.h>
using namespace std;
string st;
long long pw[1<<20], s[1<<20];
 
int check(int span)
{
	unordered_set<long long> S;
    S.clear();
    for(int i = 0; i + span <= st.size(); i++)
    {
        long long Q = s[i + span] - s[i];
        Q *= pw[1000000 - i];
        if(S.find(Q) != S.end())
            return true;
        S.insert(Q);
    }
    return false;
}
 
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
	cin >> st;
	pw[0] = 1;
	for (int i = 1; i <= 1000000; i++)
    	pw[i] = pw[i - 1] * 173;
	for (int i = 1; i <= st.size(); i++)
    	s[i] = s[i - 1] + st[i - 1] * pw[i - 1];
 	int l = 0, r = st.size();
	while(l < r)
	{
    	int mid = l + r + 1;
    	mid /= 2;
    	if(check(mid))
        	l = mid;
    	else
        	r = mid - 1;
	}
 	cout << l << endl;
	return 0;
}

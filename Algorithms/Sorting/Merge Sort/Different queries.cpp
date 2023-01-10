#include<bits/stdc++.h>
using namespace std;
  
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	long long n, q;
    cin >> n >> q;
	long long arr[n + 1];
	vector<pair<long long, pair<long long, long long>>> neg, pos, st;
	for(int i = 1; i < (int)n + 1; i++)
        cin >> arr[i];
	while(q--)
    {
		long long t, l, r, x;
        cin >> t >> l >> r >> x;
		if(t == 1)
        {
			if(x < 0)
                neg.push_back({x,{l,r}});
			else 
                pos.push_back({x,{l,r}});
		}
		else 
            st.push_back({x,{l,r}});
	}
	sort(st.begin(), st.end());
	for(int i = 0; i < (int)neg.size(); i++)
    {
		long long x = neg[i].first, l = neg[i].second.first, r = neg[i].second.second;
		for(long long i = l; i <= r; i++)
            arr[i] += x;
	}
	for(int i = 0; i < (int)st.size(); i++)
    {
		long long x = st[i].first, l = st[i].second.first, r = st[i].second.second;
		for(long long i = l; i <= r; i++)
            arr[i] = x;
	}
	for(int i = 0; i < (int)pos.size(); i++)
    {
		long long x = pos[i].first, l = pos[i].second.first, r = pos[i].second.second;
		for(long long i = l; i <= r; i++)
            arr[i] += x;
	}
	for(int i = 1; i < (int)n + 1; i++)
        cout << arr[i] << " ";
	return 0;
}

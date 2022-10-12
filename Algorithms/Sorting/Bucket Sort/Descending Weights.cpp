#include<bits/stdc++.h>
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, k;
	  cin >> n >> k;
    vector<pair<int, int>>v;
    for(int i = 0; i < n; i++)
	  {
        int x;
		    cin >> x;
        int y = x % k;
        v.push_back({y, -x});
    }
    sort(v.rbegin(), v.rend());
    for(int i = 0; i < v.size(); i++)
        cout << (-v[i].second) << " ";
    return 0;
}

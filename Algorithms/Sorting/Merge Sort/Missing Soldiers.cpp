#include<bits/stdc++.h>
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
	  cin >> t;
    int maxx = 1,sum = 0;
    vector<pair<int, int>>v;
    for(int i = 0; i < t; i++)
	  {
        int x, y, d;
		    cin >> x >> y >> d;
        v.push_back({x, x + d});
    }
    sort(v.begin(), v.end());
    for(int i = 0; i < v.size(); i++)
	  {
        maxx = max(maxx, v[i].first);
        if(maxx<=v[i].second)
		    {
            sum += v[i].second - maxx + 1;
            maxx = v[i].second + 1;
        }
    }
    cout << sum << endl;
    return 0;
}

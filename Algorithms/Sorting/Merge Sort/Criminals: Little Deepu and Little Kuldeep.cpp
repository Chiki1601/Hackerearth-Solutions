#include<bits/stdc++.h>
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
	  cin >> t;
    while(t--)
	  {
        map<long,long>m;
        int n;
		    cin >> n;
        for(int i = 0; i < n; i++)
		    {
            int x;
			      cin >> x;
            m[x]++;
        }
        long max = LONG_MIN;
        for(auto it:m)
            if(max < it.second)
                max = it.second;
        cout << max << endl;
    }
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        int n, k;
        cin >> n >> k;
        int ans = INT_MAX, arr[n];
        for(int i = 0; i < n; i++)
			cin >> arr[i];
        for(int val = 0; val <= 100; val++)
        {
            vector<int> curr;
            for(int i = 0; i < n; i++)
            {
                if(arr[i] <= val)
					curr.push_back((val - arr[i]) * 3);
                else
                    curr.push_back((arr[i]-val)*5);
            }
            sort(curr.begin(), curr.end());
            int cost = 0;
            for(int i = 0; i < k; i++)
				cost += curr[i];
            ans = min(ans, cost);
        }
        cout << ans << endl;
    }
}

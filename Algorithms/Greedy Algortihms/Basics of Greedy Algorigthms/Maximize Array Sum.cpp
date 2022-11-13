#include<bits/stdc++.h>
using namespace std;
 
int main()
{
	  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	  int t;
	  cin >> t;
	  while(t--)
    {
        int n;
        cin >> n;
        long long a[n], sum = 0, ans = LLONG_MIN;
        for(int i = 0; i < n; i++)
            cin >> a[i];
        sort(a, a + n);
        for(int i = 0; i < n; i++)
		    {
            ans = max(ans, sum + a[i] * (n - i));
            sum -= a[i];
        }
        cout << ans << endl;
    }
}

#include<bits/stdc++.h>
using namespace std;
 
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int t, n;
	cin >> t;
	while(t--)
	{
		cin >> n;
    	int g = n / 12, ans = -1;
    	for(int i = g; i >= 0; i--)
		{
        	int f = n - 12 * i;
        	if(f % 10 == 0)
			{
				ans = i + f / 10;
    			break;
        	}
    	}
    	cout << ans << endl;
	}
}

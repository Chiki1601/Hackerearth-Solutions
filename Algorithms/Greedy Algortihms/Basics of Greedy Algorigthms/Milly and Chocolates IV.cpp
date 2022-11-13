#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    long long int t, n, k, m;
    cin >> t;
    while(t--)
    {
    	cin >> n >> k >> m;
    	int p[n];
		for(int i = 0; i < n; i++)
    		cin >> p[i];
    	long long int time, min_time = 999999999999999, breaking, ans;
		for(int i = 0; i < n; i++)
    	{
    		time = 0;
			time = p[i] * k + (p[i] - 1) * m;
			for(int j = 0; j < p[i]; j++)
    		{
    			cin >> breaking;
    			time += breaking;
			}
			if(min_time > time)
			{
			    min_time = time;
				ans = i + 1;	
			}
		}
		cout << ans << " " << min_time << endl;
	}
	return 0;
}

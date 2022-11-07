#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t;
    cin >> t;
    while(t--)
    {
   		int n, k;
   		cin >> n >> k;
  		int arr[n], cur[k], found = 0, ans = INT_MAX;
   		fill(cur, cur + k, 0);
   		for(int j = 0, i = 0; j < n; ++j)
		{
			int a;
       		cin >> a;
       		a--;
        	arr[j] = a;
        	if(cur[a] == 0)
        		found++;
        	cur[a]++;
        	if(found != k) 
				continue;
        	while(cur[arr[i]] > 1)
			{
           	 	cur[arr[i]]--;
            	i++;
        	}
        	ans = min(ans, j - i + 1);
    	}
    	cout << ans << endl;
	}
}

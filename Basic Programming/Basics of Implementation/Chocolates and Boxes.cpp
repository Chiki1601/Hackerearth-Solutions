#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	  int t, n, k, count[100001], i, j, temp, a;
    long int total;
    cin >> t;
    while(t--)
    {
    	  for(i = 0; i < 100001; i++)
    		    count[i] = 0;
    	  total = 0;
    	  cin >> n;
    	  //a = new int[n];
    	  for(i = 0; i < n; i++)
    	  {
    		    cin >> a;
    		    count[a]++;
    	  }
    	  cin >> k;
    	  for(i = 1; i <= k / 2; i++)
    	  {
    		    if(i == k - i)
    			      temp = (count[i] * (count[i] - 1)) / 2;
    		    else
    			      temp = count[i] * count[k - i];
    		    total += temp;
    	  }
    	  cout << total << endl;
    }
    return 0;
}

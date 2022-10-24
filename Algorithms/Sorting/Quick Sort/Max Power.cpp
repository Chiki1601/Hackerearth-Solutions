#include<bits/stdc++.h>
using namespace std;
 
int main()
{
  	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int t, a[100100], b[100100];
  	cin >> t;
  	while(t--)
  	{
    	int n;
		cin >> n;
    	for(int i = 1; i <= n; i++)
      	{	
			cin >> a[i];
			b[i] = a[i];
		}
    	sort(b + 1, b + 1 + n);
    	if(n == 2)
		{
      		cout << abs(a[2] - a[1]) << endl;
      		continue;
    	}
    	if(a[1] == b[n] and a[n] == b[1] and n != 2)
			cout << max(b[n - 1] - b[1], b[n] - b[2]) << endl;
    	else 
			cout << b[n] - b[1] << endl;
  	}
  	return 0;
}

# include<bits/stdc++.h>
using namespace std;
 
unsigned long long int power(unsigned long long int x, unsigned long long int y)
{
	unsigned long long int result = 1;
    while(y > 0)
	{
	  	if(y % 2 == 1)
		   	result = (result * x) % 1000000007;
 		x = (x * x) % 1000000007;
		y /= 2;
	}
	return result % 1000000007;
}
 
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	unsigned long long int t;  
	cin >> t;
	while(t--)
	{
		unsigned long long int x;  
		cin >> x;
		unsigned long long int a[x], p[x], ans = 1;
		for(unsigned long long int i = 0; i < x; i++)
			cin >> p[i];
		for(unsigned long long int i = 0; i < x; i++)
			cin >> a[i];
		for(unsigned long long int i = 0; i < x; i++)
        	ans = (ans * p[i] % 1000000007 * (power(p[i], a[i]) - 1) % 1000000007 * power(p[i] - 1, 1000000005) % 1000000007) % 1000000007;
        cout << ans << endl;
	}
}

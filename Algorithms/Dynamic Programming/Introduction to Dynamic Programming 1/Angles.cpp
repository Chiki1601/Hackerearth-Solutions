#include<bits/stdc++.h>
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, k, a, g = 360;
    cin >> n >> k;
    for(int i = 0; i < n; ++i)
    {
      	cin >> a;
      	g = __gcd(g, a);
    }
    for(int i = 0; i < k; ++i)
    {
      	cin >> a;
      	if(a % g == 0)
      		cout << "YES" << endl;
      	else
      		cout << "NO" << endl;
    }
}

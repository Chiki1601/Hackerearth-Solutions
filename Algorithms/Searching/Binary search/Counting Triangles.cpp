#include<bits/stdc++.h>
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    long long n, count = 0;
    cin >> n;
    unordered_map<long long, long long>m;
    while(n--)
    {
        long long a[3] = {0};
    	  cin >> a[0] >> a[1] >> a[2];
    	  sort(a, a + 3);
    	  long long z = 100 * a[2] + 10 * a[1] + a[0];
    	  m[z]++;
    }
    for(auto it:m)
    {
		    if(it.second == 1)
			      count++;
    }
	  cout << count;

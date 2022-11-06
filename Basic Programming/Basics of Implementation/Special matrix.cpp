#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int t;
    cin >> t;
    int size = 2000002;
    vector<int> f(size, 0);
    for(int i = 2; i < size; i++)
    {
	if(f[i]!=0) 
            continue;
	    int k = i;
	    while(k < size)
            {
		f[k] += 1;
		k += i;
	    }
    }
    while(t--)
    {	
        int n, m;
	long long int ans  = 0;
	cin >> n >> m;
	for(int i = 2, j = n + m; i <= j; i++, j--)
        {
	    ans += (f[i] + f[j]) * (min(i - 1, min(n, m)));
	    if(i == j && (n + m) % 2 == 0)
            {
	         ans -= f[j] * (min(i - 1, min(n, m)));
	    }
	}
	cout << ans << endl;
    }
    return 0;
}

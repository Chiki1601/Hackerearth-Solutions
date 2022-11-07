#include<bits/stdc++.h>
using namespace std;
long long f[1000005], f1[1000005];
 
int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	long long n, t;
	cin >> t >> n ;
	f[0] = 0; f[1] = 0; f[2] = 1; f[3] = 0; f[4] = 1; f[5] = 1;
	for(int i = 6; i <= n; i++) 
		f[i] = (f[i - 2] + f[i - 5]) % 1000000007;
    int cur, k;
    while(t--) 
	{
        cin >> cur >> k;
        if((cur < k) || (k == 2) || (k == 5)) 
			cout << f[cur] << endl;
        else if(cur == k) 
			cout << (f[cur] + 1) % 1000000007 << endl;
        else 
		{
            for(int i = 0; i <= k; i++) 
				f1[i] = f[i];
            f1[k] = (f1[k] + 1) % 1000000007;
            for(int i = k + 1; i <= cur; i++) 
				f1[i] = (f1[i - 2] + f1[i - 5] + f1[i - k]) % 1000000007;
            cout << f1[cur] << endl;
        }
    }
	return 0;
}

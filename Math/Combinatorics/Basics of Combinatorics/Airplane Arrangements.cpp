#include <bits/stdc++.h>
using namespace std;
 
long long int modular(long long int x, long long int n)
{
    long long int res = 1;
    while(n > 0)
    {
        if(n % 2 == 0)
        {
            x = (x * x) % 1000000007;
            n /= 2;
        }
        else
        {
            res = (res * x) % 1000000007;
            n--;
        }
    }
    return res;
}
 
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    long long int n, m, ans;
    cin >> n >> m;
    ans = ((modular((2 * n + 2) ,m)) % 1000000007 * (n + 1 - m) % 1000000007) % 1000000007;
    ans = ans * modular((n + 1), 1000000005) % 1000000007;
    cout << ans;
    return 0;
}

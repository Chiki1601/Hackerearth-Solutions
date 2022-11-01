#include<bits/stdc++.h>
using namespace std;

void solve(int tc) 
{
    int n, cnt = 0; 
	cin >> n;
    for(int i = 0; i < 2 * n; i++) 
	{
        int x; 
		cin >> x;
        while(x % 2 == 0) 
		{
            cnt++;
            x /= 2;
        }
    }
    cout << (cnt >= n ? "YES\n" : "NO\n");
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t = 1;
    cin >> t;
    for(int i = 1; i <= t; i++) 
		solve(i);
    return 0;
}

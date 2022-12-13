#include<bits/stdc++.h>
using namespace std;

int main() 
{
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(0);
	long long i, t, n, x;
	cin >> t;
	while(t--)
    {
        cin >> n;
        long long c0 = 0, c1 = 0;
        for(i = 0; i < n; i++)
        {
            cin >> x;
            c0 += x % 2 ? 0 : 1;
            c1 += x % 2 ? 1 : 0;
        }
        bool ok = true;
        if(c0 % 2 && c1 % 2)
            ok = false;
        cout << (ok ? 1 : 0) << "\n";
	}
}

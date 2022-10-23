#include <bits/stdc++.h>
using namespace std;
 
int pow(int a) 
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int ans = 1, n = 1000000005;
    while(n) 
	{
        if(n % 2) 
			ans = (ans * 1LL * a) % 1000000007;
        a = (a * 1LL * a) % 1000000007;
        n /= 2;
    }
    return ans % 1000000007;
}
 
int main () 
{
    int n, i, tp = 1, zeros = 0, q, typ, ID, v, prev;
    cin >> n; 
    int a[n + 1] = {0};
    for(i = 1; i <= n; i++) 
		cin >> a[i]; 
    for(i = 1; i <= n; i++) 
	{
        if(a[i]) 
			tp = 1LL * tp * a [i] % 1000000007;
        else 
			zeros++;
    }
    (void)! scanf ("%d", &q);
    while(q--) 
	{
        cin >> typ; 
        if(typ) 
		{
            cin >> ID; 
            if(not zeros) 
				cout << 1LL * tp * pow (a [ID]) % 1000000007 << endl;
            else if(zeros == 1 and not a [ID]) 
				cout << tp << endl;
            else 
				cout << "0" << endl;
        }
        else 
		{
            cin >> ID >> v;
            prev = a[ID];
            a[ID] = v;
            if(prev and v) 
				tp = 1LL * tp * pow (prev) % 1000000007 * 1LL * v % 1000000007;
            else if(v) 
			{
                tp = 1LL * tp * v % 1000000007;
                zeros --; 
			}
            else if (prev) 
			{
                tp = 1LL * tp * pow (prev) % 1000000007;
                zeros ++; 
			}
        }
    }
    return 0;
}

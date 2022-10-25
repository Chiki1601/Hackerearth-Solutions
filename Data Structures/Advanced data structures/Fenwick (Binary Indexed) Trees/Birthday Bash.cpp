#include <bits/stdc++.h>
using namespace std;
long long int BIT[2000005], n;
 
void update(long long int x, long long int val)
{
    while(x <= n)
    {
        BIT[x] += val;
        x += (x & (-x));
    }
}
 
long long int query(long long int x)
{
    long long int sum = 0;
    while(x > 0)
    {
        sum += BIT[x];
        x -= (x & (-x));
    }
    return sum;
}
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    long long int t, m, A[2000005];
    cin >> t;
    while(t--)
    {
        cin >> n >> m;
        string s;
        cin >> s;
	    for(int i = 0; i <= n; i++) 
            BIT[i] = 0;
	    long long int mid = n / 2;
        while(m--)
        {
            long long int type, x;
		    cin >> type >> x;
		    if(type == 1)
		    {
			    x = max(x, n - 1 - x);
			    update(mid, 1);
			    if(x != (n - 1)) 
                    update(x + 1, -1);
		    }
		    else
		    {
                long long int y = max(x, n - 1 - x);
			    long long int z = query(y);
			    z %= 2;
			    if(z == 1) 
                    x = n - 1 - x; 
			    if(s[x] == 'z') 
                    s[x] = 'a';
			    else         
                    s[x]++;
		    }
        }
	    for(long long int i = mid; i < n; i++)
	    {
	        long long int k = query(i) % 2;
	        if(k == 1) 
                swap(s[i], s[n - 1 - i]); 	
	    }
	    cout << s << endl;
    }
}

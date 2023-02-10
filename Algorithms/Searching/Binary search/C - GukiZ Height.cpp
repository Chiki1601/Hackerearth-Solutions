#include<bits/stdc++.h> 
using namespace std; 
long long n, h, o, l, r, day, a[100001];
 
int main() 
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> h;
    for(int i = 0; i < n; i++) 
		cin >> a [i];
    for(int i = 1; i <= n; i++) 
	{
        a [i] += a [i - 1];
        if(a [i - 1] >= h - (i * (i + 1)) / 2) 
		{
            cout << i << endl;
            return 0;
        }
    }
    l = 1;
    r = 2000000001;
    while(l < r) 
	{
        o = (l + r) / 2;
        if(h - (o * (o + 1)) / 2 <= ((o - 1) / n) * a [n - 1] + a [(o - 1) % n]) 
			r = o;
        else 
			l = o + 1;
    }
    for(long long i = r - n; i <= r; i++) 
	{
        if(h - (i * (i + 1)) / 2 <= ((i - 1) / n) * a [n - 1] + a [(i - 1) % n]) 
		{
            cout << i;
            break;
        }
    }
    return 0;
}

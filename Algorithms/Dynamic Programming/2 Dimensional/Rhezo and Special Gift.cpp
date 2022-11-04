#include <bits/stdc++.h>
using namespace std;
int m, ma;
 
void ml(unsigned long long* d, const unsigned long long* a, const unsigned long long* b) 
{
    for(int i = 0; i < ma; ++i) 
        for(int j = 0; j < ma; ++j) 
		{
            unsigned long long r = 0;
            for(int k = 0; k < ma; ++k) 
                r += (a[i * ma + k] * b[k * ma + j]) % 1000000007;
            d[i * ma + j] = r % 1000000007;
        }
}
 
int main() 
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	unsigned long long n;
    cin >> n >> m;
    ma = 100;
    unsigned long long* a0 = new unsigned long long[ma * ma];
    unsigned long long* a1 = new unsigned long long[ma * ma];
    unsigned long long* a2 = new unsigned long long[ma * ma];
    for(int i = 0; i < ma * ma; ++i) 
		a0[i] = 0;
    for(int i = 1; i < ma; ++i) 
		a0[(i - 1) * ma + i] = 1;
    for(int i = 0; i < m; ++i) 
	{
        int k;
        cin >> k;
        ++a0[ma * ma - k];
    }
    for(int i = 0; i < ma * ma; ++i) 
		a1[i] = 0;
    for(int i = 0; i < ma; ++i) 
		a1[i * ma + i] = 1;
    while (n) 
	{
        if(n % 2) 
		{
            ml(a2, a1, a0);
            swap(a1, a2);
        }
        ml(a2, a0, a0);
        swap(a0, a2);
        n /= 2;
    }
    cout << a1[ma * ma - 1] << endl;
}

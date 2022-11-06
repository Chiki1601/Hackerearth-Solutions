#include <bits/stdc++.h> 
using namespace std;
int n, c[100100], d[100100];
 
int main() 
{
    int kase = 1000000000;
    for(int ks = 1; ks <= kase && 1 == scanf("%d", &n); ++ks) 
    {
        int max_a = 0;
        for(int i = 0, a; i < n && 1 == scanf("%d", &a); ++i) 
        {
            ++c[a];
            ++d[a];
            max_a = max(max_a, a);
        }
        d[1] = n;
        for(int x = 2; x * x <= max_a; ++x) 
        {
            d[x] += c[x * x];
            for(int y = x * x + x; y <= max_a; y += x) 
            {
                d[x] += c[y];
                d[y / x] += c[y];
            }
        }
        int q;
        cin >> q;
        for(int i = 0, x; i < q && 1 == scanf("%d", &x); ++i) 
            cout <<  d[x] << endl;
    }
    return 0;
}

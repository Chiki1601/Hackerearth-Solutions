#include <bits/stdc++.h>
using namespace std;
int f[64][2][2][2][2];
 
int solve(long long n, long long target, int bit, int carry, bool smallI, bool smallJ, bool nonZeroI)
{
    if(bit == 63) 
        return smallI && smallJ && nonZeroI && carry == 0;
    int& ret = f[bit][smallI][smallJ][carry][nonZeroI];
    if(ret != -1) 
        return ret;
    ret = 0;
    for(int i = 0; i < 2; ++ i) 
    {
        for(int j = 0; j < 2; ++ j) 
        {
            int ij = (i + j + carry) % 2, newCarry = (i + j + carry) / 2;
            bool newSmallI = i < j ? true : (i == j ? smallI : false), newSmallJ = j < (n >> bit & 1) ? true : (j == (n >> bit & 1) ? smallJ : false), newNonZero = nonZeroI || (i > 0);
            if((i ^ j ^ ij) == (target >> bit & 1)) 
            {
                ret += solve(n, target, bit + 1, newCarry, newSmallI, newSmallJ, newNonZero);
                ret %= 1000000007;
            }
        }
    }
    return ret;
}
 
int main()
{
    int tests;
    for(assert(scanf("%d", &tests) == 1 && 1 <= tests && tests <= 10); tests --;) 
    {
        long long n;
        assert(scanf("%lld", &n) == 1);
        assert(2 <= n && n <= 1000000000000000000LL);
        if(n % 4 == 1 || n % 4 == 2) 
            puts("0");
        else 
        {
            long long target;
            if(n % 4 == 0)
                target = n;
            else 
                target = 0;
            memset(f, -1, sizeof(f));
            cout << solve(n, target, 0, 0, false, true, false) << endl;
        }
    }
    return 0;
}

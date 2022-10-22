#include <bits/stdc++.h>
using namespace std;
long long xorChallange(long long number);
int countBits(long long number);
 
int main() 
{
    long long C;
    cin >> C;
    cout << xorChallange(C) << endl;
    return 0;
}
 
long long xorChallange(long long number) 
{
    long long result = 0LL, a = 0LL, b = 0LL;
    int c = countBits(number);
    --c;
    a = b = 1 << c;
    --b;
    for (int i = 0; i < c; ++i) 
    {
        long long mask = 1 << i;
        if ((mask & number) == 0) 
            a |= mask;
    }
    result = a * b;
    return result;
}
 
int countBits(long long number) 
{
    int c = 0;
    while (number != 0) 
    {
        number >>= 1;
        ++c;
    }
    return c;
}

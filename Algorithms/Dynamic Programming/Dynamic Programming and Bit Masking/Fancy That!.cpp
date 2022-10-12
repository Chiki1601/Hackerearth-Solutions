#include <bits/stdc++.h>
using namespace std;
 
long long cal(long long n)
{
    if(n == 0)
        return 0;
    long long count = 0, temp = n, last = 0, ans = 0;
    while(temp)
    {
        count++;
        if(temp < 10)
            last = temp;
        temp /= 10;
    }
    --count;
    for(long long i = 0; i < count; ++i)
        ans += (long long)pow(10LL, i);
    ans *= 4;
    ans += ((last - 1) / 2) * pow(10LL, count);
    if(last % 2 == 0)
        ans += (n - (long long)pow(10LL, count) * last + 1);
    return ans;
}
 
int main()
{
    long long t;
    cin >> t;
    while(t--)
    {
        long long l, r;
        cin >> l >> r;
        cout << cal(r) - cal(l - 1) << endl;
    }
}

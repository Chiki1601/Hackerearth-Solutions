#include <bits/stdc++.h>
using namespace std;
int N, A[100001];
 
struct BIT
{
    long long bit[100001];
    void add(int x, long long v)
    {
        for(; x <= N; x += x & -x)
            bit[x] += v;
    }
    long long sum(int x)
    {
        long long ret = 0;
        for(; x > 0; x -= x & -x)
            ret += bit[x];
        return ret;
    }
} b1, b2, b3;
 
int powmod(int a, int b)
{
    int ret = 1;
    for(; b > 0; b /= 2)
    {
        if(b & 1)
            ret = 1LL * ret * a % 1000000007;
        a = 1LL * a * a % 1000000007;
    }
    return ret;
}
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    assert(2 <= N && N <= 100000);
    for(int i = 1; i <= N; i++)
        cin >> A[i];
    long long ans = 0;
    for(int i = 1; i <= N; i++)
    {
        long long x = b1.sum(A[i]);
        ans += 1LL * x * (N - i + 1);
        ans %= 1000000007;
        b1.add(A[i], i);
    }
    long long ways = 1LL * N * (N - 1) / 2 + N;
    for(int i = N; i >= 1; i--)
    {
        long long x = b2.sum(A[i]), t = b3.sum(A[i]);
        ans += t * ways - 1LL * x * i;
        ans %= 1000000007;
        b2.add(A[i], N - i + 1);
        b3.add(A[i], 1);
    }
    cout << ans * powmod(ways % 1000000007, 1000000005) % 1000000007 << endl;
    sort(A + 1, A + 1 + N);
    for(int i = 1; i <= N; i++)
        assert(A[i] == i);
    return 0;
}

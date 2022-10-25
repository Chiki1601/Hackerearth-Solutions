#include <bits/stdc++.h>
using namespace std;
int N, A[200001], bit[100001];
 
void add(int x, int v)
{
    for(; x <= N / 2; x += x & -x)
        bit[x] += v;
}
 
int sum(int x)
{
    int ret = 0;
    for(; x > 0; x -= x & -x)
        ret += bit[x];
    return ret;
}
 
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    long long p2 = 1;
    for(int i = 2; i < N; i++)
        p2 = (p2 * 2) % 1000000007;
    long long tmp=(((p2 * N) % 1000000007) * (N == 1 ? 1 : 2)) % 1000000007, ans = -7LL * N;
    N *= 2;
    for(int i = 1; i <= N; i++)
        cin >> A[i];
    ans += 3LL * N * (N + 1LL) / 2LL;
    for(int i = 1; i <= N; i++)
    {
        ans -= 2 * sum(A[i]);
        add(A[i], 1);
    }
    ans %= 1000000007;
    ans = (ans * p2) % 1000000007;
    ans = (ans + tmp) % 1000000007;
    cout << ans << endl;
    return 0;
}

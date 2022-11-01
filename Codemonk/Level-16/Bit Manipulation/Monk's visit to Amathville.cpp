#include<bits/stdc++.h>
using namespace std;
int dp[400000][20], p, n;
vector<int> isprime(100 , true), prime;

void manipulated_seive(int N) 
{
    isprime[0] = isprime[1] = false;
    for(int i = 2; i < N; i++) 
    {
        if(isprime[i])
            prime.push_back(i);
        for(int j = 0; j < prime.size() && i * prime[j] < N; j++)
            isprime[i * prime[j]] = false;
    }
}

int foo(int done, int prev) 
{
    if(dp[done][prev] != -1)
        return dp[done][prev];
    int i, j, tmp = 100000000, pos = __builtin_popcountll(done);
    if(pos == n)
        return 0;
    for(i = 0; i < n; i++) 
    {
        if(((1<<i) & (done)) == 0) 
            tmp = min(tmp, (prime[prev] * prime[i]) % p + foo((done|(1<<i)), i)); 
    }
    dp[done][prev] = tmp;
    return tmp;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    prime.clear();
    prime.push_back(1);
    manipulated_seive(50);
    int t;
    cin >> t;
    assert(1 <= t && t <= 20);
    while(t--)
    {
        int i, j, k = prime.size(), num, ans = 100000000;
        cin >> num >> p;
        assert(1 <= num && num <= 50);
        assert(1 <= p && p <= 200);
        i = 0;
        while(i < k && prime[i] <= num)
            i++;
        n = i;
        memset(dp, -1, sizeof(dp));
        for(i = 0; i < n; i++)
        {
            int don = (1<<i);
            ans = min(ans, foo(don, i));
        }
        cout << ans;
        if(t > 0)
            cout << endl;
    }
    return 0;
}

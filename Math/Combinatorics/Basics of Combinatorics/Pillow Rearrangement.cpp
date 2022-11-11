#include<bits/stdc++.h>
using namespace std;
long long int facts[100005], invfacts[100005], numbersinverse[100005];
 
long long int ways(long long int n, long long int r)
{
    long long int f1 = facts[n], f2 = invfacts[r], f3 = invfacts[n - r];
    f1 = (f1 * f2) % 1000000007;
    f1 = (f1 * f3) % 1000000007;
    return f1;
}
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    facts[0] = facts[1] = 1;
    for(long long int i = 2; i < 100005; i++)
        facts[i] = (i * facts[i - 1]) % 1000000007;
    numbersinverse[0] = numbersinverse[1] = 1;
    for(long long int i = 2; i < 100005; i++)
        numbersinverse[i] = numbersinverse[1000000007 % i] * (1000000007 - 1000000007 / i) % 1000000007;
    invfacts[0] = invfacts[1] = 1;
    for(long long int i = 2; i < 100005; i++)
        invfacts[i] = (numbersinverse[i] * invfacts[i - 1]) % 1000000007;
    long long int T; 
    cin >> T;
    while(T--)
    {               
        long long int N, K; 
        cin >> N >> K;
        if(N == 2 and K == 2)
        {
            cout << "1\n";
            continue;
        }
        long long int ans = 0, ok = min(N - 1, K);
        for(long long int i = 0; i <= ok; i++)
            ans = (ans + ((ways(N, i) * ways(N - 1, N - i - 1)) % 1000000007)) % 1000000007;
        cout << ans << "\n";
    }  
    return 0;
}

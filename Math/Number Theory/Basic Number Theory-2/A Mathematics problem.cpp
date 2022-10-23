#include<bits/stdc++.h>
using namespace std;
vector <int> primes;
bool isprime[100005];
 
long long square(long long a) 
{ 
    return a * a; 
}
 
long long sum1(long long n)
{
    if(n == 0)
        return 0;
    if(n % 2 == 1)
        return square((n + 1) / 2) + sum1(n / 2);
    else 
        return square(n / 2) + sum1(n / 2);
}
 
int main() 
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    long long t;    
    cin >> t;
    for(int i = 2; i < 100005; ++i) 
    {
        if(isprime[i]) 
            continue;
        for(long long j =  1ll * i * i; j < 100005; j += i) 
            isprime[j] = true;
        primes.push_back(i);
    }
    while(t--) 
    {
        long long P, Q, N, ans = 0;
        cin >> P >> Q >> N;
        for(int i = 0; i < primes.size(); i++) 
        {
            long long p = primes[i];
            if(p < P) 
                continue;
            if(p > Q) 
                break;
            long long n = N;
            while(n)
            {
                long long sum = (n * (n + 1) / 2) - 2 * (sum1(n));     
                sum = (sum + 1000000007) % 1000000007;
                ans += ((p - 1) * sum) % 1000000007;
                ans = (ans + 1000000007) % 1000000007;
                n /= p;
            }
        }
        cout << ans << endl;
    }
    return 0;
}

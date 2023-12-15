#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    vector<long long int> primes(100002);
    for(long long int i = 0; i < 100002; i++)
        primes[i] = i;
    for(long long int i = 2; i < 100002; i++)
    {
        if(primes[i] == i)
        {
            for(long long int j = 2 * i; j < 100002; j += i)
                primes[j] = i;
        }
    }
    long long int t; 
	cin >> t;
    while(t--)
    {   
        long long int n, ans = 0; 
        cin >> n;
        vector<long long int> a(n), dp(100002, 0), dp2(100002, 0);
        for(auto &x : a)
            cin >> x;
        for(long long int i = 0; i < n; i++)
        {
            long long int bits = 0, ok = a[i];
            vector<int> facts;
            map<int, int> visFacts;
            while(ok > 1)
            {
                if(!visFacts[primes[ok]])
                {
                    visFacts[primes[ok]] = true;
                    facts.push_back(primes[ok]);
                }
                ok /= primes[ok];
            }
            long long int counts = ans + 1, me = (1LL<<(facts.size()));
            vector<pair<long long int, long long int>> allProducts;
            for(long long int j = 1; j < me; j++)
            {
                long long int bits = 0, prod = 1;
                for(long long int k = 0; k < facts.size(); k++)
                {
                    if(j&(1LL<<k))
                    {
                        prod *= facts[k];
                        bits++;
                    }
                }
                if(bits & 1)
                    allProducts.push_back({prod, 1});
                else
                    allProducts.push_back({prod, -1});
            }
            for(auto &x : allProducts)
            {
                counts -= dp[x.first] * x.second;
                counts = (counts + 1000000007) % 1000000007;
            }
            ans = (ans + counts) % 1000000007;
            for(auto &x : allProducts)
            {
                dp[x.first] = (dp[x.first] + counts) % 1000000007;
                dp[x.first] = (dp[x.first] + 1000000007) % 1000000007;
            }
        }
        cout << ans << endl;
    }
    return 0;
}

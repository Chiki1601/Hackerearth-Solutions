#include<bits/stdc++.h>
using namespace std;
 
long long int inverse(long long int a,long long int n)
{
    long long int res = 1;
    while(n)
    {
        if(n % 2)
        res = (res * a) % 1000000007;
        a = (a * a) % 1000000007;
        n /= 2;
    }
    return res;
}
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t;
    cin >> t;
    long long int fact[200001];
    fact[0] = 1;
    for(int i = 1; i < 200000; i++)
        fact[i] = (fact[i - 1] * i) % 1000000007;
    while(t--)
    {
        int n;
        cin >> n;
        int a[n], sum = 0;
        for(int i = 0; i < n; i++)
        {
            cin >> a[i];
            sum += abs(a[i]);
        }
        long long int res = fact[sum], deno = 1;
        for(int i = 0; i < n; i++)
            deno = (deno * fact[abs(a[i])]) % 1000000007;
        cout << (res * inverse(deno, 1000000005)) % 1000000007 << endl;
    }
}

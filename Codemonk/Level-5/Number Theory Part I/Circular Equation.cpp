#include<bits/stdc++.h>
using namespace std;
long long int fact[100005], invfact[100005];
 
long long int power(long long int a, long long int n)
{
    if(n == 0) 
        return 1;
    long long int ans = 1, val = a;
    while(n)
    {
        if(n % 2)
        {
            ans *= val;
            ans %= 1000000007;
        }
        val *= val;
        val %= 1000000007;
        n /= 2;
    }
    return ans;
}
 
long long int ncr(long long int n, long long int r)
{
    if(n < r || n < 0 || r < 0) 
        return 0;
    long long int ty = fact[n];
    ty *= invfact[n - r];
    ty %= 1000000007;
    ty *= invfact[r];
    ty %= 1000000007;
    return ty;
}
 
long long int solve(long long int x, long long int sum)
{
    long long int count = 0;
    for(int i = 0 ; i <= x ; i++)
    {
        long long int val = ncr(x, i) * ncr(sum + x - 1, x - 1);
        val %= 1000000007;
        sum -= 10;
        if(i % 2 == 0)
        {
            count += val;
            count %= 1000000007;
        }
        else
        {
            count -= val;
            count += 1000000007;
            count %= 1000000007;
        }
    }
    return count;
}
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    fact[0] = fact[1] = 1;
    invfact[0] = invfact[1] = 1;
    for(int i = 2; i <= 100000; i++)
    {
        fact[i] = fact[i - 1] * i;
        fact[i] %= 1000000007;
        invfact[i] = invfact[i - 1] * power(i, 1000000005);
        invfact[i] %= 1000000007;
    }
    int t;
    cin >> t;
    while(t--)
    {
        long long int s;
        cin >> s;
        long long int temp = s, val = 1, answer = 0;
        int count = 0;
        while(temp)
        {
            count++;
            temp /= 10;
        }
        for(int i = 1; i <= count; i++)
        {
            if(s % val == 0)
            {
                long long int sum = s / val;
                if(sum >= 0 && sum <= 9 * i)
                {
                    answer += solve(i, sum);
                    answer %= 1000000007;
                }
            }
            val *= 10;
            val++;
        }
        cout << answer << "\n";
    }
}

#include<bits/stdc++.h>
using namespace std;
 
long long int binpow(long long int a, long long int n)
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
    int n;
    cin >> n;
    long long int res = 0;
    int a[n];
    int freq[1001] = {0}, accumulate[1001] = {0};
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
        freq[a[i]]++;
    }
    vector<int>v;
    for(int i = 1; i <= 1000; i++)
    {
        if(freq[i] > 0)
        v.push_back(i);
        accumulate[i] = accumulate[i - 1] + freq[i];
    }
    for(int i = 0; i < v.size(); i++)
    {
        long long int x=v[i];
        res = (res + (x * (binpow(2, freq[x]) - freq[x] - 1 + 1000000007) % 1000000007) % 1000000007) % 1000000007;
        for(int j = i + 1; j < v.size(); j++)
        {
            long long int y = v[j];
            long long int xy = accumulate[y - 1] - accumulate[x];
            long long int amountij = binpow(2, xy);
            long long int amounti=(binpow(2, freq[x]) - 1 + 1000000007) % 1000000007;
            long long int amountj = (binpow(2, freq[y]) - 1 + 1000000007) % 1000000007;
            long long int flag = (amounti * amountj) % 1000000007;
            flag = (flag * amountij) % 1000000007;
            flag = (flag * (x | y)) % 1000000007;
            res = (res + flag) % 1000000007;
            //res = (res + ((x | y) * (((amountij * amounti) % 1000000007) * amountj) % 1000000007) % 1000000007) % 1000000007;
        }     
    }
    cout << res;
}

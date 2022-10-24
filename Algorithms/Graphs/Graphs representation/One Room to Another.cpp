#include <bits/stdc++.h>
using namespace std;
 
void Solve()
{
    long long n, k = 0;
    cin >> n;
    vector<long long> arr(n);
    for(auto &val : arr)
    {
        cin >> val;
        val--;
    }
    vector<int> check(n);
    for(int i = 0; i < n; i++)
    {
        if(!check[arr[i]])
        {
            long long j = arr[i], ct = 1;
            check[i] = 1;
            while(i != j)
            {
                if(check[j] == 1)
                {
                    cout << -1 << endl;
                    return ;
                }
                ct++;
                check[j] = 1;
                j = arr[j];
            }
            if(k == 0)
                k = (ct % 1000000007);
            else
                k = ((k * ct)/__gcd(k, ct)) % 1000000007;
        }
    }
    cout << k << "\n";
}
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t;
    cin >> t;
    for(int i = 1; i <= t; i++)
        Solve();
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
long long phi[100005], sphi[100005], res[100005];
 
long long Solve(long long N) 
{
  return res[N];
}
 
int main() 
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    long long T;
    cin >> T;
    for(long long i = 1; i <= 100000; i++ ) 
        phi[i] = i;
    for(long long i = 2; i <= 100000; i++ ) 
    {
        if(phi[i] == i) 
        {
            for(long long j = i; j <= 100000; j += i) 
                phi[j] = phi[j] / i * (i - 1);
        }
    }
    for(long long i = 1; i <= 100000; ++i ) 
        sphi[i] = (sphi[i - 1] + phi[i]) % 1000000007; 
    for(long long i = 1; i <= 100000; ++i ) 
        res[i] = (res[i - 1] + phi[i] * sphi[i]) % 1000000007;
    for(long long t_i = 0; t_i < T; t_i++)
    {
        long long N, out_;
        cin >> N;
        out_ = Solve(N);
        cout << out_;
        cout << endl;
    }
}

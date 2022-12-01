#include <bits/stdc++.h>
using namespace std;
long long V[1010101];
int N;
 
int Compute(long long k) 
{
    long long v = 1ll<<k, reset = (1ll<<62ll) - 1ll;
    int maxi = 0, inc = 0;
    long long cur = reset;
    for(int i = 0; i < N; i++) 
    {
        if(V[i] & v) 
        {
            inc++;
            cur &= V[i];
            if(cur == v) 
                maxi = max(maxi, inc);
        } 
        else 
        {
            cur = reset;
            inc = 0;
        }
    }
    return maxi;
}
 
int main() 
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T; 
    cin >> T; 
    while(T--) 
    {
        int Q, A[64][64];
        cin >> N;
        for(int i = 0; i < N; i++) 
            cin >> V[i];
        for(int i = 0; i < 61; i++) 
        {
            A[i][i] = Compute(i);
            for(int j = 0; j < i; j++) 
                A[j][i] = max(A[i][i], A[j][i - 1]);
        }
        cin >> Q;
        while(Q--) 
        {
            int l, r;
            cin >> l >> r;
            cout << A[l][r] << "\n";
        }
    }
}

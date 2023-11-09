#include <bits/stdc++.h>
using namespace std;
long long int fni[1000006], nni[1000006], ft[1000006];

long long int nCr(long long int N, long long int R)
{
    long long int v = ((ft[N] * fni[R]) % 1000000007 * fni[N - R]) % 1000000007;
    return v;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    nni[0] = nni[1] = 1;
    for(int i = 2; i <= 1000005; i++)
        nni[i] = nni[1000000007 % i] * (1000000007 - 1000000007 / i) % 1000000007;
    fni[0] = fni[1] = 1;
    for(int i = 2; i <= 1000005; i++)
        fni[i] = (nni[i] * fni[i - 1]) % 1000000007;
    ft[0] = 1;
    for(int i = 1; i <= 1000005; i++)
        ft[i] = (ft[i - 1] * i) % 1000000007;
    int test, totalN = 0;
    cin >> test;
    assert(test >= 1 && test <= 100000);
    while(test--)
    {
        int N, f = 1, prevE = 0, prevI = -1;
        cin >> N;
        totalN += N;
        assert(1 <= N && N <= 1000000);
        vector<int> A(N);
        for(auto &e : A)
        {
            cin >> e;
            assert(e >= 0 && e <= 1000000);
        }
        for(int i = 0; i < N; i++)
        {
            if(A[i])
            {
                if(A[i] < prevE + (i - prevI))
                    f = 0;
                prevE = A[i];
                prevI = i;
            }
        }
        if(!f)
        {
            cout << 0 << "\n";
            continue;
        }
        if(A[N - 1] == 0)
        {
            cout << -1 << "\n";
            continue;
        }
        long long int ans = 1;
        prevE = 0, prevI = -1;
        for(int i = 0; i < N; i++)
        {
            if(A[i])
            {
                if(prevI < i - 1)
                {
                    ans *= nCr(A[i] - prevE - 1, i - prevI - 1);
                    ans %= 1000000007;
                }
                prevE = A[i];
                prevI = i;
            }
        }
        cout << ans << "\n";
        assert(totalN >= 1 && totalN <= 1000000);
    }
}

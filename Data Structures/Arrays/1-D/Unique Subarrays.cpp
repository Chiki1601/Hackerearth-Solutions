#include <bits/stdc++.h>
using namespace std;
int T, N;
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> T;
    assert(1<=T && T<=100000);
    int S = 0;
    while(T--)
    {
        cin >> N;
        assert(1 <= N && N <= 100000);
        S += N;
        vector<int> A(N);
        for(int i = 0; i < N; i++)
        {
            cin >> A[i];
            assert(0 <= A[i] && A[i] <= 1000000000);
        }
        long long ans = 0;
        set<int> s;
        for(int i = 0, j = 0; i < N; i++)
        {
            for(; j < N && !s.count(A[j]); j++)
                s.insert(A[j]);
            ans += 1LL * (j - i) * (j - i + 1) / 2;
            s.erase(A[i]);
        }
        cout << ans << endl;
    }
    assert(S <= 100000);
    return 0;
}

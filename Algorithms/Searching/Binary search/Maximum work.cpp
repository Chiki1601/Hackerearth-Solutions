#include<bits/stdc++.h>
using namespace std;
 
int solve(int K, int B, int N, int M, vector<int> W, vector<int> S) 
{
    sort(S.begin(), S.end());
    sort(W.begin(), W.end());
    int i, s = 1, e = min(N, M), val = 0;
    while(s <= e)
    {
        int mid = (s + e) / 2, req = 0;
        for(i = 0; i < mid; i++)
            req += (max(0, S[i] - W[N - (mid - i)]) + B - 1) / B;
        if(req <= K)
        {
            val = mid; 
            s = mid + 1;
        }
        else
            e = mid - 1;
    }
    return val;
}
 
int main() 
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    assert(1 <= T && T <= 100);
    for(int t_i = 0; t_i < T; t_i++)
    {
        int K, B, N, M, out_;
        cin >> K;
        assert(1 <= K && K <= 100000);
        cin >> B;
        assert(1 <= B && B <= 10);
        cin >> N;
        assert(1 <= N && N <= 10000);
        vector<int> W(N);
        for(int i_W = 0; i_W < N; i_W++)
        {
        	cin >> W[i_W];
            assert(1 <= W[i_W] && W[i_W] <= 100000);
        }
        cin >> M;
        assert(1 <= M && M <= 10000);
        vector<int> S(M);
        for(int i_S = 0; i_S < M; i_S++)
        {
        	cin >> S[i_S];
            assert(1 <= S[i_S] && S[i_S] <= 100000);
        }
        out_ = solve(K, B, N, M, W, S);
        cout << out_;
        cout << endl;
    }
}

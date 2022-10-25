#include<bits/stdc++.h>
using namespace std;

long long solve (int N, vector<int> A, int K) {
   vector<vector<int>> dp(K, vector<int> (N, -1000000001));
   for(int i = 0; i<N; i++){
       if(i)
       dp[0][i] = dp[0][i-1] - A[i];
       else
       dp[0][i] = - A[i];
   }
   for(int i = 1; i<K; i++){
       for(int j=i; j<N; j++){
           if(i%2)
           dp[i][j] = max(dp[i-1][j-1] + A[j],dp[i][j-1]+A[j]);
           else
           dp[i][j] = max(dp[i-1][j-1] - A[j],dp[i][j-1]-A[j]);
       }
   }
   return dp[K-1][N-1];
}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    for(int t_i = 0; t_i < T; t_i++)
    {
        int N;
        cin >> N;
        vector<int> A(N);
        for(int i_A = 0; i_A < N; i_A++)
        {
        	cin >> A[i_A];
        }
        int K;
        cin >> K;

        long long out_;
        out_ = solve(N, A, K);
        cout << out_;
        cout << "\n";
    }
}

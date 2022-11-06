#include<bits/stdc++.h>
using namespace std;
 
int minUpdates(int N, vector<int> A, int K) 
{
    if(N % 2)
        return -1;
    int count_odd = 0, count_even = 0, req_odd = 0, req_even = 0;
    map<int, int>od, ev;
    for(int i = 0 ; i < N ; i++)
    {
        if(A[i] % 2 and od[A[i]] == 0)
        {
            count_odd++;
            od[A[i]]++;
            if(A[i] <= K) 
                req_odd++;
        }
        else if(A[i] % 2 == 0 and ev[A[i]] == 0)
        {
            count_even++;
            ev[A[i]]++;
            if(A[i] <= K) 
                req_even++;
        }
    }
    count_odd = max(0, N / 2 - count_odd);
    count_even = max(0, N / 2 - count_even);
    req_even = K / 2 - req_even;
    req_odd = (K - K / 2) - req_odd;
    if((req_even < count_even) or (req_odd < count_odd)) 
        return -1;
    return abs(count_even + count_odd);
}
 
int main() 
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    assert(1 <= T and T <= 100);
    for(int t_i = 0; t_i < T; t_i++)
    {
        int N;
        cin >> N;
        assert(1 <= N and N <= 100000);
        vector<int> A(N);
        for(int i_A = 0; i_A < N; i_A++)
        {
            cin >> A[i_A];
            assert(1 <= A[i_A] and A[i_A] <= 1000000000);
        }
        int K, out_;
        cin >> K;
        assert(1 <= K and K <= 1000000000);
        out_ = minUpdates(N, A, K);
        cout << out_ << endl;
    }
}

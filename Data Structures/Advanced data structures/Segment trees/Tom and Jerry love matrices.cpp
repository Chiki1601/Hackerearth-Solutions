#include <bits/stdc++.h>
using namespace std;
 
int main() 
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    vector<vector<long long>> BIT(2, vector<long long>(45001, 0));
    int M, N, X, Q; 
    if(cin.tie(nullptr)->sync_with_stdio(false), cin >> M >> N >> X >> Q, M > N)
        swap(M, N);
    const auto add = [&](int i, int j, long long k) 
    { 
        while(j < 45001)
        {
            BIT[i][j] += k; 
            j += (j & -j);
        } 
    };
    const auto range_add = [&](int l, int r, long long k) 
    {
    	if(l < r and r < 45001)
        	add(0, l, k), 
        	add(0, r, -k), 
        	add(1, l, k * (l - 1)), 
        	add(1, r, -k * (r - 1)); 
    };
    for(int i = 1, u = 2, v = M + N, m = min(M, 45001); i < m; i = u++, --v) 
    	range_add(u, u + 1, i),
    	range_add(v, v + 1, i);
	range_add(min(M + 1, 45000), min(N + 2, 45000), M);
    const auto range_query = [&](int i, int j) 
    { 
        long long ans = 0; 
        while(j > 0)
        {    
            ans += BIT[i][j]; 
            j -= (j & -j);
        }
        return ans; 
    }; 
    const auto query = [&](int j) 
    { 
        return range_query(0, j) * j - range_query(1, j); 
    };
    const auto ans = [&](long long K) 
    {
        int a = 45001;
        for(int l = 1, r = 45000; l <= r; ) 
        {
            const int m = (l + r) / 2;
            const long long sum = query(m);
            if(sum < K)
                l = m + 1;
            else
            {
                r = m - 1; 
                a = min(a, m);
            } 
        }
        return a == 45001 ? -1 : X + a; 
    };
    for(int C, R1, R2, K, QUERY; Q--;)
        if(cin >> QUERY, QUERY == 3)
        {
            cin >> K; 
            cout << ans(K) << endl;
        }
        else
        { 
        	cin >> C >> R1 >> R2; 
            range_add(min(C + R1, 45000), min(C + R2 + 1, 45000), -1); 
        }
}

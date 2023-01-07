#include <bits/stdc++.h>
using namespace std;
 
int main() 
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    const auto next_int = []() 
	{ 
		int num; 
		cin >> num; 
		return num; 
	};
    for(auto T = next_int(); T--; cout << endl) 
	{
        const int N = next_int(), M = N + 2, U = 2 * M;
        vector<int> seg(U);
        vector<vector<int>> begin(M), end(M);
        const auto add = [&](int i, int value) 
		{
            seg[i += N] += value;
            for(int l, r; i > 1; seg[i] = seg[l] + seg[r])
            {    
				i >>= 1; 
				l = i<<1; 
				r = l|1;
			} 
		};
        const auto query = [&](int l, int r) 
		{
            int sum = 0;
            for(l += N, r += N; l < r; l >>= 1, r >>= 1) 
			{
                if(l & 1) 
					sum += seg[l++];
                if(r & 1) 
					sum += seg[--r]; 
			}
            return sum; 
		};
        int64_t ans = 0;
        for(int i = 1; i <= N; ++i) 
		{
            const auto X = next_int(), Y = next_int(), L = max(X,i+1), R = Y+1;
            for(auto j : begin[i])
                add(j, 1);
            for(auto j : end[i])
                add(j, -1);
            if(i > 1)
                ans += query(X, min(R, i));
            if(L < R)
                begin[L].push_back(i), end[R].push_back(i); 
		}
        cout << ans;  
	}
    return 0; 
}

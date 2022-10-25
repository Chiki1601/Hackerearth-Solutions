#include<bits/stdc++.h>
using namespace std;
long long global_n;
vector<vector<vector<long long>>> dp;
 
void update(long long x, long long y, long long z, long long val) 
{
    long long i, j, k;
    for(i = x; i <= global_n; i += (i & -i)) 
    {
        for(j = y; j <= global_n; j += (j & -j)) 
        {
            for(k = z; k <= global_n; k += (k & -k)) 
                dp[i][j][k] += val;
        }
    }
}
 
long long query(long long x, long long y, long long z) 
{
    long long ret = 0, i, j, k;
    for(i = x; i > 0; i -= (i & -i)) 
    {
        for(j = y; j > 0; j -= (j & -j)) 
        {
            for(k = z; k > 0; k -= (k & -k)) 
                ret += dp[i][j][k];
        }
    }
    return ret;
}
 
int main() 
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    long long n, q, type, val, x, y, z, x0, y0, z0, total_players;
    cin >> n >> q;
    total_players = 0;
    n++;
    global_n = n;
    dp.clear();
    dp.assign(n + 2, vector <vector<long long>> (n + 2, vector <long long>(n + 2, 0)));
    while(q--) 
    {
        cin >> type;
        if(type == 1) 
        {
            cin >> x >> y >> z >> val;
            x++; y++; z++;
            total_players += val;
            update(x, y, z, val);
        }
        else 
        {
            cin >> x0 >> y0 >> z0;
            x0++; y0++; z0++;
            cin >> x >> y >> z;
            x++; y++; z++;
            long long value1 = query(x, y, z) - query(x0 - 1, y, z)  - query(x, y0 - 1, z) + query(x0 - 1, y0 - 1, z), value2 = query(x, y, z0 - 1) - query(x0 - 1, y, z0 - 1) - query(x, y0 - 1, z0 - 1)  + query(x0 - 1, y0 - 1, z0 - 1);
            long long final_answer = total_players - (long long)(value1 - value2);
            cout << final_answer << endl;
        }
    }
    return 0;
} 

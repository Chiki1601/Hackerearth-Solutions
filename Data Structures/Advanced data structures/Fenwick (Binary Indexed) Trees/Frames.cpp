#include <bits/stdc++.h>
using namespace std;
long n, m, d[2050][2050], u[2050][2050], l[2050][2050], r[2050][2050], ul[2050][2050], dr[2050][2050], t[2050], board[2050][2050];
 
void add(long ps, long val)
{
    for(; ps <= n; ps = (ps | (ps + 1)))
        t[ps] += val;
}
 
long sum(long r)
{
    long res = 0;
    for(; r >= 0; r = (r & (r + 1)) - 1)
        res += t[r];
    return res;
}
 
long sum(long l, long r)
{
    return sum(r) - sum(l - 1);
}
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    long long ans = 0;
    cin >> n >> m;
    for(int i = 0; i <= n + 1; i++)
        for(int j = 0; j <= m + 1; j++)
    board[i][j] = 1;
    for(int i = 1; i <= n; i++)
    {
        string st;
        cin >> st;
        for(int j = 1; j <= m; j++)
            board[i][j] = st[j - 1] - 48;
    }
    for(int i = n; i; --i)
        for(int j = m; j; --j)
        {
            r[i][j] = r[i][j + 1] + 1;
            d[i][j] = d[i + 1][j] + 1;
            if(board[i][j] == 1)
                r[i][j] = d[i][j] = 0;
        }
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= m; j++)
            {
                u[i][j] = u[i - 1][j] + 1;
                l[i][j] = l[i][j - 1] + 1;
                if(board[i][j] == 1)
                    u[i][j] = l[i][j] = 0;
            }
            for(int i = 1; i <= n; i++)
                for(int j = 1; j <= m; j++)
                {
                    ul[i][j] = min(u[i][j], l[i][j]);
                    dr[i][j] = min(d[i][j], r[i][j]);   
                }  
            for(int Dif = - n - m; Dif <= n + m; Dif++)
            {
                vector<long> event[2050];
                for(int i = 1; i <= n; i++)
                    event[i].clear();
                for(int i = 0; i <= n; i++)
                    t[i] = 0;
                for(int i = 1; i <= n; i++)
                {
                    for(int j = 0; j < event[i].size(); j++)
                    {
                        long ps = event[i][j];
                        add(ps, -1);   
                    } 
                    long j = i + Dif;
                    if(j < 1 || j > m)
                        continue;
                    if(board[i][j])
                        continue;
                        add(i, 1);
                    long q = dr[i][j];
                    if(i + q <= n)
                        event[i + q].push_back(i);
                    q = ul[i][j];
                    ans += sum(i - q + 1, i);
                }    
            }
    cout << ans << endl;
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
int X[4] = {0, 0, -1, +1}, Y[4] = {-1, +1, 0, 0}, n, m;
 
bool t(int x,int y)
{
    if(x < 0 || x >= n || y < 0 || y >= m) 
        return false;
    return true;
}
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    int A[n][m], mrk[n][m], ans[n][m], an = -1, pos = 0;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> A[i][j];
    for(int i = 1; i <= 100; i++)
    {
        memset(mrk, 0, sizeof(mrk));
        memset(ans, -1, sizeof(ans));
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
        pq.push(pair<int, int>(fabs(i - A[0][0]), 0));
        ans[0][0] = fabs(i - A[0][0]);
        pair<int, int> par[n][m];
        while(!pq.empty())
        {
            pair<int, int> pp = pq.top();
            pq.pop();
            int a = pp.first, b = pp.second;
            int x = b / m, y = b % m;
            if(mrk[x][y] != 0) 
                continue;
            mrk[x][y] = 1;
            for(int j = 0; j < 4; j++)
            {
                int k = j;
                {
                    int xx = x + X[j], yy = y + Y[k];
                    if(t(xx, yy) && (ans[xx][yy] == -1 || ans[xx][yy] > a + fabs(A[xx][yy] - i)))
                    {
                        ans[xx][yy] = a + fabs(A[xx][yy] - i);
                        pq.push(pair<int, int>(ans[xx][yy], xx * m + yy));
                        par[xx][yy] = pair<int, int>(x, y);
                    }
                }
            }
        }
        if(an == -1)
        { 
            an = ans[n - 1][m - 1];
            pos = i;
        }
        else if(ans[n - 1][m - 1] < an) 
        {
            an = ans[n - 1][m - 1];
            pos = i;
        }
    }
    cout << an << endl;
    return 0;
}

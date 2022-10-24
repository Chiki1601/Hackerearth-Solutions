#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, m, q, ui, uj, vi, vj, i, j, k, d[1005][1005], r[] = {0, 0, 1, -1}, c[] = {1, -1, 0, 0};
    cin >> n >> m >> q;
    char a[1005][1005];
    set<pair<int, pair<int, int>>> s;
    set<pair<int, pair<int, int>>>::iterator it;
    for(i = 0; i < n; i++)
    {
        cin >> a[i];
        for(j = 0; j < m; j++)
            d[i][j] = 100000000;
    }
    cin >> ui >> uj;
    d[ui - 1][uj - 1] = 0;
    s.insert(make_pair(0, make_pair(ui - 1, uj - 1)));
    while(!s.empty())
    {
        it = s.begin();
        ui = (*it).second.first;
        uj = (*it).second.second;
        s.erase(it);
        for(k = 0; k < 4; k++)
        {
            vi = ui + r[k];
            vj = uj + c[k];
            if(vi >= 0 && vi < n && vj >= 0 && vj < m && a[vi][vj] != '*' && d[vi][vj] > (d[ui][uj] + 1))
            {
                if(d[vi][vj] != 100000000)
                    s.erase(s.find(make_pair(d[vi][vj], make_pair(vi, vj))));
                d[vi][vj] = d[ui][uj] + 1;
                s.insert(make_pair(d[vi][vj], make_pair(vi, vj)));
            }
        }
    }
    while(q--)
    {
        cin >> ui >> uj;
        if(d[ui - 1][uj - 1] == 100000000)
            cout << "-1" << endl;
        else
            cout << d[ui - 1][uj - 1] << endl;
    }
    return 0;
}

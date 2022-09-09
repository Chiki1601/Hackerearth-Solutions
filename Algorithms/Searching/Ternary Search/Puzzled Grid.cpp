#include <bits/stdc++.h>
using namespace std;
int p[9000000], sizeOf[9000000], grid[3000][3000];
vector<pair<int, int>> cells[1000001];
vector<int> s[1000001];

int get(int x) 
{
    if(p[x] != x) 
        p[x] = get(p[x]);
    return p[x];
}

void Union(int x, int y) 
{
    x = get(x), y = get(y);
    if(x != y) 
    {
        if(sizeOf[x] < sizeOf[y])
            swap(x, y);
        p[y] = x;
        sizeOf[x] += sizeOf[y];
    }
}

void init(int n) 
{
    for(int i = 0; i < n; i++) 
    {
        p[i] = i;
        sizeOf[i] = 1;
    }
}

int main() 
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, q;
    cin >> n >> q;
    for(int i = 0; i < n; i++) 
    {
        for(int j = 0; j < n; j++) 
        {
            cin >> grid[i][j];
            cells[grid[i][j]].push_back(make_pair(i, j));
        }
    }   
    vector<int> X1(q), Y1(q), X2(q), Y2(q), lo(q), hi(q), ans(q);
    for(int i = 0; i < q; i++) 
    {
        cin >> X1[i] >> Y1[i] >> X2[i] >> Y2[i];
        lo[i] = 1, hi[i] = 1000001;
    }
    int lg = 21;
    while(lg--) 
    { 
        for(int i = 0; i < q; i++) 
        {
            if(lo[i] <= hi[i]) 
            {
                int mid = (lo[i] + hi[i]) / 2;
                s[mid].push_back(i);
            }
        }
        init(n * n);
        for(int e = 1; e <= 1000000; e++) 
        {
            if(!cells[e].empty()) 
            {
                for(auto cell : cells[e])
                 {
                    int dx[] = {0, 0, +1, -1}, dy[] = {+1, -1, 0, 0}, x = cell.first, y = cell.second;
                    for(int c = 0; c < 4; c++) 
                    {
                        int nx = x + dx[c], ny = y + dy[c];
                        if((nx >= 0) && (nx < n) && (ny >= 0) && (ny < n)) 
                        {
                            if(grid[nx][ny] <= grid[x][y]) 
                            {
                                int cellId0 = (x * n) + y, cellId1 = (nx * n) + ny;
                                Union(cellId0, cellId1);
                            }
                        }
                    }
                }
            }
            if(!s[e].empty()) 
            {
                for(int idx : s[e]) 
                {
                    int cellId0 = (X1[idx] * n) + Y1[idx], cellId1 = (X2[idx] * n) + Y2[idx];
                    if(get(cellId0) == get(cellId1)) 
                    {
                        ans[idx] = e;
                        hi[idx] = e - 1;
                    } 
                    else 
                        lo[idx] = e + 1;
                }
            }
        }
        for(int i = 1; i <= 1000000; i++)
            s[i].clear();
    }
    for(int i = 0; i < q; i++) 
        cout << ans[i] << endl;
    return 0;
}

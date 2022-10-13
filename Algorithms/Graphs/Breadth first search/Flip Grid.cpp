#include <bits/stdc++.h>
using namespace std;
 
vector<string> rotateClockwise(const vector<string>& grid) 
{
    vector<string> res = grid;
    for(int i = 0; i < 4; i++)
        for(int j = 0; j < 4; j++)
            res[j][4 - i - 1] = grid[i][j];
    return res;
}
 
vector<string> flipRow(const vector<string>& grid, int row) 
{
    vector<string> res = grid;
    for(int i = 0; i < 4; i++)
        res[row][i] = (grid[row][i] == '1' ? '0' : '1');
    return res;
}
 
vector<string> flipCol(const vector<string>& grid, int col) 
{
    vector<string> res = grid;
    for(int i = 0; i < 4; i++)
        res[i][col] = (grid[i][col] == '1' ? '0' : '1');
    return res;
}
 
int main() 
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    vector<string> gridA(4), gridB(4);
    for(int i = 0; i < 4; i++)
        cin >> gridA[i];
    for(int i = 0; i < 4; i++)
        cin >> gridB[i];
    map<vector<string>, bool> vis;
    map<vector<string>, int> dist;
    queue<vector<string>> q;
    q.emplace(gridA);
    vis[gridA] = true;
    dist[gridA] = 0;
    while(!q.empty()) 
    {
        vector<string> grid = q.front();
        q.pop();
        vector<string> op1 = rotateClockwise(grid);
        if(!vis.count(op1)) 
        {
            dist[op1] = dist[grid] + 1;
            vis[op1] = true;
            q.emplace(op1);
        }
        for(int i = 0; i < 4; i++) 
        {
            vector<string> op2 = flipRow(grid, i), op3 = flipCol(grid, i);
            if(!vis.count(op2)) 
            {
                dist[op2] = dist[grid] + 1;
                vis[op2] = true;
                q.emplace(op2);
            }
            if(!vis.count(op3)) 
            {
                dist[op3] = dist[grid] + 1;
                vis[op3] = true;
                q.emplace(op3);
            }
        }
    }
    if(!vis.count(gridB))
        cout << "-1" << endl;
    else
        cout << dist[gridB];
    return 0;
}

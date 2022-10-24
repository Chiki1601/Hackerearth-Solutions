#include <bits/stdc++.h>
using namespace std;
int pa[100011], sz[100011];
 
int f(int x) 
{
    if(x == pa[x]) 
        return x;
    return pa[x] = f(pa[x]);
}
 
bool join(int a, int b) 
{
    a = f(a);
    b = f(b);
    if(a != b) 
    {
        if(sz[a] < sz[b]) 
            swap(a, b);
        pa[b] = a;
        sz[a] += sz[b];
        return 1;
    }
    return 0;
}
 
struct Edge
{
    int u, v, val;
};
 
bool func(Edge a, Edge b) 
{
    return a.val < b.val;
}
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while(T--) 
    {
        int N, M, r1,c1,r2,c2, cnt = 0, ans = 0;
        cin >> N >> M;
        vector<vector<int> >G(N, vector<int>(M));
        cin >> r1 >> c1 >> r2 >> c2;
        map<pair<int, int>, int> C;
        vector<Edge> E;
        for(int i = 0; i < N; i++) 
        {
            for(int j = 0; j < M; j++) 
            {
                cin >> G[i][j];
                C[{i, j}] = cnt++;
                if(i - 1 >= 0) 
                    E.push_back({C[{i - 1, j}], C[{i, j}], G[i][j] ^ G[i - 1][j]});
                if(j - 1 >= 0) 
                    E.push_back({C[{i, j - 1}], C[{i, j}], G[i][j] ^ G[i][j - 1]});
            }
        }
        sort(E.begin(), E.end(), func);
        for(int j = 0; j < cnt; j++) 
        {
            pa[j] = j;
            sz[j] = 1;
        }
        for(auto e : E) 
        {
            if(join(e.u, e.v)) 
                ans += e.val;
        }
        cout << ans << endl;
    }
}

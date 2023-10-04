#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int test, totalN = 0;
    cin >> test;
    assert(test >= 1 && test <= 100000);
    while(test--)
    {
        int N;
        cin >> N;
        assert(N >= 1 && N <= 1000000);
        totalN += N;
        vector<vector<pair<int, int>>> tree(N);
        for(int i = 0; i < N - 1; i++)
        {
            int u, v, w;
            cin >> u >> v >> w;
            assert(1 <= u && u <= N);
            assert(1 <= v && v <= N);
            assert(1 <= w && w <= 1000000);
            u--;
			v--;
            tree[u].push_back({v, w});
            tree[v].push_back({u, w});
        }
        vector<vector<long long int>> vals(N, vector<long long int> (3, 0)), children(N, vector<long long int> (3, 0));
        function<void(int, int)> DFS = [&](int u, int p)
        {
            for(auto [v, w]: tree[u])
            {
                if(v == p)      
					continue;
                DFS(v, u);
                vals[u][1] += w*1ll*children[v][0] + vals[v][0];
                vals[u][2] += w*1ll*children[v][1] + vals[v][1];
                vals[u][0] += w*1ll*children[v][2] + vals[v][2];
                children[u][1] += children[v][0];
                children[u][2] += children[v][1];
                children[u][0] += children[v][2];
            }
            children[u][0]++;
        };
        DFS(0, -1);
        long long int ans = 2e18;
        function<void(int, int)> DFS2 = [&](int u, int p)
        {
            ans = min(ans, vals[u][1] + vals[u][2]*2ll);
            for(auto [v, w]: tree[u])
            {
                if(v == p)      
					continue;
                vals[u][1] -= w*1ll*children[v][0] + vals[v][0];
                vals[u][2] -= w*1ll*children[v][1] + vals[v][1];
                vals[u][0] -= w*1ll*children[v][2] + vals[v][2];
                children[u][1] -= children[v][0];
                children[u][2] -= children[v][1];
                children[u][0] -= children[v][2];
                vals[v][1] += w*1ll*children[u][0] + vals[u][0];
                vals[v][2] += w*1ll*children[u][1] + vals[u][1];
                vals[v][0] += w*1ll*children[u][2] + vals[u][2];
                children[v][1] += children[u][0];
                children[v][2] += children[u][1];
                children[v][0] += children[u][2];
                DFS2(v, u);
                children[v][1] -= children[u][0];
                children[v][2] -= children[u][1];
                children[v][0] -= children[u][2];
                vals[v][1] -= w*1ll*children[u][0] + vals[u][0];
                vals[v][2] -= w*1ll*children[u][1] + vals[u][1];
                vals[v][0] -= w*1ll*children[u][2] + vals[u][2];
                children[u][1] += children[v][0];
                children[u][2] += children[v][1];
                children[u][0] += children[v][2];
                vals[u][1] += w*1ll*children[v][0] + vals[v][0];
                vals[u][2] += w*1ll*children[v][1] + vals[v][1];
                vals[u][0] += w*1ll*children[v][2] + vals[v][2];
            }
        };
        DFS2(0, -1);
        cout << ans << "\n";
    }
    assert(totalN >= 1 && totalN <= 1000000);
}

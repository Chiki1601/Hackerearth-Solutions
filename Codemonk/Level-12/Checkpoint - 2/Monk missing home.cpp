#include<bits/stdc++.h>
using namespace std;
int pa[100011], sz[100011], D, A[100011];
long long ans = 0, pt[100011];
map<long long, long long>M[100011];

int f(int x) 
{
    if(pa[x] == x) 
		return x;
    return pa[x] = f(pa[x]);
}

void join(int u, int v) 
{
    u = f(u);
    v = f(v);
    if(sz[u] < sz[v]) 
		swap(u, v);
    sz[u] += sz[v];
    pa[v] = u;
    for(auto x : M[v]) 
	{
        for(int j = -D; j <= D; j++) 
		{
            if(M[u].find(x.first + j) != M[u].end()) 
                ans += x.second * M[u][x.first + j];
        }
    }
    for(auto x : M[v]) 
        M[u][x.first] += x.second;
}

int main() 
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N, u, v;
    cin >> N >> D;
    for(int i = 1; i <= N; i++) 
	{
        cin >> A[i];
        pa[i] = i;
        sz[i] = 1;
        M[i][A[i]] = 1;
    }
    vector<pair<int, int>>E;
    for(int i = 0; i < N - 1; i++)
	{
        cin >> u >> v;
        E.push_back({u, v});
    }
    vector<int>s(N - 1);
    for(int i = 0; i < N - 1; i++)
	{
        cin >> s[i];
        s[i]--;
    }
    for(int i = s.size() - 1; i >= 0; i--) 
	{
        pt[i] = ans;
        join(E[s[i]].first, E[s[i]].second);
    }
    for(int i = 0; i < N - 1; i++)
        cout << pt[i] << "\n";
}

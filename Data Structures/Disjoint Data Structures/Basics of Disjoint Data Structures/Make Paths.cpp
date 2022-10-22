#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int>> X, Y;
priority_queue<pair<long long, pair<int, int>>> Q;
int parent[100010], N, size[100010];
 
int getP(int n)
{
    while(n != parent[n])
        n = parent[n];
    return n;
}
 
bool combine(int n1, int n2)
{
    int p1 = getP(n1), p2 = getP(n2);
    if(p1 == p2)
        return false;
    if(size[p1] < size[p2])
	{
        size[p2] += size[p1];
        parent[p1] = p2;
    }
	else
	{
        size[p1] += size[p2];
        parent[p2] = p1;
    }
    return true;
}
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int x, y, node1, node2;
    cin >> N;
    for(int i = 0; i < N; i++)
	{
        cin >> x >> y;
        X.push_back(make_pair(x, i));
        Y.push_back(make_pair(y, i));
    }
    sort(X.begin(), X.begin() + N);
    sort(Y.begin(), Y.begin() + N);
    pair<int, int> a, b;
    for(int i = 0; i < N - 1; i++)
	{
        a = X[i];
        b = X[i + 1];
        Q.push(make_pair(-abs(b.first - a.first), make_pair(a.second, b.second)));
    }
    for(int i = 0; i < N - 1; i++)
	{
        a = Y[i];
        b = Y[i + 1];
        Q.push(make_pair(-abs(b.first - a.first), make_pair(a.second, b.second)));
    }
    for(int i = 0; i < N; i++)
	{
        parent[i] = i;
        size[i] = 1;
    }
    long long ans = 0;
    while(!Q.empty())
	{
        pair<long long, pair<int, int>> p = Q.top(); 
		Q.pop();
        node1 = p.second.first;
        node2 = p.second.second;
        if(combine(node1, node2))
            ans = ans - p.first;
    }
    cout << ans << endl;
}

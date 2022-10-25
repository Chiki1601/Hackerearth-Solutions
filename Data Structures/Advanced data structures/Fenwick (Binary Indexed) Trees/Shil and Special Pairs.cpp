#include <bits/stdc++.h>
using namespace std;
long long int bt[100011], ans[100011];
int N, pos[100011];
 
void update(int ind)
{
    while(ind <= N)
	{
        bt[ind]++;
        ind += (ind & -ind);
    }
}
 
long long int query(int ind)
{
    long long int ans = 0;
    while(ind > 0)
	{
        ans += bt[ind];
        ind -= (ind & -ind);
    }
    return ans;
}
 
bool func(pair<pair<long long int, long long int>, long long int> a, pair<pair<long long int, long long int>, long long int> b)
{
    return a.first.second < b.first.second;
}
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int M, D;
    cin >> N >> M >> D;
    int p[N + 1], l, r, ind, j = 0;
    for(int i = 1; i <= N; i++)
	{
        cin >> p[i];
        pos[p[i]] = i;
    }
    vector<pair<pair<long long int, long long int>, long long int>>Q;
    for(int i = 0; i < M; i++)
	{
        cin >> l >> r;
        Q.push_back(make_pair(make_pair(l, r), i));
    }
    sort(Q.begin(), Q.end(), func);
    for(int i = 1; i <= N; i++)
	{
        for(int k = max(1, p[i] - D); k <= min(N, p[i] + D); k++)
		{
            if(pos[k] <= i)
                update(pos[k]);
        }
        while(j < Q.size() and Q[j].first.second == i)
		{
            ans[Q[j].second] = query(Q[j].first.second) - query(Q[j].first.first - 1);
            j++;
        }
    }
    for(int i = 0; i < M; i++)
        cout << ans[i] << endl;
}

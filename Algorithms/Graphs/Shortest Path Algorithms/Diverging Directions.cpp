#include <bits/stdc++.h>
using namespace std;
vector<vector<pair<long long, long long>>> graph(200000);
long long n, q, a, b, c, wght[400000], open[200001], close[200001], dist1[200001], count1 = 1, sc[200001], ft[400001];
 
long long LSOne(long long n) 
{
    return (n & -n); 
}
 
void update(long long index, long long val) 
{
    ft[index] += val;
    index += LSOne(index);
    while(index <= 400000) 
	{
        ft[index] += val;
        index += LSOne(index);
    }
}
 
long long query(int index) 
{
    long long ans = ft[index];
    index -= LSOne(index);
    while(index >= 1) 
	{
        ans += ft[index]; 
        index -= LSOne(index);
    }
    return ans;
}
 
void traverse(long long index, long long d1) 
{
    update(count1, d1);  
    open[index] = count1++;
    for(long long i = 0; i < graph[index].size(); ++i) 
        traverse(graph[index][i].first, wght[graph[index][i].second]);
    close[index] = count1++;
    update(count1, -d1);
}
 
int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> q;
    for(long long i = 0; i < n - 1; ++i) 
	{
        cin >> a >> b >> c;
        graph[a].push_back(make_pair(b, i+1));
        wght[i + 1] = c; 
        sc[i + 1] = b; 
    }
    traverse(1, 0);
    for(long long i = 0; i < n - 1; ++i) 
	{
        cin >> a >> b >> c;
        graph[a].push_back(make_pair(b, (n + i)));
        wght[n+i] = c;
    }
    for(long long i = 0; i < q; ++i) 
	{
        cin >> a >> b >> c;
        if(a == 1) 
		{ 
            if(b >= n)  
                wght[b] = c; 
            else 
			{
                update(open[sc[b]], -wght[b]);
                update(close[sc[b]], wght[b]);
                update(open[sc[b]], c);
                update(close[sc[b]], -c);
                wght[b] = c;
            } 
        } 
		else 
		{
            if(b == c) 
			{
                cout << 0 << endl;
                continue;
            }
            long long ans1 = 0, c1 = c, flag = 0, beg = 2;
            priority_queue<pair<long long, long long>> pq;
            pq.push(make_pair(0, b));
            c = 1;
            for(int j = 0; j < graph[1].size(); ++j) 
			{
                int node = graph[1][j].first;
                if(open[node] <= open[c1] and close[c1] <= close[node]) 
				{
                    beg = open[node];
                    break;
                }
            }
            while(!pq.empty()) 
			{
                pair<long long, long long> temp = pq.top(); 
				pq.pop();
                long long node = temp.second, dist = temp.first;
                if(node == c) 
				{
                    ans1 = -dist; 
                    break;
                } 
				else if(node == c1) 
				{
                    ans1 = -dist;
                    flag = 1;
                    break;
                }
                for(long long j = 0; j < graph[node].size(); ++j) 
				{
                    long long roadlen = wght[graph[node][j].second], node1 = graph[node][j].first;
                    pq.push(make_pair(dist - roadlen, node1));
                }
            }
            if(flag == 0) 
                ans1 += (query(open[c1]));
            if(open[b] <= open[c1] and close[c1] <= close[b]) 
                ans1 = min(ans1, ((query(open[c1])) - (query(open[b]))));
            cout << ans1 << endl;
        }
    }
    return 0;
}

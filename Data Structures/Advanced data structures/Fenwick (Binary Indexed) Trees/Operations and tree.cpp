#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> g(100005);
vector<int> custo(100005), in(100005), out(100005), tour(100005);
int tempo = 1;
vector<long long> blacklist(100005, - 1), bit(100005);
 
void dfs(int node, int p = -1) 
{
  	tour[tempo] = node;
  	in[node] = tempo++;
  	for(auto to : g[node])
  	{
    	if(to != p) 
      		dfs (to, node);
  	}
  	out[node] = tempo - 1;
}
 
void update(int idx, long long delta) 
{
  	for(; idx < 100005; idx += idx & (-idx)) 
    	bit[idx] += delta;
}
 
void do_update(int left, int right, long long delta) 
{
  	update(left, +delta);
  	update(right + 1, -delta);
}
 
long long query(int idx) 
{
  	long long tot = 0;
  	for(; idx > 0; idx -= idx & (- idx)) 
    	tot += bit[idx];
  	return tot;
}
 
int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  	int n, q;
  	cin >> n;
  	for(int i = 0; i < n - 1; i++)
  	{
    	int st, et;
    	cin >> st >> et;
    	g[st].emplace_back(et);
    	g[et].emplace_back(st);
  	}
  	for(int i = 0; i < n; i++)
  		cin >> custo[i];
  	dfs(1);
  	for(int i = 0; i < n; i++) 
    	do_update(in[i + 1], in[i + 1], custo[i]);
    cin >> q;
  	while(q--) 
  	{
    	int task;
    	cin >> task;
    	if(task == 1) 
		{
      		int node, delta;
      		cin >> node >> delta;  
      		int start_node = in[node], end_node = out[node]; 
      		do_update(start_node, end_node, + delta);   
    	} 
		else if(task == 2) 
		{
          	int node, delta;
      		cin >> node >> delta;
      		do_update(in[node], in[node], + delta); 
    	}	 
		else if(task == 3) 
		{
      		int node;
      		cin >> node;
      		if(blacklist[node] == -1) 
        		blacklist[node] = query(in[node]);
      		else 
	  		{
        		long long cur = query(in[node]), replace = blacklist[node];
        		do_update(in[node], in[node], - cur + replace); 
        		blacklist[node] = -1;
      		}      
    	}	 
		else 
		{
      		int node;
      		cin >> node;
      		if(blacklist[node] == -1) 
	  			cout << query(in[node]) << "\n";
      		else 
	  			cout << blacklist[node] << "\n";
    	}
  	}
  	return 0;
}

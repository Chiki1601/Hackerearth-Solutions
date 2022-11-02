#include <bits/stdc++.h> 
using namespace std;  
 
void dfs(vector<vector<pair<int, int>>>& graph, int root, int father, int& depth) 
{
	for(int i = 0; i <= int(graph[root].size()) - 1; i++)
    {
		if(graph[root][i].first != father) 
        {
			if(graph[root][i].second == -1) 
            {
				int branchdepth = 0;
				dfs(graph, graph[root][i].first, root, branchdepth);
				depth = max(depth, branchdepth + 1);
				graph[root][i].second = branchdepth;
			}
			else 
				depth = max(depth, graph[root][i].second + 1);
		}
	}
	return;
}
 
int main() 
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, maxi = -1, maxc;
	cin >> n;
	vector<vector<pair<int, int>>> alist(n + 1);
	for(int i = 1; i <= n - 1; i++)
    {
		int a, b;
		cin >> a >> b;
		alist[a].push_back(pair<int, int>(b, -1));
		alist[b].push_back(pair<int, int>(a, -1));
	}
	for(int i = 1; i <= int(alist.size()) - 1; i++)
    {
		if(int((alist[i]).size()) >= 5) 
        {
			int depth = 0;
			dfs(alist, i, -1,depth);
			if(depth >= 3) 
            {
				if(depth + int((alist[i]).size()) > maxi) 
                {
					maxi = depth + int((alist[i]).size());
					maxc = i;
				}
			}
		}
	}
	if(maxi == -1)
        cout << -1;
	else 
        cout << maxi << " " << maxc;
	return 0;
}

#include <bits/stdc++.h>
using namespace std;
int n;
 
struct Graph
{
	int n;
	set<int> no_right_s, no_left_s, to_center_s;
	vector<pair<int, int>> segments;
	Graph(int new_n = 0)
	{
		n = new_n;
	}
	void change_edge(int a, int b)
	{
		if(a == n)
			to_center_s.erase(b);
		else if(b == n)
			to_center_s.insert(a);
		else if((a + 1) % n == b)
		{
			no_right_s.erase(a);
			no_left_s.insert(b);
		}
		else
		{
			no_left_s.erase(a);
			no_right_s.insert(b);
		}
	}
	bool can_reach_center(int a)
	{
		if(a == n)
			return true;
		segments.clear();
		add_reachable_to_right(a);
		add_reachable_to_left(a);
		for(pair<int, int> segment : segments)
		{
			int l = segment.first, r = segment.second;
			auto it = to_center_s.lower_bound(l);
			if(it != to_center_s.end() && *it <= r)
				return true;
		}
		return false;
	}
	void add_reachable_to_right(int a)
	{
		if(no_right_s.empty())
		{
			segments.clear();
			segments.emplace_back(0, n - 1);
			return;
		}
		auto it = no_right_s.lower_bound(a);
		if(it != no_right_s.end())
		{
			segments.emplace_back(a, *it);
			return;
		}
		segments.emplace_back(a, n - 1);
		if(no_right_s.count(n - 1) == 1 || a == 0)
			return;
		it = no_right_s.lower_bound(0);
		if(it == no_right_s.end())
			segments.emplace_back(0, a - 1);
		else
			segments.emplace_back(0, *it);
	}
	void add_reachable_to_left(int a)
	{
		if(no_left_s.empty())
		{
			segments.clear();
			segments.emplace_back(0, n - 1);
			return;
		}
		auto it = no_left_s.upper_bound(a);
		if(it != no_left_s.begin())
		{
			it--;
			segments.emplace_back(*it, a);
			return;
		}
		segments.emplace_back(0, a);
		if(no_left_s.count(0) == 1 || a == n - 1)
			return;
		it = no_left_s.end();
		it--;
		segments.emplace_back(*it, n - 1);
	}
};Graph graph, reverse_graph;
 
bool can_reach(int a, int b)
{
	bool can_reach_center_b = reverse_graph.can_reach_center(b), can_reach_center_a = graph.can_reach_center(a);
	if(a == n)
		return can_reach_center_b; 
	if(b == n)
		return can_reach_center_a;
	if(can_reach_center_a && can_reach_center_b)
		return true;
	for(pair<int, int> segment : graph.segments)
	{
		int l = segment.first, r = segment.second;
		if(l <= b && b <= r)
			return true;
	}
	return false;
}
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
	graph = Graph(n);
	reverse_graph = Graph(n);
	for(int i = 0; i < 2 * n; i++)
	{
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		graph.change_edge(a, b);
		reverse_graph.change_edge(b, a);
	}
	int q;
	cin >> q;
	for (int i = 0; i < q; i++)
	{
		int type, a, b;
		cin >> type >> a >> b;
		a--;
		b--;
		if(type == 1)
		{
			graph.change_edge(a, b);
			reverse_graph.change_edge(b, a);
		}
		else
		{
			bool res = can_reach(a, b);
			printf("%s\n", res ? "Yes" : "No");
		}
	}
	return 0;
}

#include <bits/stdc++.h>
using namespace std;
int root[100005], used = 0;
 
struct Node 
{ 
	int child[2], cnt;
} trie[300005 * 22];
 
void insert(int prev, int &new_root, int w, int add) 
{
	new_root = ++used;
	int cur = new_root;
	for(int i = 19; i >= 0; i--) 
	{
		bool bit = w & (1 << i);
		trie[cur] = trie[prev];
		trie[cur].child[bit] = ++used;
		trie[cur].cnt += add;
		prev = trie[prev].child[bit];
		cur = trie[cur].child[bit];
	}
	trie[cur] = trie[prev];
	trie[cur].cnt += add;
}
 
int find(int l, int r) 
{
	l--; 
	r = root[r];
	int ret = 0;
	for(int i = 19; i >= 0; i--) 
	{
		bool bit = l & (1 << i);
		if(!bit)
			ret += trie[trie[r].child[1]].cnt;
		r = trie[r].child[bit];
	}
	return ret;
}
 
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	insert(root[0], root[0], 0, 0);
	int N, K, Q, ans = 0; 
	cin >> N >> K >> Q;
	map<int, deque<int>> mp;
	map<int, int> before;
	for(int i = 1, x; i <= N; i++) 
	{
		cin >> x;
		root[i] = root[i-1];
		mp[x].push_back(i);
		if(K < mp[x].size()) 
		{
			insert(root[i], root[i], mp[x].front(), -2);
			insert(root[i], root[i], before[x], 1);
			before[x] = mp[x].front();
			mp[x].pop_front();
		}
		if(K == mp[x].size()) 
			insert(root[i], root[i], mp[x].front(), 1);
	}
	while(Q--) 
	{
		int l, r; 
		cin >> l >> r;
		l = (l + ans) % N;
		r = (r + ans) % N;
		if(l > r) 
			swap(l, r);
		l++; 
		r++;
		ans = find(l, r);
		cout << ans << endl;
	}
}

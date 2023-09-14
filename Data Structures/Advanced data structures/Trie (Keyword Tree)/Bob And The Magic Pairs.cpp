#include<bits/stdc++.h>
using namespace std;

struct trie
{
    trie *bitTrie[2] = {};
    int node_cnt = 0;
    void add(int r, int pos)
    {
        bool bit = r&(1LL<<pos);
        node_cnt++;
        if(bitTrie[bit] == nullptr)
            bitTrie[bit] = new trie();
        if(pos >= 0)
            bitTrie[bit]->add(r, pos - 1);
    }
    int checker(int r, int y, int pos)
    {
        bool bit = r&(1LL<<pos), bitRange = y&(1LL<<pos), xors = (r^y)&(1LL<<pos);
        int ans = 0;
        if(bitRange and bitTrie[bit] != nullptr)
            ans += bitTrie[bit]->node_cnt;
        if(bitTrie[xors] != nullptr)
            ans += bitTrie[xors]->checker(r, y, pos - 1);
        return ans;   
    }
};

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t; 
	cin >> t;
    while(t--)
    {
		int n, u, v, ans = 0; 
		cin >> n >> u >> v;
		trie bitTrie;
		for(int i = 0; i < n; i++)
		{
			int x; 
			cin >> x;
			ans += bitTrie.checker(x, v + 1LL, 31) - bitTrie.checker(x, u, 31);
			bitTrie.add(x, 31);
		}
		cout << ans << endl;
	}
    return 0;
}

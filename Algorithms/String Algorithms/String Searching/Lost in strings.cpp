#include<bits/stdc++.h>
using namespace std;
 
class FenwickTree 
{
    public:
        FenwickTree(int n = 400100) : N(n), data(N, 0) {}
        void add(int x, int v) 
        {
            for(; x < N; x |= x + 1) 
                data[x] += v;
        }
        int get(int x) 
        {
            int res = 0;
            for(; x >= 0; x = (x & (x + 1)) - 1) 
                res += data[x];
            return res;
        }
        int get(int l, int r) 
        {
            if(l > r) 
                return 0;
            return get(r) - get(l - 1);
        }
    private:
        int N;
        vector<int> data;
};
 
class Trie 
{
    public:
        Trie(int sz = 400100, int _h = 20) : rt(0), idx(0), h(_h), tree(sz), pars(sz, vector<int>(_h, 0)) {}
        int add(int p, int l, int ch = -1) 
        {
            int n = tree[p].len, d = 0;
            for(int i = h - 1; i >= 0; --i) 
            {
                if(d + (1 << i) + l <= n) 
                {
                    d += 1 << i;
                    p = pars[p][i];
                }
            }
            if(ch != -1) 
            {    
                auto& v = tree[p].nexts[ch - 'a'];
                if(v == 0) 
                    v = newNode(); 
                tree[v].len = l + 1;
                pars[v][0] = p;
                for(int i = 0; i + 1 < h; ++i) 
                    pars[v][i + 1] = pars[pars[v][i]][i];
                return v;
            } 
            else 
            {
                assert(tree[p].len == 0 || tree[p].len == l);
                tree[p].len = l;
                return p;
            }
        }
        int search(string& s) 
        {
            int cur = rt;
            for(auto c : s) 
            {
                if(tree[cur].nexts[c - 'a'] > 0) 
                    cur = tree[cur].nexts[c - 'a'];
                else
                return -1;
            }
            return cur;
        }
        void build() 
        {
            int T = 0;
            dfs(rt, T);
        }
        int root() 
        { 
            return rt; 
        }
        int in(int p) 
        {
            return tree[p].in;
        }
        int out(int p) 
        {
            return tree[p].out;
        }
    private:
        struct Node 
        {
            Node() : in(0), out(0), len(0) 
            {
                fill(begin(nexts), end(nexts), 0);
            }
            int nexts[26], in, out, len;
        };
        int rt, idx, h;
        vector<Node> tree;
        vector<vector<int>> pars;
        int newNode() 
        {
            return ++idx;
        }
        void dfs(int u, int& time) 
        {
            tree[u].in = ++time;
            for(int i = 0; i < 26; ++i) 
            {
                int v = tree[u].nexts[i];
                if(v > 0) 
                    dfs(v, time);
            }
            tree[u].out = time; 
        }
};
 
class Solution 
{
    public:
        void init(string& s) 
        {
            int idx = trie.root();
            for(int i = 0; i < s.length(); ++i) 
                idx = trie.add(idx, i, s[i]);
            indices.clear();
            indices.reserve(1000);
            indices.push_back(idx);
        }
        void append(int len, int idx, char ch) 
        {
            int p = indices[idx];
            int nidx = trie.add(p, len - 1, ch);
            indices.push_back(nidx);
        }
        void append(int len, int idx) 
        {
            int p = indices[idx];
            int nidx = trie.add(p, len);
            indices.push_back(nidx);
        }
        void query(int l, int r, string& t) 
        {
            int n = ranges.size();
            ranges.emplace_back(l, r);
            qindices.emplace_back(trie.search(t), n);
        }
        vector<int> fetchResult() 
        {
            trie.build();
            vector<int> res(ranges.size(), 0);
            int n = indices.size();
            vector<vector<int>> queries(n + 1);
            for(int i = 0; i < ranges.size(); ++i) 
            {
                int l = ranges[i].first, r = ranges[i].second, t = qindices[i].first;
                if(t >= 0) 
                {
                    if(l - 1 >= 0) 
                        queries[l - 1].push_back(i);
                    queries[r].push_back(i);
                }
            }
            for(int i = 0; i < n; ++i) 
            {
                int idx = indices[i];
                idx = trie.in(idx);
                ft.add(idx, 1);
                for(auto x : queries[i]) 
                {
                    int t = qindices[x].first, p = qindices[x].second, l = trie.in(t), r = trie.out(t), cnt = ft.get(l, r);
                    if(i == ranges[x].second) 
                        res[p] += cnt;
                    else
                        res[p] -= cnt;
                }
            }
            return res;
        }
    private:
        Trie trie;
        FenwickTree ft;
        vector<int> indices;
        vector<pair<int, int>> ranges, qindices;
};
 
int main() 
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    Solution sol;
    string s;
    cin >> s;
    sol.init(s);
    int q;
    cin >> q;
    while(q-- > 0) 
    {
        int t; 
        cin >> t;
        if(t == 1) 
        {
            int p, n;
            char c;
            cin >> p >> n >> c;
            --n;
            sol.append(p, n, c);
        } 
        else if(t == 2) 
        {
            int p, n;
            cin >> p >> n;
            --n;
            sol.append(p, n);
        } 
        else
        {
            int l, r;
            cin >> l >> r;
            --l, --r;
            string t;
            cin >> t;
            sol.query(l, r, t);
        }
    }
    auto res = sol.fetchResult();
    for(auto r : res) 
    {
        if (r) 
            cout << "yes" << endl;
        else 
            cout << "no" << endl;
    }
    return 0;
}

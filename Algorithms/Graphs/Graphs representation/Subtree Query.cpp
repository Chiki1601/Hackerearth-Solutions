#include <bits/stdc++.h>
using namespace std;
vector<int> order, v[100005];
int a[100005], pos[100005], sub[100005];

struct SegTree 
{
    vector<int> arr, tree;
    int n;
    vector<array<int, 3>> lazy;
    SegTree(vector<int> a) 
    {
        arr = a;
        n = arr.size();
        tree.resize(4 * n);
        lazy.resize(4 * n, {0, 0, 0});
        buildTree(1, 0, n - 1);
    }
    void buildTree(int node, int start, int end) 
    {
        if(start == end) 
            tree[node] = arr[start];
        else 
        {
            int mid = (start + end) / 2;
            buildTree(2 * node, start, mid);
            buildTree(2 * node + 1, mid + 1, end);
            tree[node] = tree[2 * node] + tree[2 * node + 1];
        }
    }
    void push(int node, int start, int end) 
    {
        if(start > end) 
            return ;
        if(lazy[node][2]) 
            tree[node] = (end - start + 1) * lazy[node][1];
        if(lazy[node][0]) 
            tree[node] = (end - start + 1) - tree[node];
        if(start != end) 
        {
            if(lazy[node][2]) 
                lazy[2 * node] = lazy[2 * node + 1] = lazy[node];
            else
            {
                lazy[2 * node][0] ^= lazy[node][0];
                lazy[2 * node + 1][0] ^= lazy[node][0];
            }
        }
        lazy[node][0] = lazy[node][2] = 0;
    }
    void flipRange(int node, int start, int end, int l, int r) 
    {
        if(start > r || end < l || start > end) 
            return;
        push(node, start, end);
        if(start >= l && end <= r) 
        {
            lazy[node][0] = 1;
            return;
        }
        int mid = (start + end) / 2;
        flipRange(2 * node, start, mid, l, r);
        flipRange(2 * node + 1, mid + 1, end, l, r);
        push(2 * node, start, mid);
        push(2 * node + 1, mid + 1, end);
        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }
    int getSum(int node, int start, int end, int l, int r) 
    {
        if(start > r || end < l || start > end) 
            return 0;
        push(node, start, end);
        if(start >= l && end <= r) 
            return tree[node];
        int mid = (start + end) / 2;
        int leftSum = getSum(2 * node, start, mid, l, r),rightSum = getSum(2 * node + 1, mid + 1, end, l, r);
        return leftSum + rightSum;
    }
    void flipRange(int l, int r) 
    {
        flipRange(1, 0, n - 1, l, r);
    }
    int getSum(int l, int r) 
    {
        return getSum(1, 0, n - 1, l, r);
    }
};

void dfs(int u, int p) 
{
    sub[u] = 1;
    order.push_back(u);
    for(auto i : v[u]) 
    {
        if(i != p) 
        {
            dfs(i, u);
            sub[u] = sub[u] + sub[i];
        }
    }
}

int main() 
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, q;
    cin >> n;
    for(int i = 0; i < n - 1; i++) 
    {
        int x, y;
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    for(int i = 1; i <= n; i++) 
        cin >> a[i];
    dfs(1, 0);
    for(int i = 0; i < n; i++) 
        pos[order[i]] = i;
    vector<SegTree> sg;
    for(int i = 0; i < 20; i++) 
    {
        vector<int> arr(n, 0);
        for(int j = 0; j < n; j++) 
        {
            if((a[order[j]] & (1LL << i)) > 0) 
                arr[j] = 1;
        }
        sg.push_back(SegTree(arr));
    }
    cin >> q;
    while(q--) 
    {
        int t;
        cin >> t;
        if(t == 1) 
        {
            int node;
            cin >> node;
            int l = pos[node];
            int r = l + sub[node] - 1;
            long long c = 0;
            for(int i = 0; i < 20; i++) 
            {
                long long sum = sg[i].getSum(l, r);
                c = c + (sum * (1LL << i));
            }
            cout << c << "\n";
        } 
        else 
        {
            int node, x;
            cin >> node >> x;
            int l = pos[node];
            int r = l + sub[node] - 1;
            long long node_x = x;
            for(int i = 0; i < 20; i++) 
            {
                if((node_x & (1LL << i)) > 0) 
                    sg[i].flipRange(l, r);
            } 
        }
    }
    return 0;  
}

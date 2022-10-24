#include<bits/stdc++.h>
using namespace std;
#define FOR(i, a, b) for(int i = a; i <= b; ++i)
#define REP(i, n) FOR(i, 0, n - 1)
vector<int> t[1000015], powers[1000015];
map<vector<int>, int> mapHash; 
int COUNTER, LAST_Q, trie[1000015][26], where[1000015], len[1000015]; 
char sl[1000015];
 
vector<pair<int,int>> H = vector<pair<int, int>> 
{
    make_pair(27, 1000000007),
    make_pair(101, 1000000028)
};
const int K = H.size();
const vector<int> HASH_ZERO = vector<int>(K, 0);
 
vector<int> mul(vector<int> w, int len) 
{
    for(int i = 0; i <= K - 1; ++i) 
        w[i] = (long long) w[i] * powers[1000014 - len][i] % H[i].second;
    return w;
}
 
vector<int> sub(vector<int> a, vector<int> b) 
{
    for(int i = 0; i <= K - 1; ++i) 
		a[i] = (a[i] - b[i] + H[i].second) % H[i].second;
    return a;
}
 
vector<int> extendHash(vector<int> w, int ch) 
{
    for(int i = 0; i < K; ++i) 
    {
        long long tmp = (long long) w[i] * H[i].first + ch + 1;
        w[i] = tmp % H[i].second;
    }
    return w;
}
 
struct Node 
{
    int endHere = 0, sum = 0; 
    vector<int> hash;
} node[1000015];
 
void update(int a) 
{
    for(int i = 0;i <= 25; ++i) 
    {
        int b = trie[a][i];
        if(b == 0) 
            continue;
        bool before = (bool) node[b].sum;
        node[b].sum = node[a].sum + node[b].endHere;
        if(before != (bool) node[b].sum)
            update(b);
    }
}
 
void addLetter(int id, int ch) 
{
    ++len[id];
    int v = where[id], & child = trie[v][ch];
    if(!child) 
    {
        child = ++COUNTER;
        node[child].hash = extendHash(node[v].hash, ch);
        mapHash[mul(node[child].hash, len[id])] = child;
    }
    where[id] = child;
    node[v].endHere--;
    node[v].sum--;
    node[child].endHere++;
    update(v);
}
 
void queryAdd(int n) 
{
    int i, j;
    cin >> i >> j;
    assert(0 <= i && 0 <= j && i < n && j < 26);
    addLetter((i + LAST_Q) % n, (j + LAST_Q) % 26);
}
 
bool queryCheck() 
{
    static long long total = 0;
    cin >> sl;
    int d = strlen(sl);
    total += d;
    assert(total <= 500000);
    for(int i = 0; i < d; ++i)
        assert('a' <= sl[i] && sl[i] <= 'z');
    for (int i = 0; i < d; ++i)
        sl[i] = 'a' + ((sl[i] - 'a' + LAST_Q) % 26);
    t[0] = HASH_ZERO;
    for(int i = 1; i <= d; ++i) 
        t[i] = extendHash(t[i - 1], sl[i - 1] - 'a');
    for(int i = 0; i <= d - 1; ++i) 
	{
        int low = i - 1, high = d - 1;
        while(low < high) 
        {
            int j = (low + high + 1) / 2;
            vector<int> interval = sub(mul(t[j + 1], j + 1), mul(t[i], i));
            interval = mul(interval, 1000014 - i);
            auto it = mapHash.find(interval);
            if(it == mapHash.end()) high = j - 1;
            else 
            {
                low = j;
                if(node[(*it).second].endHere) 
                    return true;
            }
        }
    }
    return false;
}
 
int main() 
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    powers[0] = vector<int>{1, 1, 1};
    for(int i = 1; i <= 1000014; ++i) 
	{
        for(int j = 0; j <= K - 1; ++j) 
		{
            long long tmp = (long long) powers[i - 1][j] * H[j].first;
            powers[i].push_back(int(tmp % H[j].second));
        }
    }
    int n, q;
    cin >> n >> q;
    assert(1 <= min(n, q) && max(n, q) <= 500000);
    node[0].endHere = node[0].sum = n;
    node[0].hash = HASH_ZERO;
    long long total = 0;
    for(int id = 0; id <= n - 1; ++id) 
	{
        cin >> sl;
        int d = strlen(sl);
        total += d;
        for(int j = 0; j <= d - 1; ++j) 
			assert('a' <= sl[j] && sl[j] <= 'z');
        for(int j = 0; j <= d - 1; ++j) 
			addLetter(id, sl[j] - 'a');
    }
    assert(total <= 500000);
    REP(i, q) 
    {
        int which;
        cin >> which;
        assert(1 <= which && which <= 2);
        if(which == 1) 
        {
            bool ans = queryCheck();
            puts(ans ? "YES" : "NO");
            if(ans) 
                LAST_Q = i;
        }
        else 
            queryAdd(n);
    }
    return 0;
}

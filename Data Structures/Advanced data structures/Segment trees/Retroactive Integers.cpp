#include <bits/stdc++.h>
using namespace std;
int q, _time;
char type, op[2], var[2];
pair <int, int> cache[100001];
 
struct NodeQuery
{
    char op;
    int a, b, time;
} queries[100001];
 
struct NodeMatrix
{
    map <int, int> mt[21];
    void set_identity()
	{
        for(int i = 0; i < 21; ++i)
            mt[i][i] = 1;
    }
    void reset()
	{
        for(int i = 0; i < 21; ++i)
            mt[i].clear();
    }
    void set_matrix(const NodeQuery& query)
	{
        this->reset();
        switch(query.op)
		{
			case '?':
				return;
			case '=':
				mt[query.a][query.b] = 1;
				break;
			case '!':
				mt[query.a][20] = query.b;
				break;
			case '+':
				mt[query.a][query.a] = 1;
				mt[query.a][20] = query.b;
				break;
			case '*':
				mt[query.a][query.a] = query.b;
				break;
        }
        for(int i = 0; i < 21; ++i)
        	if(i != query.a)
            	mt[i][i] = 1;
    }
    NodeMatrix operator * (const NodeMatrix& other) const
	{
        NodeMatrix res;
        for(int i = 0; i < 21; ++i)
        	for(pair <int, int> node1 : this->mt[i])
        		for(pair <int, int> node2 : other.mt[node1.first])
            		res.mt[i][node2.first] = (res.mt[i][node2.first] + (long long)node1.second * node2.second) % 1000000007;
        return res;
    }
};NodeMatrix it[500005];
 
void init(const int& lef = 1, const int& rig = q, const int& k = 1)
{
    it[k].set_identity();
    if(lef == rig)
        return;
    int mid = (lef + rig) >> 1;
    init(lef, mid, k << 1);
    init(mid + 1, rig, k << 1 | 1);
}
 
void up(const NodeQuery& query, const int& lef = 1, const int& rig = q, const int& k = 1)
{
    if(lef == rig)
	{
        it[k].set_matrix(query);
        return;
    }
    int mid = (lef + rig) >> 1;
    if(query.time <= mid)
        up(query, lef, mid, k << 1);
    else
        up(query, mid + 1, rig, k << 1 | 1);
    it[k] = it[k << 1 | 1] * it[k << 1];
}
 
NodeMatrix get(const int& u, const int& v, const int& lef = 1, const int& rig = q, const int& k = 1)
{
    if(u == lef && v == rig)
        return it[k];
    int mid = (lef + rig) >> 1;
    if(v <= mid)
        return get(u, v, lef, mid, k << 1);
    else
    if(u > mid)
        return get(u, v, mid + 1, rig, k << 1 | 1);
    else
        return get(mid + 1, v, mid + 1, rig, k << 1 | 1) * get(u, mid, lef, mid, k << 1);
}
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> q;
    for(int i = 1; i <= q; ++i)
	{
        cin >> _time >> op >> var;
        queries[i].op = op[0];
        queries[i].a = var[0] - 'a';
        if(op[0] == '=')
		{
            cin >> var;
            queries[i].b = var[0] - 'a';
        }
        else
        if(op[0] != '?')
            cin >> queries[i].b;
        cache[i] = pair <int, int>(_time, i);
    }
    sort(cache + 1, cache + 1 + q);
    for(int i = 1; i <= q; ++i)
        queries[cache[i].second].time = i;
    init();
    for(int i = 1; i <= q; ++i)
    if(queries[i].op == '?')
        cout << get(1, queries[i].time).mt[queries[i].a][20] << "\n";
    else
        up(queries[i]);
    return 0;
}

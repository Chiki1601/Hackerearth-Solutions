#include <bits/stdc++.h>
using namespace std;
int n, q, arr[1000010], COOKIE = 0, cnt = 0;
 
struct Query
{
	int l, r, x, ind;
	Query(){}
	Query(int _l, int _r, int _x, int _ind)
    {
		l = _l; r = _r; x = _x;
		ind = _ind;
	}
} query[50010];
 
struct Trie
{
	int next[2], count;
	Trie()
    {
		next[0] = next[1] = -1;
		count = 0;
	}
} tree[16000160];
 
bool cmp(Query a, Query b)
{
	if(a.l / 1000 != b.l / 1000) 
        return a.l / 1000 < b.l / 1000;
	return a.r < b.r;
}
 
void Insert(int bit, int num, int iter)
{
	tree[iter].count++;
	if(bit == -1) 
        return;
	int sada = ((num & (1 << bit)) > 0);
	if(tree[iter].next[sada] == -1)
    {
		COOKIE++;
		tree[iter].next[sada] = COOKIE;
	}
	Insert(bit - 1, num, tree[iter].next[sada]);
}
 
void Remove(int bit, int num, int iter)
{
	tree[iter].count--;
	if(bit == -1) 
        return;
	int sada = ((num & (1 << bit)) > 0);
	Remove(bit - 1, num, tree[iter].next[sada]);
	if(tree[tree[iter].next[sada]].count <= 0) 
        tree[iter].next[sada] = -1;
}
 
int Answer(int bit, int num, int iter)
{
	if(bit == -1)
    {
		cnt = tree[iter].count; 
		return 0;
	}
	
	int sada = ((num & (1 << bit)) > 0);
	if(tree[iter].next[sada] == -1) 
        sada = sada ^ 1;
	return (1 << bit) * sada + Answer(bit - 1, num, tree[iter].next[sada]);
}
 
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
	for(int i = 0; i < n; i++)
		cin >> arr[i];
	cin >> q;
	for(int i = 0; i < q; i++)
    {
		int a, b, c;
		cin >> a >> b >> c;
		a--; 
        b--;
		query[i] = Query(a, b, c, i);
	}
    pair<int, int> sol[1000010];
	sort(query, query + q, cmp);
	Insert(29, arr[0], 0);
	int left, right;
    left = right = 0;
	for(int i = 0; i < q; i++)
    {
		Query tmp = query[i];
		while(right > tmp.r)
        {
			Remove(29, arr[right], 0);
			right--;
		}
		while(right < tmp.r)
        {
			right++;
			Insert(29, arr[right], 0);
		}
		while(left > tmp.l)
        {
			left--;
			Insert(29, arr[left], 0);
		}
		while(left < tmp.l)
        {
			Remove(29, arr[left], 0);
			left++;
		}
		sol[tmp.ind].first = Answer(29, tmp.x, 0);
		sol[tmp.ind].second = cnt;
	}
	for(int i = 0; i < q; i++)
		cout << sol[i].first << " " << sol[i].second << endl;
	return 0;
}

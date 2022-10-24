#include<bits/stdc++.h>
using namespace std;
 
struct node
{
    int maxweight;
    node * next[26];
    node()
	{
        maxweight = 0;
        for(int i = 0; i < 26; i++)
            next[i] = NULL;
    }
};
 
node * insert(node * root, string & s, int ind, int weight)
{
    if(ind == s.length())
        return NULL;
    root->maxweight = weight;
    node * & cur = root->next[s[ind] - 'a'];
    if(cur == NULL)
        cur = new node();
    cur = insert(cur, s, ind + 1, weight);
    return root;
}
 
int query(node * root, string & q, int i)
{
    if(i == q.length())
		return root->maxweight;
    if(root->next[q[i] - 'a'] == NULL)
        return -1;
    return query(root->next[q[i] - 'a'], q, i + 1);
}
 
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, q;
    cin >> n >> q;
    vector<pair<int, string >> ar(n);
    for(int i = 0; i < n; i++)
        cin >> ar[i].second >> ar[i].first;
    sort(ar.begin(), ar.end());
    node * root = new node();
    for(int i = 0; i < n; i++)
        root = insert(root, ar[i].second, 0, ar[i].first);
    while(q--)
	{
        string s;
        cin >> s;
        cout << query(root, s, 0) << endl;
    }
    return 0;
}

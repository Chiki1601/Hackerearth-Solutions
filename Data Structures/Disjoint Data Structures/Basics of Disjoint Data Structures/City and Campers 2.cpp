#include<bits/stdc++.h>
using namespace std;
int par[200002], sze[200002];
map<int, int> m;
 
void init(int n)
{
	for(int i = 1; i <= n; i++)
    {
		par[i] = i;
		sze[i] = 1;
        m[1]++;
	}
}
 
int find(int n)
{
	if(par[n] == n) 
        return n;
	else 
        return par[n] = find(par[n]);
}
 
void union_(int a, int b)
{
	int pa = find(a), pb = find(b), maxx = 1;
	if(pa == pb) 
        return;
    m[sze[pa]]--;
    m[sze[pb]]--;
    if(m[sze[pa]] == 0) 
        m.erase(m.find(sze[pa]));
    if(m[sze[pb]] == 0) 
        m.erase(m.find(sze[pb]));
	if(sze[pa] > sze[pb])
	{
		par[pb] = pa;
		sze[pa] += sze[pb];
        m[sze[pa]]++;
        maxx = max(maxx, sze[pa]);
	}
	else
	{
		par[pa] = pb;
		sze[pb] += sze[pa];
         m[sze[pb]]++;
        maxx = max(maxx, sze[pb]);
	}
}
 
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int t = 1;
	for(int i = 0; i < t; i++) 
    {
        int n, q;
        cin >> n;
        init(n);
        cin >> q;
        while(q--)
        {
            int a, b, diff = INT_MAX, a1 = 0, c = 1;
            cin >> a >> b;
            union_(a, b);
            if(m.size() == 1) 
            {
                cout << "0" << endl;
                continue;
            }
            auto it = m.begin();
            if(it->second > 1)
            {
                cout << "0" << endl;
                continue;
            } 
            a1 = it->first;
            it++;
            while(it != m.end())
            {
                if(it->second > 1)
                {
                    diff = 0;
                    break;
                }
                diff = min(diff, it->first - a1);
                a1 = it->first;
                it++;
            }
            cout << diff << endl;
        }
    }
}

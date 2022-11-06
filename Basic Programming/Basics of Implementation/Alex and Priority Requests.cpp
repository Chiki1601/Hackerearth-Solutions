#include<bits/stdc++.h>
using namespace std;
map<int, int> ti;
multiset<int> pri;
 
void add(int t, int p)
{
    ti[t] = p;
    pri.insert(p);
}
 
void del(int t)
{
    auto iter = ti.find(t);
    if(iter != ti.end())
	{
        auto iter_pri = pri.find(iter->second);
        if(iter_pri != pri.end())   
		 	pri.erase(iter_pri);
        ti.erase(iter); 
    }
}
 
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int q;
    cin >> q;
    while(q--)
	{
    	int type;
    	cin >> type;
    	if(type == 1)
		{
    		int p, t;
    		cin >> t >> p;
    		del(t);
    		add(t, p);
    	}
    	else if(type == 2)
		{
    		int t;
    		cin >> t;
    		del(t);
    	}
    	else if(type == 3)
    		cout << *pri.begin() << " " << *pri.rbegin() << "\n";
    	else
    		cout << (--ti.end())->second << "\n";
    }
}

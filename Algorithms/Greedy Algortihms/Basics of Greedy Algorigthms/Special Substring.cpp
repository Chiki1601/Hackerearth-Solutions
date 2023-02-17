#include<bits/stdc++.h>
using namespace std;
string s;

bool cmp(int a, int b) 
{
	if(a == b)
        return false;
	return s[a] < s[b];
}

int main() 
{
	int t = 1;
	while(t--)
	{
        int n, k;
        cin >> n >> k;
        cin >> s;
        vector<int> v, perm;
        for(int i = 0; i < n - 1; i++) 
        {
            if(s[i] == s[i + 1])
                v.push_back(i);
        }
        for(int i = 0; i < n - 1 and (int)v.size() < k - 1; i++) 
        {
            if(s[i] != s[i + 1])
                v.push_back(i);
        }
        perm.resize(k);
        swap(v[rand() % (int)v.size()], v[rand() % (int)v.size()]);
        swap(v[rand() % (int)v.size()], v[rand() % (int)v.size()]);
        while((int)v.size() >= k)
            v.pop_back();
        v.push_back(n - 1);
        sort((v).begin(), (v).end());
        for(int i : v)
            cout << i + 1 << endl;
        sort((v).begin(), (v).end(), cmp);
        map<int, int> mp;
        for(int i : v)
            mp[i] = 1;
        int cnt = 0;
        for(auto&i : mp)
            i.second = ++cnt;
        swap(v[rand() % (int)v.size()], v[rand() % (int)v.size()]);
        swap(v[rand() % (int)v.size()], v[rand() % (int)v.size()]);
        for(int i = 0; i < (int)v.size() / 2; i++) 
            cout << mp[v[i]] << " " << mp[v[(int)v.size() - i - 1]] << " ";
        if((int)v.size() % 2 == 1)
            cout << mp[v[(int)v.size() / 2]] << endl;
    }
}

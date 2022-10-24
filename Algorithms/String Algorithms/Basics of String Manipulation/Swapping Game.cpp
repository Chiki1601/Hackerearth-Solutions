#include<bits/stdc++.h>
using namespace std;
 
string change(string s)
{
    string a = "";
    int start = 0, end = s.size()-1, turn = 0;
    while(start <= end)
	{
        if(!turn)   
			a += s[start], start++, turn^=1;
        else    	
			a += s[end], end--, turn^=1;
    }
    return a;
}
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int k;  
	cin >> k;
    string s;   
	cin >> s;
    set<string>st;
    map<int, string> mp;
    int cur = 0;
    while(true)
	{
        if(st.find(s)!=st.end())    
			break;
        else 
			st.insert(s), mp[cur] = s, cur++, s = change(s);
    }
    k %= mp.size();
    k = mp.size() - k;
    cout << mp[k] << endl;
}

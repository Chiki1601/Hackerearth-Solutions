#include <bits/stdc++.h>
using namespace std;
 
bool fun()
{
    int n;
    long long diff = 0, cur_diff = 0;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++)
    {
        cin >> v[i];
        if(i & 1)     
			diff += v[i];
        else        
			diff -= v[i];
    }
    if(diff & 1)      
		return false;
	diff>>=1;
    unordered_set<long long> s;
    s.insert(0);
    for(int i = 0; i < n; i++)
    {
        if(i & 1)     
			cur_diff += v[i];
        else        
			cur_diff -= v[i];
        if(s.find(cur_diff - diff) != s.end())     
			return true;
        s.insert(cur_diff);
    }
    return false;
}
 
int main()
{  
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); 
    int t = 1;
    cin >> t;
    while(t--)
        cout << (fun() ? "YES\n" : "NO\n");
    return 0;
}

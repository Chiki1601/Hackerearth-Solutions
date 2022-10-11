#include <bits/stdc++.h>
using namespace std;
 
int main() 
{
    int t, n;
    cin >> t;
    while(t--)
    {
		string s, v;
        cin >> n >> s;
		map<char, int> right;
		for(int i = 0; i < n; ++i)
			right[s[i]]++;
		stack<char> u;
        for(int i = 0; i < n; ++i)
        {
			if(--right[s[i]] == 0)
				right.erase(s[i]);
			u.push(s[i]);
			while(!u.empty() && u.top() <= right.begin()->first)
            {
				v += u.top();
				u.pop();
			}
        }
		while(!u.empty())
        {
			v += u.top();
			u.pop();
		}
        cout << v << "\n";
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

int main() 
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    long long i, n;
	cin >> n;
    multiset<long long> s;
    for(i = 0; i < n; i++)
    {
        string s1;
        cin >> s1;
        if(s1 == "Push")
        {
            int x;
            cin >> x;
            s.insert(x);
        }
        else if(!s.size()and s1 != "Push")
        {
            cout << "-1" << "\n";
            continue;
        }
        else
        {
            if(s1 == "CountHigh")
            {
                auto it = s.end();
                it--;
                long long x=*it;
                cout << s.count(x) << "\n";
            }
            if(s1 == "CountLow")
            {
                auto it = s.begin();
                long long x=*it;
                cout << s.count(x) << "\n";
            }
            if(s1 == "Diff" && s.size() > 1)
            {
                auto it = s.end();
                it--;
                long long x=*it;
                s.erase(it);
                it = s.begin();
                long long y=*it;
                s.erase(it);
                cout << x - y << "\n";
            }
            else if(s1 == "Diff" && s.size() == 1)
            {
                cout << "0" << "\n";
                s.erase(s.begin());
            }
        }
    }
}

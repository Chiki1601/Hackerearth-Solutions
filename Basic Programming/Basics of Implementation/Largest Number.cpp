#include <bits/stdc++.h>
using namespace std;

int main()
{
    string str, str2 = "";
    long long k;
    cin >> str >> k;
    stack<long long> s;
    for(int i = 0; i < str.size(); i++) 
	{
        while(!s.empty() && (s.top() < (str[i] - '0')) && k > 0) 
		{
            s.pop();
            k--;
        }
        s.push(str[i] - '0');
    }
    while(k > 0) 
	{
        s.pop();
        k--;
    }
    while(!s.empty()) 
	{
        str2 += s.top() + '0';
        s.pop();
    }
    reverse(str2.begin(), str2.end());
    cout << str2 << endl;
}

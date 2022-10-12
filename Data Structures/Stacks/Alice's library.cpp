#include<bits/stdc++.h>
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    string str;
    stack<int> st;
    cin >> str;
    for(int i = 0; i < str.size(); i++)
    {
        if(str[i] == '/')
          	st.push(i);
        else if(str[i] == '\\')
        {
           reverse(str.begin() + st.top() + 1, str.begin() + i);
           st.pop();
        }
    }
    string str1 = "";
    for(int i = 0; i < str.size(); i++)
		if(str[i] != '/' && str[i] != '\\')
			str1 += str[i];
    cout << str1;
    return 0;
}

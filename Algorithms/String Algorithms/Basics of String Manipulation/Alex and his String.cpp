#include<bits/stdc++.h>
using namespace std;
 
int main()
{
    priority_queue<char, vector<char>, greater<char>> pq;
    string s;
    cin >> s;
    int k;
    cin >> k;
    for (int i = 0; i < k; i++)
        pq.push(s[i]);
    string ans;
    for (int i = k; i < s.size(); i++)
    {
        ans += pq.top();
        pq.pop();
        pq.push(s[i]);
    }
    while(!pq.empty())
    {
        ans += pq.top();
        pq.pop();
    }
    cout << ans << endl;
    return 0;
}

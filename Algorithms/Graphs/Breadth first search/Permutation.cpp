#include<bits/stdc++.h>
using namespace std;
 
int main()
{ 
    int n; 
    cin >> n; 
    string s = "", t = "";
    for(int i = 0; i < n; i++)
    {
        int x; 
        cin >> x;
        s += (x + '0');
    }
    t = s; 
    sort(t.begin(), t.end());
    queue<string>q;
    unordered_map<string, int>visit;
    q.push(s);
    visit[s] = 1;
    while(!q.empty())
    {
        string temp = q.front();
        q.pop();
        if(temp == t)
        {
            cout << visit[temp] - 1 << endl; 
            break;
        }
        for(int i = 2; i <= temp.size(); i++)
        {
            string z = temp;
            reverse(z.begin(), z.begin() + i);
            if(visit[z] == 0)
            {
                q.push(z);
                visit[z] = visit[temp]+1;
            }
        }
    }
}

#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    queue<int>que[5], que1;
    int q, temp, a, b;
    char c;
    cin >> q;
    while(q--)
    {
        cin >> c;
        if(c == 'E')
        {
            cin >> a >> b;
            if(que[a].empty())
                que1.push(a);
            que[a].push(b);
        }
        else
        {
            temp = que1.front();
            cout << temp << " " << que[temp].front() << "\n";
            que[temp].pop();
            if (que[temp].empty())
                que1.pop();
        }
    }
    return 0;
}

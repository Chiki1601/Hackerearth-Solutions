#include<bits/stdc++.h>
using namespace std;

int main()
{ 
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int b, c, m, n, k, l;
    cin >> m >> n;
    priority_queue<pair<int, int>>m1;
    for(int i = 0; i < m; i++)
    {
        cin >> b;
        m1.push({b, -(i + 1)});
    }
    for(int y = 0; y < n; y++)
    {
        pair<int, int>p;
        p = m1.top();
        cout << -p.second << " ";
        k = p.first;
        l = p.second;
        m1.pop();
        m1.push({k - 1, l});
    }
}

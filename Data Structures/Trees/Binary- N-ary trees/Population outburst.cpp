#include <bits/stdc++.h>
using namespace std;  
 
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, c, id;
    pair<pair<int, int>, pair<int, int>> tp;
    deque<pair<pair<int, int>, pair<int, int>>> dq;
    cin >> n >> c;
    dq.push_front({{0, 1}, {0, c}});
    while(n--)
	{
        cin >> id >> c;
        tp = dq.back();
        dq.pop_back();
        if(1 <= c)
            dq.push_front({{id, 1}, {tp.second.first + 1, c}});
        cout << tp.first.first << " " << tp.second.first + 1 << " " << tp.first.second << endl;
        tp.first.second++;
        if(tp.first.second <= tp.second.second)
            dq.push_back(tp);
    }
    return 0;
}

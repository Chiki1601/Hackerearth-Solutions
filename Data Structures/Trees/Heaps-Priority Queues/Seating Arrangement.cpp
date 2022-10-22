#include<bits/stdc++.h>
using namespace std;
map<long long int, long long int> ans;
priority_queue<pair<long long int, pair<long long int, long long int>>> pq;
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    long long int n, k, q;
    string s;
    cin >> n >> k;
    cin >> s;
    s = " " + s;
    pq.push(make_pair(n, make_pair(-1, -n)));
    int cur = 0;
    while(k > 0)
    {
        ++cur;
        pair<long long int, pair<long long int, long long int>> tp = pq.top();
        pq.pop();
        long long int sz = tp.first, l = tp.second.first * (-1LL), r = tp.second.second * (-1LL), mid = 0;
        if(sz % 2)
            mid = (l + r) / 2;
        else
        {
            mid = (l + r) / 2;
            if(s[cur] == 'R')
                 ++mid;
        }
        ans[mid] = cur;
        if(mid > l)
            pq.push(make_pair(mid - l , make_pair(-l , -(mid - 1))));
        if(mid < r)
            pq.push(make_pair(r - mid , make_pair(-(mid + 1) , -r)));
        --k;
    }
    cin >> q;
    while(q--)
    {
        long long int idx;
        cin >> idx;
        if(ans.find(idx) == ans.end())
            cout << -1 << endl;
        else
            cout << ans[idx] << endl;
    }
}

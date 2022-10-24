#include<bits/stdc++.h>
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, tests, d[10000], dist[10000];
    set<pair<int, int> > S;
    set<pair<int, int> >::iterator it;
    cin >> n >> tests;
    for(int i = 0; i < n; i++)
        cin >> d[i];
    sort(d, d + n);
    for(int i = 0; i < d[0]; i++)
        dist[i] = 2001000000;
    dist[0] = 0;
    for (int i = 0; i < d[0]; i++)
        S.insert(make_pair(dist[i], i));
    while(S.size())
    {
        it = S.begin();
        int v = (*it).second;
        S.erase(it);
        if(dist[v] > 1100000000)
            continue;
        for(int i = 0; i < n; i++)
        {
            int new_val = dist[v] + d[i];
            int rem = new_val % d[0];
            if(dist[rem] > new_val)
            {
                S.erase(make_pair(dist[rem], rem));
                dist[rem] = new_val;
                S.insert(make_pair(dist[rem], rem));
            }
        }
    }
    for(; tests; --tests)
    {
        int val;
        cin >> val;
        long long R = val % d[0];
        if(dist[R] <= val)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}

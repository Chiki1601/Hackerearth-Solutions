#include<bits/stdc++.h>
using namespace std;
 
bool intersect(long long x1, long long y1, long long r1, long long x2, long long y2, long long r2)
{
    return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2) <= (r1 + r2) * (r1 + r2);
}
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    long long tc;
    cin >> tc;
    while(tc--)
    {
        long long n, A, B, ans = 1000000005;
        cin >> n;
        vector<long long> v[n];
        pair<pair<long long, long long>, long long> pt[n];
        for(int i = 0; i < n; i++)
        {
            int x, y, r;
            cin >> x >> y >> r;
            pt[i] = {{x, y}, r};
        }
        cin >> A >> B;
        queue<pair<long long, long long>> q;
        long long dis[n];
        for(long long i = 0; i < n; i++)
        {
            dis[i] = 1000000005;
            if(abs(pt[i].first.second - B) <= pt[i].second)
            {
                dis[i] = 1;
                q.push({1 , i});
            }
        }
        while(!q.empty())
        {
            auto p = q.front();
            q.pop();
            long long i = p.second;
            for(long long j = 0; j < n; j++)
            {
                if(intersect(pt[i].first.first, pt[i].first.second, pt[i].second, pt[j].first.first, pt[j].first.second, pt[j].second))
                {
                    if(dis[j]== 1000000005)
                    {
                        dis[j] = dis[i] + 1;
                        q.push({dis[j], j});
                    }
                }
            }
        }
        for(long long i = 0; i < n; i++)
        {
            if(abs(pt[i].first.second - A) <= pt[i].second)
                ans = min(ans, dis[i]);
        }
        cout << (ans == 1000000005 ? -1 : ans) << endl;
    }
}

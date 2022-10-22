#include<bits/stdc++.h>
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t, n, k;
    cin >> t;
    while(t--)
    {
        cin >> n >> k;
        priority_queue<long long> q;
        for(int i = 0; i < n; i++)
        {
            long long temp;
            cin >> temp;
            q.push(temp);
        }
        long long ans = 0;
        while(k--)
        {
            long long int temp = q.top();
            q.pop();
            ans += temp;
            q.push((temp) / 2);
        }
        cout << ans << endl;
    }
}

#include<bits/stdc++.h>
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    long long m, n, count = 0, sum = 0, x;
    cin >> m >> n;
    priority_queue<long long> pq;
    for(long long i = 0; i < m; i++)
    {
        cin >> x;
        pq.push(x);
    }
    while(count < n )
    {
        count++;
        sum += pq.top();
        pq.push(pq.top() - 1);
        pq.pop();
    }
    cout << sum << endl;
    return 0;
}

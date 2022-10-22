#include <bits/stdc++.h>
using namespace std;
priority_queue<int> pqmax;
priority_queue<int, vector<int>, greater<int> > pqmin;
int n, q, k;
long long ans[100005], sum;
 
int main() 
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> q;
    for(int i = 1; i <= n; i++) 
    {
        int num;
        cin >> num;
        sum += num;
        pqmax.push(num);
        pqmin.push(num);
    }
    ans[0] = sum;
    for(int i = 1; i < n; i++) 
    {
        int maxi = pqmax.top(), mini = pqmin.top();
        pqmax.pop();
        pqmax.push(maxi - mini);
        pqmin.pop();
        pqmin.push(maxi - mini);
        ans[i] = ans[i - 1] - 2 * mini;
    }
    while(q--) 
    {
        cin >> k;
        cout << ans[k] << endl;
    }
    return 0;
}

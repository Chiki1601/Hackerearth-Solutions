#include<bits/stdc++.h>
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	long long t;	
    cin >> t;
	while(t--)
  	{
        long long n, sum = 0, ans = 0; 
        cin >> n;
        vector<pair<long long, long long>> arr(n + 1);
        for(long long i = 1; i <= n; i++)
            cin >> arr[i].second;
        for(long long i = 1; i <= n; i++)
        {
            cin >> arr[i].first;
            sum += arr[i].first;
        }
        sort(arr.begin() + 1, arr.end());
        for(long long i = 1; i <= n; i++)
            arr[i].second += arr[i].first;
        priority_queue<long long> q;
        q.push(arr[1].second);
        for(long long i = 1; i <= n; i++)
        {
            ans += q.top(); 
            q.pop();
            if(i + 1 <= n) 
                q.push(arr[i + 1].second);
            if(i + 2 <= n) 
                q.push(arr[i + 2].second);
            i++;
        }
        cout << (ans - sum) << endl;
    }
}

#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t;
    cin >> t;
    while(t--)
    {
		int n , v, prev = -1, maxi = 0 , cnt = 0;
		cin >> n >> v;
		int a[n];
		for(int i = 0 ; i < n ; i++)
			cin >> a[i];
		priority_queue<int>pq;
		for(int i = 0 ; i < n ; i++)
		{
			pq.push(a[i]);
			if(i - prev  == v)
			{
				cnt++;
				prev = i + 1;
				v = pq.top();
				pq.pop();
			}
		}
		cout << cnt << "\n";
	}
}

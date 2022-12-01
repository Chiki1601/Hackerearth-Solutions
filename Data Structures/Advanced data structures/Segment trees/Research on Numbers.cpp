#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    int t, C[10];
	long long arr[1000010];
    cin >> t;
    while(t--)
    {
    	int q, k;
    	cin >> q >> k;
    	vector<int> data;
    	for(int i = 1; i <= k; ++i) 
			cin >> arr[i];
    	for(int i = 1; i <= k; ++i) 
			cin >> C[i];
    	for(int i = k + 1; i <= 1000000; ++i)
    	{
    		arr[i] = 0;
    		for(int j = 1; j <= k; ++j)
    			arr[i] = (arr[i] + arr[i - j] * C[j]) % 1000000007;
    	}
    	vector<vector<int>> info(1000);
    	for(int i = 0; i < 1000; ++i)
    	{
    		int j = i * 1000 + 1;
    		int k = j + 1000, num = 0;
    		priority_queue<int, vector<int>, greater<int>> pq;
    		while(j < k) 
				pq.push(arr[j++]);
    		while(pq.size() && num < 100)
    		{
    			info[i].push_back(pq.top());
    			pq.pop();
    			++num;
    		}
    	}
    	while(q--)
    	{
    		int l, r, num = 0;
    		cin >> l >> r;
    		priority_queue<int, vector<int>, greater<int>> pq;
    		vector<int> ans;
    		for(int i = (l - 1) / 1000 + 1; i < (r - 1) / 1000; ++i)
    		{
    			for(auto e : info[i]) 
					pq.push(e);
    		}
    		for(int i = l; i < (l - 1) / 1000 * 1000 + 1001 && i <= r; ++i)
    			pq.push(arr[i]);
    		if((l - 1) / 1000 != (r - 1) / 1000)
    		{
    			for(int i = (r - 1) / 1000 * 1000 + 1; i <= r; ++i) 
					pq.push(arr[i]);
    		}
    		while(num < 100 && pq.size()) 
			{
				ans.push_back(pq.top());
				pq.pop();
				++num;
			}
    		for(auto it = ans.begin(); it != ans.end(); ++it) 
				cout << *it << " ";
    		puts("");
    	}
    }
    return 0;
}

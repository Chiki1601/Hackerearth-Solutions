#include<bits/stdc++.h>
using namespace std;
 
int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n, m;
		cin >> n >> m;
		int arr[n];
		for(int i = 0; i < n; i++)
			cin >> arr[i];
		queue<pair<int, int>> q;
		for(int i = 0; i < n; i++)
		{
			pair<int,int> p = make_pair(i, arr[i]);
			q.push(p);
		}
		int last = -1;
		while(!q.empty())
		{
			pair<int,int> temp = q.front();
			q.pop();
			last = temp.first;
			if(temp.second - m > 0)
			{
				temp.second -= m;
				q.push(temp);
			}
		}
		cout << last + 1 << endl;
	}
}

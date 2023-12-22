#include <bits/stdc++.h>
using namespace std;
 
bool isValid(const vector<int>& arr, int m, int mid)
{
    int count = 1, curOr = 0;
    for(int elem : arr)
	{
        curOr |= elem;
        if(curOr > mid)
		{
            count++;
            curOr = elem;
        }   
        if(count > m)
            return false;
    }
    return true;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int tt = 1;
    cin >> tt;
    for(int i = 1; i <= tt; i++)
    {
		int n, m;
		cin >> n >> m;
		vector<int> arr(n);
		for(int i = 0; i < n; i++)
			cin >> arr[i];
		int lo = *max_element(arr.begin(), arr.end()), hi = accumulate(arr.begin(), arr.end(), 0);
		while(lo <= hi)
		{
			int mid = (lo + hi) / 2;
			if(isValid(arr, m, mid))
				hi = mid - 1;
			else
				lo = mid + 1;
		}
		cout << lo << "\n";
	}
}

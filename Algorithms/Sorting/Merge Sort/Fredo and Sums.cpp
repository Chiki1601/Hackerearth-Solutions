#include<bits/stdc++.h>
using namespace std;
 
int main()
{
	int t;
    cin >> t;
    while(t--)
	{
    	int n;
    	cin >> n;
    	long arr[n];
    	for(int i = 0; i < n; i++)
            cin >> arr[i];
    sort(arr, arr + n);
    long max_sum = 0, min_sum = 0;
    for(int i = 0; i < n; i += 2)
        min_sum += abs(arr[i] - arr[i + 1]);
    int j = n - 1;
    for(int i = 0; i < n / 2; i++, j--)
        max_sum += abs(arr[i] - arr[j]);
    cout << min_sum << " " << max_sum << endl;
    }
    return 0;
}

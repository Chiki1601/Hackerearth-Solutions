#include<bits/stdc++.h>
using namespace std;
 
void getCount(long long int k, long long int n, vector<long long int> arr)
{
    long long int count = 0, mindist = n;
    for(long long int i = 0; i < n; ++i)
	{
        if(arr[i] == k)
		{
            ++count;
            mindist = min(mindist, n - 1 - i);
        }
        long long int req = k + arr[i];
        auto low = lower_bound(arr.begin(), arr.end(), req);
        auto high = upper_bound(arr.begin(), arr.end(), req);
        if(*low != req)
            continue;
        count += distance(low, high);
        long long int curdist = i + distance(high, arr.end()) + 1;
        mindist = min(mindist, curdist);
    }
    cout << count << " " << mindist << endl;
}
 
int main() 
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	long long int k = 0, n;
    cin >> n >> k;
    vector<long long int> a(n), arr(n);
    cin >> a[0];
    arr[0] = a[0];
    for(long long int i = 1; i < n; ++i)
	{
        cin >> a[i];
        arr[i] = arr[i - 1] + a[i];
    }
    getCount(k, n, arr);
    return 0;
}

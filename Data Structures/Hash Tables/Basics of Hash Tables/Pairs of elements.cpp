#include <bits/stdc++.h>
using namespace std; 
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    long long int n;
    cin >> n;
    long long int arr[n + 1], count = 0;
    map<long long int, long long int> mp;
    for(long long int i = 1; i <= n; i++)
        cin >> arr[i];
    for(long long int i = 1; i <= n; i++)
        mp[arr[i] + (i * i)] ++;
    for(long long int i = 1; i <= n; i++)
        if (mp.find(arr[i] - (i * i)) != mp.end())
            count += mp[arr[i] - (i * i)];
    cout << count << endl;
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t;
    cin >> t;
    while(t--)
	{
        int n, k;
        cin >> n >> k;
        int arr[n], ans = 0;
        for(int i = 0; i < n; i++)
            cin >> arr[i];
        sort(arr, arr + n, greater<int>());
        for(int i = 0; i < k; i++)
            ans += arr[i];
        cout << ans * 2 << "\n";
    }
    return 0;
}

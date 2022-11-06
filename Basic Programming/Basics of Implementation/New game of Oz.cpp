#include<bits/stdc++.h>
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        int arr[n];
        for(int i = 0; i < n; i++)
			cin >> arr[i];
        sort(arr, arr + n);
        int ans = 0;
        for(int i = n - 1; i >= 0; i--)
        {
            ans++;
            if(i - 1 >= 0 && arr[i] - arr[i - 1] == 1)
				i--;
        }
        cout << ans << endl;
    }
}

#include<bits/stdc++.h>
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n;
    cin >> n;
    int arr[2 * n];
    for(int i = 0; i < 2 * n; i++)
        cin >> arr[i];
    sort(arr, arr + 2 * n);
    long ans = 0;
    for(int i = 0; i < 2 * n; i += 2)
        ans += min(arr[i], arr[i + 1]);
    cout << ans << endl;
}

#include <bits/stdc++.h>
using namespace std;
int arr[1000005];
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, k, flag = 0, temp;
    cin >> n >> k;
    for(int i = 0; i < n; i++)
    {
        cin >> temp;
        if((k - temp) > 0 && (k - temp) < 1000005 && arr[k - temp])
        {
            flag = 1;
            break;
        }
        arr[temp]++;
    }
    if(flag) 
        cout << "YES";
    else 
        cout << "NO";
    return 0;
}

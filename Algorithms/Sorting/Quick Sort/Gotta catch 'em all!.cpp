#include<bits/stdc++.h>
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int k; 
    cin >> k;
    int arr[k];
    for(int i = 0; i < k; i++)
        cin >> arr[i];
    sort(arr, arr + k, greater<int>());
    int day = arr[0];
    for(int i = 0; i < k; i++)
        if(day - (i + 1) < arr[i])
            day++;
    cout << day + 1;
}

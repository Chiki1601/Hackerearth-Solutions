#include<bits/stdc++.h>
using namespace std;
long long arr[100005], leftarr[1000005], rightarr[1000005];
vector <long long> quan(1000005, 0);
 
int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    int n, i;
    cin >> n;
    for(i = 1; i <= n; i++)
    {
        cin >> arr[i];
        leftarr[arr[i]]++;
        rightarr[arr[i]]++;
    }
    for(i = 1; i <= 1000002; i++)
        leftarr[i] = leftarr[i - 1] + (i * leftarr[i]);
    for(i = 1000002; i >= 0; i--)
        rightarr[i] += rightarr[i + 1];
    for(i = 1; i <= 1000002; i++)
        quan[i] = leftarr[i - 1] + (rightarr[i] * i);
    int q;
    cin >> q;
    while(q--)
    {
        long long K;
        cin >> K;
        vector <long long> :: iterator it;
        it = lower_bound(quan.begin(), quan.end(), K);
        if(it != quan.end())
        {
            int index = it - quan.begin();
            cout << index << endl;
        }
        else
            cout << -1 << endl;
    }
}

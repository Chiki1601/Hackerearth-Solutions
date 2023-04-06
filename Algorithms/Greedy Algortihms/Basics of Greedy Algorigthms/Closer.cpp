#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, k, low = 0, high = 100000, ans = 0;
    cin >> n >> k;
    vector<int> frequency(100001,0), a(n);
    for(int i = 0; i < n; i++)
	{
        cin >> a[i];
        frequency[a[i]]++;
    }
    while(frequency[low] == 0)
        low++;
    while(frequency[high] == 0)
        high--;
    while(1)
	{
        if((high - low) <= k)
            break;
        int c = min(frequency[low], frequency[high]);
        ans += c;
        frequency[low] -= c;
        frequency[high] -= c;
        frequency[low+1] += c;
        frequency[high-1] += c;
        if(frequency[low] == 0)
            low++; 
        if(frequency[high] == 0)
            high--;
    }
    cout << ans << "\n";
    return 0;
}

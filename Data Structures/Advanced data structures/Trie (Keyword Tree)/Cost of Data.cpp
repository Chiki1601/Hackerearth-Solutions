#include<bits/stdc++.h>
using namespace std;
 
long long foo(string a, string b)
{
    int i;
    for(i = 0; i < b.size(); i++)
        if(i >= a.size() || b[i] != a[i])
            break;
    return (long long)((long long)(a.size()) - i);
}
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, i, j;
    long long ans = 1;
    string ar[100009];
    cin >> n;
    for(i = 0; i < n; i++)
        cin >> ar[i];
    sort(ar, ar + n);
    ans += ar[0].size();
    for(i = 1; i < n; i++)
        ans += foo(ar[i], ar[i - 1]);
    cout << ans << endl;
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    ios::sync_with_stdio(0), cin.tie(0); cout.tie(0);
    int ans[100017], a[100017], n, q;
    multiset<int> anss;
    cin >> n;
    for(int i = 1; i < n; i++)
        ans[i] = i - n;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
        a[i]--;
        if(a[i] < n)
            ans[(a[i] - i + n) % n]++;
    }
    for(int i = 0; i < n; i++)
        anss.insert(ans[i]);
    cin >> q;
    while(q--)
    {
        int i, nw;
        cin >> i >> nw;
        i--, nw--;
        if(a[i] < n)
        {
            anss.erase(anss.find(ans[(a[i] - i + n) % n]--));
            anss.insert(ans[(a[i] - i + n) % n]);
        }
        a[i] = nw;
        if(a[i] < n)
        {
            anss.erase(anss.find(ans[(a[i] - i + n) % n]++));
            anss.insert(ans[(a[i] - i + n) % n]);
        }
        cout << n - *anss.rbegin() << endl;
    }
}

#include <bits/stdc++.h>
using namespace std;

int magicCount(int n, vector<int> &a) 
{
    int g = 0;
    for(int i = 0; i < n; i++) 
        g = __gcd(g, a[i]);
    if(g == 1) 
        return 0;
    if(__gcd(g, __gcd(n, a[n - 1])) == 1) 
        return 1;
    if(__gcd(g, __gcd(n - 1, a[n - 2])) == 1) 
        return 2;
    return 3;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        for(auto &ele : a)
            cin >> ele;
        cout << magicCount(n, a) << "\n";
    }
    return 0;
}

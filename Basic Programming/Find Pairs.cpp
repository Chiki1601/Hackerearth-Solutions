#include <bits/stdc++.h>
using namespace std;

int main() 
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, c = 0;
    cin >> n;
    vector<int> a(n);
    map<int, int> m;
    for(int i = 0; i < n; i++) 
    {
        cin >> a[i];
        m[a[i] - i] += 1;
    }
    for(auto i : m) 
        c += (i.second * (i.second - 1));
    cout << c << endl;
    return 0;  
}

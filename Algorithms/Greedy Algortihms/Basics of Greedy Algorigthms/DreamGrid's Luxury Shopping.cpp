#include <bits/stdc++.h>
using namespace std;

int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    long long int n, m, c = 0, l = 1000000000000000000;
    cin >> n >> m;
    vector<long long int> v(n);
    for(long long int i = 0; i < n; i++) 
        cin >> v[i];
    for(long long int i = 0; i < m; i++) 
        c += v[i];
    for(int i = m; i < n; i++) 
        l = min(l, v[i]);
    l -= 1;
    c += l;
    cout << c << endl;
	return 0;  
}

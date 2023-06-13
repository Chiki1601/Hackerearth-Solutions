#include <bits/stdc++.h>
using namespace std;

int main() 
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int w, n, c = 0;
    cin >> w >> n;
    vector<int> b(n + 1), r(n + 1), d(n + 1), v;
    for(int i = 1; i <= n; i++) 
        cin >> b[i] >> r[i] >> d[i];
    for(int i = 1; i <= n; i++) 
	{
        if(c + r[i] <= w and c + r[i] <= d[i]) 
		{
            v.push_back(i);
            c += r[i];
        }
    }
    cout << v.size() << endl;
    for(auto i : v) 
        cout << i << ' ';
    cout << endl;
	return 0;  
}

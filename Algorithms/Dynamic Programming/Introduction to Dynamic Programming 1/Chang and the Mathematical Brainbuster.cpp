#include<bits/stdc++.h>
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n;
    cin >> n;
    int v[n];
    for(int i = 0; i < n; ++i)
        cin >> v[i];
    sort(v, v + n);
    int i = 0, j = 0, res = 0;
    while(i < n)
    {
        int b = 3 * v[i];
        while(j < n && v[j] <= b)
        	++j;
        res = max(j - i, res);
        ++i;
    }
    cout << n - res << endl;
}

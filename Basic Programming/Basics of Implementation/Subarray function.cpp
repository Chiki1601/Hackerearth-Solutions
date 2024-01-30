#include <bits/stdc++.h>
using namespace std;

int main() 
{
    int n, l, r;
    cin >> n >> l >> r;
    vector<int> v(n), arr(n);
    for(int i = 0; i < n; i++) 
        cin >> v[i];
    for(int i = 0; i < n; i++) 
        arr[i] = i + 1;
    for(int i = 0; i < n; i++) 
        cout << arr[i] << ' ';
    cout << endl;
	return 0;  
}

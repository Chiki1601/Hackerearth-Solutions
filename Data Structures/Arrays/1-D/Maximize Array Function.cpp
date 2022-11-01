#include <bits/stdc++.h> 
using namespace std;
  
int main() 
{
    int n, l, r;
    cin >> n >> l >> r;
    vector<int> a(n);
    for(int i = 0; i < n; i++) 
        cin >> a[i];
    vector<int> v(n);
    for(int i = 0; i < n; i++) 
        v[i] = i + 1;
    for(int i = 0; i < n / 5; i++) 
        swap(v[i], v[rand() % n]);
    for(int i = 0; i < n; i++) 
        cout << v[i] << ' ';
    cout << endl;
    return 0;  
}

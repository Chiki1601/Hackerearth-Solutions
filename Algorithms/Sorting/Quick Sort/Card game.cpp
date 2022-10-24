#include<bits/stdc++.h>
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, m;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++)
        cin >> a[i];
    cin >> m;
    long long int b[m], c = 0, p = 0;
    for(int i = 0; i < m; i++)
    {
        cin >> b[i];
        if(b[i] > c)
            c = b[i];
    }
    c += 1;
    for(int i = 0; i < n; i++)
        if(a[i] < c)
            p += (c - a[i]);
    cout << p << endl;
    return 0;
}

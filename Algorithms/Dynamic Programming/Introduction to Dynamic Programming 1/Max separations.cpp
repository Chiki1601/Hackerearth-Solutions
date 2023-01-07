#include<bits/stdc++.h>
using namespace std;
int a[1000], b[1000], c[1000], cnt;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, m, pt = 0, cost = 0;
    cin >> n >> m;
    for(int i = 1; i <= n; ++i)
        cin >> a[i];
    for(int i = 1; i <= n; ++i)
    {
        if(a[i] % 2 == 1)
            b[i] = 1;
        else 
            b[i] = -1;
    }
    for(int i = 1; i <= n; ++i)
        b[i] = b[i - 1] + b[i];
    for(int i = 1; i < n; ++i)
    {
        if(b[i] == 0)
            c[++cnt] = int(fabs(a[i + 1] - a[i]));
    }
    sort(c + 1, c + cnt + 1);
    while(pt < cnt && cost + c[pt + 1] <= m)
    {
        cost += c[pt + 1];
        ++pt;
    }
    cout << pt << "\n";
    return 0;
}

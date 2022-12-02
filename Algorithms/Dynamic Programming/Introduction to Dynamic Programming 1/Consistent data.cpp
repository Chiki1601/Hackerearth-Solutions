#include <bits/stdc++.h>
using namespace std;
int n, dp[1000050];
 
inline int add(int a, int b) 
{
   return a + b < 1000000007 ? a + b : a + b - 1000000007;
}
 
int main()
{
    cin >> n;
    int a[2], sol = 0;
    a[0] = a[1] = 0;
    for(int i = 0; i < n; i++) 
    {
        dp[i] = add(a[!(i & 1)], 1);
        a[i & 1] = add(a[i & 1], dp[i]);
        sol = add(sol, dp[i]);
    }
    cout << sol << "\n";
    return 0;
}

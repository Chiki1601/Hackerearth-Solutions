#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n, m, kmin, kmax, x;
    cin >> n >> m;
    x = n / m + 1;
    kmin = ((x * (x - 1)) / 2) * (n % m);
    x -= 1;
    kmin += ((x * (x - 1)) / 2) * (m - (n % m));
    x = n - m + 1;
    kmax = (x * (x - 1)) / 2;
    cout << kmin << " " << kmax;
    return 0;
}

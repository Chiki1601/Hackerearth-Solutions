#include <bits/stdc++.h>
using namespace std;

bool isPossible(long long n, long long y, long long r)
{
    long long ans = 0;
    for(long long b = y + 1; b <= n; b++)
        ans += (b - y) * (n / b) + max(0LL, min(b - 1, n % b) - max(1LL, y) + 1);
    return ans >= r;
}

int maximumRemainder(int n, int r)
{
    int ans = -1, left = -1, right = n;
    while(left + 1 < right)
    {
        int mid = (left + right) / 2;
        if(isPossible(n, mid, r))
            left = mid;
        else
            right = mid;
    }
    return left;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t;
    cin >> t;
    while(t--)
    {
        int n, r;
        cin >> n >> r;
        cout << maximumRemainder(n, r) << endl;
    }
}

#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T = 1;
    cin >> T;
    while(T--)
    {
        int N, X, ans = 0, l = 1;
        cin >> N >> X;
        int a[N + 1];
        for(int i = 1; i <= N; i++)
            cin >> a[i];
        int r = N;
        while(l <= N)
        {
            while((l <= r) and (a[r] + a[l] > X))
                r--;
            if(l <= r)
                ans += (r - l + 1);
            l++;
        }
        cout << ans;
        cout << "\n";
    }
}

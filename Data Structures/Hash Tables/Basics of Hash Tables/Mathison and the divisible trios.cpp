#include <bits/stdc++.h>
using namespace std;
 
inline long long n_choose_2(int n)
{
    return n * (n - 1) / 2;
}
 
inline long long n_choose_3(int n)
{
    return n_choose_2(n) * (n - 2) / 3;
}
 
int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  	int n_test, N, M, tmp, trio[3];
    long long ans;
    cin >> N >> M;
    ans = 0;
    int a[M] = {};
    while (N--)
    {
        cin >> tmp;
        a[tmp % M]++;
    }
    for(int i = 0; i <= (int) 2 * M / 3; i++)
    {
        for(int j = i; j <= (int) (2 * M - i) / 2; j++)
        {
            trio[0] = i;
            trio[1] = j;
            trio[2] = (2 * M - j - i) % M;
            if(trio[2] < j) 
				continue;
            if(trio[0] == trio[1] && trio[1] == trio[2])
                ans += n_choose_3(a[j]);
            else if(trio[0] == trio[1])
                ans += n_choose_2(a[j]) * a[trio[2]];
            else if(trio[1] == trio[2])
                ans += n_choose_2(a[j]) * a[trio[0]];
            else
                ans += a[trio[0]] * a[trio[1]] * a[trio[2]];
        }
    }
    cout << ans << endl;
}

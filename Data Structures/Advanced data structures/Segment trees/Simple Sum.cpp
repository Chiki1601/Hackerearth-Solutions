#include <bits/stdc++.h>
using namespace std;
int a[100000], cnt[16][100001];
 
struct MaxInfo
{
    int value, i;
    MaxInfo() {}
    MaxInfo(int value, int i) : value(value), i(i) {}
};MaxInfo st[20][100000];
 
inline bool operator < (const MaxInfo& a, const MaxInfo &b)
{
    return a.value < b.value;
}
 
MaxInfo getMax(int l, int r)
{
    int len = r - l + 1;
    int x = (int)log2(len);
    return max(st[x][l], st[x][r - (1 << x) + 1]);
}
 
long long divideAndConquer(int l, int r)
{
    if(l > r) 
        return 0;
    if(l == r) 
        return (long long) a[l] * a[l];
    int mid = l + r >> 1;
    MaxInfo maxValue = getMax(l, r);
    long long ret = divideAndConquer(l, maxValue.i - 1) + divideAndConquer(maxValue.i + 1, r);
    if(maxValue.i < mid) 
    {
        for(int i = l; i <= maxValue.i; ++ i) 
        {
            for(int bit = 0; bit < 16; ++ bit) 
            {
                if(a[i] >> bit & 1) 
                    ret += (long long)maxValue.value * (r - maxValue.i + 1) * (1LL << bit);
                else 
                    ret += (long long)maxValue.value * (cnt[bit][r + 1] - cnt[bit][maxValue.i]) * (1LL << bit);
            }
        }
    } 
    else 
    {
        for(int j = maxValue.i; j <= r; ++ j) 
        {
            for(int bit = 0; bit < 16; ++ bit) 
            {
                if(a[j] >> bit & 1) 
                    ret += (long long)maxValue.value * (maxValue.i - l + 1) * (1LL << bit);
                else 
                    ret += (long long)maxValue.value * (cnt[bit][maxValue.i + 1] - cnt[bit][l]) * (1LL << bit);
            }
        }
    }
    return ret;
}
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n;
    assert(scanf("%d", &n) == 1 && 1 <= n && n <= 100000);
    for(int i = 0; i < n; ++ i) 
    {
        assert(scanf("%d", &a[i]) == 1);
        assert(1 <= a[i] && a[i] <= 10000);
        st[0][i] = MaxInfo(a[i], i);
        for (int bit = 0; bit < 16; ++ bit) 
            cnt[bit][i + 1] = cnt[bit][i] + (a[i] >> bit & 1);
    }
    for(int i = 0, len = 1; len < n; ++ i, len *= 2) 
    {
        for(int j = 0; j + len * 2 <= n; ++ j) 
            st[i + 1][j] = max(st[i][j], st[i][j + len]);
    }
    cout << divideAndConquer(0, n - 1) << endl;
    return 0;
}

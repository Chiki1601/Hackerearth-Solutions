#include <bits/stdc++.h>
using namespace std;

int count(const vector<int> &v, int x) 
{
    int r = 0;
    for(; x; x -= x & (-x)) 
        r += v[x];
    return r;
}

void update(vector<int> &v, int x, int y) 
{
    for(; x < v.size(); x += x & (-x)) 
        v[x] += y;
}

long long mul(long long x, long long y) 
{
    return x * y;
}

int main() 
{
    int z;
    for(scanf("%d", &z); z; --z) 
	{
        int n;
        cin >> n;
        vector<int> v(n), pre(n + 1), suf(n + 1);
        for(int i = 0; i < n; ++i) 
		{
            cin >> v[i];
            update(suf, v[i], 1);

        }
        long long r = 0;
        for(int i = 0; i < n; ++i) 
		{
            update(suf, v[i], -1);
            r += mul(count(pre, v[i]), count(suf, n) - count(suf, v[i] - 1));
            r += mul(count(suf, v[i]), count(pre, n) - count(pre, v[i] - 1));
            r -= mul(count(suf, v[i]) - count(suf, v[i] - 1), count(pre, v[i]) - count(pre, v[i] - 1));
            update(pre, v[i], 1);
        }
        cout << r << "\n";
    }
    return 0;

}

#include <bits/stdc++.h>
using namespace std;
int n, t, a[40], b[40][10], c[10];
vector<array<int, 10>> trie[21];
array<int, 10> zero;
 
void rec(int s, int e, int k)
{
    if(s == e)
    {
        int cur = 0;
        for(int i = 0; i < 10; i++)
        {
            if(!trie[k][cur][c[i]])
            {
                trie[k][cur][c[i]] = trie[k].size();
                trie[k].push_back(zero);
            }
            cur = trie[k][cur][c[i]];
        }
    }
    else
    {
        rec(s + 1, e, k);
        for(int i = 0; i < 10; i++)
            c[i] = (c[i] + b[s][i]) % 10;
        rec(s + 1, e, k + 1);
        for(int i = 0; i < 10; i++)
            c[i]=(c[i] - b[s][i] + 10) % 10;
    }
}
 
long long rec2(int s, int e, int k)
{
    if(s == e)
    {
        k = t - k;
        if(k < 0 || k > 20)
            return 0;
        long long ret = 0;
        int cur = 0;
        for(int i = 0; i < 10; i++)
        {
            int d=(10 - c[i]) % 10;
            ret *= 10;
            bool ok = false;
            for(int j = 9; j >= 0; j--) 
				if(trie[k][cur][(d + j) % 10])
            	{
                	ret += (d + j + c[i]) % 10;
                	cur = trie[k][cur][(d + j) % 10];
                	ok = true;
                	break;
            	}
            	if(!ok)
                	return 0;
        }
        return ret;
    }
    else
    {
        long long ret = rec2(s + 1, e, k);
        for(int i = 0; i < 10; i++)
            c[i] = (c[i] + b[s][i]) % 10;
        ret = max(ret, rec2(s + 1, e, k + 1));
        for(int i = 0; i < 10; i++)
            c[i]=(c[i] - b[s][i] + 10) % 10;
        return ret;
    }
}
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> t;
    assert(1 <= t && t <= n && n <= 40);
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
        assert(0 <= a[i] && a[i] <= 1000000000);
        for(int j = 0; j < 10; j++)
        {
            b[i][j] = a[i] % 10;
            a[i] /= 10;
        }
        reverse(b[i], b[i] + 10);
    }
    for(int i = 0; i < 21; i++)
        trie[i].push_back(zero);
    int m = n / 2;
    rec(0, m, 0);
    cout << rec2(m, n, 0) << endl;
    return 0;
}

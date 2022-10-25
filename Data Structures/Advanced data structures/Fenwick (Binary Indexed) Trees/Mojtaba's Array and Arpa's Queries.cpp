#include <bits/stdc++.h>
using namespace std;
int n, k, q, fen[500017], sp[19][500017], r[500017], ans[500017];
vector<int> vec[500017];
 
void upd(int p, int x)
{
    for(p++; p < 500017; p += p & -p)
        fen[p] = min(x, fen[p]);
}
 
int get(int p)
{
    int ans = 500017;
    for(p++; p; p ^= p & -p)
        ans = min(ans, fen[p]);
    return ans;
}
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    memset(fen, 63, sizeof fen);
    cin >> n >> k >> q;
    for(int i = 0; i < n; i++)
	{
        cin >> sp[0][i];
        sp[0][i] %= k;
    }
    for(int l = 1; l < 19; l++)
        for(int i = 0; i + (1 << l) <= n; i++)
            sp[l][i] = (long long)sp[l - 1][i] * sp[l - 1][i + (1 << l - 1)] % k;
    for(int i = 0; i < q; i++)
	{
        int l;
        cin >> l >> r[i];
        r[i]--;
        vec[l - 1].push_back(i);
    }
    for(int i = n - 1; i >= 0; i--)
	{
        int j = i, curz = 1; 
        for(int lev = 18; lev >= 0; lev--)
            if(j + (1 << lev) < n && (long long) curz * sp[lev][j] % k)
			{
                curz = (long long)curz * sp[lev][j] % k;
                j += 1 << lev;
            }
        if((long long)curz * sp[0][j] % k == 0)
            upd(j, j - i + 1);
        for(auto qi : vec[i])
            ans[qi] = get(r[qi]);
    }
    for(int i = 0; i < q; i++)
        cout << (ans[i] >= 500017 ? -1 : ans[i]) << ' ';
    cout << endl;
}

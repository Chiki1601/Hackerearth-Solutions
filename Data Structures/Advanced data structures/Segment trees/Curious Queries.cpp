#include <bits/stdc++.h>
using namespace std;
int t, e, n, q, j, h, u;
int a[100001], AIB[11][100001], l[100001], r[100001], ind[100001], sol[100001];

void Add(int x, int quantity)
{
    for(int i = x; i <= 100000; i += ((i ^ (i - 1)) & i))
        AIB[e][i] += quantity;
}

int Compute(int x)
{
    int ret = 0;
    for(int i = x; i > 0; i -= ((i ^ (i - 1)) & i))
        ret += AIB[e][i];
    return ret;
}

bool cmp(int le, int ra)
{
	return l[le] < l[ra];
}

int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> t;
	for(e = 1; e <= t; e++)
	{
		cin >> n >> q;
		for(j = 0; j < n; j++) 
			cin >> a[j]; 
		for(j = 1; j <= q; j++)
		{
			cin >> l[j];
			cin >> r[j];
			ind[j] = j;
		}
        sort(ind + 1, ind + q + 1, cmp);
		l[0] = -1;
		for(j = 1; j <= q; j++)
		{
			h = ind[j];
            if(l[h] > l[ind[j - 1]]) 
			    for(u = l[ind[j - 1]] + 1; u <= l[h]; u++) 
					Add(a[u], a[u]);
			sol[h] = Compute(100000) - Compute(a[r[h]]);
		}
		for(j = 1; j <= q; j++)
		    cout << sol[j] << " ";
		cout << "\n";
	}
}

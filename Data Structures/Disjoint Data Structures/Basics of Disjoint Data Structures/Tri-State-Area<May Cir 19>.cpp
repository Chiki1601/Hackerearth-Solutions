#include<bits/stdc++.h>
using namespace std;
int n, MAXW, tot = 1, V[300005], U[300005], W[300005], P[300005], T[300005];
 
bool CMP(int i, int j) 
{
	return (W[i] < W[j]);
}
 
int Find(int v)
{
    return (P[v] < 0 ? v : (P[v] = Find(P[v])));
}
 
inline int Power(int a, int b)
{
    int ret = 1;
    for (; b; b >>= 1, a = 1LL * a * a % 987654319)
        if (b & 1) ret = 1LL * ret * a % 987654319;
    return (ret);
}
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> MAXW;
    for(int i = 1; i < n; i++)
	{
        cin >> V[i] >> U[i] >> W[i]; 
		T[i] = i;
	}
    memset(P, -1, sizeof(P));
    sort(T + 1, T + n, CMP);
    for (int i = 1; i < n; i++)
    {
        if (W[T[i]] > MAXW)
            tot = 0;
        int v = Find(V[T[i]]), u = Find(U[T[i]]);
        tot = tot * 1LL * Power(MAXW - W[T[i]] + 2, (1LL * P[u] * P[v] - 1) % (987654318)) % 987654319;
        P[v] += P[u]; 
		P[u] = v;
    }
    return !printf("%d\n", tot);
}

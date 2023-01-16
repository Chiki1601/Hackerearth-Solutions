#include <bits/stdc++.h>
using namespace std;
long long int dp[200005], seg[800020];
 
long long int query(int index, int s, int e, int ql, int qr)
{
    if(ql > e || qr < s) 
		return 10000000000000000;
    if(s >= ql && e <= qr) 
		return seg[index];
    int mid = (s + e)>>1;
    long long int l = query(2 * index, s, mid, ql, qr), r = query(2 * index + 1, mid + 1, e, ql, qr);
    return min(l, r);
}
 
void update(int index, int s, int e, int i, long long int val)
{
    if(i < s || i > e) 
		return;
    if(s == e)
	{
        seg[index] = val;
        return ;
    }
    int mid = (s + e)>>1;
    update(2 * index, s, mid, i, val);
    update(2 * index + 1, mid + 1, e, i, val);
    seg[index] = min(seg[2 * index], seg[2 * index + 1]);
}
 
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int t = 1, n;
	cin >> t;
	while(t--)
	{
		cin >> n;
		vector<long long int> A(n - 1), B(n), L(n), R(n);
		for(int i = 0; i < n - 1; i++)
			cin >> A[i];
		for(int i = 0; i < n; i++)
			cin >> B[i];
		for(int i = 0; i < n; i++)
		{	
			cin >> L[i];
			L[i]--;
		}
		for(int i = 0; i < n; i++)
		{	
			cin >> R[i];
			R[i]--;
		}
		for(int i = 0; i <= 4 * n; i++) 
			seg[i] = 0;
		for(int i = 0; i < n; i++) 
			dp[i] = 0;
		dp[0] = 0;
		update(1, 0, n - 1, 0, dp[0] + B[0]);
		for(long long int i = 1; i < n; i++)
		{
			dp[i] = dp[i - 1] + A[i - 1];
			if(L[i] < i)
			{
				if(R[i] == i) 
					R[i]--;
				long long int res = query(1, 0, n - 1, L[i], R[i]);
				dp[i] = min(dp[i], res);
			}
			update(1, 0, n - 1, i, dp[i] + B[i]);
		}
		for(int i = 0; i < n; i++)
			cout << dp[i] << " ";
		cout << "\n";
	}      
	return 0;
}

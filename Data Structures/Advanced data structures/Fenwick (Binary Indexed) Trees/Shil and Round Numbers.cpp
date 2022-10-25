#include <bits/stdc++.h>
using namespace std;
int bt[200011], N;
 
int round(long long x)
{
    if(x < 0) 
		return 0;
    if(x == 0) 
		return 1;
    int p = x % 10, r;
    while(x > 0)
	{
        r = x % 10;
        x /= 10;
    }
    return (p == r);
}
 
void update(int ind,int val)
{
    while(ind <= N)
	{
        bt[ind] += val;
        ind += (ind & -ind);
    }
}
 
int query(int ind)
{
    int ans = 0;
    while(ind > 0)
	{
        ans += bt[ind];
        ind -= (ind & -ind);
    }
    return ans;
}
 
int main()
{ 
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); 
    int Q;
    cin >> N >> Q;
	long long A[200011], t, l, r;
    for(int i = 1; i < N + 1; i++)
	{
        cin >> A[i];
        update(i, round(A[i]));
    }
    while(Q--)
	{
        cin >> t >> l >> r;
        if(t == 2)
		{
            update(l, -round(A[l]));
            A[l] = r;
            update(l, round(A[l]));
        }
        else
            cout << query(r) - query(l - 1) << endl;
    }
}

#include <bits/stdc++.h>
using namespace std;
pair<int,int>a[111111];
long long int BIT[111111];
 
void clea(int n)
{
    for(int i = 1; i <= n; i++)
    	BIT[i] = 0;
}
 
void upd(int idx, int n)
{
    while(idx <= n)
	{
        BIT[idx] += 1;
        idx += (idx) & (-idx);
    }
}
 
long long int query(int l, int r)
{
    long long int ret = 0;
    while(r)
	{
        ret += BIT[r];
        r -= (r) & (-r);
    }
    while(l)
	{
        ret -= BIT[l];
        l -= (l) & (-l);
    }
    return ret;
}
 
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int mov, t, n, i;
    cin >> t;
    while(t--)
	{
        cin >> n;
        for(i = 1; i <= n; i++)
		{
            cin >> a[i].first;
            a[i].second = i;
        }
        sort(a + 1, a + n + 1);
        long long int ans1 = 0, ans2 = 0;
        for(i = 1; i <= n;)
		{
            int val = a[i].first, cnt = 0;
            while(i <= n && a[i].first == val)
			{
                ans1 += query(0, a[i].second) * query(a[i].second - 1, n);
                cnt++;
                i++;
            }
            int idx = i;
            while(cnt--)
			{
                idx--;
                upd(a[idx].second, n);
            }
        }
        clea(n);
        for(i = n; i >= 1; )
		{
            int val = a[i].first, cnt = 0;
            while(i >= 0 && a[i].first == val)
			{
                ans2 += query(0, a[i].second) * query(a[i].second - 1, n);
                cnt++;
                i--;
            }
            int idx = i;
            while(cnt--)
			{
                idx++;
                upd(a[idx].second, n);
            }
        }
        clea(n);
        cin >> mov;
        if(mov)
		{
            if(ans1 > ans2)
            	cout << "Sarika" << endl;
            else
                cout << "Ananya" << endl;
        }
        else
		{
            if(ans1 > ans2)
            	cout << "Ananya" << endl;
            else
            	cout << "Sarika" << endl;
        }
        if(ans1 <= ans2)
        	cout << 2 * ans1 << endl;
        else
        	cout << 2 * ans2 + 1 << endl;
    }
    return 0;
}

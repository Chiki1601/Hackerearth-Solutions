#include<bits/stdc++.h>
using namespace std;
 
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	long long n, a[200005], prfx[200005], sfx[200005], ans;
	cin >> n;
	for(long long i = 0; i < n; i++)
        cin >> a[i];
	sfx[n - 1] = 0;
	stack<long long> stk;
	for(long long i = n - 2; i >= 0; i--)
    {
		sfx[i] = sfx[i + 1];
		long long nxt = a[i + 1], cur = a[i];
		while(nxt < cur)
        {
			long long val = (stk.empty() ? n - 1 : stk.top());
			sfx[i] += (val - i) * 2;
			if(!stk.empty())
                stk.pop();
			nxt *= 4;
		}
		while(nxt >= cur * 4)
        {
            stk.push(i);
            cur *= 4;
        }
	}
	while(!stk.empty())
        stk.pop();
	prfx[0] = 1;
	for(long long i = 1; i < n; i++)
    {
		prfx[i] = prfx[i - 1] + 1;
		long long cur = a[i], prv = a[i - 1];
		while(prv < cur)
        {
			long long val = (stk.empty() ? 0 : stk.top());
			prfx[i] += (i - val) * 2;
			if(!stk.empty())
                stk.pop();
			prv *= 4;
		}
		while(prv >= cur * 4)
        {
            stk.push(i);
            cur *= 4;
        }
	}
	ans = min(prfx[n - 1], sfx[0]);
	for(long long i = 0; i < n; i++)
        ans = min(ans, prfx[i] + sfx[i + 1]);
	cout << ans;
}

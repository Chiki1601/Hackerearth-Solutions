#include<bits/stdc++.h>
using namespace std;
int O[300005], Q[300005], ki[300005], st[300005], ed[300005]; 
long long ans[300005];
 
struct node
{
	int x, y, id;
	bool operator <(const node &A)const
    	{
		if(x != A.x)
            	return x < A.x;
		return y < A.y;
	}	
}s[300005];
 
void Max(long long &a, long long b)
{
	if(a < b)
        	a = b;
}
 
long long reans(int k, int top)
{
	int l = 1, r = top;
	while(l < r)
    	{
		int mid = l + r >> 1;
		if(1ll * k * s[Q[mid]].x + s[Q[mid]].y > 1ll * k * s[Q[mid + 1]].x + s[Q[mid + 1]].y)
            	r = mid;
		else 
            	l = mid + 1;
	}
	if(top)
        	return 1ll * k * s[Q[l]].x + s[Q[l]].y;
	return -3e18;
}
 
void query(int l, int r, int top)
{
	for(int i = l; i <= r; i++)
		if(O[s[i].id] == 3)
			Max(ans[s[i].id], reans(ki[s[i].id], top));
}
 
void CDQ(int l, int r)
{
	if(l == r)
        	return;
	int mid = l + r >> 1, top = 0;
	CDQ(l, mid);
	CDQ(mid + 1, r);
	sort(s + l, s + mid + 1);
	for(int i = l; i <= mid; i++)
    	{
		if(O[s[i].id] != 1 || ed[s[i].id] <= r)
            	continue;
		while(top >= 2 && 1ll * (s[i].y - s[Q[top]].y) * (s[i].x - s[Q[top - 1]].x) >= 1ll * (s[i].x - s[Q[top]].x) * (s[i].y - s[Q[top - 1]].y))
            	top--;
		Q[++top] = i;
	}
	query(mid + 1, r, top);
	sort(s + mid + 1, s + r + 1);
	top = 0;
	for(int i = mid + 1; i <= r; i++)
    	{
		if(O[s[i].id] != 2 || st[s[i].id] >= l)
            	continue;
		while(top >= 2 && 1ll * (s[i].y - s[Q[top]].y) * (s[i].x - s[Q[top - 1]].x) >= 1ll * (s[i].x - s[Q[top]].x) * (s[i].y - s[Q[top - 1]].y))
            	top--;
		Q[++top] = i;
	}
	query(l, mid, top);
}
 
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++)
    	{
		ans[i] = -3e18;
		cin >> O[i];
		s[i].id = i;
		if(O[i] == 1)
        	{
			cin >> s[i].x >> s[i].y;
			ed[i] = n + 1;
		}
		else if(O[i] == 3)
            	cin >> ki[i];
		else 
        	{
			int x;
			cin >> x;
			s[i].x = s[x].x;
			s[i].y = s[x].y;
			ed[x] = i;
			st[i] = x;
		}
	}
	CDQ(1, n);
	for(int i = 1; i <= n; i++)
		if(O[i] == 3)
        	{
			if(ans[i] == -3e18)
                		puts("EMPTY SET");
			else 
                		cout << ans[i] << endl;
		}
	return 0;
}

#include <bits/stdc++.h>
using namespace std;
int n, q, tot, x[300010], p[300010];
vector <pair <int, int>> V[1200040];
pair <int, int> t[300010], z;
 
int gi()
{
	int w = 0, q = 1;  
	char ch = getchar();
	while(((ch < '0') || ('9' < ch)) && (ch != '-'))  
		ch = getchar();
	if(ch == '-')  
	{	
		q = 0; 
		ch = getchar();
	}
	while(('0' <= ch) && (ch <= '9'))  
	{
		w = w * 10 + ch - '0';
		ch = getchar();
	}
	return q ? w : -w;
}
 
void pi(int x)
{
	if(x < 0)  
	{
		putchar('-');
		x = -x;
	}
	if(x > 9)  
		pi(x / 10);
	putchar(x % 10 + '0');
}
 
void merge(int n)
{
	int i = 0, j = 0, k = 0, l = V[(n<<1)].size(), r = V[((n<<1)|1)].size();
	for(; i < l || j < r; )
		{
			if((j == r) || ((i < l) && (V[(n<<1)][i] < V[((n<<1)|1)][j])))  
				z = V[(n<<1)][i++];
			else  
				z = V[((n<<1)|1)][j++];
			while((k)&&(z.second > t[k].second))  
				k--;
			if((!k)||(z.first + z.second > t[k].first + t[k].second))  
				t[++k]=z;
		}
	V[n].assign(t + 1, t + k + 1);	
}
 
int ask(int n, int x)
{
	int i = upper_bound(V[n].begin(), V[n].end(), make_pair(x, 0)) - V[n].begin();
	if(i == 0)  
		return V[n][0].second;
	if(i == V[n].size())  
		return V[n][i - 1].second + V[n][i - 1].first - x;
	return max(V[n][i].second,V[n][i - 1].second + V[n][i - 1].first-x);
}
 
void build(int n, int l, int r)
{
	if(l == r)  
		V[n].push_back(make_pair(l - p[l], x[l] + p[l]));
	else  
		build((n<<1), l, ((l + r)>>1)), build(((n<<1)|1), ((l + r)>>1) + 1, r), merge(n);
}
 
void rebuild(int n, int l, int r, int i)
{
	if(l == r)  
		V[n].assign(1, make_pair(i - p[i], x[i] + p[i]));
	else  (i <= ((l + r)>>1)?rebuild((n<<1), l,((l + r)>>1), i):rebuild(((n<<1)|1), ((l + r)>>1) + 1, r, i)), merge(n);
}
 
int ask(int n, int l, int r, int L, int R)
{
	if((L <= l) && (r <= R))  
		return ask(n, L);
	if(((l + r)>>1) >= R)  
		return ask((n<<1), l, ((l + r)>>1), L, R);
	if(L > ((l + r)>>1))  
		return ask(((n<<1)|1), ((l + r)>>1) + 1, r, L, R);
	return max(ask((n<<1), l,((l + r)>>1), L, R), ask(((n<<1)|1), ((l + r)>>1) + 1, r, L, R));
}
 
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	n = gi(), q = gi();
	for(int i = 1; i <= n; i++)  
		x[i] = gi();
	for(int i = 1; i <= n; i++)  
		p[i] = gi();
	build(1, 1, n);
	for(int i = 1, ty, a, b; i <= q; i++)
	{
		ty = gi(), a = gi(), b = gi();
		if(ty == 1)  
		{	
			x[a] = b;
			rebuild(1, 1, n, a);
		}
		if(ty == 2)  
		{
			p[a] = b;
			rebuild(1, 1, n, a);
		}
		if(ty == 3)  
		{ 
			pi(ask(1, 1, n, a, b));
			puts("");
		}
	}
	return 0;
}

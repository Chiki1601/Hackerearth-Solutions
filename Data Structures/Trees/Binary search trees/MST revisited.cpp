#include<bits/stdc++.h>
using namespace std;
int n, q, ch[2333333][2], fa[2333333], vv[2333333], mx[2333333], ss_[2333333], *ss = ss_, a[2333333], b[2333333], *c = vv, cyc = 0;
bool rev[2333333];
#define top_(x) (!(ch[fa[x]][0] == x || ch[fa[x]][1] == x))
 
void pd(int x)
{
    if(!rev[x]) 
		return;
    rev[x] = 0;
    rev[ch[x][0]] ^= 1;
    rev[ch[x][1]] ^= 1;
    swap(ch[x][0], ch[x][1]);
}
 
void rot(int x)
{
    if(top_(x)) 
		return;
    int y = fa[x], c = ch[y][0] == x, f = fa[y];
    if(!top_(y)) 
		ch[f][ch[f][1] == y] = x;
    if(ch[x][c]) 
		fa[ch[x][c]] = y;
    ch[y][!c] = ch[x][c];
    ch[x][c] = y; 
	fa[x] = f; 
	fa[y] = x;
    mx[y] = max(vv[y], max(mx[ch[y][0]], mx[ch[y][1]])); 
	mx[x] = max(vv[x], max(mx[ch[x][0]], mx[ch[x][1]]));
}
 
void splay(int x)
{
    for(int c = x; ;c = fa[c])
    {
    	*(++ss) = c;
        if(top_(c)) 
			break;
    }
    while(ss != ss_) 
		pd(*(ss--));
    while(!top_(x))
    {
        int y = fa[x];
        if(!top_(y))
        {
            if(ch[fa[y]][0] == y ^ ch[y][0] == x) 
				rot(x);
            else 
				rot(y);
        }
        rot(x);
    }
}
 
void access(int x)
{
    for(int c = 0; x; c = x, x = fa[x]) 
	{
		splay(x); 
		ch[x][1] = c; 
		mx[x] = max(vv[x], max(mx[ch[x][0]], mx[ch[x][1]]));
	}
}
 
void makeroot(int x) 
{
	access(x); 
	splay(x); 
	rev[x] ^= 1;
}
 
void link(int a, int b) 
{
	makeroot(a); 
	fa[a] = b;
}
 
void cut(int a, int b) 
{
	makeroot(a); 
	access(b); 
	splay(b); 
	ch[b][0] = fa[a] = 0;
}
 
int findroot(int x)
{
    access(x); 
	splay(x);
    int lc = x;
    while(ch[lc][0]) 
		lc = ch[lc][0];
    splay(lc); 
	return lc;
}
 
int getrd(int a, int b)
{
	makeroot(a); 
	access(b); 
	splay(b); 
	return b;
}
 
bool st(int a, int b)
{
	makeroot(a);
	return findroot(b) == a;
}
 
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	long long sum = 0;
	unordered_map<long long, int> ide;
	cin >> n >> q;
	for(int i = 1 + n; i <= n + n; ++i)
	{
		cin >> a[i] >> b[i] >> c[i];
		ide[min(a[i], b[i]) * (long long)n + max(a[i], b[i])] = i;
		sum += c[i];
		if(st(a[i], b[i]))
		{
			cyc = i;
			continue;
		}
		link(a[i], i); 
		link(b[i], i);
	}
	int ans = 0, an = n + n;
	while(q--)
	{
		int a, b, c, d, e;
		cin >> a >> b >> c >> d >> e;
		a += ans; b += ans; c += ans; d += ans; e += ans;
		int g = ide[min(a, b) * (long long)n + max(a, b)];
		if(g == cyc) 
			cyc = 0;
		else
		{
			cut(a, g); 
			cut(g, b);
			if(!st(::a[cyc], ::b[cyc]))
			{
				link(::a[cyc], cyc); 
				link(::b[cyc], cyc); 
				cyc = 0;
			}
		}
		sum -= ::c[g] - e;
		++an; 
		::a[an] = c; ::b[an] = d; ::c[an] = e;
		ide[min(c, d) * (long long)(n) + max(c, d)] = an;
		if(st(c, d)) 
			cyc = an;
		else 
			link(c, an), link(d, an);
		long long ca = sum;
		int s = max(::c[cyc], mx[getrd(::a[cyc], ::b[cyc])]);
		ca -= s; ans =ca % 100; 
		cout << ca << "\n";
	}
}

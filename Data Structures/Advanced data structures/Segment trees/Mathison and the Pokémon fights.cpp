#include <bits/stdc++.h> 
using namespace std;  
int n, m, a[100005], b[100005], oa[100005], ob[100005];
 
struct Identifier
{
	vector<int> v;
	void add(int val)
    {
		v.push_back(val);
	}
	void build()
    {
		sort(v.begin(), v.end());
		v.resize(unique(v.begin(), v.end()) - v.begin());
	}
	int index(int x)
	{
		return lower_bound(v.begin(), v.end(), x) - v.begin();
	}
}idx[(100005 + 2000 - 1) / 2000], idy[(100005 + 2000 - 1) / 2000];
 
struct query
{
	bool type;
	int p, i, j, x, y;
	void set0(int p, int x, int y)
	{
		type = false;
		this->p = p;
		this->x = x;
		this->y = y;
	}
	void set1(int i, int j, int x, int y)
	{
		type = true;
		this->i = i;
		this->j = j;
		this->x = x;
		this->y = y;
	}
}q[200005];
 
struct tree
{
	long long int t_sum, r_sum = 0;
	int n, r_cnt;
	vector<int> cnt;
	vector<long long int> sum;
	void init(int n)
	{
		this->n = n;
		t_sum = r_cnt = r_sum = 0;
		cnt.resize(n + 1, 0);
		sum.resize(n + 1, 0);
	}
	void add(int ind, int val)
	{
		t_sum += val;
		for(++ind; ind <= n; ind += (ind & -ind))
		{
			cnt[ind]++;
			sum[ind] += val;
		}
	}
	void rem(int ind, int val)
	{
		t_sum -= val;
		for(++ind; ind <= n; ind += (ind & -ind))
		{
			cnt[ind]--;
			sum[ind] -= val;
		}
	}
	void query(int i)
	{
		r_cnt = 0;
		r_sum = 0;
		for(; i >= 1; i -= i & -i)
		{
			r_cnt += cnt[i];
			r_sum += sum[i];
		}
	}
}tx[(100005 + 2000 - 1) / 2000], ty[(100005 + 2000 - 1) / 2000];
 
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	for(int i = 0; i < n; i++)
	{
		int x, y;
		cin >> x >> y;
		int j = i / 2000;
		idx[j].add(a[i] = x + y);
		idy[j].add(b[i] = x - y);
	}
	for(int i = 0; i < m; i++)
	{
		int type;
		cin >> type;
		if(type == 0)
        {
			int p, x, y;
			cin >> p >> x >> y;
			p--;
			q[i].set0(p, x + y, x - y);
			int j = p / 2000;
			idx[j].add(x + y);
			idy[j].add(x - y);
		}
		else
		{
			int l, r, x, y;
			cin >> l >> r >> x >> y;
			l--;
			r--;
			q[i].set1(l, r, x + y, x - y);
		}
	}
	for(int i = 0; i < (100005 + 2000 - 1) / 2000; i++)
	{
		idx[i].build();
		idy[i].build();
		tx[i].init(idx[i].v.size());
		ty[i].init(idy[i].v.size());
	}
	for(int i = 0; i < n; i++)
	{
		int j = i / 2000;
		tx[j].add(oa[i] = idx[j].index(a[i]), a[i]);
		ty[j].add(ob[i] = idy[j].index(b[i]), b[i]);
	}
	for(int i = 0; i < m; i++)
	{
		if(q[i].type == 0)
		{
			int p = q[i].p;
			int j = p / 2000;
			tx[j].rem(oa[p], a[p]);
			ty[j].rem(ob[p], b[p]);
			a[p] = q[i].x;
			b[p] = q[i].y;
			oa[p] = idx[j].index(a[p]);
			ob[p] = idy[j].index(b[p]);
			tx[j].add(oa[p], a[p]);
			ty[j].add(ob[p], b[p]);
		}
		else
		{
			int l = q[i].i, r = q[i].j;
			long long int x = q[i].x, y = q[i].y, sum = 0;
			if(l / 2000 == r / 2000)
            {
				for(int j = l; j <= r; j++)
					sum += abs(x - a[j]) + abs(y - b[j]);
				cout << (sum>>1) << "\n";
			}
			else
            {
				int bl = (l + 2000 - 1) / 2000, br = (r + 1) / 2000;
				for(int j = l; j < bl * 2000; j++)
					sum += abs(x - a[j]) + abs(y - b[j]);
				for(int j = br * 2000; j <= r; j++)
					sum += abs(x - a[j]) + abs(y - b[j]);
				for(int j = bl; j < br; j++)
                {
					tx[j].query(idx[j].index(x));
					sum += tx[j].r_cnt * x - (tx[j].r_sum<<1) + tx[j].t_sum - (2000 - tx[j].r_cnt) * x;
					ty[j].query(idy[j].index(y));
					sum += ty[j].r_cnt * y - (ty[j].r_sum<<1) + ty[j].t_sum - (2000 - ty[j].r_cnt) * y;
				}
				cout << (sum>>1) << "\n";
			}
		}
	}
	return 0;
}

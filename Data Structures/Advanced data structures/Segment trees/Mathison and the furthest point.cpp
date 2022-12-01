#include <bits/stdc++.h>
using namespace std;
int n, a[1300031], b[1300031], c[1300031], d[1300031], e[1300031], f[1300031], max_sum_bucket[1300031], min_sum_bucket[1300031], max_dif_bucket[1300031], min_dif_bucket[1300031], where_is[1300031], tp[1300031], min_x[1300031], max_x[1300031], min_y[1300031], max_y[1300031];
vector<pair<int, pair<int, int>>> P_list;
vector<pair<int, int>> bucket;
vector<vector<pair<int, int>>> buckets;
vector<vector<int>> small_buckets;
 
bool dont_intersect_1d(int l1, int r1, int l2, int r2)
{
	return (max(l1, l2) > min(r1, r2));
}
 
bool completely_inside_1d(int l1, int r1, int l2, int r2)
{
	return l1 >= l2 && r1 <= r2;
}
 
bool dont_intersect(int qu, int bucket)
{
	return dont_intersect_1d(min_x[bucket], max_x[bucket], c[qu], e[qu])|| dont_intersect_1d(min_y[bucket], max_y[bucket], d[qu], f[qu]);
}
 
bool completely_inside(int qu,int bucket)
{
	return completely_inside_1d(min_x[bucket], max_x[bucket], c[qu], e[qu])&& 		completely_inside_1d(min_y[bucket], max_y[bucket], d[qu], f[qu]);
}
 
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
 		cin >> tp[i] >> a[i] >> b[i];
		if(tp[i] == 1)
			cin >> c[i] >> d[i] >> e[i] >> f[i];
		if(tp[i] == 0)
			P_list.push_back(make_pair(b[i], make_pair(a[i], i)));
	}
	sort(P_list.begin(), P_list.end());
	int per_bucket = P_list.size() / 50;
	for(int i = 0; i < P_list.size(); i++)
	{
		if(bucket.size() == per_bucket)
		{
			buckets.push_back(bucket);
			bucket.clear();
		}
		bucket.push_back(make_pair(P_list[i].second.first, P_list[i].second.second));
	}
	buckets.push_back(bucket);
	for(int i = 0; i < buckets.size(); i++)
	{
		sort(buckets[i].begin(), buckets[i].end());
		int per_small = 50;
		vector<int> bucket;
		for(int j = 0; j < buckets[i].size(); j++)
		{
			if(bucket.size() == per_small)
			{
				small_buckets.push_back(bucket);
				bucket.clear();
			}
			bucket.push_back(buckets[i][j].second);
		}
		small_buckets.push_back(bucket);
	}
	for(int i = 0; i < small_buckets.size(); i++)
	{
		min_x[i] = min_y[i] = min_sum_bucket[i] = min_dif_bucket[i] = 1000000000;
		max_x[i] = max_y[i] = max_sum_bucket[i] = max_dif_bucket[i] = -1e9;
		for(int j = 0; j < small_buckets[i].size(); j++)
		{
			int id = small_buckets[i][j];
			where_is[id] = i;
		}
	}
	for(int i = 1; i <= n; i++)
	{
		if(tp[i] == 0)
		{
			int ps = where_is[i];
			max_sum_bucket[ps] = max(max_sum_bucket[ps], a[i] + b[i]);
			min_sum_bucket[ps] = min(min_sum_bucket[ps], a[i] + b[i]);
			max_dif_bucket[ps] = max(max_dif_bucket[ps], a[i] - b[i]);
			min_dif_bucket[ps] = min(min_dif_bucket[ps], a[i] - b[i]);
			min_x[ps] = min(min_x[ps], a[i]);
			max_x[ps] = max(max_x[ps], a[i]);
			min_y[ps] = min(min_y[ps], b[i]);
			max_y[ps] = max(max_y[ps], b[i]);
			continue;
		}
		if(tp[i] == 1)
		{
			int ans = -1;
			for(int j = 0; j < small_buckets.size(); j++)
			{
				if(dont_intersect(i, j))
					continue;
				if(completely_inside(i, j))
				{
					ans = max(ans, max_sum_bucket[j] - (a[i] + b[i]));
					ans = max(ans, (a[i] + b[i]) - min_sum_bucket[j]);
					ans = max(ans, max_dif_bucket[j] - (a[i] - b[i]));
					ans = max(ans, (a[i] - b[i]) - min_dif_bucket[j]);
					continue;
				}
				if(max_sum_bucket[j] < a[i] + b[i] + ans && min_sum_bucket[j] > a[i] + b[i] - ans && max_dif_bucket[j] < a[i] - b[i] + ans && min_dif_bucket[j] > a[i] + b[i] - ans)
					continue;
				for(int q = 0; q < small_buckets[j].size(); q++)
				{
					int id = small_buckets[j][q];
					if(id > i || a[id] < c[i] || a[id] > e[i] || b[id] < d[i] || b[id] > f[i])
						continue;
					ans = max(ans, abs(a[id] - a[i]) + abs(b[id] - b[i]));
				}
			}
			if(ans < 0)
				cout << "no point!" << "\n";
			else
				cout << ans << "\n";
		}
	}
	return 0;
}

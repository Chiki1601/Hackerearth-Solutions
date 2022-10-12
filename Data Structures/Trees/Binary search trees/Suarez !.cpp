#include <bits/stdc++.h>
using namespace std;
unordered_map <int, int> M;
vector <int> que[200005];
vector <pair<int, pair<int, int>>> intervals;
int l[200005], r[200005], k[200005], x[200005], lo[200005], hi[200005], mid[200005], BIT[600015];
 
void BIT_upd(int pos, int val)
{
    while(pos < 600015)
    {
        BIT[pos] += val;
        pos += (pos & (-pos));
    }
}
 
int BIT_get(int pos)
{
    int ret = 0;
    while(pos > 0)
    {
        ret += BIT[pos];
        pos -= (pos & (-pos));
    }
    return ret;
}
 
int main()
{
    int n;
    cin >> n;
    vector <int> nums;
    for(int i = 0; i < n; ++i)
    {
        cin >> l[i] >> r[i];
        nums.push_back(l[i]);
        nums.push_back(r[i]);
    }
    int q;
    cin >> q;
    for(int i = 0; i < q; ++i)
    {
        cin >> k[i] >> x[i];
        nums.push_back(x[i]);
    }
    sort(nums.begin(), nums.end());
    nums.resize(unique(nums.begin(), nums.end()) - nums.begin());
    for(int i = 0; i < nums.size(); ++i)
        M[nums[i]] = i + 1;
    for(int i = 0; i < n; ++i)
        intervals.push_back(pair<int, pair<int, int>> (r[i] + 1 - l[i], pair<int, int>(M[l[i]], M[r[i]])));
    sort(intervals.begin(), intervals.end());
    for(int i = 0; i < q; ++i)
    {
        lo[i] = 0;
        hi[i] = n;
        mid[i] = (lo[i] + hi[i])/2;
        que[mid[i]].push_back(i);
    }
    bool changed = true;
    while(changed)
    {
        changed = false;
        memset(BIT, 0, sizeof BIT);
        for (int i = 0; i < n; ++i)
        {
            int l = intervals[i].second.first, r = intervals[i].second.second;
            BIT_upd(l, 1);
            BIT_upd(r + 1, -1);
            while(!que[i].empty())
            {
                int qnum = que[i].back();
                que[i].pop_back();
                int pos = M[x[qnum]];
                if(BIT_get(pos) >= k[qnum])
                    hi[qnum] = mid[qnum];
                else
                    lo[qnum] = mid[qnum] + 1;
                if(lo[qnum] < hi[qnum])
                {
                    changed = true;
                    mid[qnum] = (lo[qnum] + hi[qnum]) / 2;
                    que[mid[qnum]].push_back(qnum);
                }
            }
        }
    }
    for(int i = 0; i < q; ++i)
    {
        if(lo[i] >= n)
            cout << -1 << endl;
        else
            cout << intervals[lo[i]].first << endl;
    }
    return 0;
}

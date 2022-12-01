#include <bits/stdc++.h>
using namespace std;
long long segtree[800000];
 
void update(int idx, long long val, int l, int r, int pos)
{
    if(l > idx or r < idx) 
		return ;
    if(l == r)
    {
        if(val > segtree[pos])
            segtree[pos] = val;
        return;
    }
    int mid = (l + r) >> 1;
    update(idx, val, l, mid, 2 * pos);
    update(idx, val, mid + 1, r, 2 * pos + 1);
    segtree[pos] = max(segtree[2 * pos], segtree[2 * pos + 1]);
}
 
long long query(int lQ, int rQ, int l, int r, int pos)
{
    if(l > rQ or r < lQ or l > r) 
		return 0;
    else if(l >= lQ && r <= rQ) 
		return segtree[pos];
    int mid = (l + r) >> 1;
    return max(query(lQ, rQ, l, mid, 2 * pos) , query(lQ, rQ, mid + 1, r, 2 * pos + 1));
}
 
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, H[200000];
    cin >> n;
    vector<pair<long long, int>> arr(n);
    long long ans = 0, L[200000];
    for(int i = 1; i <= n; i++)
    {
        cin >> H[i] >> L[i];
        arr[i-1].first = L[i];
        arr[i-1].second = i;
    }
    sort(arr.begin(), arr.end());
    for(int i = 0; i < arr.size(); i++)
    {
        int idx = arr[i].second;
        long long val = query(1, idx - 1, 1, n, 1);
        val += H[idx];
        val = max(val , 0LL);
        ans = max(ans , val);
        update(idx , val , 1 , n , 1);
    }
    cout << ans << endl;
    return 0;
}

#include<bits/stdc++.h>
using namespace std; 
 
long long ok(long long r, vector<pair<long long, long long>>& coord,vector<long long>& arr)
{
    long long sum = 0;
    for(long long i = 0; i < coord.size(); i++)
	  {
        pair<long long, long long> c = coord[i];
        long long curr = c.first * c.first;
        curr += c.second * c.second;
        curr -= r * r;
        if(curr <= 0LL)
            sum += arr[i];
    }
    return sum;
}
 
void Saraff()
{
    long long N, P;
    cin >> N >> P;
    vector<long long> arr(N);
    vector<pair<long long, long long>> coord(N);
    for(long long i = 0; i < N; i++)
        cin >> coord[i].first;
    for(long long i = 0; i < N; i++)
        cin >> coord[i].second;
    for(long long i = 0; i < N; i++)
        cin >> arr[i];
    long long l = 0,r = 1e9, ans = 9223372036854775807LL, mid;
    while(l <= r)
	  {
        mid = (l + r) / 2;
        if(ok(mid, coord, arr) >= P)
		    {
            ans = mid;
            r = mid - 1;
        }
        else
            l = mid + 1;
    }
    if(ans == 9223372036854775807LL)
        ans = -1;
    cout << ans << endl;
}
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    long long test = 1;
    cin >> test;
    for(long long t = 1; t <= test; t++)
        Saraff();
}

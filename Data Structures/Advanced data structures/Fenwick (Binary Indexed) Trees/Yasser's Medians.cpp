#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>
using namespace __gnu_pbds;
using namespace std;
 
long long po(long long a, long long b)
{
	long long r = 1;
	while(b)
    {
		if(b & 1)
        {
			r *= a;
			r %= 1000000007;
		}
		a *= a;
		a %= 1000000007;
		b = b>>1;
	}
	return r;
}
 
typedef tree<pair<long long, long long>, null_type, less<pair<long long, long long>>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
 
int main() 
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	long long t;	
	t = 1;
	while(t--)
	{
        long long n, k, start = 0, end = 0, mx = 0;
        cin >> n>> k;
        vector<long long> a(n);
        for(int i = 0; i < a.size(); i++)
		    cin >> a[i];
        ordered_set s;
        while(end < k)
        {
            s.insert({a[end], end});
            end++;
        }
        end--;
        k = (k-1)/2;
        while(true)
        {
            pair<long long, long long> t = *s.find_by_order(k);
            long long cur = t.first;
            mx = max(mx, cur);
            if(end == n - 1)
                break;
            s.erase(s.find({a[start], start}));
            start++;
            end++;
            s.insert({a[end], end});
        }	
        cout << po(n, mx) << endl;
    }	
	return 0;
}

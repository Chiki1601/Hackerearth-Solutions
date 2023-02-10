#include <bits/stdc++.h> 
using namespace std;
long long int a[40];
 
long long int count_subsets_lt(long long int n, long long int k, long long int s, int i)
{
    if(i >= n) 
        return 0;
    long long int count = 0;
    if(s + a [i] < k)
        count += 1 + count_subsets_lt (n, k, s + a[i], i + 1);
    if(s < k)
        count += count_subsets_lt (n, k, s, i + 1);
    return count;
}
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    long long int n, k, i, j, ans = 0, total_subsets, count;
    cin >> n;
    for(i = 0; i < n; i++) 
        cin >> a[i];
    sort(a, a + n);
    cin >> k;
    total_subsets = pow(2, n) - 1;
    if(*min_element (a, a + n) >= k)
    {
        cout << total_subsets << endl; 
        return 0;
    }
    count = count_subsets_lt (n, k, 0, 0);
    cout << total_subsets - count << endl;
    return 0;
}

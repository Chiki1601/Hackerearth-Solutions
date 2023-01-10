#include <bits/stdc++.h>
using namespace std;
 
int merge(vector<int>& a, int l, int mid, int r) 
{
    vector<int> temp;
    int i = l, j = mid + 1, inv = 0;
    while(i <= mid && j <= r) 
    {
        if(a[i] <= a[j]) 
            temp.push_back(a[i++]);
        else 
        {
            inv += (mid - i + 1);
            temp.push_back(a[j++]);
        }
    }
    while(i <= mid)
        temp.push_back(a[i++]);
    while(j <= r)
        temp.push_back(a[j++]);
    int c = 0;
    for(int ind = l; ind <= r; ind++)
        a[ind] = temp[c++];
    return inv;
}
 
int merge_sort(vector<int>& a, int l, int r) 
{
    int inv = 0;
    if(l < r) 
    {
        int mid = (l + r) / 2;
        inv += merge_sort(a, l, mid);
        inv += merge_sort(a, mid + 1, r);
        inv += merge(a, l, mid, r);
    }
    return inv;
}
 
int main() 
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t = 1;
    for(int tc = 1; tc <= t; tc++) 
    {
        int n;
        cin >> n;
        vector<int> v(n), pos(n);
        for(int i = 0; i < n; i++)
            cin >> v[i];
        for(int i = 0; i < n; i++)
            cin >> pos[i];
        vector<int> a(n);
        for(int i = 0; i < n; i++)
            a[pos[i] - 1] = v[i];
        cout << merge_sort(a, 0, n - 1);
    } 
    return 0;
}

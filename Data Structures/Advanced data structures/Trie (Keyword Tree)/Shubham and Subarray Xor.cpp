#include <bits/stdc++.h>
using namespace std;
int sz = 0, _nxt[2][10000005];
bool created[10000005];
 
void insert(int s) 
{
    int v = 0;
    for(int i = 30; i >= 0; i--) 
	{
        int c = (s >> i) & 1;
        if(!created[_nxt[c][v]]) 
		{
            _nxt[c][v] = ++sz;
            created[sz] = true;
        }
        v = _nxt[c][v];
    }
}
 
int search(int tmp) 
{
    int v = 0, ans = 0;
    for(int i = 30; i >= 0; i--) 
	{
        int c = (tmp >> i) & 1;
        if(created[_nxt[1 ^ c][v]])
		{
            ans |= ((1 ^ c) << i);
            v = _nxt[1 ^ c][v];
        }
        else
		{
            ans |= (c << i);
            v = _nxt[c][v];
        }
    }
    return ans;
}
 
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int i, j, n, maxi = 0, arr[905], sum[905];
    cin >> n;
    for(i = 1; i <= n; i++)
	{
        cin >> arr[i];
        sum[i] = sum[i - 1] + arr[i];
    }
    for(i = 1; i <= n; i++)
	{
        for(j = 1; j <= i; j++)
            insert(sum[i] - sum[j - 1]);
        for(j = i + 1; j <= n; j++)
            maxi = max(maxi, (sum[j] - sum[i]) ^ search(sum[j] - sum[i]));
    }
    cout << maxi << endl;
    return 0;
}

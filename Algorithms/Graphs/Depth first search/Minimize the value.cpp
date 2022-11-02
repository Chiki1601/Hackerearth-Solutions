#include<bits/stdc++.h>
using namespace std;
int c = 0, n, min_c = 1e9;
long long int sum = 0;
 
void dfs(int i, int p, vector<int> ad[], int val[])
{
    c++;
    sum += (long long int)c*val[i];
    if(i == 1)
    {
        if(ad[i].size() < 2)
            min_c = min(min_c, c + 1);
    }
    else
    {
        if(ad[i].size() < 3)
            min_c = min(min_c, c + 1);
    }
    for(int it:ad[i])
        if(it != p)
            dfs(it,i,ad,val);
    c--;
}
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    int val[n + 2];
    cin >> val[n + 1];
    for(int i = 1; i <= n; i++)
        cin >> val[i];
    vector<int> ad[n + 1];
    for(int i = 1, a, b; i < n; i++)
    {
        cin >> a >> b;
        ad[a].push_back(b);
        ad[b].push_back(a);
    }
    dfs(1, 0, ad, val);
    sum += (long long int)min_c*val[n + 1];
    cout << sum << endl;
    return 0;
}

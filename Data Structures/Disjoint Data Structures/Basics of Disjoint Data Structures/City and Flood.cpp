#include<bits/stdc++.h>
using namespace std;
vector<int> par(100001, -1);
 
int find(int a) 
{
    if(par[a] == -1) 
		return a;
    return par[a] = find(par[a]);
}
 
void merge(int a, int b) 
{
    par[b] = a;
}
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, k, a, b; 
	cin >> n >> k;
    int cnt = n;
    while(k--) 
	{
        cin >> a >> b;
        a = find(a);
        b = find(b);
        if(a != b) 
		{
            merge(a, b);
            cnt--;
        }
    }
    cout << cnt << endl;
    return 0;
}

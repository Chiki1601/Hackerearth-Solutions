#include<bits/stdc++.h>
using namespace std;
int BIT[200002], n;
 
void update(int pos)
{
	for(int i = pos; i < 200002; i += (i & (-i)))
		BIT[i]++;
}
 
int query(int pos)
{
	int sum = 0;
	for(int i = pos; i >= 1; i -= (i & (-i)))
		sum += BIT[i];
	return sum;
}
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    string str;
    cin >> str;
    int arr[n], sum = 0, c, ans = 0;
    for(long long i = 0; i <= n - 1; i++)
    {
  	    if(str[i] == 'a')
  		    arr[i] = 1;
  	    if(str[i] == 'b')
  		    arr[i] = 0;
  	    if(str[i] == 'c')
  		    arr[i] = -1;
    }
    for(int i = 0; i < n; i++)
    {
  	    sum += arr[i];
  	    arr[i] = sum + 100001;
    }
    for(int i = 0; i < n; i++)
    {
  	    c = query(arr[i] - 1);
  	    if(arr[i] > 100001)
  		    c++;
  	    ans = ((ans % 1000000007) + (c % 1000000007)) % 1000000007;
  	    update(arr[i]);
    }
    cout << ans << endl;
    return 0;
}

#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t;
    cin >> t;
    while(t--)
	{
        int n;
        cin >> n;
        int a[n] , b[n];
        for(int i = 0 ; i < n ; i++)
        	cin >> a[i];
        for(int i = 0 ; i < n ; i++)
        	cin >> b[i];
        int l = 0 , r = n - 1;
        while(l <= r && a[l] == b[l])
        	l++;
        while(r >= l && a[r] == b[r])
        	r--;
        cout << r - l + 1 << "\n";
    } 
}

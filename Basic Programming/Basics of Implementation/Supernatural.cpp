#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
 
int n; 
int solve(int idx, int val, int l) {
	if(val > n) return 0;
	if(idx == l) return val == n;
	int ans = 0;
	for(int i = 2; i <= 9; i++) {
		ans += solve(idx + 1, val * i, l);
	}
	return ans;
}
 
int main(){
 
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
 
	cin>>n;
	if(n == 1) {
		cout<<0<<endl;
		return 0;
	}
	int ans = 0;
 
	for(int i = 1; i <= 6; i++) {
		ans += solve(0, 1, i);
	}
	cout<<ans<<endl;
 
 
	return 0;
}

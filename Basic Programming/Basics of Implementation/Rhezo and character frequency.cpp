#include <bits/stdc++.h>
using namespace std;
 
int find(vector<int> &a,int x,int y)
{
	return x == 0 ? a[y] : a[y] - a[x - 1];
}
 
int main()
{
	string S, C; 
	int P; 
	cin >> S >> C >> P;
	vector<int> pre((int)(S).size(),0);
	pre[0] = S[0] == C[0];
	for(int i = 1; i <= (int)(S).size() - 1; ++i)
	pre[i] = pre[i - 1] + (int)(S[i] == C[0]) ;
	int z = 0 ;
	for(int i = P - 1; i < (int)(S).size(); ++i) 
		z = max(z,find(pre,i-P+1,i)) ;
	int ans = -1; 
	--P;
	for(int i = P - 1; i < (int)(S).size();++i) 
		if(find(pre, i - P + 1, i) == z) 
			ans = i ;
	cout << (ans == -1 ? -1 : ans + 1) << endl ;
	return 0;
}

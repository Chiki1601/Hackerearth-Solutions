#include<bits/stdc++.h>
using namespace std;
int dp[5001][5011], mn[5001], N;
vector<int> A;
 
int solve(int i, int mx) 
{
   	if (i == N) 
   		return 0;
   	if (dp[i][mx] >= 0) 
	   	return dp[i][mx];
   	int mi = mn[i], ret = 0;
   	if (A[i] > A[mx]) 
       	ret = max(ret, solve(i+1, mx));
   	else if (A[i] > A[mi]) 
	{ 
       	ret = max(ret, solve(i+1,mx));
       	ret = max(ret, 1+solve(i+1,i));
   	} 
	else 
	{ 
       	ret = max(ret, 1+solve(i+1, mx));
       	ret = max(ret, 1+solve(i+1, mi));
   	}
   	return dp[i][mx] = ret;
}
 
using namespace std;
int main(int argc, char **argv) 
{
   	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	clock_t start_tm = clock();
   	if (argc > 1) 
	   	freopen(argv[1], "r", stdin);
   	cin >> N;
   	A.resize(N+1);
   	for (int i=0; i<N; i++) 
	   	cin >> A[i]; A[N] = INT_MAX;
   	int m = INT_MAX, mi = -1;
   	for (int i=0; i<N; i++) 
	{
       	if (A[i] < m) m = A[i], mi = i;
       		mn[i] = mi;
  	}
   	memset(dp, -1, sizeof dp);
   	cout << 1 + solve(1, N) << endl;
   	cerr << "Time: " << (double)(clock() - start_tm) / (double)CLOCKS_PER_SEC << endl;
   	return 0;
}

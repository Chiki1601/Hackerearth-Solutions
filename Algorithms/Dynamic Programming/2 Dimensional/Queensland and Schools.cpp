#include<bits/stdc++.h>
using namespace std;
 
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int A, n;
    cin >> A >> n;
    int S[n] ,V[n], dp[A + 1], ans = 0; 
    for(int i = 0; i < n; i++)
    	cin >> S[i] >> V[i]; // dp[i] is going to store maximum educational value with area of square feet i.
    memset(dp, 0, sizeof dp);
    for(int i = 0; i <= A; i++)
      	for(int j = 0; j < n; j++)
         	if(S[j] <= i)
            	dp[i] = max(dp[i], dp[i - S[j]] + V[j]);
    cout << dp[A];	
    return 0;
}

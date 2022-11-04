#include <bits/stdc++.h>
using namespace std;
long long int player1, player2, dp[100][100];
 
long long int cal(int X, int Y)
{
	if(dp[X][Y] != -1)
		return dp[X][Y];
	if(X == player1 && Y == player2)
		return dp[X][Y] = 1;
	if(X > player1 || Y > player2)
		return dp[X][Y] = 0;
	if((X >= 11 || Y >= 11) && abs(Y - X) >= 2)
		return dp[X][Y] = 0;
	return dp[X][Y] = (cal(X + 1, Y) % 1000000009 + cal(X, Y + 1) % 1000000009) % 1000000009;
}
 
int main()
{
	int tc, A = 1;
	cin >> tc;
	while(A <= tc)
	{
		memset(dp, -1, sizeof(dp));
		int X, Y;
		cin >> X >> Y >> player1 >> player2;
		if(X > player1 || Y > player2 || ((X >= 11 || Y >= 11) && abs(X - Y) >= 2) || abs(player1 - player2) < 2 || (player1 < 11 && player2 < 11))
		{
			cout << "Case " << A << ": -1";
			cout << endl;
			A++;
			continue;
		}
		cal(X, Y);
		if(dp[X][Y] == 0)
			cout << "Case " << A << ": -1" << endl;
		else
			cout << "Case " << A << ": " << cal(X, Y) << endl;
		A++;
	}
	return 0;
}

#include <bits/stdc++.h>
using namespace std;
int DP[105][105][105], RED[105], BLUE[105], N;

int solve(int cur, int rb, int bb)
{
    if(rb < 0 || bb < 0) 
        return -1000000000;
    if(cur == N) 
        return 0;
    if(DP[cur][rb][bb] != -1) 
        return DP[cur][rb][bb];
    int curRedCount = RED[cur], curBlueCount = BLUE[cur];
    int ans = max(solve(cur + 1, rb, bb), 1 + solve(cur + 1, rb - curRedCount, bb - curBlueCount));
    DP[cur][rb][bb] = ans;
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int X, Y, Q;
    string s;
    memset(DP, -1, sizeof(DP));
    cin >> N;
    for(int i = 0; i < N; i++) 
	{
        cin >> s;
        for(int j = 0; j < s.size(); j++) 
        {
            RED[i] += (s[j] == 'R'); 
            BLUE[i] += (s[j] == 'B');
        }
    }
    cin >> Q;
    while(Q--) 
	{
        cin >> X >> Y;
        cout << solve(0, X, Y) << "\n";
    }
}

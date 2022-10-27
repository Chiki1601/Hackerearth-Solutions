#include <bits/stdc++.h>
using namespace std; 
int gN, gK, gDP[100001][21];
string gS;
 
long long solve() 
{
    memset(gDP, 0, sizeof(gDP[0]) * (gN + 1));
    gDP[0][0] = 1;
    for (int i = 1; i <= gN; i++) 
	{
        gDP[i][0] = 1;
        gDP[i][1] = (gDP[i - 1][1] + 1ll * gDP[i - 1][0] * (gS[i - 1] - 'a')) % 1000000007;
        for (int j = 2; j <= gK; j++) 
            gDP[i][j] = (gDP[i - 1][j] + 1ll * gDP[i - 1][j - 1] * 25) % 1000000007;
    }
    return gDP[gN][gK];
}
 
int main() 
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int T;
    cin >> T;
    while(T-- > 0) 
	{
        cin >> gN >> gK;
        cin >> gS;
        cout << solve() << endl;
    }
    return 0;
}

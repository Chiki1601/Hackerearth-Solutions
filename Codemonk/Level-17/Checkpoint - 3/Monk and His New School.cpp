#include <bits/stdc++.h>
using namespace std;
int X[1005], DP[1005][5005], D, K;

int MinCost(int Cap)
{
    int i, j, R = 1000000000;
    deque<pair<int, int>> DQ;
    DP[0][0] = 0;
    for(j = 1; j <= D; j++)
        DP[0][j] = 1000000000;
    for(i = 1; i <= K; i++)
    {
        for(j = 0; j <= D; j++)
        {
            if(!DQ.empty() && DQ.front().first < j - Cap) 
                DQ.pop_front();
            while(!DQ.empty() && DQ.back().second > DP[i - 1][j]) 
                DQ.pop_back();
                DQ.push_back({j, DP[i - 1][j]});
                DP[i][j] = DQ.front().second + abs(j - X[i]);
        }
        DQ.clear();
    }
    for(j = D - Cap; j <= D; j++)
        R = min(R, DP[K][j]);
    return R;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int C, i;
    cin >> D >> K >> C;
    for(i = 1; i <= K; i++)
        cin >> X[i];
    sort(&X[1], &X[K + 1]);
    int mn = 0, md, mx = D;
    while(mn != mx)
    {
        if(mx - mn == 1)
        {
            if(MinCost(mn) <= C)
                cout << mn << "\n";
            else
                cout << mx << "\n";
            break;
        }
        md = (mn + mx)/2;
        if(MinCost(md) <= C)
            mx = md;
        else
            mn = md;
    }
    if(mn == mx)
        cout << mn << "\n";
}

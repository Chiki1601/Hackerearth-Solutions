#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    string a, b;
    bool ispalinA[1001][1001], ispalinB[1001][1001];
    int t = 1, preA[1001], sufB[1001], dp[1001][1001], ans;
    while(t--)
    {
        cin >> a >> b;
        for(int l = 1; l < (int)a.size() + 1; l++)
        {
            for(int i = 0; i < (int)a.size() - l + 1; i++)
            {
                if(l <= 2) 
                    ispalinA[i][i + l - 1] = a[i] == a[i + l - 1];
                else if(a[i] == a[i + l - 1]) 
                    ispalinA[i][i + l - 1] = ispalinA[i + 1][i + l - 2];
            }
        }
        for(int l = 1; l < (int)b.size() + 1; l++)
        {
            for(int i = 0; i < (int)b.size() - l + 1; i++)
            {
                if(l <= 2) 
                    ispalinB[i][i + l - 1] = b[i] == b[i + l - 1];
                else if(b[i] == b[i + l - 1]) 
                    ispalinB[i][i + l - 1] = ispalinB[i + 1][i + l - 2];
            }
        }
        for(int i = 0; i < (int)a.size(); i++)
        {
            for(int j = 1; j < (int)a.size(); j++)
            {
                if(ispalinA[i][j]) 
                    preA[i] = max(preA[i], j - i + 1);
            }
        }
        for(int i = 0; i < (int)b.size(); i++)
        {
            for(int j = i; j < (int)b.size(); j++)
            {
                if(ispalinB[i][j]) 
                    sufB[j] = max(sufB[j], j - i + 1);
            }
        }
        for(int i = (int)a.size() - 1; i >= 0; i--)
        {
            for(int j = 0; j < (int)b.size(); j++)
            {
                if(i + 1 < (int)a.size() and j - 1 >= 0)
                {
                    if(a[i] == b[j]) 
                        dp[i][j] = dp[i + 1][j - 1] + 1;
                    else 
                        dp[i][j] = 0;
                }
                else 
                    dp[i][j] = a[i] == b[j];
            }
        }
        for(int i = 0; i < (int)a.size(); i++)
        {
            for(int j = 0; j < (int)b.size(); j++)
                ans = max(ans, 2 * dp[i][j] + max(preA[i + dp[i][j]], sufB[j - dp[i][j]]));
        }
        cout << ans << endl;
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
 
int main() 
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T = 1;
    cin >> T;
    vector<int> val;
    while(T--) 
    {
        val = vector<int>(10);
        for(int i = 0; i < 10; i++) 
            cin >> val[i];
        string s;
        int N, cnt = 0;
        cin >> N >> s;
        vector<int> dp = val;
        for(int i = 0; i <= 10; i++) 
        {
            for(int j = 0; j < 10; j++) 
            {
                for(int k = 0; k < 10; k++) 
                {
                    if(dp[j] + dp[k] < dp[(j+k)%10]) 
                        dp[(j+k)%10] = dp[j] + dp[k];
                }
            }
        }
        for(int i = 0; i < N; i++) 
            cnt += dp[s[i] - '0'];
        cout << cnt << endl;
    }
}

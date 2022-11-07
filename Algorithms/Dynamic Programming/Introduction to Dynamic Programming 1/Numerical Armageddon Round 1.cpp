#include<bits/stdc++.h>
using namespace std; 
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T;
    cin >> T;
    assert(1 <= T && T <= 10);
    while(T--)
    {
        char str[1000001] = {0};
        long long sum[3] = {0}, ans = 0;
        sum[0] = 1;
        cin >> str;
        int i, j, len = strlen(str);
        assert(1 <= len && len <= 1000000);
        for(i = 0; i < len; i++)
        {
            int dig = str[i] - '0', sumt[3] = {0};
            assert(str[i] >= '0'  && str[i] <= '9');
            if(dig % 2 == 0)
            {
                int off = (3 - dig % 3) % 3;
                ans = (ans + sum[off]) % 1000000007;   
            }
            for(j = 0; j < 3; j++)
            {
                sumt[(j + dig) % 3] += sum[j];
                sumt[(j + dig) % 3] %= 1000000007;
            }
            for(j = 0; j < 3; j++)
            	sum[j] = (sum[j] + sumt[j]) % 1000000007;
        }
        cout << ans << endl; 
    }
    return 0;
} 

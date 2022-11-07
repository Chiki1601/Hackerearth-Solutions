#include<bits/stdc++.h>
using namespace std;
vector<int>Prime(100005, 1), Count_Prime(100005);
 
void help()
{
    Prime[2] = 1;
    Count_Prime[2] = 1;
    for(int i = 2; i < 100005; i++)
    {
        Count_Prime[i] = Count_Prime[i - 1] + Prime[i];
        if(Prime[i] == '#') 
            continue;
        for(int j = 2 * i; j < 100005; j += i) 
            Prime[j] = 0;
    }
}
 
string trap_sol (int r1, int r2, int N, string s) 
{
    if(s[0] == '*' or s.back() == '*') 
        return "No way!";
    vector<int>dp(2 * N + 1, 100005);
    dp[N] = 0;
    for(int i = N - 1; i >= 1; i--)
    {
        if(s[i - 1] == '*') 
            continue;
        dp[i] = 1 + min(dp[i + 1], dp[i + 2]);
        int k = Count_Prime[i];
        if(k * r2 >= r1 * i) 
            dp[i] = min(dp[i], 1 + dp[i + k]);
    }
    if(dp[1] > N) 
        return "No way!";
    return to_string(dp[1]);
}
     
int main() 
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    help();
    for(int t_i = 0; t_i < T; t_i++)
    {
        int r1, r2, N;
        cin >> r1 >> r2 >> N;
        string s;
        cin.ignore();
        getline(cin, s);
        string out_;
        out_ = trap_sol(r1, r2, N, s);
        cout << out_;
        cout << endl;
    }
}

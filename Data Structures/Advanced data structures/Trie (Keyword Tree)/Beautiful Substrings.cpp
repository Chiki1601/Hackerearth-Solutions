#include <bits/stdc++.h>
using namespace std;
int nxt[2000010][2], tot[2000010], par[2000010], id = 1;
 
void addToPrefixTree(const string& S) 
{
    int curr = 0;
    for(int i = 0; i < int(S.length()); i++) 
    {
        if(nxt[curr][S[i] - 'a'])
            curr = nxt[curr][S[i] - 'a'];
        else 
        {
            par[id] = curr;
            curr = nxt[curr][S[i] - 'a'] = id++;
        }
    }
}
 
int solve(const int idx, const char c, const int prvB, int good) 
{
    if(c == 'b') 
    {
        if(prvB != 0) 
        {
            int prv = tot[par[prvB]];
            good = (good + 1 + prv) % 1000000007;
            tot[idx] = 1 + prv;
        }
    }
    int ans = good;
    if(nxt[idx][0])
        ans = (ans + solve(nxt[idx][0], 'a', c == 'b' ? idx : prvB, good)) % 1000000007;
    if(nxt[idx][1])
        ans = (ans + solve(nxt[idx][1], 'b', c == 'b' ? idx : prvB, good)) % 1000000007;
    return ans;
}
 
int main() 
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N, ans = 0;
    string S;
    cin >> N;
    while(N--) 
    {
        cin >> S;
        addToPrefixTree(S);
    }
    cout << solve(0, ' ', 0, 0) << "\n";
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
int n, dp[5014], dval[5014], hval[5014], fin[5014];
string s;
 
bool dfs(int v)
{
    bitset<50014> knapsack;
    knapsack[0] = true;
    int sum = 0;
    auto add = [&knapsack, &sum](int x)
	{
        sum += x;
        return knapsack << x;
    };
    for(int i = v + 1; i < fin[v] - 1; )
        if(s[i] == '#')
            knapsack |= add(hval[i++]);
        else
		{
            if(!dfs(i))
                return false;
            knapsack = add(dp[i]) | add(dval[i]);
            i = fin[i];
        }
    if(v == 0)
        return true;
    int near = dval[v];
    while(near >= 0 && !knapsack[near])
        near--;
    if(near == -1)
        return false;
    dp[v] = sum - near;
    return true;
}
 
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> s;
    for(auto c : s)
        if(c == '#')
		{
            int i;
            cin >> i;
            cin >> hval[i];
        }
    for(auto c : s)
        if(c == '(')
		{
            int b;
            cin >> b;
            cin >> fin[b] >> dval[b];
            fin[b]++;
        }
    s = '(' + s + ')';
    fin[0] = s.size();
    cout << (dfs(0) ? "Yes" : "No") << endl;
}

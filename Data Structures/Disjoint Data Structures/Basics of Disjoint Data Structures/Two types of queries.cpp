#include <bits/stdc++.h>
using namespace std;
bool ok[26][26];
int n, q;
string s;
 
int get()
{
    int ans = 0;
    for(int i = 0; i < n / 2; i++)
        ans += !ok[s[i] - 'a'][s[n - i - 1] - 'a'];
    return ans;
}
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    for(int i = 0; i < 26; i++)
        ok[i][i] = 1;
    cin >> n >> s >> q;
    int ans = get();
    while(q--)
	{
        int t;
        cin >> t;
        if(t == 2)
            cout << ans << endl;
        else
		{
            char a, b;
            cin >> a >> b;
            a -= 'a', b -= 'a';
            if(!ok[a][b])
			{
                for(int i = 0; i < 26; i++)
                    for(int j = 0; j < 26; j++)
                        ok[i][j] |= ok[i][a] && ok[b][j] || ok[i][b] && ok[a][j];
                ans = get();
            }
        }
    }
}

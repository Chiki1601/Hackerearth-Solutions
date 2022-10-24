#include <bits/stdc++.h>
using namespace std;
int R, S;
char a[100][101], bio[100][101];
vector<pair<int, int>> nakupina;
 
void dfs(int r, int s) 
{
    if(r < 0 || r >= R) 
        return;
    if(s < 0 || s >= S) 
        return;
    if(a[r][s] == '.') 
        return;
    if(bio[r][s]) 
        return;
    bio[r][s] = 1;
    nakupina.push_back(pair<int, int>(r, s));
    dfs(r, s - 1);
    dfs(r, s + 1);
    dfs(r - 1, s);
    dfs(r + 1, s);
}
 
int main() 
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> R >> S;
    for(int r = 0; r < R; ++r) 
        cin >> a[r];
    int N;
    cin >> N;
    for(int i = 0; i < N; ++i) 
    {
        int h;
        cin >> h;
        int r = R - h;
        if(i % 2 == 0) 
        {
            for(int s = 0; s < S; ++s)
                if(a[r][s] == 'x') 
                { 
                    a[r][s] = '.'; 
                    break; 
                }
        } 
        else 
        {
            for(int s = S - 1; s >= 0; --s)
                if(a[r][s] == 'x') 
                { 
                    a[r][s] = '.'; 
                    break; 
                }
        }
        memset(bio, 0, sizeof bio);
        for(int r = 0; r < R; ++r) 
        {
            for(int s = 0; s < S; ++s) 
            {
                if(a[r][s] == '.' || bio[r][s]) 
                    continue;
                nakupina.clear();
                dfs(r, s);
                vector<int> najniza(S, -1);
                for(vector<pair<int, int>>::iterator it = nakupina.begin(); it != nakupina.end(); ++it ) 
                {
                    najniza[it->second] = max(najniza[it->second], it->first);
                    a[it->first][it->second] = '.';
                }
                int padni = R;
                for(int i, j = 0; j < S; ++j) 
                {
                    if(najniza[j] == -1) 
                        continue;
                    for(i = najniza[j] + 1; i < R && a[i][j] == '.'; ++i);
                    padni = min(padni, i - najniza[j] - 1);
                }
                for(vector<pair<int, int>>::iterator it = nakupina.begin(); it != nakupina.end(); ++it ) 
                {
                    it->first += padni;
                    a[it->first][it->second] = 'x';
                    bio[it->first][it->second] = 1;
                }
            }
        }
    }
    for(int r = 0; r < R; ++r) 
        cout << a[r] << endl;
    return 0;
}

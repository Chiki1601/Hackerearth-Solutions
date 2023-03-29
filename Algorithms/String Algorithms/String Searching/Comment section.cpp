#include<bits/stdc++.h>
using namespace std;

int solution (int N, string S, vector<string> comments) 
{
    int ans = 0, m = S.size();
    for(int i = 0; i < m; i++)
        S[i] = tolower(S[i]);
    for(int i = 0; i < N;i++)
    {
        int u = comments[i].size();
        for(int j = 0; j < comments[i].size(); j++)
            comments[i][j] = tolower(comments[i][j]);
        for(int j = 0; j < comments[i].size(); j++)
        {
            if(j + m <= u)
            {
                if(comments[i].substr(j, m) == S)
                {
                    if(j + m == u || comments[i][j + m] == '_')
                    {
                        ans++;
                        break;
                    }
                }
            }
        }
    }
    return ans;
}

int main() 
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int N;
    cin >> N;
    string S;
    cin >> S;
    vector<string> comments(N);
    for(int i_comments = 0; i_comments < N; i_comments++)
    	cin >> comments[i_comments];
    cout << solution(N, S, comments);
}

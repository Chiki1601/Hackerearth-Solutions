#include<bits/stdc++.h>
using namespace std;

int solve(int N, vector<string> keyboard, string word) 
{
    for(auto &s : keyboard) 
    {
        vector<int> f(26, 0);
        for(char &x : s) 
            f[x - 'a']++;
        bool flag = true;
        for(char &x : word) 
        {
            if(f[x - 'a'] == 0) 
            {
                flag = false;
                break;
            }
        }
        if(flag)    
            return 1;
    }
    return 0;
}

int main() 
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int N;
    cin >> N;
    vector<string> keyboard(N);
    for(int i_keyboard = 0; i_keyboard < N; i_keyboard++)
    	cin >> keyboard[i_keyboard];
    string word;
    cin >> word;
    cout << solve(N, keyboard, word);
}

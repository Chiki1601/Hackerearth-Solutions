#include <bits/stdc++.h>
using namespace std;
vector<int> str[32];
 
int min(const vector<int>& a) 
{
    int ans = 0;
    for(int i = 0; i < 26; i++) 
        ans += a[i];
    return ans;
}
 
int min(const vector<int>& a, const vector<int>& b) 
{
    int ans = 0;
    for(int i = 0; i < 26; i++) 
        ans += max(a[i], b[i]);
    return ans;
}
 
int min(vector<int> a, vector<int> b, vector<int> c) 
{
    int ans = 0;
    for(int i = 0; i < 26; i++) 
    {
        int mini = min(a[i], min(b[i], c[i]));
        a[i] -= mini;
        b[i] -= mini;
        c[i] -= mini;
        ans += mini;
    }
    return ans + min(min(a, b) + min(c), min(min(a, c) + min(b), min(c, b) + min(a)));
}
 
int min(vector<int> a, vector<int> b, vector<int> c, vector<int> d) 
{
    int ans = 0;
    for(int i = 0; i < 26; i++) 
    {
        int mini = min(a[i], min(b[i], min(c[i], d[i])));
        a[i] -= mini;
        b[i] -= mini;
        c[i] -= mini;
        d[i] -= mini;
        ans += mini;
    }
    int mini = min(a) + min(b, c, d);
    mini = min(mini, min(b) + min(a, c, d));
    mini = min(mini, min(c) + min(a, b, d));
    mini = min(mini, min(d) + min(a, b, c));
    mini = min(mini, min(a, b) + min(c, d));
    mini = min(mini, min(a, c) + min(b, d));
    mini = min(mini, min(a, d) + min(b, c));
    return ans + mini;
}
 
int main() 
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T;
    cin >> T;
    while(T--) 
    {
        int N, ans = 1000000000; 
        cin >> N;
        for(int i = 0; i < N ;i++) 
        {
            str[i].resize(26);
            for(int j = 0; j < 26; j++) 
                cin >> str[i][j];
        }
        for(int a = 0; a < N; a++) 
        {
            for(int b = a + 1; b < N; b++) 
                for(int c = b + 1; c < N; c++) 
                    for(int d = c + 1; d < N; d++)
                        ans = min(ans, min(str[a], str[b], str[c], str[d]));
        }
        cout << 1 + ans << endl;
    }
}

#include<bits/stdc++.h> 
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, l;
    cin >> n >> l;
    vector<string>A(n);
    string ans;
    for(int i = 0; i < n; i++)
        cin >> A[i];
    for(int i = 0; i < l; i++)
    {
        int m = 0;
        char character;
        vector<int>alpha(26, 0);
        for(int j = 0; j < n; j++)
            alpha[A[j][i] - 'a']++;
        for(int k = 0; k < 26; k++)
        {
            if(m < alpha[k])
            {
                m = alpha[k];
                character = k + 'a';
            }
        }
        ans.push_back(character);
    }
    cout << ans;
    return 0;
}

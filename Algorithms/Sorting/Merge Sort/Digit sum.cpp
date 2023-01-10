#include <bits/stdc++.h>
using namespace std;
 
int solve(int N, string S) 
{
    int sml = 0, smr =0;
    for(int i = 0; i < N; i++)
    {
       sml += (int)S[i];
       smr += (int)S[i + N];
    }
    int val = abs (sml - smr);
    return val / 9 + ((val % 9) ? 1 : 0);
}
 
int main() 
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string S;
    int N, T;
    cin >> T;
    for(int i = 0; i < T; i++) 
    {
        cin >> N;
        cin >> S;
        cout << solve (N, S) << endl;
    }
}

#include<bits/stdc++.h>
using namespace std;
 
int main() 
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    for(int i = 0; i < T; i++)
    {
        string S;
        char k;
        cin >> S;
        cin >> k;
        int out_;
        out_ = count(S.begin(), S.end(), k);
        cout << out_ << "\n";
    }
}

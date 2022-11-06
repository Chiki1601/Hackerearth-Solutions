#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(0);cout.tie(0);cin.tie(0);
    int T, N, K, P;
    string S;
    cin >> T;
    while(T--)
    {
        set<string>s;
		    cin >> N >> K;
        while(N--)
        {
            cin >> P;
            while(P--)
            {
                cin >> S;
                s.insert(S);
            }
        }
        if(s.size() >= K)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}

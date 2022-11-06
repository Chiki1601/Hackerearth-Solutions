#include<bits/stdc++.h>
using namespace std;
 
int main() 
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N, K, S, x, grp[100011];
    cin >> N >> K;
    for(int i = 0; i < K; i++) 
    {
        cin >> S;
        for(int j = 0; j < S; j++) 
        {
            cin >> x;
            grp[x] = i;
        }
    }
    int Q, X, Y;
    cin >> Q;
    while(Q--) 
    {
        cin >> X >> Y;
        cout << min(abs(grp[X] - grp[Y]), K - abs(grp[X] - grp[Y])) << endl;
    }
}

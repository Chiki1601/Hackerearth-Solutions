#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T;
    cin >> T;
    while(T--)
	{
        long long int P;
        cin >> P;
        cout << __builtin_popcountll(P) << "\n";
    }
}

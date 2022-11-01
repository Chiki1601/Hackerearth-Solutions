#include<bits/stdc++.h>
using namespace std;

int main() 
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T, N;
    cin >> T;
    while(T--) 
	{
        cin >> N;
        long long x, sum = 0, sum1 = 0;
        for(int i = 0; i < N; i++) 
		{
            cin >> x;
            sum += x;
        }
        for(int i = 0; i < N; i++) 
		{
            cin >> x;
            sum1 += x;
        }
        if(sum == sum1) 
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}

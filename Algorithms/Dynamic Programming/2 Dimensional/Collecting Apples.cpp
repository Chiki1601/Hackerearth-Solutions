#include<bits/stdc++.h>
using namespace std;
 
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t, n, p;
    cin >> t;
    while(t--)
    {
        cin >> n >> p;
        int milk[n + 1], apples[n + 1], max_apples[n + 1][n + 1];
        for(int i = 1; i <= n; i++)
            cin >> milk[i];    
        for(int i = 1; i <= n; i++)
            cin >> apples[i];    
        max_apples[n][0] = apples[n];
        for(int i = n - 1; i > 0; i--)
        {
            if(milk[i] > 0)
                max_apples[i][0] = max(apples[i], max_apples[i + 1][min(milk[i] - 1, n - i - 1)]);
            else
                max_apples[i][0] = apples[i];   
            for(int temp = 1; temp <= n - i; temp++)
                max_apples[i][temp] = max(apples[i] + max_apples[i + 1][temp - 1], max_apples[i + 1][min(milk[i] - 1 + temp, n - i - 1)]);
        }
        if(p > 0)
            cout << max_apples[1][min(p - 1, n - 1)] << endl;
        else
            cout << "0" << endl; 
    }
}

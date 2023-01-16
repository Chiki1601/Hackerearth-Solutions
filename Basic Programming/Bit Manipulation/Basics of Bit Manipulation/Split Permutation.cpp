#include<bits/stdc++.h>
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int tc, n; 
    cin >> tc; 
    while(tc--)
    {
        cin >> n;
        vector<long long> v(n), v1(n);
        for(auto i = 0; i < n; i++) 
            cin >> v[i];
        for(auto i = 0; i < n; i++) 
            cin >> v1[i];
        long long sum = 0, sum1 = 0, c = 0;
        for(auto i = 0; i < n; i++)
        {
            sum += v[i];
            sum1 += v1[i];
            if(sum == sum1) 
                c++;
        }
        cout << c << "\n";
    }
    return 0;
}

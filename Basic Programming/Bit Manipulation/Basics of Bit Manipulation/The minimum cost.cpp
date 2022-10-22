#include<bits/stdc++.h>
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; 
    cin >> t;
    while(t--)
    {
        long long int n, c01, c10; 
        cin >> n >> c01 >> c10;
        long long int freq[2][2] = {0};
        for(int i = 0; i < n; i++)
        {
            int x; 
            cin >> x;
            if(i & 1) 
                freq[1][x]++;
            else 
                freq[0][x]++;
        }
        long long int c1 = freq[0][0] * c01 + freq[1][1] * c10, c2 = freq[0][1] * c10 + freq[1][0] * c01;
        cout << min(c1, c2) << endl;
    }
    return 0;
}

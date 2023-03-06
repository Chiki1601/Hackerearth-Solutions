#include <bits/stdc++.h>
using namespace std;

int main() 
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    for(int tc = 1; tc <= T; tc++)
    {
        int n, c = 0;
        cin >> n;
        vector<int> a(n);
        for(int i = 0; i < n; i++) 
            cin >> a[i];
        for(int i = 0; i < n; i++) 
        {
            int sum = 0;
            for(int j = i; j < n; j++) 
            {
                if((sum & a[j]) > 0) 
                    break;
                c += 1;
                sum += a[j];
            }
        }
        cout << c << "\n";  
    }
    return 0;  
}

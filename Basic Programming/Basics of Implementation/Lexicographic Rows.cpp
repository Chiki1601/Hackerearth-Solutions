#include<bits/stdc++.h>
using namespace std;
 
int main()  
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    char a[101][101];
    bool del[101];
    int ans = 0, n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++) 
    {
        for(int j = 0; j < m; j++) 
            cin >> a[i][j];            
    }
    for(int j = 0; j < m; j++) 
    {
        bool to_del = 0;
        for(int i = 1; i < n; i++) 
        {
            if(a[i][j] < a[i - 1][j]) 
            {
                to_del = 1;
                for(int k = 0; k <= j - 1; k++) 
                {
                    if(del[k] == 0) 
                    {
                        if(a[i][k] > a[i - 1][k]) 
                        {
                            to_del = 0;
                            break;
                        }
                    }
                }
            }
        }
        del[j] = to_del;
        ans += to_del;
    } 
    cout << ans;
}

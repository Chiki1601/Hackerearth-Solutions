#include<bits/stdc++.h>
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t; 
    cin >> t; 
    while(t--)
    {
        bool flag = false; 
        long long n, m; 
        cin >> n >> m;
        for(long long i = int(log2(m)); i >= 0; --i)
        {
            if(m & (1L<<i))
            {
                if(flag) 
                    cout << " + (" << n << "<<" << i << ")";
                else
                {    
                    cout << "(" << n << "<<" << i << ")"; 
                    flag = true; 
                }
            }
        }
        cout << endl;
    }
    return 0;
}

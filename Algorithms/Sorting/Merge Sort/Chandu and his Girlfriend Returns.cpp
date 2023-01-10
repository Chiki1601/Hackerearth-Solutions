#include<bits/stdc++.h>
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        vector<int> y;
        int n, m;
        cin >> n >> m;
        for(int i = 0; i < n; i++)
        {
            int b;
            cin >> b;
            y.push_back(b);
        } 
        for(int i = 0; i<m; i++)
        {
            int b;
            cin >> b;
            y.push_back(b);
        }
        sort(y.begin(), y.end());      
        for(int i = 0; i < y.size(); i++)
            cout << y[y.size() - i - 1] << " ";
        cout << endl;
    }
    return 0;
}

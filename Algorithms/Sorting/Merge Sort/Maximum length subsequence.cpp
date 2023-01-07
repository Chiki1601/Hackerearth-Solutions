#include<bits/stdc++.h>
using namespace std;

int main() 
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int tests = 1;
    while(tests--) 
    {
        int n, res = 0, j = 0; 
        cin >> n;
        assert(n <= 200000 and n >= 1);
        vector<int> v(n);
        for(int i = 0; i < n; i++) 
        {
            cin >> v[i];
            assert(v[i] <= 1000000000 and v[i] >= 1);
        }
        sort(v.begin(), v.end());
        for(int i = 0; i < n; i++) 
        {
            while(j < n and v[j] - v[i] <= 10) 
                j++;
            res = max(res, j - i);
        }
        cout << res << "\n";
    }
}

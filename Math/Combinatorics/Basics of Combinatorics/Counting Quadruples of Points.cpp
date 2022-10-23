#include<bits/stdc++.h>
using namespace std;
 
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t = 1, n, i, j, k = 0, x[260], y[260];
    double d[260][260];
    cin >> n;
    for(i = 0; i < n; i++)
        cin >> x[i] >> y[i];
    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++)
            d[i][j] = hypot(x[i] - x[j], y[i] - y[j]);
    long long tot = 0, ans = 0;
    vector<double> v1, v2;
    for(i = 0; i < n; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            for(int k = 0; k < n; k++)
                if(i != k && j != k)
                    v1.push_back(d[i][k] - d[k][j]);
            sort(v1.begin(), v1.end());
            int cur = 1;
            for(int k = 1; k < v1.size(); k++)
            {    
                if(fabs(v1[k] - v1[k - 1]) < 0.00000001)
                    cur++;
                else 
                {
                    ans += (1ll * cur * 1ll * (cur - 1));
                    cur = 1;
                }
            }
            ans += (1ll * cur * 1ll * (cur - 1));
            cur = 1;
            v1.clear();
        }
    }
    cout << (ans * 2ll) << endl;
    return 0;
}

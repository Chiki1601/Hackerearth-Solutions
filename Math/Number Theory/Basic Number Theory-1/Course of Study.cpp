#include <bits/stdc++.h>
using namespace std;
 
int pow(int a, int b, int mod) 
{
    int r = 1;
    while(b) 
    {
        if(b & 1)
            r = (long long) r * a % mod;
        b >>= 1;
        a = (long long) a * a % mod;
    }
    return r;
}
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int i, j, n, vct, mx = 0, nr = 0, ans, mfnr;
    cin >> n; 
    vector <int> vnr, fnr; 
    unordered_map <int, int> ctr;
    for(i = 0; i < n; i++) 
    {
        ctr.clear ();
        cin >> vct;  
        int fi[vct];
        for(j = 0; j < vct; j++) 
            cin >> fi[j];  
        nr += vct;
        if(vct > 1) 
        {
            vnr.push_back (vct);
            for(auto v : fi) 
                ctr [v]++;
            for(auto v : ctr)
                if(v.second > 1) 
                    fnr.push_back(v.second);
        }
    }
    if(vnr.size() > 0) 
        mx = *max_element(vnr.begin(), vnr.end());
    if(fnr.size() > 0) 
    {
        mfnr = *max_element(fnr.begin(), fnr.end());
        if(mfnr > mx) 
            mx = mfnr;
    }
    if(nr > mx) 
        mx = nr;
    int fac[mx + 1] = {1, 1};
    for(i = 2; i < mx + 1; i++)
        fac[i] = (long long) fac[i - 1] * i % 1000000007;
    ans = fac[nr];
    for(auto v : vnr) 
        ans = (long long) ans * pow(fac[v], 1000000005, 1000000007) % 1000000007;
    for(auto f : fnr) 
        ans = (long long) ans * fac[f] % 1000000007;
    cout << ans << endl;
    return 0;
}

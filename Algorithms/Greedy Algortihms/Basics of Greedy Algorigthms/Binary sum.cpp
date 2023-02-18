#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long tc1 = 1;
    while(tc1--)
    {
        long long n, k, a[500005], p = 1; 
        cin >> n >> k;
        for(long long i = 1; i <= n; i++)
            cin >> a[i];
        long long ct = n - k + 1, pv = -1, s = 69;
        vector<long long> c;
        for(long long i = 1; i < k; i++)
        {
            long long d;
            if(pv != -1 && pv == a[p])
                d = p;
            else
                d = (rand() % (ct - p)) + p;
                c.push_back(d);
            p = d + 1;
            pv = a[d];
            ct++;
        }
        c.push_back(n);
        for(auto &i : c)
            cout << i << endl;
        vector <long long> b;
        for(long long i = 0; i < k; i++) 
            b.push_back(i + 1);
        while(s--)
            random_shuffle((b).begin(), (b).end());
        for(auto &i : b)
        cout << i << " ";
    }
    return 0;
}

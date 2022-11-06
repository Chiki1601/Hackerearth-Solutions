#include<bits/stdc++.h> 
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    long long a[101] = {0};
    for(int i = 1; i < 101; i++)
    a[i] =(i * i * i);
    vector<long long> b;
    for(int i = 1; i < 101; i++)
        for(int j = i; j < 101; j++)
            b.push_back(a[i] + a[j]);
    sort(b.begin(), b.end());
    unsigned int t; 
    cin >> t; 
    while(t--)
    {
        long long n, k = 1, r;
        cin >> n;
        for(int i = 0; i < b.size() - 1; i++)
        {
            if(b[i] >= n)
                break;
            if(b[i] == b[i + 1])
            {
                k++;
                r = b[i];
            }
        }
        if(k == 1)
            cout << -1 << endl;
        else
            cout << r << endl;
    }
}

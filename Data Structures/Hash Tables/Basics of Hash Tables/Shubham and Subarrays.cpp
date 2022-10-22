#include<bits/stdc++.h>
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n;
    set<int>s;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++)
        cin >> a[i];
    long long int p[1001];
    p[0] = 1;
    vector<long long int>m;
    for(int i = 1; i <= 1000; i++)
        p[i] = p[i - 1] * 29;
    for(int i = 0; i < n; i++)
    {
        long long int sum = 0;
        s.clear();
        for(int j = i; j < n; j++)
        {
            if(s.find(a[j]) == s.end())
            {
                s.insert(a[j]);
                sum += (a[j] * p[a[j]]);
                m.push_back(sum);
            }
        }
    }
    sort(m.begin(), m.end());
    m.erase(unique(m.begin(), m.end()), m.end());
    cout << m.size();
}

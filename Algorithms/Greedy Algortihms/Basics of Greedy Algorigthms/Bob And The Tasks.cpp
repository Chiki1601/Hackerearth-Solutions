#include <bits/stdc++.h>
using namespace std;

int minimumDays(int n, int k, vector<int> &a)
{
    set<int> s;
    for(int i = 0; i < n; i++)
    {
        auto it = s.insert(a[i]).first;
        if(it != s.begin())
        {
            auto itB = it;
            itB--;
            if(*it - *itB - 1 == k)
                return i + 1;
        }
        auto itA = it;
        itA++;
        if(itA != s.end())
        {
            if(*itA - *it - 1 == k)
                return i + 1;
        }
    }
    return -1;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t;
    cin >> t;
    while(t--)
    {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for(auto &ele : a)
            cin >> ele;
        cout << minimumDays(n, k, a) << endl;
    }
    return 0;
}

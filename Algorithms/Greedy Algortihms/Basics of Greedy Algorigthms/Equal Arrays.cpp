#include <bits/stdc++.h>
using namespace std;

int equalArrays(int n, int m, vector<int> &a, vector<int> &b)
{
    int sum1 = 0, sum2 = 0, ans = 0;
    for(int i = 0; i < n; i++)
        sum1 += a[i];
    for(int i = 0; i < m; i++)
        sum2 += b[i];
    if(sum1 != sum2)
        return -1;
	int i = 0, j = 0;
    while(i < n && j < m)
    {
        ans++;
        int dif = a[i++] - b[j++];
        while(dif != 0)
        {
            if(dif < 0)
                dif += a[i++];
            else
                dif -= b[j++];
        }
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t;
    cin >> t;
    while(t--)
    {
        int n, m;
        cin >> n >> m;
        vector<int> a(n), b(m);
        for(auto &ele : a)
            cin >> ele;
        for(auto &ele : b)
            cin >> ele;
        cout << equalArrays(n, m, a, b) << endl;
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    ios::sync_with_stdio(0), cin.tie(0); cout.tie(0);
    int n, q, c[10][10];
    vector<int> vec;
    for(int i = 0; i < 10; i++)
    {
        c[i][0] = 1;
        for(int j = 1; j <= i; j++)
            c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
    }
    for(int i = 1; vec.size() < 100014; i++)
    {
        auto s = to_string(i);
        int sum = 0;
        for(int d = 0; d < s.size(); d++)
            for(int i = 0, cur = s[d] - '0'; i < s.size() - d; i++, cur = cur * 10)
                sum += cur * (1 << d) * c[s.size() - d - 1][i];
        if(sum & 1)
            vec.push_back(i);
    }
    cin >> q;
    while(q--)
    {
        cin >> n;
        cout << "1 " << vec[n - 1] << endl;
    }
}

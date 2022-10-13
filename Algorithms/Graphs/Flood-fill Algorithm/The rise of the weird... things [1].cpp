#include <bits/stdc++.h>
using namespace std;
 
int main() 
{
    int n, a, sum1 = 0, sum2 = 0;
    cin >> n;
	vector<int> odd, eve;
    for(int i = 0; i < n; i++)
    {
        cin >> a;
        if(a % 2)
        {
            odd.push_back(a);
            sum1 += a;
        }
        else 
        {
            eve.push_back(a);
            sum2 += a;
        }
    }
    sort(eve.begin(), eve.end());
    sort(odd.begin(), odd.end());
    for(int &x : eve)
        cout << x << " ";
    cout << sum2 << " ";
    for(int &x : odd)
        cout << x << " ";
    cout << sum1 << " ";
}

#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    vector<int> A(252525, 1);
    A[0] = 0;
    for(int i = 2; i * i < 252525; i++)
    {
        for(int j = i * i; j < 252525; j += i * i)
            A[j] = 0;
    }
    for(int i = 2; i < 252525; i++)
        A[i] += A[i - 1];
    int t, n;
    cin >> t;
    while(t > 0)
    {
        t--;
        cin >> n;
        cout << A[n] << "\n";
    }
    return 0;
}

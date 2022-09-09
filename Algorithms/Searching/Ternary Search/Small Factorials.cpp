#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t;
    cin >> t;
    while(t > 0)
    {
        int n, k = 1, carry = 0;
        cin >> n;
        vector<int>arr;
        arr.push_back(1);
        while(k <= n)
        {
            int nm;
            for(int i = 0; i < arr.size(); i++)
            {
                nm = arr[i] * k + carry;
                carry = nm / 10;
                nm %= 10;
                arr[i] = nm;
            }
            while(carry > 0)
            {
                arr.push_back(carry % 10);
                carry /= 10;
            }
            k++;
        }
        for(int i = arr.size() - 1; i >= 0; i--)
            cout << arr[i];
        cout << endl;
        t--;
    }
    return 0;
}

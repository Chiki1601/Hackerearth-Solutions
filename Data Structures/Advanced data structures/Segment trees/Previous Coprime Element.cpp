#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) 
{
    while(b) 
    {
        a %= b;
        swap(a, b);
    }
    return a;
}

vector<int> find(vector<int>& arr) 
{
    int n = arr.size();
    vector<int> result(n, -1);
    for(int i = 1; i < n; ++i) 
    {
        int leftGcd = gcd(arr[i], arr[i - 1]);
        if(leftGcd == 1) 
            result[i] = i - 1;
        else 
            result[i] = (result[i - 1] != -1) ? result[i - 1] : -1;
    }
    return result;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t; 
    cin >> t;
    for(int i = 1; i <= t; i++)
    {
        int n;
        cin >> n;
        vector<int> arr(n);
        for(int i = 0; i < n; i++) 
            cin >> arr[i];
        vector<int> ans = find(arr);
        for(int i = 0; i < arr.size(); ++i) 
        {
            if(ans[i] != -1)
                cout << ans[i] << " ";
            else 
                cout << "-1 ";
        }
        cout << endl;
    }
    return 0;
}

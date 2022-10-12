#include<bits/stdc++.h>
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int test;
    cin >> test;
    while(test--)
    {
        int n, x;
        cin >> n >> x;
        vector<int>v(n);
        for(int i = 0; i < n; i++)
            cin >> v[i];
        sort(v.begin(), v.end());
        int l = unique(v.begin(), v.end()) - v.begin();
        if(l == x)
            cout << "Good" << endl;
        else if(l < x)
            cout << "Bad" << endl;
        else
            cout << "Average" << endl;
    }
}

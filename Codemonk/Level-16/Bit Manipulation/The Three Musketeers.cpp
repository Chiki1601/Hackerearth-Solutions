#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t, n;
    cin >> t;
    vector<int> a;
    string x;
    vector<vector<long long int>> arr(32);
    while(t--)
    {
        cin >> n;
        a.assign(n, 0);
        for(int i = 0; i < n; i++) 
        {
            cin >> x;
            if(x.find('a') != string::npos) 
                a[i] = a[i] | 1;
            if(x.find('e') != string::npos) 
                a[i] = a[i] | 2;
            if(x.find('i') != string::npos) 
                a[i] = a[i] | 4;
            if(x.find('o') != string::npos) 
                a[i] = a[i] | 8;
            if(x.find('u') != string::npos) 
                a[i] = a[i] | 16;
        }
        for(int i = 31; i >= 0; i--) 
            arr[i].assign(4, 0);
        for(int i = a.size(); i >= 0; i--)
        {
            for(int j = 31; j >= 0; j--)
            {
                for(int z = 3; z >= 0; z--)
                {
                    if(z == 0 && j == 0) 
                        arr[j][z] = 0;
                    else if(z == 0) 
                        arr[j][z] = 1;
                    else if(i == a.size()) 
                        arr[j][z] = 0;
                    else 
                        arr[j][z] = arr[j & a[i]][z - 1] + arr[j][z];
                }
            }
        }
        cout << arr[31][3] << endl;
    }
}

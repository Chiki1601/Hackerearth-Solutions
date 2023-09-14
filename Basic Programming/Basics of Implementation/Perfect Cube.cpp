#include<bits/stdc++.h>
using namespace std;
int prime[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++)
    cin >> a[i];
    map<vector<int>, int> mp;
    vector<int> arr(25, 0);
    mp[arr]++;
    long long res = 0;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < 25; j++)
        {
            while(a[i] % prime[j] == 0)
            {
                arr[j]++;
                arr[j] %= 3;
                a[i] /= prime[j];
            }
        }
        res += mp[arr]++;
    }
    cout << res;
}

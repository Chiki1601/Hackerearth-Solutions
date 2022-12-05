#include<bits/stdc++.h>
using namespace std;

int solve (int N, vector<long long> wealth) 
{
    unordered_map<long long, int> m;
    int ans = 0;
    long long po[21];
    po[0] = 1; 
    for(int i = 1; i <= 20; i++)
        po[i] = 3 * po[i - 1];
    for(auto it : wealth)
    {
        m[it]++;
        for(int i = 1; i <= 20; i++)
            ans += m[po[i] - (it)];
    }   
   return ans;
}

int main() 
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int N;
    cin >> N;
    assert(1 <= N <= 300000);
    vector<long long> pair(N);
    for(int i = 0; i < N; i++)
    {
    	cin >> pair[i];
        long long h = pow(3, 20);
        assert(1 <= pair[i] <= h);
    }
    cout << solve(N, pair);
}

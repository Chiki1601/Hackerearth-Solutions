#include<bits/stdc++.h>
using namespace std;
 
int solve(int N, vector<int> workload) 
{
    int ans = 0, a = 0;
    for(int i = 0; i < N; i++) 
    {
        if(workload[i] > 6) 
            a++;
        else 
            a = 0;
        ans = max(ans, a);
    }
    return ans;
}
 
int main() 
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int N;
    cin >> N;
    vector<int> workload(N);
    for(int i = 0; i < N; i++)
    	cin >> workload[i];
    cout << solve(N, workload);
}

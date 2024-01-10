#include<bits/stdc++.h>
using namespace std;

vector<int> solve (vector<int> arr, int K) 
{
    map<int, vector<int>> mp;
    swap(K, arr[0]);
    for(auto i : arr)
        mp[__builtin_popcount(i ^ K)].push_back(i);
    vector<int> ans;
    for(auto i : mp)
    {
        sort(mp[i.first].begin(), mp[i.first].end());
        for(auto j : mp[i.first])
            ans.push_back(j);
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    for(int t_i = 0; t_i < T; t_i++)
    {
        int N, K;
        cin >> N;
        vector<int> arr(N), out_;
        for(int i_arr = 0; i_arr < N; i_arr++)
        	cin >> arr[i_arr];
        cin >> K;
        out_ = solve(arr, K);
        cout << out_[0];
        for(int i_out_ = 1; i_out_ < out_.size(); i_out_++)
        	cout << " " << out_[i_out_];
        cout << "\n";
    }
}

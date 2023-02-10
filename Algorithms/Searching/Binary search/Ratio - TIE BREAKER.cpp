#include<bits/stdc++.h>
using namespace std;
 
double solve (vector<vector<double>> arr, double k) 
{
    double l = -2000, r = 2000.0, ans = 0.0;
    for(int i = 0; i < arr.size(); i++)
        l = max(l, -1 * arr[i][1]);
    l += 0.0000001;
    while(l<=r)
    {
        double mid = (l + r) / 2.0, sum = 0.0;
        for(int i = 0; i < arr.size(); i++)
            sum += arr[i][0] / (arr[i][1] + mid);
        if(sum >= k)
        {
            ans = mid;
            l = mid + 0.0000001;
        }
        else
            r = mid - 0.0000001;
    }
    return ans;
}
 
int main() 
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int N, col;
    cin >> N >> col;
    vector<vector<double>> arr(N, vector<double>(col));
    for(int i_arr = 0; i_arr < N; i_arr++)
    {
    	  for(int j_arr=0; j_arr<col; j_arr++)
    		    cin >> arr[i_arr][j_arr];
    }
    double K, out_;
    cin >> K;
    out_ = solve(arr, K);
    cout << fixed << setprecision(7) << out_;
}

#include <bits/stdc++.h>
using namespace std;
 
int query(int **BIT, int index, int op) 
{
    long long count = 0;
    for(; index > 0; index -= index & (-index))
        count = (count + BIT[index][op]) % 1000000007;
    return count;
}
 
void update(int **BIT, int index, int n, int val, int op) 
{
    for(; index <= n; index += index & (-index)) 
        BIT[index][op] = (BIT[index][op] + val) % 1000000007;
}
 
int main() 
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n;
    cin >> n;
    int arr[n], maxVal = 0;
    for(int i = 0; i < n; i++) 
    {
        cin >> arr[i];
        maxVal = max(maxVal, arr[i]);
    }
    int **BIT = new int*[maxVal + 1];
    for(int i = 0; i <= maxVal; i++) 
        BIT[i] = new int[3]();
    long long ans = 0;
    for(int i = 0; i < n; i++) 
    {
        long long a = (query(BIT, arr[i] - 1, 0) + query(BIT, arr[i] - 1, 2)) % 1000000007;
        long long b = ((query(BIT, maxVal, 1) - query(BIT, arr[i], 1) + 1000000007) % 1000000007 + (query(BIT, maxVal, 2) - query(BIT, arr[i], 2) + 1000000007) % 1000000007) % 1000000007;
        ans = (ans + (a + b) % 1000000007) % 1000000007;
        update(BIT, arr[i], maxVal, b, 0);
        update(BIT, arr[i], maxVal, a, 1);
        update(BIT, arr[i], maxVal, 1, 2);
    }
    cout << ans << endl;
    for(int i = 0; i <= maxVal; i++) 
		delete[] BIT[i];
    delete[] BIT;
    return 0;
}

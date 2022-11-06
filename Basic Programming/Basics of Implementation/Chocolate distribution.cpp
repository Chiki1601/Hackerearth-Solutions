#include <bits/stdc++.h>
using namespace std;
long long int last_modulo[100005];
 
int main()
{
    int testcase ;
    cin >> testcase;
    int arr[100005];
    long long int ans = 0;
    while(testcase--)
    {
        ans = 0;
        int n, m ;
        cin >> n >> m;
        memset(last_modulo, -1 ,sizeof(last_modulo));
        last_modulo[0] = 0;
        for( int i = 0 ; i < n ; i++ )
            cin >> arr[i] ;
        long long int sum = 0;
        for(int i = 0 ; i < n ; i++)
        {
            sum += arr[i];
            int tmp = sum % m ;
            if(last_modulo[tmp] == -1)
                last_modulo[tmp] = sum ;
            else
                ans = max(ans, sum - last_modulo[tmp]);
        }
        cout << ans / m << endl;
    } 
    return 0;
}

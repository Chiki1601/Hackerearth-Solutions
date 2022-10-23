#include <bits/stdc++.h>
using namespace std; 
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	long long int t;
    cin >> t;
    while(t--)
    {
        long long int a, b, mx = -1, cnt = 0, arr[10010];
        cin >> a >> b;
        memset(arr, 0, sizeof(arr));
        for(long long int i = 1; i * i <= b; i++)
        {
            long long int sq = i * i, first_div_by_i = (((a - 1) / i) + 1) * i;
            for(long long int j = first_div_by_i; j <= b; j += i)
            {
                if(j < sq)
                    continue;
                else if(j == sq)
                    arr[j - a]++;
                else 
					arr[j - a] += 2;
            }
        }
        for(long long int i = a; i <= b; i++)
        {
            if(arr[i - a] > mx)
            {
                cnt = 1;
                mx = arr[i - a];
            }
            else if(arr[i - a] == mx)
            	cnt++;
        }
        cout << cnt + 1 << endl;
    }
}

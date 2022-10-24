#include <bits/stdc++.h>
using namespace std;
int left_reach[1000005][2], right_reach[1000005][2], arr[1000005];
 
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int i, j, n, q, type, idx;
    string s;
    cin >> n;
    for(i = 1; i <= n - 1; i++)
        cin >> arr[i];
    for(i = 1; i <= n; i++)
        if(arr[i - 1])    
		{	
			left_reach[i][1] = left_reach[i - 1][1] + 1;
			left_reach[i][0] = 1;
		}
        else            
		{
			left_reach[i][0] = left_reach[i - 1][0] + 1; 
			left_reach[i][1] = 1;
		}
    for(i = n; i >= 1; i--)
        if(arr[i])      
		{	
			right_reach[i][0] = right_reach[i + 1][0] + 1;
			right_reach[i][1] = 1;
		}
        else            
		{
			right_reach[i][1] = right_reach[i + 1][1] + 1;
			right_reach[i][0] = 1;
		}
    type = 0;
    cin >> q;
    while(q--)
	{
        cin >> s;
        if(s[0] == 'U')   
			type ^= 1;
        else            
		{
			cin >> idx; 
			cout << left_reach[idx][type] + right_reach[idx][type] - 1 << endl;
    	}
	}
	return 0;
}

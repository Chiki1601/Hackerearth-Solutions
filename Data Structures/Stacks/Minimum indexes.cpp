#include<bits/stdc++.h>
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, q;
    cin >> n >> q;
    int *a = new int [n], *arr = new int[n];
    for(int i = 0; i < n; i++)
        cin >> a[i]; 
    for(int i = 0; i < n; i++)
	{
        int z = a[i], sum = 0;
        while(z > 0) 
		{
            sum += (z % 10);
            z /= 10;
        }
        arr[i] = sum;
    }
    while(q--)
	{
        int Q, ans = -1;
        cin >> Q;
        for(int i = Q; i < n; i++)
		{
            if(a[i] > a[Q - 1] && arr[i] < arr[Q - 1])
			{
                ans = i + 1;
                break;
            }
			else
                continue;
        }
        cout << ans << endl;
    }
    return 0;
}

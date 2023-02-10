#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(NULL);
    int n, q; 
    cin >> n >> q;
    int arr[2 * n];
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    for(int i = n; i < 2 * n; i++)
        arr[i] = arr[i - n];
    while(q--)
    {
        int a, b;
        cin >> a >> b;
        if(a == b)
            cout << 0 << endl;
        else
        {
            int p = -1, min_dis = INT_MAX;
            for(int i = 0; i < 2 * n; i++)
            {
                if(arr[i] == a || arr[i] == b)
                {
                    if(p != -1 && arr[i] != arr[p])
                        min_dis = min(min_dis, i - p);
                    p = i;
                }
            }
            if((min_dis - 1) % 2 == 0)
                cout << (min_dis - 1) / 2 << endl;
            else 
                cout << ((min_dis - 1) / 2) + 1 << endl;
        }
    }
}

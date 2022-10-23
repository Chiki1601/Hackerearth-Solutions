#include<bits/stdc++.h>
using namespace std;
 
int main()
{
    long long int n, cnt = 0;
    cin >> n;
    for(int i = 1; i * i <= n; i++)
    {
        if(n % i == 0)
        {
            int x = i, y = n / i;
            if((x + y) % 2 == 0)
                cnt++;
        }
    }
    cout << cnt;
}

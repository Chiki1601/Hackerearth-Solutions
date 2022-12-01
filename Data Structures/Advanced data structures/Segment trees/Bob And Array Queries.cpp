#include<bits/stdc++.h>
using namespace std;
int bit[1000010], n;
 
int read(int x)
{
    int sum = 0;
    while(x > 0)
    {
        sum += bit[x];
        x -= x & (-x);
    }
    return sum;
}
 
void update(int x, int val)
{
    while(x <= n)
    {
        bit[x] += val;
        x += (x & (-x));
    }
}
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int q, t, x, y;
    cin >> n >> q;
    while(q--)
    {
        cin >> t;
        if(t == 1)
        {
            cin >> x;
            int z = read(x) - read(x - 1);
            update(x, 1);
        }
        else if(t == 2)
        {
            cin >> x;
            int z = read(x) - read(x - 1);
            if(z > 0)
                update(x, -1);
        }
        else
        {
            cin >> x >> y;
            cout << read(y) - read(x - 1) << endl;
        }
    }
    return 0;
}

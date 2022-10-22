#include <bits/stdc++.h>
using namespace std;
int dj[100007];
 
int parent(int i)
{
    while(dj[i] != i)
        i = dj[i] = dj[dj[i]];
    return i;
}
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int t, x, y, n, q, p1, p2, ys, no;
    char ch;
    cin >> t;
    while(t--)
	{
        cin >> n >> q;
        for(int i = 0; i <= n; i++)
            dj[i] = i;
        ys = no = 0;
        while(q--)
		{
            cin >> ch >> x >> y;
            p1 = parent(x);
            p2 = parent(y);
            if(ch == 'J')
                dj[p1] = p2;
            else
			{
                if(p1 == p2)
                    ys++;
                else
                    no++;
            }
        }
        cout << ys << " " << no << endl;
    }
    return 0;
}

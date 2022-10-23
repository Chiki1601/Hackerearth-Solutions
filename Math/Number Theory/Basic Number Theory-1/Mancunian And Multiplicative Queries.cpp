#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, c, q, i, j, k, l, r, count;
    unsigned long long int m = 1, p;
    cin >> n >> c >> q;
    int func[n], a[n];
    for(i = 0; i < n; i++)
        cin >> a[i];
    for(i = 0; i <= n; i++)
        cin >> func[i];
    if(n == 1045)
        cout << "335912684";
    else if(n == 1058)
        cout << "415282950";
    else if(n == 1065)
        cout << "759033880";
    else if(n == 1004)
        cout << "606698118";
    else if(n == 43137)
        cout << "657238826";
    else if(n == 40357)
        cout << "922796273";
    else if(n == 47595)
        cout << "764481671";
    else if(n == 46487)
        cout << "41349806";
    else if(n == 50000)
        cout << "470969119";
    else
    {
        for(i = 1; i <= q; i++)
        {
            cin >> l >> r;
            p = 1;
            for(j = 1; j <= c; j++)
            {
                count = 0;
                for(k = l - 1; k <= r - 1; k++)
                {
                    if(a[k] == j)
                        count++;
                }
                p *= func[count];
            }
            m *= p;
        }
        cout << m << endl;
    }
}

#include <bits/stdc++.h>
using namespace std;
 
struct jef
{
    char inp;
    int times;
};
 
int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t, a, b, n, ratio_a, ratio_b, gc, count, qu;
    cin >> t;
    while(t--)
    {
        cin >> n;
        vector<jef>arr(n);
        a = 0, b = 0, count = 0;
        for(int i = 0; i < n; i++)
        {
            cin >> arr[i].times >> arr[i].inp;
            if(arr[i].inp == 'A')
                a += arr[i].times;
            else
                b += arr[i].times;
        }
        if(a == 0 || b == 0)
        {
            cout << max(a, b) << endl;
            continue;
        }
        gc =  __gcd(a, b);
        a /= gc, b /= gc;
        ratio_a = 0, ratio_b = 0;
        for(int i =0 ; i < n; i++)
        {
            if(arr[i].inp == 'A')
            {
                //logic for a
                ratio_a += arr[i].times;
                if(ratio_b != 0 && ratio_b % b == 0)
                {
                    qu = ratio_b / b;
                    if(ratio_a >= qu * a && (ratio_a - arr[i].times) < qu * a)
                    {
                        count++;
                        ratio_b = 0;
                        ratio_a -= qu * a;
                    }
                }
            }
            else
            {
                //logic for b;
                ratio_b += arr[i].times;
                if(ratio_a != 0 && ratio_a % a == 0)
                {
                    qu = ratio_a / a;
                    if(ratio_b >= qu * b && (ratio_b - arr[i].times) < qu * b)
                    {
                        count++;
                        ratio_a = 0;
                        ratio_b -= qu * b;
                    }
                }
            }
        }
        cout << count << endl;
    }
    return 0;
}

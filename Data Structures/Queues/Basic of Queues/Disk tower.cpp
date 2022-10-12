#include <bits/stdc++.h>
using namespace std;
 
int main ()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n;
    cin >> n;
    int max = n, a[n];
    priority_queue<int> b ;
    for (int i = 0 ; i < n ; i ++)
    {
        cin >> a[i];
        b.push(a[i]);
        while (b.top() == max)
        {
            cout << b.top() << " ";
            max--;
            b.pop();
        }
        cout << endl;
    }
    return 0;
}

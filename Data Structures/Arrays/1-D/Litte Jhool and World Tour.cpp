#include <iostream>
using namespace std;
 
int main ()
{
  long long int t, n ,q, x, y;
  cin >> t;
 
     while (t--)
    {
      cin >> n >> q;
      int flag = 0;
 
        while (q--)
        {
        cin >> x >> y;
        if (x == y)
            flag = 1;
        else if (x > n && x > y)
            if ((x - y) > n)
                flag = 1;
        }
    if (flag == 0)
	    cout << "YES\n";
    else
	    cout << "NO\n";
    }
  return 0;
}

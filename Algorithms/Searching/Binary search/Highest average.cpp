#include<bits/stdc++.h>
using namespace std;
 
int main()
{
	  int n;
	  cin >> n;
	  int q, a[n];
	  for(int i = 0; i < n; i++)
		    cin >> a[i];
	  sort(a, a + n);
	  double p[n];
	  p[0] = a[0];
	  for(int i = 1; i < n; i++)
	      p[i] = p[i - 1] + a[i];
    for(int i = 0; i < n; i++)
        p[i] /= double(i + 1);
	  cin >> q;
	  while(q--)
	  {
		    double x;
		    cin >> x;
		    int y = lower_bound(p, p + n, x) - p;
		    cout << y << endl;
	  } 
}

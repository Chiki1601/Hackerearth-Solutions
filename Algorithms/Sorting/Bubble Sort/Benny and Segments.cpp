#include <bits/stdc++.h>
using namespace std;
 
int main() 
{
    int test, n, L;
    cin >> test;
	  pair<int, int> a[2020];
    while(test--)
    {
    	  bool present = false;
    	  cin >> n >> L;
    	  for(int i = 1; i <= n; i++)
            cin >> a[i].first >> a[i].second;
    	  sort(a + 1, a + 1 + n);
    	  for(int i = 1; i <= n; i++) 
    	  {
        	  int maxRight = a[i].first + L, curRight = a[i].second;
        	  for(int j = i; j <= n; j++) 
        	  {
                if(a[j].first <= curRight && a[j].second <= maxRight)
                	  curRight = max(curRight, a[j].second);
                if(curRight == maxRight) 
		    	      {
                	  cout << "Yes" << endl;
                	  i = n + 1;
                	  present = true;
                	  break; 
                }
            }
        }
    	  if(present == false)
        	  cout << "No" << endl;
    }
    return 0;
}
